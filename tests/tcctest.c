/*
 * TCC auto test program
 */
#അന്തര്ഭാവ "config.h"

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

#എങ്കിൽ defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#അല്ലെങ്കിൽ
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#എങ്കിൽ defined(_WIN32)
#define LONG_DOUBLE ഇരട്ട
#define LONG_DOUBLE_LITERAL(x) x
#അല്ലെങ്കിൽ
#define LONG_DOUBLE long ഇരട്ട
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

തരനിർവചനം __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#അന്തര്ഭാവ TCCLIB_INC

#അന്തര്ഭാവ TCCLIB_INC1.TCCLIB_INC2

#അന്തര്ഭാവ TCCLIB_INC1.h>

#അന്തര്ഭാവ TCCLIB_INC3

#അന്തര്ഭാവ <tcclib.h>

#അന്തര്ഭാവ "tcclib.h"

#അന്തര്ഭാവ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#അല്ലെങ്കിൽ
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#അന്തര്ഭാവ INC(42test)
#അന്തര്ഭാവ incname
#അന്തര്ഭാവ stringify(funnyname)

പൂർണ്ണസംഖ്യ fib(പൂർണ്ണസംഖ്യ n);
ശൂന്യം അക്കം(പൂർണ്ണസംഖ്യ n);
ശൂന്യം forward_ref(ശൂന്യം);
പൂർണ്ണസംഖ്യ isid(പൂർണ്ണസംഖ്യ c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
ശൂന്യം funny_വരി_continuation (പൂർണ്ണസംഖ്യ, ..\
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
#define താഴെയുള്ള_2 താഴെയുള്ള_2 ", world"

സ്ഥിതം പൂർണ്ണസംഖ്യ onetwothree = 123;
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

#എങ്കിൽ 1
#define B3 1
#അല്ലെങ്കിലെങ്കിൽ 1
#define B3 2
#അല്ലെങ്കിലെങ്കിൽ 0
#define B3 3
#അല്ലെങ്കിൽ
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

പൂർണ്ണസംഖ്യ qq(പൂർണ്ണസംഖ്യ x)
{
    തിരികെ x + 40;
}
#define qq(x) x

#define spin_lock(lock) ചെയ്യുക { } ആകുമ്പോൾ (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

ശൂന്യം macro_test(ശൂന്യം)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(മുകളിലെ_2, താഴെയുള്ള_2));
    printf("s2=%s\n", xglue(മുകളിലെ_2, താഴെയുള്ള_2));
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
#അല്ലെങ്കിൽ
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#അല്ലെങ്കിൽ
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#അല്ലെങ്കിൽ
    printf("B1 not defined\n");
#endif
#അല്ലെങ്കിൽ
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#അല്ലെങ്കിൽ
    printf("B2 not defined\n");
#endif
#endif

#എങ്കിൽ 1+1
    printf("test true1\n");
#endif
#എങ്കിൽ 0
    printf("test true2\n");
#endif
#എങ്കിൽ 1-1
    printf("test true3\n");
#endif
#എങ്കിൽ defined(A)
    printf("test trueA\n");
#endif
#എങ്കിൽ defined(B)
    printf("test trueB\n");
#endif

#എങ്കിൽ 0
    printf("test 0\n");
#അല്ലെങ്കിലെങ്കിൽ 0
    printf("test 1\n");
#അല്ലെങ്കിലെങ്കിൽ 2
    printf("test 2\n");
#അല്ലെങ്കിൽ
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
        പൂർണ്ണസംഖ്യ a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(സന്ദേശം) printf("%s\n",സന്ദേശം)

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
#എങ്കിൽ !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      സ്ഥിരം അക്ഷരം *fn = get_file_from_header();
      എങ്കിൽ (fn[0] == '.' && fn[1] == '/')
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


സ്ഥിതം ശൂന്യം print_അക്കം(അക്ഷരം *fn, പൂർണ്ണസംഖ്യ വരി, പൂർണ്ണസംഖ്യ അക്കം) {
    printf("fn %s, line %d, num %d\n", fn, വരി, അക്കം);
}

ശൂന്യം recursive_macro_test(ശൂന്യം)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_അക്കം(x) print_അക്കം(__FILE__,__LINE__,x)
    print_അക്കം(123);
    WRAP(print_അക്കം(123));
    WRAP(WRAP(print_അക്കം(123)));

സ്ഥിതം ഘടന recursive_macro { പൂർണ്ണസംഖ്യ rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#എങ്കിൽ __TINYC__
പൂർണ്ണസംഖ്യ op(a, b)
{
    തിരികെ a / b;
}

പൂർണ്ണസംഖ്യ ret(a)
{
    എങ്കിൽ (a == 2)
        തിരികെ 1;
    എങ്കിൽ (a == 3)
        തിരികെ 2;
    തിരികെ 0;
}
#endif

#എങ്കിൽ !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
അക്ഷരം str_ag1[] = "b";
അക്ഷരം str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
അക്ഷരം str_ag3[] = { "ab"[1], 0 };
അക്ഷരം str_x[2] = { "xy" "z"[2], 0 };
#endif
അക്ഷരം *str_ar[] = { "one", "two" };
ഘടന str_SS {unsigned അക്ഷരം a[3], b; };
ഘടന str_SS str_sinit15 = { "r" };
ഘടന str_SS str_sinit16[] = { { "q" }, 2 };

സ്ഥിതം ശൂന്യം string_test2()
{
    അക്ഷരം *p = "hello";
    അക്ഷരം a3[2] = { "p" };
    അക്ഷരം a4[2] = { "ab" "c"[2], 0 };
    അക്ഷരം *pa1 = "def" + 1;
    അക്ഷരം *pa2 = { "xyz" + 1 };
    പൂർണ്ണസംഖ്യ i = 0;
    ഘടന str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    അക്ഷരം str_ag3[] = { "ab"[1], 0 };
    അക്ഷരം str_x[2] = { "xy" "z"[2], 0 };
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

ശൂന്യം ps(സ്ഥിരം അക്ഷരം *s)
{
    പൂർണ്ണസംഖ്യ c;
    ആകുമ്പോൾ (1) {
        c = *s;
        എങ്കിൽ (c == 0)
            നിർത്തുക;
        printf("%c", c);
        s++;
    }
}

സ്ഥിരം അക്ഷരം foo1_string[] = "\
bar\n\
test\14\
1";

ശൂന്യം string_test()
{
    unsigned പൂർണ്ണസംഖ്യ b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#എങ്കിൽ 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    ആകുമ്പോൾ ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    ആകുമ്പോൾ (b != 0x80000000) {
        അക്കം(b);
        b = b * 2;
    }
    string_test2();
}


ശൂന്യം if1t(പൂർണ്ണസംഖ്യ n, പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ c)
{
    എങ്കിൽ (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    എങ്കിൽ (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    എങ്കിൽ (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    എങ്കിൽ (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    എങ്കിൽ (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    എങ്കിൽ (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    എങ്കിൽ (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    എങ്കിൽ (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    എങ്കിൽ (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    എങ്കിൽ (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    എങ്കിൽ (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    എങ്കിൽ (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    എങ്കിൽ (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    എങ്കിൽ (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

ശൂന്യം if2t(ശൂന്യം)
{
    എങ്കിൽ (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

ശൂന്യം if3t(ശൂന്യം)
{
    അസ്ഥിര long long i = 1;
    എങ്കിൽ (i <= 18446744073709551615ULL)
      ;
    അല്ലെങ്കിൽ
      printf ("if3t:wrong 1\n");
}

ശൂന്യം if_test(ശൂന്യം)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

ശൂന്യം loop_test()
{
    പൂർണ്ണസംഖ്യ i;
    i = 0;
    ആകുമ്പോൾ (i < 10)
        printf("%d", i++);
    printf("\n");
    വേണ്ടി(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    ചെയ്യുക {
        printf("%d", i++);
    } ആകുമ്പോൾ (i < 10);
    printf("\n");

    അക്ഷരം എണ്ണം_2 = 123;
    /* c99 for loop init test */
    വേണ്ടി (size_t എണ്ണം_2 = 1; എണ്ണം_2 < 3; എണ്ണം_2++)
        printf("count=%d\n", എണ്ണം_2);
    printf("count = %d\n", എണ്ണം_2);

    /* break/continue tests */
    i = 0;
    ആകുമ്പോൾ (1) {
        എങ്കിൽ (i == 6)
            നിർത്തുക;
        i++;
        എങ്കിൽ (i == 3)
            തുടരുക;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    ചെയ്യുക {
        എങ്കിൽ (i == 6)
            നിർത്തുക;
        i++;
        എങ്കിൽ (i == 3)
            തുടരുക;
        printf("%d", i);
    } ആകുമ്പോൾ(1);
    printf("\n");

    വേണ്ടി(i = 0;i < 10;i++) {
        എങ്കിൽ (i == 3)
            തുടരുക;
        printf("%d", i);
    }
    printf("\n");
}

തരനിർവചനം പൂർണ്ണസംഖ്യ typedef_and_label;

ശൂന്യം goto_test()
{
    പൂർണ്ണസംഖ്യ i;
    സ്ഥിതം ശൂന്യം *label_table[3] = { &&label1, &&label2, &&label3 };
    ഘടന {
        പൂർണ്ണസംഖ്യ bla;
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
    എങ്കിൽ (i >= 10) 
        പോകുക s_end;
    printf("%d", i);
    i++;
    പോകുക s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    വേണ്ടി(i=0;i<3;i++) {
        പോകുക *label_table[i];
    label1:
        printf("label1\n");
        പോകുക next;
    label2:
        printf("label2\n");
        പോകുക next;
    label3:
        printf("label3\n");
    next: ;
    }
}

എണ്ണൽ {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

എണ്ണൽ test {
    E5 = 1000,
};

ഘടന S_enum {
    എണ്ണൽ {E6 = 42, E7, E8} e:8;
};

എണ്ണൽ ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

എണ്ണൽ { BIASU = -1U<<31 };
എണ്ണൽ { BIASS = -1 << 31 };

സ്ഥിതം പൂർണ്ണസംഖ്യ getint(പൂർണ്ണസംഖ്യ i)
{
  എങ്കിൽ (i)
    തിരികെ 0;
  അല്ലെങ്കിൽ
    തിരികെ (പൂർണ്ണസംഖ്യ)(-1U << 31);
}

ശൂന്യം enum_test()
{
    എണ്ണൽ test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    ഘടന S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    എങ്കിൽ (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    അല്ലെങ്കിൽ
      printf("enum unsigned: wrong\n");
    എങ്കിൽ (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    അല്ലെങ്കിൽ
      printf("enum unsigned: wrong\n");
}

തരനിർവചനം പൂർണ്ണസംഖ്യ *my_ptr;

തരനിർവചനം പൂർണ്ണസംഖ്യ mytype1;
തരനിർവചനം പൂർണ്ണസംഖ്യ mytype2;

ശൂന്യം typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    പൂർണ്ണസംഖ്യ b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

ശൂന്യം forward_test()
{
    forward_ref();
    forward_ref();
}


ശൂന്യം forward_ref(ശൂന്യം)
{
    printf("forward ok\n");
}

തരനിർവചനം ഘടന struct1 {
    പൂർണ്ണസംഖ്യ f1;
    പൂർണ്ണസംഖ്യ f2, f3;
    സംഘം union1 {
        പൂർണ്ണസംഖ്യ v1;
        പൂർണ്ണസംഖ്യ v2;
    } u;
    അക്ഷരം str[3];
} struct1;

ഘടന struct2 {
    പൂർണ്ണസംഖ്യ a;
    അക്ഷരം b;
};

സംഘം union2 {
    പൂർണ്ണസംഖ്യ w1;
    പൂർണ്ണസംഖ്യ w2;
};

ഘടന struct1 st1, st2;

ഘടന empty_mem {
    /* nothing */ ;
    പൂർണ്ണസംഖ്യ x;
};

പൂർണ്ണസംഖ്യ tab[3];
പൂർണ്ണസംഖ്യ tab2[3][2];

പൂർണ്ണസംഖ്യ g;

ശൂന്യം f1(പൂർണ്ണസംഖ്യ g)
{
    printf("g1=%d\n", g);
}

ശൂന്യം scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        പൂർണ്ണസംഖ്യ g;
        g = 3;
        printf("g3=%d\n", g);
        {
            പൂർണ്ണസംഖ്യ g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

പൂർണ്ണസംഖ്യ st2_i;
പൂർണ്ണസംഖ്യ *st2_p = &st2_i;
ശൂന്യം scope2_test()
{
    അക്ഷരം a[50];
    st2_i = 42;
    വേണ്ടി (പൂർണ്ണസംഖ്യ st2_i = 1; st2_i < 10; st2_i++) {
        ബാഹ്യ പൂർണ്ണസംഖ്യ st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
ബാഹ്യ പൂർണ്ണസംഖ്യ st_global1;
പൂർണ്ണസംഖ്യ st_global1=42;
ബാഹ്യ പൂർണ്ണസംഖ്യ st_global1;
പൂർണ്ണസംഖ്യ st_global1;
ബാഹ്യ പൂർണ്ണസംഖ്യ st_global2;
പൂർണ്ണസംഖ്യ st_global2;
ബാഹ്യ പൂർണ്ണസംഖ്യ st_global2;
പൂർണ്ണസംഖ്യ st_global2;

ശൂന്യം array_test()
{
    പൂർണ്ണസംഖ്യ i, j, a[4];

    printf("sizeof(a) = %d\n", വലുപ്പം(a));
    printf("sizeof(\"a\") = %d\n", വലുപ്പം("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", വലുപ്പം(__func__));
#endif
    printf("sizeof tab %d\n", വലുപ്പം(tab));
    printf("sizeof tab2 %d\n", വലുപ്പം tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    വേണ്ടി(i=0;i<3;i++)
        വേണ്ടി(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    വേണ്ടി(i=0;i<3*2;i++) {
        printf(" %3d", ((പൂർണ്ണസംഖ്യ *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", വലുപ്പം(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", വലുപ്പം(ptrdiff_t));
}

ശൂന്യം വ്യഞ്ജകം_test()
{
    പൂർണ്ണസംഖ്യ a, b;
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

പൂർണ്ണസംഖ്യ isid(പൂർണ്ണസംഖ്യ c)
{
    തിരികെ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

പൂർണ്ണസംഖ്യ vstack[10], *vstack_ptr;

ശൂന്യം vpush(പൂർണ്ണസംഖ്യ vt, പൂർണ്ണസംഖ്യ vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

ശൂന്യം vpop(പൂർണ്ണസംഖ്യ *ft, പൂർണ്ണസംഖ്യ *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

ശൂന്യം expr2_test()
{
    പൂർണ്ണസംഖ്യ a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

പൂർണ്ണസംഖ്യ const_len_ar[വലുപ്പം(1/0)]; /* div-by-zero, but in unevaluated context */

ശൂന്യം constant_വ്യഞ്ജകം_test()
{
    പൂർണ്ണസംഖ്യ a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", വലുപ്പം(const_len_ar));
}

പൂർണ്ണസംഖ്യ tab4[10];

ശൂന്യം വ്യഞ്ജകം_ptr_test()
{
    പൂർണ്ണസംഖ്യ arr[10], *p, *q;
    പൂർണ്ണസംഖ്യ i = -1;

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
    p = (പൂർണ്ണസംഖ്യ *)((അക്ഷരം *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        ഘടന size12 {
            പൂർണ്ണസംഖ്യ i, j, k;
        };
        ഘടന size12 s[2], *sp = s;
        പൂർണ്ണസംഖ്യ i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (പൂർണ്ണസംഖ്യ*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (പൂർണ്ണസംഖ്യ)((p - q) / 3));
}

ശൂന്യം വ്യഞ്ജകം_cmp_test()
{
    പൂർണ്ണസംഖ്യ a, b;
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

ഘടന empty {
};

ഘടന aligntest1 {
    അക്ഷരം a[10];
};

ഘടന aligntest2 {
    പൂർണ്ണസംഖ്യ a;
    അക്ഷരം b[10];
};

ഘടന aligntest3 {
    ഇരട്ട a, b;
};

ഘടന aligntest4 {
    ഇരട്ട a[0];
};

ഘടന __attribute__((aligned(16))) aligntest5
{
    പൂർണ്ണസംഖ്യ i;
};
ഘടന aligntest6
{
    പൂർണ്ണസംഖ്യ i;
} __attribute__((aligned(16)));
ഘടന aligntest7
{
    പൂർണ്ണസംഖ്യ i;
};
ഘടന aligntest5 altest5[2];
ഘടന aligntest6 altest6[2];
പൂർണ്ണസംഖ്യ pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
ഘടന aligntest7 altest7[2] __attribute__((aligned(16)));

ഘടന aligntest8
{
  പൂർണ്ണസംഖ്യ i;
} __attribute__((aligned(4096)));

ഘടന Large {
    unsigned long flags;
    സംഘം {
	ശൂന്യം *u1;
	പൂർണ്ണസംഖ്യ *u2;
    };

    ഘടന {
	സംഘം {
	    unsigned long index;
	    ശൂന്യം *freelist;
	};
	സംഘം {
	    unsigned long counters;
	    ഘടന {
		പൂർണ്ണസംഖ്യ bla;
	    };
	};
    };

    സംഘം {
	ഘടന {
	    long u3;
	    long u4;
	};
	ശൂന്യം *u5;
	ഘടന {
	    unsigned long compound_head;
	    unsigned പൂർണ്ണസംഖ്യ compound_dtor;
	    unsigned പൂർണ്ണസംഖ്യ compound_order;
	};
    };
} __attribute__((aligned(2 * വലുപ്പം(long))));

തരനിർവചനം unsigned long long __attribute__((aligned(4))) unaligned_u64;

ഘടന aligntest9 {
    unsigned പൂർണ്ണസംഖ്യ buf_nr;
    unaligned_u64 start_lba;
};

ഘടന aligntest10 {
    unsigned പൂർണ്ണസംഖ്യ buf_nr;
    unsigned long long start_lba;
};

ശൂന്യം struct_test()
{
    struct1 *s;
    സംഘം union2 u;
    ഘടന Large ls;

    printf("sizes: %d %d %d %d\n",
           വലുപ്പം(ഘടന struct1),
           വലുപ്പം(ഘടന struct2),
           വലുപ്പം(സംഘം union1),
           വലുപ്പം(സംഘം union2));
    printf("offsets: %d\n", (പൂർണ്ണസംഖ്യ)((അക്ഷരം*)&st1.u.v1 - (അക്ഷരം*)&st1));
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
    printf("str_addr=%x\n", (പൂർണ്ണസംഖ്യ)(uintptr_t)st1.str - (പൂർണ്ണസംഖ്യ)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest1), __alignof__(ഘടന aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest2), __alignof__(ഘടന aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest3), __alignof__(ഘടന aligntest3));
#എങ്കിൽ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest4), __alignof__(ഘടന aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest5), __alignof__(ഘടന aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest6), __alignof__(ഘടന aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest7), __alignof__(ഘടന aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest8), __alignof__(ഘടന aligntest8));
#എങ്കിൽ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest9), __alignof__(ഘടന aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           വലുപ്പം(ഘടന aligntest10), __alignof__(ഘടന aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           വലുപ്പം(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           വലുപ്പം(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           വലുപ്പം(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#എങ്കിൽ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", വലുപ്പം(ഘടന empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(ഘടന empty));

    printf("Large: sizeof=%d\n", വലുപ്പം(ls));
    memset(&ls, 0, വലുപ്പം(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (പൂർണ്ണസംഖ്യ)((അക്ഷരം*)&ls.compound_head - (അക്ഷരം*)&ls));
}

/* simulate char/short return value with undefined upper bits */
സ്ഥിതം പൂർണ്ണസംഖ്യ __csf(പൂർണ്ണസംഖ്യ x) { തിരികെ x; }
സ്ഥിതം ശൂന്യം *_csf = __csf;
#define csf(t,n) ((t(*)(പൂർണ്ണസംഖ്യ))_csf)(n)

/* XXX: depend on endianness */
ശൂന്യം char_short_test()
{
    പൂർണ്ണസംഖ്യ var1, var2;
    signed അക്ഷരം var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed അക്ഷരം *)&var1, *(signed അക്ഷരം *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned അക്ഷരം *)&var1, *(unsigned അക്ഷരം *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(പൂർണ്ണസംഖ്യ *)&var1, *(പൂർണ്ണസംഖ്യ *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned പൂർണ്ണസംഖ്യ *)&var1, *(unsigned പൂർണ്ണസംഖ്യ *)&var2);
    *(signed അക്ഷരം *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(പൂർണ്ണസംഖ്യ *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed അക്ഷരം)(var1 + 1), (signed അക്ഷരം)(var4 + 1));
#എങ്കിൽ !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned അക്ഷരം,0x89898989);
    var4 = csf(signed അക്ഷരം,0xabababab);
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
    var1 = (signed അക്ഷരം)(unsigned അക്ഷരം)(var3 + 1);
    var4 = (signed അക്ഷരം)(unsigned അക്ഷരം)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(പൂർണ്ണസംഖ്യ)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed അക്ഷരം)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

തരനിർവചനം ഘടന Sym {
    പൂർണ്ണസംഖ്യ v;
    പൂർണ്ണസംഖ്യ t;
    പൂർണ്ണസംഖ്യ c;
    ഘടന Sym *next;
    ഘടന Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

സ്ഥിതം പൂർണ്ണസംഖ്യ toupper1(പൂർണ്ണസംഖ്യ a)
{
    തിരികെ TOUPPER(a);
}

സ്ഥിതം unsigned പൂർണ്ണസംഖ്യ calc_vm_flags(unsigned പൂർണ്ണസംഖ്യ prot)
{
  unsigned പൂർണ്ണസംഖ്യ prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  തിരികെ prot_bits;
}

എണ്ണൽ cast_enum { FIRST, LAST };

സ്ഥിതം ശൂന്യം tst_cast(എണ്ണൽ cast_enum ce)
{
    printf("%d\n", ce);
}

ശൂന്യം bool_test()
{
    പൂർണ്ണസംഖ്യ *s, a, b, t, f, i;

    a = 0;
    s = (ശൂന്യം*)0;
    printf("!s=%d\n", !s);

    എങ്കിൽ (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#എങ്കിൽ 1 && 1
    printf("a1\n");
#endif
#എങ്കിൽ 1 || 0
    printf("a2\n");
#endif
#എങ്കിൽ 1 ? 0 : 1
    printf("a3\n");
#endif
#എങ്കിൽ 0 ? 0 : 1
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
    printf("type of bool: %d\n", (പൂർണ്ണസംഖ്യ) ( (~ ((unsigned പൂർണ്ണസംഖ്യ) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned പൂർണ്ണസംഖ്യ)0)) / 2 );
    /* test ? : cast */
    {
        പൂർണ്ണസംഖ്യ aspect_on;
        പൂർണ്ണസംഖ്യ aspect_native = 65536;
        ഇരട്ട bfu_aspect = 1.0;
        പൂർണ്ണസംഖ്യ aspect;
        വേണ്ടി(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        സ്ഥിതം പൂർണ്ണസംഖ്യ v1 = 34 ? : -1; /* constant case */
        സ്ഥിതം പൂർണ്ണസംഖ്യ v2 = 0 ? : -1; /* constant case */
        പൂർണ്ണസംഖ്യ a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    വേണ്ടി(i=0;i<256;i++) {
        എങ്കിൽ (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

ബാഹ്യ പൂർണ്ണസംഖ്യ undefined_function(ശൂന്യം);
ബാഹ്യ പൂർണ്ണസംഖ്യ defined_function(ശൂന്യം);

#ifdef __clang__
പൂർണ്ണസംഖ്യ undefined_function(ശൂന്യം) {}
#endif

സ്ഥിതം വരിയിൽ ശൂന്യം refer_to_undefined(ശൂന്യം)
{
  undefined_function();
}

ശൂന്യം optimize_out_test(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  പൂർണ്ണസംഖ്യ j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  എങ്കിൽ (0)
    printf("oo:%d\n", undefined_function());
  അല്ലെങ്കിൽ
    printf("oo:%d\n", defined_function());
  എങ്കിൽ (1)
    printf("oo:%d\n", defined_function());
  അല്ലെങ്കിൽ
    printf("oo:%d\n", undefined_function());
  ആകുമ്പോൾ (1) {
      printf("oow:%d\n", defined_function());
      നിർത്തുക;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  തിരഞ്ഞെടുപ്പ് (j)
    അവസ്ഥ 1: നിർത്തുക;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  ആകുമ്പോൾ (1)
    നിർത്തുക;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  ചെയ്യുക
    നിർത്തുക;
  ആകുമ്പോൾ (1);
  printf ("ool2:%d\n", defined_function());
  വേണ്ടി (;;)
    നിർത്തുക;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  ആകുമ്പോൾ (1) {
	{
	  നിർത്തുക;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  ആകുമ്പോൾ (j) {
      എങ്കിൽ (j == 0)
	നിർത്തുക; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  ആകുമ്പോൾ (j) {
      എങ്കിൽ (1)
	j--;
      അല്ലെങ്കിൽ
	breakhere: നിർത്തുക;
      printf("ool6:%d\n", defined_function());
      പോകുക breakhere;
  }
  j = 1;
  ആകുമ്പോൾ (j) {
      j--;
      തുടരുക;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  എങ്കിൽ (0 && undefined_function())
    undefined_function();
  എങ്കിൽ (defined_function() && 0)
    undefined_function();
  എങ്കിൽ (0 && 0)
    undefined_function();
  എങ്കിൽ (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  എങ്കിൽ (1 || undefined_function())
    ;
  അല്ലെങ്കിൽ
    undefined_function();
  എങ്കിൽ (defined_function() || 1)
    ;
  അല്ലെങ്കിൽ
    undefined_function();
  എങ്കിൽ (1 || 1)
    ;
  അല്ലെങ്കിൽ
    undefined_function();
  എങ്കിൽ (defined_function() || 1 || undefined_function())
    ;
  അല്ലെങ്കിൽ
    undefined_function();

  എങ്കിൽ (defined_function() && 0)
    refer_to_undefined();

  എങ്കിൽ (0) {
      (ശൂന്യം)വലുപ്പം( ({
		     ചെയ്യുക { } ആകുമ്പോൾ (0);
		     0;
		     }) );
      undefined_function();
  }

  എങ്കിൽ (0) {
      തിരഞ്ഞെടുപ്പ് (defined_function()) {
          അവസ്ഥ 0: undefined_function(); നിർത്തുക;
          സ്ഥിരസ്ഥിതി: undefined_function(); നിർത്തുക;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  എങ്കിൽ (1)
    തിരികെ;
  printf ("oor:%d\n", undefined_function());
}

പൂർണ്ണസംഖ്യ defined_function(ശൂന്യം)
{
  സ്ഥിതം പൂർണ്ണസംഖ്യ i = 40;
  തിരികെ i++;
}

/* GCC accepts that */
സ്ഥിതം പൂർണ്ണസംഖ്യ tab_reinit[];
സ്ഥിതം പൂർണ്ണസംഖ്യ tab_reinit[10];

സ്ഥിതം പൂർണ്ണസംഖ്യ tentative_ar[];
സ്ഥിതം പൂർണ്ണസംഖ്യ tentative_ar[] = {1,2,3};

പൂർണ്ണസംഖ്യ cinit1; /* a global variable can be defined several times without error ! */
പൂർണ്ണസംഖ്യ cinit1; 
പൂർണ്ണസംഖ്യ cinit1 = 0;
പൂർണ്ണസംഖ്യ *cinit2 = (പൂർണ്ണസംഖ്യ []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
അക്ഷരം സ്ഥിരം * സ്ഥിരം cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
ശൂന്യം *cinit52 = &(ശൂന്യം*){ (ശൂന്യം*) 52 };

#എങ്കിൽ __TINYC__ || __GNUC__ >= 6
പൂർണ്ണസംഖ്യ cinit4 = (പൂർണ്ണസംഖ്യ){44};
ശൂന്യം *cinit51 = (ശൂന്യം*){ (ശൂന്യം*) 51 };
ഘടന _c6 { പൂർണ്ണസംഖ്യ a,b; } cinit6 = (ഘടന _c6){61,62}, *cinit7 = &(ഘടന _c6){71,72};
#അല്ലെങ്കിൽ
പൂർണ്ണസംഖ്യ cinit4 = 44;
ശൂന്യം *cinit51 = (ശൂന്യം*)51;
ഘടന _c6 { പൂർണ്ണസംഖ്യ a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

ശൂന്യം compound_literal_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ *p, i;
    അക്ഷരം *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (പൂർണ്ണസംഖ്യ)cinit51);
    printf("cinit52 : %d\n", *(പൂർണ്ണസംഖ്യ*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (പൂർണ്ണസംഖ്യ []){1, 2, 3};
    വേണ്ടി(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    വേണ്ടി(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (അക്ഷരം *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (അക്ഷരം *){ q };
    printf("q3=%s\n", q3);

    q = (അക്ഷരം []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (പൂർണ്ണസംഖ്യ []){1, 2, cinit1 + 3};
    വേണ്ടി(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    വേണ്ടി(i=0;i<3;i++) {
        p = (പൂർണ്ണസംഖ്യ []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#എങ്കിൽ __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    തിരികെ a + b;
}

പൂർണ്ണസംഖ്യ kr_func2(a, b)
{
    തിരികെ a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    തിരികെ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
അക്ഷരം invalid_function_def()[] {തിരികെ 0;}

#അല്ലെങ്കിൽ
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

ശൂന്യം അക്കം(പൂർണ്ണസംഖ്യ n)
{
    അക്ഷരം *tab, *p;
    tab = (അക്ഷരം*)malloc(20); 
    p = tab;
    ആകുമ്പോൾ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        എങ്കിൽ (n == 0)
            നിർത്തുക;
    }
    ആകുമ്പോൾ (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    സ്വതന്ത്രം(tab);
}

/* structure assignment tests */
ഘടന structa1 {
    പൂർണ്ണസംഖ്യ f1;
    അക്ഷരം f2;
};

ശൂന്യം struct_assign_test1(ഘടന structa1 s1, പൂർണ്ണസംഖ്യ t, ദശാംശം f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

ഘടന structa1 struct_assign_test2(ഘടന structa1 s1, പൂർണ്ണസംഖ്യ t)
{
    s1.f1 += t;
    s1.f2 -= t;
    തിരികെ s1;
}

ശൂന്യം struct_assign_test(ശൂന്യം)
{
    ഘടന S {
      ഘടന structa1 lsta1, lsta2;
      പൂർണ്ണസംഖ്യ i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    സ്ഥിതം ഘടന {
        ശൂന്യം (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

ശൂന്യം cast1(അക്ഷരം a, short b, unsigned അക്ഷരം c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

അക്ഷരം bcast;
short scast;

ശൂന്യം cast_test()
{
    പൂർണ്ണസംഖ്യ a;
    അക്ഷരം c;
    അക്ഷരം tab[10];
    unsigned b,d;
    short s;
    അക്ഷരം *p = ശൂന്യ;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (അക്ഷരം)(a + 1),
           (short)(a + 1),
           (unsigned അക്ഷരം)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (അക്ഷരം)0xfffff,
           (short)0xfffff,
           (unsigned അക്ഷരം)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", വലുപ്പം(c), വലുപ്പം((പൂർണ്ണസംഖ്യ)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (അക്ഷരം)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", വലുപ്പം(+(അക്ഷരം)'a'));
    printf("sizeof(-(char)'a') = %d\n", വലുപ്പം(-(അക്ഷരം)'a'));
    printf("sizeof(~(char)'a') = %d\n", വലുപ്പം(-(അക്ഷരം)'a'));

#എങ്കിൽ CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (പൂർണ്ണസംഖ്യ)p, (unsigned പൂർണ്ണസംഖ്യ)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (ശൂന്യം *)a, (ശൂന്യം *)b, (ശൂന്യം *)c, (ശൂന്യം *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(പൂർണ്ണസംഖ്യ)ul);
}

/* initializers tests */
ഘടന structinit1 {
    പൂർണ്ണസംഖ്യ f1;
    അക്ഷരം f2;
    short f3;
    പൂർണ്ണസംഖ്യ farray[3];
};

പൂർണ്ണസംഖ്യ sinit1 = 2;
പൂർണ്ണസംഖ്യ sinit2 = { 3 };
പൂർണ്ണസംഖ്യ sinit3[3] = { 1, 2, {3}, };
പൂർണ്ണസംഖ്യ sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
പൂർണ്ണസംഖ്യ sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
പൂർണ്ണസംഖ്യ sinit6[] = { 1, 2, 3 };
പൂർണ്ണസംഖ്യ sinit7[] = { [2] = 3, [0] = 1, 2 };
അക്ഷരം sinit8[] = "hello" "trala";

ഘടന structinit1 sinit9 = { 1, 2, 3 };
ഘടന structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
ഘടന structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

അക്ഷരം *sinit12 = "hello world";
അക്ഷരം *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
അക്ഷരം sinit14[10] = { "abc" };
പൂർണ്ണസംഖ്യ sinit15[3] = { വലുപ്പം(sinit15), 1, 2 };

ഘടന { പൂർണ്ണസംഖ്യ a[3], b; } sinit16[] = { { 1 }, 2 };

ഘടന bar {
        അക്ഷരം *s;
        പൂർണ്ണസംഖ്യ len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

പൂർണ്ണസംഖ്യ sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

ഘടന complexinit0 {
    പൂർണ്ണസംഖ്യ a;
    പൂർണ്ണസംഖ്യ b;
};

ഘടന complexinit {
    പൂർണ്ണസംഖ്യ a;
    സ്ഥിരം ഘടന complexinit0 *b;
};

സ്ഥിരം സ്ഥിതം ഘടന complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (സ്ഥിരം ഘടന complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

ഘടന complexinit2 {
	പൂർണ്ണസംഖ്യ a;
	പൂർണ്ണസംഖ്യ b[];
};

ഘടന complexinit2 cix20;

ഘടന complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

ഘടന complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

തരനിർവചനം പൂർണ്ണസംഖ്യ arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
തരനിർവചനം പൂർണ്ണസംഖ്യ arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
പൂർണ്ണസംഖ്യ sinit23[2] = { "astring" ? വലുപ്പം("astring") : -1,
		   &sinit23 ? 42 : -1 };

പൂർണ്ണസംഖ്യ sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
ഘടന bf_SS {unsigned പൂർണ്ണസംഖ്യ bit:1,bits31:31; };
ഘടന bf_SS bf_init = { .bit = 1 };
ഘടന bfn_SS {പൂർണ്ണസംഖ്യ a,b; ഘടന bf_SS c; പൂർണ്ണസംഖ്യ d,e; };
ഘടന bfn_SS bfn_init = { .c.bit = 1 };
ഘടന bfa_SS {പൂർണ്ണസംഖ്യ a,b; ഘടന bf_SS c[3]; പൂർണ്ണസംഖ്യ d,e; };
ഘടന bfa_SS bfa_init = { .c[1].bit = 1 };
ഘടന bf_SS bfaa_init[3] = { [1].bit = 1 };
ഘടന bf_SS bfaa_vinit[] = { [2].bit = 1 };
ഘടന b2_SS {long long പൂർണ്ണസംഖ്യ field : 52; long long പൂർണ്ണസംഖ്യ pad : 12; };
ഘടന b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

ബാഹ്യ പൂർണ്ണസംഖ്യ external_inited = 42;

ശൂന്യം init_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ linit1 = 2;
    പൂർണ്ണസംഖ്യ linit2 = { 3 };
    പൂർണ്ണസംഖ്യ linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    പൂർണ്ണസംഖ്യ linit6[] = { 1, 2, 3 };
    പൂർണ്ണസംഖ്യ i, j;
    അക്ഷരം linit8[] = "hello" "trala";
    പൂർണ്ണസംഖ്യ linit12[10] = { 1, 2 };
    പൂർണ്ണസംഖ്യ linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    അക്ഷരം linit14[10] = "abc";
    പൂർണ്ണസംഖ്യ linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    ഘടന linit16 { പൂർണ്ണസംഖ്യ a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    പൂർണ്ണസംഖ്യ linit17 = വലുപ്പം(linit17);
    പൂർണ്ണസംഖ്യ zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    പൂർണ്ണസംഖ്യ linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    ഘടന bf_SS bf_finit = { .bit = 1 };
    ഘടന bfn_SS bfn_finit = { .c.bit = 1 };
    ഘടന bfa_SS bfa_finit = { .c[1].bit = 1 };
    ഘടന bf_SS bfaa_finit[3] = { [1].bit = 1 };
    ഘടന bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    ഘടന b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           വലുപ്പം(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", വലുപ്പം(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           വലുപ്പം(sinit7),
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

    വേണ്ടി(i=0;i<3;i++)
        വേണ്ടി(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", വലുപ്പം(linit6));
    printf("linit8=%d %s\n", വലുപ്പം(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           വലുപ്പം(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    വേണ്ടി(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    വേണ്ടി(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    വേണ്ടി(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    വേണ്ടി(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    വേണ്ടി(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", വലുപ്പം cix20, വലുപ്പം cix21, വലുപ്പം cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", വലുപ്പം(sinit19), വലുപ്പം(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", വലുപ്പം(sinit21), വലുപ്പം(sinit22));
    printf("arrtype6: %d\n", വലുപ്പം(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    വേണ്ടി (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    വേണ്ടി (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    വേണ്ടി (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    വേണ്ടി (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    വേണ്ടി (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    വേണ്ടി (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

ശൂന്യം switch_uc(unsigned അക്ഷരം uc)
{
	തിരഞ്ഞെടുപ്പ് (uc) {
	    അവസ്ഥ 0xfb ... 0xfe:
		printf("ucsw:1\n");
		നിർത്തുക;
	    അവസ്ഥ 0xff:
		printf("ucsw:2\n");
		നിർത്തുക;
	    അവസ്ഥ 0 ... 5:
		printf("ucsw:3\n");
		നിർത്തുക;
	    സ്ഥിരസ്ഥിതി:
		printf("ucsw: broken!\n");
	}
}

ശൂന്യം switch_sc(signed അക്ഷരം sc)
{
	തിരഞ്ഞെടുപ്പ് (sc) {
	    അവസ്ഥ -5 ... -2:
		printf("scsw:1\n");
		നിർത്തുക;
	    അവസ്ഥ -1:
		printf("scsw:2\n");
		നിർത്തുക;
	    അവസ്ഥ 0 ... 5:
		printf("scsw:3\n");
		നിർത്തുക;
	    സ്ഥിരസ്ഥിതി:
		printf("scsw: broken!\n");
	}
}

ശൂന്യം switch_test()
{
    പൂർണ്ണസംഖ്യ i;
    unsigned long long ull;
    long long ll;

    വേണ്ടി(i=0;i<15;i++) {
        തിരഞ്ഞെടുപ്പ്(i) {
        അവസ്ഥ 0:
        അവസ്ഥ 1:
            printf("a");
            നിർത്തുക;
        സ്ഥിരസ്ഥിതി:
            printf("%d", i);
            നിർത്തുക;
        അവസ്ഥ 8 ... 12:
            printf("c");
            നിർത്തുക;
        അവസ്ഥ 3:
            printf("b");
            നിർത്തുക;
        അവസ്ഥ 0xc33c6b9fU:
        അവസ്ഥ 0x7c9eeeb9U:
            നിർത്തുക;
        }
    }
    printf("\n");

    വേണ്ടി (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	തിരഞ്ഞെടുപ്പ് (ull) {
	    അവസ്ഥ 1ULL << 61:
		printf("ullsw:1\n");
		നിർത്തുക;
	    അവസ്ഥ 2ULL << 61:
		printf("ullsw:2\n");
		നിർത്തുക;
	    അവസ്ഥ 3ULL << 61:
		printf("ullsw:3\n");
		നിർത്തുക;
	    അവസ്ഥ 4ULL << 61:
		printf("ullsw:4\n");
		നിർത്തുക;
	    അവസ്ഥ 5ULL << 61:
		printf("ullsw:5\n");
		നിർത്തുക;
	    സ്ഥിരസ്ഥിതി:
		printf("ullsw: broken!\n");
	}
    }

    വേണ്ടി (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	തിരഞ്ഞെടുപ്പ് (ll) {
	    അവസ്ഥ 1LL << 61:
		printf("llsw:1\n");
		നിർത്തുക;
	    അവസ്ഥ 2LL << 61:
		printf("llsw:2\n");
		നിർത്തുക;
	    അവസ്ഥ 3LL << 61:
		printf("llsw:3\n");
		നിർത്തുക;
	    അവസ്ഥ 4LL << 61:
		printf("llsw:4\n");
		നിർത്തുക;
	    അവസ്ഥ 5LL << 61:
		printf("llsw:5\n");
		നിർത്തുക;
	    സ്ഥിരസ്ഥിതി:
		printf("llsw: broken!\n");
	}
    }

    വേണ്ടി (i = -5; i <= 5; i++) {
	switch_uc((unsigned അക്ഷരം)i);
    }

    വേണ്ടി (i = -5; i <= 5; i++) {
	switch_sc ((signed അക്ഷരം)i);
    }
}

/* ISOC99 _Bool type */
ശൂന്യം c99_bool_test(ശൂന്യം)
{
#ifdef BOOL_ISOC99
    പൂർണ്ണസംഖ്യ a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", വലുപ്പം(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           വലുപ്പം ((അസ്ഥിര പൂർണ്ണസംഖ്യ)a ? b : b2));
#endif
}

ശൂന്യം bitfield_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a;
    short sa;
    unsigned അക്ഷരം ca;
    ഘടന sbf1 {
        പൂർണ്ണസംഖ്യ f1 : 3;
        പൂർണ്ണസംഖ്യ : 2;
        പൂർണ്ണസംഖ്യ f2 : 1;
        പൂർണ്ണസംഖ്യ : 0;
        പൂർണ്ണസംഖ്യ f3 : 5;
        പൂർണ്ണസംഖ്യ f4 : 7;
        unsigned പൂർണ്ണസംഖ്യ f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", വലുപ്പം(st1));

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
    എങ്കിൽ (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    അല്ലെങ്കിൽ 
        printf("st1.f1 != -1\n");
    എങ്കിൽ (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    അല്ലെങ്കിൽ 
        printf("st1.f2 != -1\n");

    ഘടന sbf2 {
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

#എങ്കിൽ 0
    Disabled വേണ്ടി now until further clarification re GCC compatibility
    ഘടന sbf3 {
        പൂർണ്ണസംഖ്യ f1 : 7;
        പൂർണ്ണസംഖ്യ f2 : 1;
        അക്ഷരം f3;
        പൂർണ്ണസംഖ്യ f4 : 8;
        പൂർണ്ണസംഖ്യ f5 : 1;
        പൂർണ്ണസംഖ്യ f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", വലുപ്പം(st3));
#endif

    ഘടന sbf4 {
	പൂർണ്ണസംഖ്യ x : 31;
	അക്ഷരം y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    ഘടന sbf5 {
	പൂർണ്ണസംഖ്യ a;
	അക്ഷരം b;
	പൂർണ്ണസംഖ്യ x : 12, y : 4, : 0, : 4, z : 3;
	അക്ഷരം c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    ഘടന sbf6 {
	short x : 12;
	unsigned അക്ഷരം y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#അല്ലെങ്കിൽ
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
ഇരട്ട strtod(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr);

#എങ്കിൽ defined(_WIN32)
ദശാംശം strtof(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr) {തിരികെ (ദശാംശം)strtod(nptr, endptr);}
LONG_DOUBLE strtold(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr) {തിരികെ (LONG_DOUBLE)strtod(nptr, endptr);}
#അല്ലെങ്കിൽ
ദശാംശം strtof(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr);
LONG_DOUBLE strtold(സ്ഥിരം അക്ഷരം *nptr, അക്ഷരം **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
ശൂന്യം prefix ## cmp(type a, type b)\
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
ശൂന്യം prefix ## fcast(type a)\
{\
    ദശാംശം fa;\
    ഇരട്ട da;\
    LONG_DOUBLE la;\
    പൂർണ്ണസംഖ്യ ia;\
    long long llia;\
    unsigned പൂർണ്ണസംഖ്യ ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (പൂർണ്ണസംഖ്യ)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned പൂർണ്ണസംഖ്യ)a;\
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
    എങ്കിൽ (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
ദശാംശം prefix ## retf(type a) { തിരികെ a; }\
ഇരട്ട prefix ## retd(type a) { തിരികെ a; }\
LONG_DOUBLE prefix ## retld(type a) { തിരികെ a; }\
\
ശൂന്യം prefix ## call(ശൂന്യം)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (ഇരട്ട)strto ## prefix("1.2", ശൂന്യ));\
}\
\
ശൂന്യം prefix ## signed_zeros(ശൂന്യം) \
{\
  type x = 0.0, y = -0.0, n, p;\
  എങ്കിൽ (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  അല്ലെങ്കിൽ\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  എങ്കിൽ (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  അല്ലെങ്കിൽ\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  എങ്കിൽ (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  അല്ലെങ്കിൽ\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  എങ്കിൽ (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  അല്ലെങ്കിൽ\
    printf ("x != -y; this is wrong!\n");\
}\
ശൂന്യം prefix ## nan(ശൂന്യം)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
ശൂന്യം prefix ## test(ശൂന്യം)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    എങ്കിൽ (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, ദശാംശം, ദശാംശം, "%f")
FTEST(d, ഇരട്ട, ഇരട്ട, "%f")
FTEST(ld, long ഇരട്ട, LONG_DOUBLE, "%Lf")

ഇരട്ട ftab1[3] = { 1.2, 3.4, -5.6 };


ശൂന്യം float_test(ശൂന്യം)
{
#എങ്കിൽ !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    അസ്ഥിര ദശാംശം fa, fb;
    അസ്ഥിര ഇരട്ട da, db;
    പൂർണ്ണസംഖ്യ a;
    unsigned പൂർണ്ണസംഖ്യ b;
    സ്ഥിതം ഇരട്ട nan2 = 0.0/0.0;
    സ്ഥിതം ഇരട്ട inf1 = 1.0/0.0;
    സ്ഥിതം ഇരട്ട inf2 = 1e5000;
    അസ്ഥിര LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", വലുപ്പം(ദശാംശം));
    printf("sizeof(double) = %d\n", വലുപ്പം(ഇരട്ട));
    printf("sizeof(long double) = %d\n", വലുപ്പം(LONG_DOUBLE));
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

പൂർണ്ണസംഖ്യ fib(പൂർണ്ണസംഖ്യ n)
{
    എങ്കിൽ (n <= 2)
        തിരികെ 1;
    അല്ലെങ്കിൽ
        തിരികെ fib(n-1) + fib(n-2);
}

#എങ്കിൽ __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#അല്ലെങ്കിൽ
ശൂന്യം __attribute__((aligned(16))) aligned_function(പൂർണ്ണസംഖ്യ i) {}
#endif

ശൂന്യം funcptr_test()
{
    ശൂന്യം (*func)(പൂർണ്ണസംഖ്യ);
    പൂർണ്ണസംഖ്യ a;
    ഘടന {
        പൂർണ്ണസംഖ്യ dummy;
        ശൂന്യം (*func)(പൂർണ്ണസംഖ്യ);
    } st1;
    long diff;

    func = &അക്കം;
    (*func)(12345);
    func = അക്കം;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = അക്കം;
    st1.func(12346);
    printf("sizeof1 = %d\n", വലുപ്പം(funcptr_test));
    printf("sizeof2 = %d\n", വലുപ്പം funcptr_test);
    printf("sizeof3 = %d\n", വലുപ്പം(&funcptr_test));
    printf("sizeof4 = %d\n", വലുപ്പം &funcptr_test);
    a = 0;
    func = അക്കം + a;
    diff = func - അക്കം;
    func(42);
    (func + diff)(42);
    (അക്കം + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((പൂർണ്ണസംഖ്യ)(uintptr_t)func) & 15);
}

ശൂന്യം lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    എങ്കിൽ (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*ദ്വിമാന*/
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

ശൂന്യം llshift(long long a, പൂർണ്ണസംഖ്യ b)
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

ശൂന്യം llfloat(ശൂന്യം)
{
    ദശാംശം fa;
    ഇരട്ട da;
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

long long llfunc1(പൂർണ്ണസംഖ്യ a)
{
    തിരികെ a * 2;
}

ഘടന S {
    പൂർണ്ണസംഖ്യ id; 
    അക്ഷരം item;
};

long long പൂർണ്ണസംഖ്യ മൂല്യം(ഘടന S *v)
{
    തിരികെ ((long long പൂർണ്ണസംഖ്യ)v->item);
}

long long llfunc2(long long x, long long y, പൂർണ്ണസംഖ്യ z)
{
    തിരികെ x * y * z;
}

ശൂന്യം check_opl_save_regs(അക്ഷരം *a, long long b, പൂർണ്ണസംഖ്യ c)
{
    *a = b < 0 && !c;
}

ശൂന്യം longlong_test(ശൂന്യം)
{
    long long a, b, c;
    പൂർണ്ണസംഖ്യ ia;
    unsigned പൂർണ്ണസംഖ്യ ua;
    printf("sizeof(long long) = %d\n", വലുപ്പം(long long));
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
#എങ്കിൽ 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          ഘടന S a;

          a.item = 3;
          printf("%lld\n", മൂല്യം(&a));
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
    u = (unsigned)(പൂർണ്ണസംഖ്യ)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    അക്ഷരം cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

ശൂന്യം manyarg_test(ശൂന്യം)
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

ശൂന്യം*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        ഘടന X { പൂർണ്ണസംഖ്യ _x; };
        ഘടന X *x = va_arg(ap, ഘടന X *);
        തിരികെ x;
}

ശൂന്യം vprintf1(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list ap, aq;
    സ്ഥിരം അക്ഷരം *p;
    പൂർണ്ണസംഖ്യ c, i;
    ഇരട്ട d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    വേണ്ടി(;;) {
        c = *p;
        എങ്കിൽ (c == '\0')
            നിർത്തുക;
        p++;
        എങ്കിൽ (c == '%') {
            c = *p;
            തിരഞ്ഞെടുപ്പ്(c) {
            അവസ്ഥ '\0':
                പോകുക the_end;
            അവസ്ഥ 'd':
                i = va_arg(ap, പൂർണ്ണസംഖ്യ);
                printf("%d", i);
                നിർത്തുക;
            അവസ്ഥ 'f':
                d = va_arg(ap, ഇരട്ട);
                printf("%f", d);
                നിർത്തുക;
            അവസ്ഥ 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                നിർത്തുക;
            അവസ്ഥ 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                നിർത്തുക;
            }
            p++;
        } അല്ലെങ്കിൽ {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

ഘടന myspace {
    short പൂർണ്ണസംഖ്യ profile;
};
ഘടന myspace2 {
#എങ്കിൽ CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    അക്ഷരം a[1];
#അല്ലെങ്കിൽ
    അക്ഷരം a[0];
#endif
};
ഘടന myspace3 {
    അക്ഷരം a[1];
};
ഘടന myspace4 {
    അക്ഷരം a[2];
};
ഘടന mytest {
    ശൂന്യം *foo, *bar, *baz;
};

ഘടന mytest stdarg_for_struct(ഘടന myspace bob, ...)
{
    ഘടന myspace george, bill;
    ഘടന myspace2 alex1;
    ഘടന myspace3 alex2;
    ഘടന myspace4 alex3;
    va_list ap;
    short പൂർണ്ണസംഖ്യ validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, ഘടന myspace2);
    alex2    = va_arg(ap, ഘടന myspace3);
    alex3    = va_arg(ap, ഘടന myspace4);
    bill     = va_arg(ap, ഘടന myspace);
    george   = va_arg(ap, ഘടന myspace);
    validate = va_arg(ap, പൂർണ്ണസംഖ്യ);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    തിരികെ (ഘടന mytest) {};
}

ശൂന്യം stdarg_for_libc(സ്ഥിരം അക്ഷരം *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

ശൂന്യം stdarg_syntax(പൂർണ്ണസംഖ്യ n, ...)
{
    പൂർണ്ണസംഖ്യ i;
    va_list ap;
    എങ്കിൽ (1)
      va_start(ap, n);
    അല്ലെങ്കിൽ
      ;
    i = va_arg(ap, പൂർണ്ണസംഖ്യ);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

തരനിർവചനം ഘടന{
    ഇരട്ട x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

സ്ഥിതം ശൂന്യം stdarg_double_struct(പൂർണ്ണസംഖ്യ nargs, പൂർണ്ണസംഖ്യ posd,...)
{
    പൂർണ്ണസംഖ്യ i;
    ഇരട്ട d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    വേണ്ടി(i = 0; i < nargs; i++) {
        എങ്കിൽ (i == posd) {
            d = va_arg (args, ഇരട്ട);
            printf ("d %d = %g\n", i, d);
        }
        അല്ലെങ്കിൽ {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

ശൂന്യം stdarg_test(ശൂന്യം)
{
    LONG_DOUBLE ld = 1234567891234LL;
    ഘടന myspace bob;
    ഘടന myspace2 bob2;
    ഘടന myspace3 bob3;
    ഘടന myspace4 bob4;

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
#എങ്കിൽ !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

പൂർണ്ണസംഖ്യ reltab[3] = { 1, 2, 3 };

പൂർണ്ണസംഖ്യ *rel1 = &reltab[1];
പൂർണ്ണസംഖ്യ *rel2 = &reltab[2];

ശൂന്യം getmyaddress(ശൂന്യം)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(ശൂന്യം)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       തിരികെ ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
ശൂന്യം relocation_test(ശൂന്യം)
{
    ശൂന്യം (*fptr)(ശൂന്യം) = (ശൂന്യം (*)(ശൂന്യം))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

ശൂന്യം old_style_f(a,b,c)
     പൂർണ്ണസംഖ്യ a, b;
     ഇരട്ട c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

ശൂന്യം decl_func1(പൂർണ്ണസംഖ്യ cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

ശൂന്യം decl_func2(cmpfn)
പൂർണ്ണസംഖ്യ cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

ശൂന്യം old_style_function_test(ശൂന്യം)
{
#എങ്കിൽ CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#അല്ലെങ്കിൽ
    old_style_f((ശൂന്യം *)1, 2, 3.0);
#endif
    decl_func1(ശൂന്യ);
    decl_func2(ശൂന്യ);
}

ശൂന്യം alloca_test()
{
    അക്ഷരം *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    അക്ഷരം *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

ശൂന്യം *bounds_checking_is_enabled()
{
    അക്ഷരം ca[10], *cp = ca-1;
    തിരികെ (ca != cp + 1) ? cp : ശൂന്യ;
}

തരനിർവചനം പൂർണ്ണസംഖ്യ constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

ശൂന്യം c99_vla_test_1(പൂർണ്ണസംഖ്യ size1, പൂർണ്ണസംഖ്യ size2)
{
    പൂർണ്ണസംഖ്യ size = size1 * size2;
    പൂർണ്ണസംഖ്യ tab1[size][2], tab2[10][2];
    ശൂന്യം *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (വലുപ്പം tab1 == size1 * size2 * 2 * വലുപ്പം(പൂർണ്ണസംഖ്യ)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (വലുപ്പം(പൂർണ്ണസംഖ്യ) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * വലുപ്പം(പൂർണ്ണസംഖ്യ)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((പൂർണ്ണസംഖ്യ *) (tab1_ptr + (size1 * 2 + 1) * വലുപ്പം(പൂർണ്ണസംഖ്യ))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    എങ്കിൽ (bad_ptr = bounds_checking_is_enabled()) {
        പൂർണ്ണസംഖ്യ *t1 = &tab1[size1 * size2 - 1][3];
        പൂർണ്ണസംഖ്യ *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        അക്ഷരം*c1 = 1 + വലുപ്പം(tab1) + (അക്ഷരം*)tab1;
        അക്ഷരം*c2 = 1 + വലുപ്പം(tab2) + (അക്ഷരം*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        പൂർണ്ണസംഖ്യ *i1 = tab1[-1];
        പൂർണ്ണസംഖ്യ *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        പൂർണ്ണസംഖ്യ *x1 = tab1[size1 * size2 + 1];
        പൂർണ്ണസംഖ്യ *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } അല്ലെങ്കിൽ {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

ശൂന്യം c99_vla_test_2(പൂർണ്ണസംഖ്യ d, പൂർണ്ണസംഖ്യ h, പൂർണ്ണസംഖ്യ w)
{
    പൂർണ്ണസംഖ്യ x, y, z;
    പൂർണ്ണസംഖ്യ (*arr)[h][w] = malloc(വലുപ്പം(പൂർണ്ണസംഖ്യ) * d*h*w);
    പൂർണ്ണസംഖ്യ c = 1;
    സ്ഥിതം പൂർണ്ണസംഖ്യ (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    വേണ്ടി (z=0; z<d; z++) {
        വേണ്ടി (y=0; y<h; y++) {
            വേണ്ടി (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    വേണ്ടി (z=0; z<d; z++) {
        വേണ്ടി (y=0; y<h; y++) {
            വേണ്ടി (x=0; x<w; x++) {
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
        വലുപ്പം (*arr), വലുപ്പം (*arr)[0], വലുപ്പം (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == വലുപ്പം (*arr + 1) - വലുപ്പം arr,
        0 == വലുപ്പം വലുപ്പം *arr - വലുപ്പം arr,
        starr[0][2][3] == arr[1][2][3]
        );
    സ്വതന്ത്രം (arr);
}

ശൂന്യം c99_vla_test_3a (പൂർണ്ണസംഖ്യ arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ശൂന്യം c99_vla_test_3b(പൂർണ്ണസംഖ്യ s, പൂർണ്ണസംഖ്യ arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ശൂന്യം c99_vla_test_3c(പൂർണ്ണസംഖ്യ s, പൂർണ്ണസംഖ്യ arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

ശൂന്യം c99_vla_test_3d(പൂർണ്ണസംഖ്യ s, പൂർണ്ണസംഖ്യ arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

ശൂന്യം c99_vla_test_3e(പൂർണ്ണസംഖ്യ s, പൂർണ്ണസംഖ്യ arr[][3][--s])
{
    printf ("%d %d %d\n", വലുപ്പം arr, s, arr[1][2][3]);
}

ശൂന്യം c99_vla_test_3(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a[2][3][4];

    memset (a, 0, വലുപ്പം(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

ശൂന്യം c99_vla_test(ശൂന്യം)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


ശൂന്യം sizeof_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a;
    പൂർണ്ണസംഖ്യ **ptr;

    printf("sizeof(int) = %d\n", വലുപ്പം(പൂർണ്ണസംഖ്യ));
    printf("sizeof(unsigned int) = %d\n", വലുപ്പം(unsigned പൂർണ്ണസംഖ്യ));
    printf("sizeof(long) = %d\n", വലുപ്പം(long));
    printf("sizeof(unsigned long) = %d\n", വലുപ്പം(unsigned long));
    printf("sizeof(short) = %d\n", വലുപ്പം(short));
    printf("sizeof(unsigned short) = %d\n", വലുപ്പം(unsigned short));
    printf("sizeof(char) = %d\n", വലുപ്പം(അക്ഷരം));
    printf("sizeof(unsigned char) = %d\n", വലുപ്പം(unsigned അക്ഷരം));
    printf("sizeof(func) = %d\n", വലുപ്പം sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", വലുപ്പം a++);
    printf("a=%d\n", a);
    ptr = ശൂന്യ;
    printf("sizeof(**ptr) = %d\n", വലുപ്പം (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", വലുപ്പം(വലുപ്പം(പൂർണ്ണസംഖ്യ)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -വലുപ്പം(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(പൂർണ്ണസംഖ്യ));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned പൂർണ്ണസംഖ്യ));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(അക്ഷരം));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned അക്ഷരം));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", വലുപ്പം(അക്ഷരം[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   വലുപ്പം( (ഘടന {പൂർണ്ണസംഖ്യ i; പൂർണ്ണസംഖ്യ j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   വലുപ്പം (ഘടന {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", വലുപ്പം(t && 0));
    printf("sizeof(1 && 1) = %d\n", വലുപ്പം(1 && 1));
    printf("sizeof(t || 1) = %d\n", വലുപ്പം(t || 1));
    printf("sizeof(0 || 0) = %d\n", വലുപ്പം(0 || 0));

    പൂർണ്ണസംഖ്യ arr[4], fn();
    printf("sizeof(0, arr) = %d\n", വലുപ്പം(0, arr));
    printf("sizeof(0, fn) = %d\n", വലുപ്പം(0, fn));
}

ശൂന്യം typeof_test(ശൂന്യം)
{
    ഇരട്ട a;
    typeof(a) b;
    typeof(ദശാംശം) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


ഘടന hlist_കണ്ണി;
ഘടന hlist_head {
    ഘടന hlist_കണ്ണി *first, *last;
};

ശൂന്യം consume_ulong (unsigned long i)
{
    i = 0;
}

ശൂന്യം statement_വ്യഞ്ജകം_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a, i;

    /* Basic stmt expr test */
    a = 0;
    വേണ്ടി(i=0;i<10;i++) {
        a += 1 + 
            ( { പൂർണ്ണസംഖ്യ b, j; 
                b = 0; 
                വേണ്ടി(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    ശൂന്യം *v = (ശൂന്യം*)39;
    typeof(({
	    (ഘടന hlist_കണ്ണി *)v;
	    })) x;
    typeof (x)
	ptr = (ഘടന hlist_കണ്ണി *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            സ്ഥിതം സ്ഥിരം അക്ഷരം *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    പൂർണ്ണസംഖ്യ t = 40;
    പൂർണ്ണസംഖ്യ b = ({ പൂർണ്ണസംഖ്യ t = 41; t; });
    പൂർണ്ണസംഖ്യ c = ({ പൂർണ്ണസംഖ്യ t = 42; t; });

    /* Test that aggregate return values work.  */
    ഘടന hlist_head h
	= ({
	   തരനിർവചനം ഘടന hlist_head T;
	   long pre = 48;
	   T t = { (ശൂന്യം*)43, (ശൂന്യം*)44 };
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
       LBL: എങ്കിൽ (i++ == 0) പോകുക LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      പോകുക LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

ശൂന്യം local_label_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a;
    പോകുക l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        പോകുക l1;
    l4:
        printf("aa1\n");
        പോകുക l3;
    l2:
        printf("aa3\n");
        പോകുക l4;
    l1:
        printf("aa2\n");
        പോകുക l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    തിരികെ;
 l4:
    printf("bb1\n");
    പോകുക l2;
 l1:
    printf("bb2\n");
    പോകുക l4;
}

/* inline assembler test */
#എങ്കിൽ (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

തരനിർവചനം __SIZE_TYPE__ word;

/* from linux kernel */
സ്ഥിതം അക്ഷരം * strncat1(അക്ഷരം * dest,സ്ഥിരം അക്ഷരം * src,size_t എണ്ണം_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (എണ്ണം_2)
	: "memory");
തിരികെ dest;
}

സ്ഥിതം അക്ഷരം * strncat2(അക്ഷരം * dest,സ്ഥിരം അക്ഷരം * src,size_t എണ്ണം_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (എണ്ണം_2)
	: "memory");
തിരികെ dest;
}

സ്ഥിതം വരിയിൽ ശൂന്യം * memcpy1(ശൂന്യം * to, സ്ഥിരം ശൂന്യം * from, size_t n)
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
തിരികെ (to);
}

സ്ഥിതം വരിയിൽ ശൂന്യം * memcpy2(ശൂന്യം * to, സ്ഥിരം ശൂന്യം * from, size_t n)
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
തിരികെ (to);
}

സ്ഥിതം __inline__ ശൂന്യം sigaddset1(unsigned പൂർണ്ണസംഖ്യ *set, പൂർണ്ണസംഖ്യ _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

സ്ഥിതം __inline__ ശൂന്യം sigdelset1(unsigned പൂർണ്ണസംഖ്യ *set, പൂർണ്ണസംഖ്യ _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
സ്ഥിതം __inline__ __const__ unsigned പൂർണ്ണസംഖ്യ swab32(unsigned പൂർണ്ണസംഖ്യ x)
{
        തിരികെ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#അല്ലെങ്കിൽ
സ്ഥിതം __inline__ __const__ unsigned പൂർണ്ണസംഖ്യ swab32(unsigned പൂർണ്ണസംഖ്യ x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	തിരികെ x;
}
#endif

സ്ഥിതം __inline__ unsigned long long mul64(unsigned പൂർണ്ണസംഖ്യ a, unsigned പൂർണ്ണസംഖ്യ b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned പൂർണ്ണസംഖ്യ resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#അല്ലെങ്കിൽ
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    തിരികെ res;
}

സ്ഥിതം __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#അല്ലെങ്കിൽ
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    തിരികെ res;
}

ഘടന struct123 {
    പൂർണ്ണസംഖ്യ a;
    പൂർണ്ണസംഖ്യ b;
};
ഘടന struct1231 {
    word addr;
};

word mconstraint_test(ഘടന struct1231 *r)
{
    word ret;
    unsigned പൂർണ്ണസംഖ്യ a[2];
    a[0] = 0;
    __asm__ അസ്ഥിര ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(ഘടന struct123 *)r->addr));
    തിരികെ ret + a[0];
}

#ifdef __x86_64__
പൂർണ്ണസംഖ്യ fls64(unsigned long long x)
{
  പൂർണ്ണസംഖ്യ bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  തിരികെ bitpos + 1;
}
#endif

ശൂന്യം other_constraints_test(ശൂന്യം)
{
    word ret;
    പൂർണ്ണസംഖ്യ var;
#എങ്കിൽ CC_NAME != CC_clang
    __asm__ അസ്ഥിര ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
ശൂന്യം base_func(ശൂന്യം)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
ബാഹ്യ ശൂന്യം override_func1 (ശൂന്യം);
ബാഹ്യ ശൂന്യം override_func2 (ശൂന്യം);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

ശൂന്യം override_func2 (ശൂന്യം)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
ബാഹ്യ പൂർണ്ണസംഖ്യ bug_table[] __attribute__((section("__bug_table")));
അക്ഷരം * get_asm_string (ശൂന്യം)
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
  ബാഹ്യ പൂർണ്ണസംഖ്യ some_ചിഹ്നം;
  asm അസ്ഥിര (".globl some_symbol\n"
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
  അക്ഷരം * str = ((അക്ഷരം*)bug_table) + bug_table[1];
  തിരികെ str;
#അല്ലെങ്കിൽ
  തിരികെ (അക്ഷരം *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
ബാഹ്യ unsigned അക്ഷരം alld_stuff[];
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

ശൂന്യം asm_local_label_diff (ശൂന്യം)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
ശൂന്യം asm_local_statics (ശൂന്യം)
{
  സ്ഥിതം പൂർണ്ണസംഖ്യ localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

സ്ഥിതം
unsigned പൂർണ്ണസംഖ്യ set;

ശൂന്യം fancy_copy (unsigned *in, unsigned *out)
{
  asm അസ്ഥിര ("" : "=r" (*out) : "0" (*in));
}

ശൂന്യം fancy_copy2 (unsigned *in, unsigned *out)
{
  asm അസ്ഥിര ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#എങ്കിൽ defined __x86_64__
ശൂന്യം clobber_r12(ശൂന്യം)
{
    asm അസ്ഥിര("mov $1, %%r12" ::: "r12");
}
#endif

ശൂന്യം test_മുകളിലെ_clobbers_really(ശൂന്യം)
{
#എങ്കിൽ defined __x86_64__
    രജിസ്റ്റർ word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm അസ്ഥിര("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm അസ്ഥിര("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

ശൂന്യം test_മുകളിലെ_clobbers(ശൂന്യം)
{
#എങ്കിൽ defined __x86_64__
    word x1, x2;
    asm അസ്ഥിര("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_മുകളിലെ_clobbers_really();
    asm അസ്ഥിര("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm അസ്ഥിര("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

സ്ഥിതം long cpu_സംഖ്യ;
ശൂന്യം trace_console(long len, long len2)
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
    എങ്കിൽ (0
        &&
            ({
              long pscr_ret__;
              തിരഞ്ഞെടുപ്പ്(len) {
                അവസ്ഥ 4:
                    {
                       long pfo_ret__;
                       തിരഞ്ഞെടുപ്പ് (len2) {
                         അവസ്ഥ 8:	printf("bla"); pfo_ret__ = 42; നിർത്തുക;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  നിർത്തുക;
                അവസ്ഥ 8:
                    {
                       long pfo_ret__;
                       തിരഞ്ഞെടുപ്പ് (len2) {
                         അവസ്ഥ 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_സംഖ്യ));	നിർത്തുക;
                         അവസ്ഥ 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_സംഖ്യ));	നിർത്തുക;
                         അവസ്ഥ 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_സംഖ്യ));	നിർത്തുക;
                         അവസ്ഥ 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_സംഖ്യ));	നിർത്തുക;
                         സ്ഥിരസ്ഥിതി: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  നിർത്തുക;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

ശൂന്യം test_asm_dead_code(ശൂന്യം)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm അസ്ഥിര ("" : "=D" (rdi) : "0" (0));
  (ശൂന്യം)വലുപ്പം (({
      പൂർണ്ണസംഖ്യ var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm അസ്ഥിര ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

ശൂന്യം test_asm_call(ശൂന്യം)
{
#എങ്കിൽ defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  സ്ഥിതം അക്ഷരം str[] = "PATH";
  അക്ഷരം *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm അസ്ഥിര ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#എങ്കിൽ 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#അല്ലെങ്കിൽ
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#എങ്കിൽ defined __x86_64__
# define RX "(%rip)"
#അല്ലെങ്കിൽ
# define RX
#endif

ശൂന്യം asm_dot_test(ശൂന്യം)
{
#ifndef __APPLE__
    പൂർണ്ണസംഖ്യ x;
    വേണ്ടി (x = 1;; ++x) {
        പൂർണ്ണസംഖ്യ r = x;
        തിരഞ്ഞെടുപ്പ് (x) {
        അവസ്ഥ 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        അവസ്ഥ 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#അല്ലെങ്കിൽ
            asm(".text; mov $123, %eax; jmp p0");
#endif
	അവസ്ഥ 3:
#എങ്കിൽ !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#അല്ലെങ്കിൽ
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        അവസ്ഥ 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#അല്ലെങ്കിൽ
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#അല്ലെങ്കിൽ
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        അവസ്ഥ 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); നിർത്തുക;
	}
        എങ്കിൽ (r == x)
            നിർത്തുക;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

ശൂന്യം asm_pcrel_test(ശൂന്യം)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

ശൂന്യം asm_test(ശൂന്യം)
{
    അക്ഷരം buf[128];
    unsigned പൂർണ്ണസംഖ്യ val, val2;
    ഘടന struct123 s1;
    ഘടന struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    പൂർണ്ണസംഖ്യ base_func = 42;
    ശൂന്യം override_func3 (ശൂന്യം);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    രജിസ്റ്റർ പൂർണ്ണസംഖ്യ regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm അസ്ഥിര ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm അസ്ഥിര ("xorl %eax, %eax");

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
    പോകുക label1;
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
    asm അസ്ഥിര(".weak override_func3\n.set override_func3, base_func");
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
    asm അസ്ഥിര("" : "=r" (asmret) : "0"(s2));
    എങ്കിൽ (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm അസ്ഥിര("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    എങ്കിൽ (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm അസ്ഥിര ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_മുകളിലെ_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    തിരികെ;
 label1:
    പോകുക label2;
}

#അല്ലെങ്കിൽ

ശൂന്യം asm_test(ശൂന്യം)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

പൂർണ്ണസംഖ്യ constant_p_var;

പൂർണ്ണസംഖ്യ func(ശൂന്യം);


/* __builtin_clz and __builtin_ctz return random values for 0 */
സ്ഥിതം ശൂന്യം builtin_test_bits(unsigned long long x, പൂർണ്ണസംഖ്യ cnt[])
{
#എങ്കിൽ GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    എങ്കിൽ ((unsigned പൂർണ്ണസംഖ്യ) x) cnt[3] += __builtin_clz(x);
    എങ്കിൽ ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    എങ്കിൽ ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    എങ്കിൽ ((unsigned പൂർണ്ണസംഖ്യ) x) cnt[6] += __builtin_ctz(x);
    എങ്കിൽ ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    എങ്കിൽ ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#എങ്കിൽ GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

ശൂന്യം builtin_test(ശൂന്യം)
{
    short s;
    പൂർണ്ണസംഖ്യ i;
    long long ll;
#എങ്കിൽ GCC_MAJOR >= 3
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ, unsigned പൂർണ്ണസംഖ്യ);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ, അക്ഷരം);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ, സ്ഥിരം പൂർണ്ണസംഖ്യ);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ, അസ്ഥിര പൂർണ്ണസംഖ്യ);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ[2], സ്ഥിരം പൂർണ്ണസംഖ്യ[2]);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ[2][3], അസ്ഥിര പൂർണ്ണസംഖ്യ[][3]);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ (*)[], സ്ഥിരം പൂർണ്ണസംഖ്യ (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (സ്ഥിരം പൂർണ്ണസംഖ്യ (*)[2])0 : (പൂർണ്ണസംഖ്യ (*)[2])0),
                സ്ഥിരം പൂർണ്ണസംഖ്യ (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (സ്ഥിരം പൂർണ്ണസംഖ്യ (*)[2][3])0 :
                              (അസ്ഥിര പൂർണ്ണസംഖ്യ (*)[2][3])0),
                സ്ഥിരം അസ്ഥിര പൂർണ്ണസംഖ്യ (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (അസ്ഥിര പൂർണ്ണസംഖ്യ (*)[2][3])0 :
                              (സ്ഥിരം പൂർണ്ണസംഖ്യ (*)[2][3])0),
                സ്ഥിരം അസ്ഥിര പൂർണ്ണസംഖ്യ (*)[2][3]);
#അല്ലെങ്കിൽ
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ *, പൂർണ്ണസംഖ്യ *);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ *, ശൂന്യം *);
    COMPAT_TYPE(പൂർണ്ണസംഖ്യ *, സ്ഥിരം പൂർണ്ണസംഖ്യ *);
    COMPAT_TYPE(അക്ഷരം *, unsigned അക്ഷരം *);
    COMPAT_TYPE(അക്ഷരം *, signed അക്ഷരം *);
    COMPAT_TYPE(അക്ഷരം *, അക്ഷരം *);
    COMPAT_TYPE(അക്ഷരം **, ശൂന്യം *);
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
#അല്ലെങ്കിൽ
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
    i = വലുപ്പം (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = വലുപ്പം (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	പൂർണ്ണസംഖ്യ cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, വലുപ്പം(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        വേണ്ടി (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        വേണ്ടി (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	വേണ്ടി (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#എങ്കിൽ defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
ശൂന്യം weak_test(ശൂന്യം) {}
#അല്ലെങ്കിൽ
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_f1(ശൂന്യം);
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_f2(ശൂന്യം);
ബാഹ്യ പൂർണ്ണസംഖ്യ                       weak_f3(ശൂന്യം);
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_v1;
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_v2;
ബാഹ്യ പൂർണ്ണസംഖ്യ                       weak_v3;

ബാഹ്യ പൂർണ്ണസംഖ്യ                           (*weak_fpa)() __attribute__((weak));
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute__((weak))     (*weak_fpb)();
ബാഹ്യ     __attribute__((weak)) പൂർണ്ണസംഖ്യ (*weak_fpc)();

ബാഹ്യ പൂർണ്ണസംഖ്യ                     weak_asm_f1(ശൂന്യം) asm("weak_asm_f1x") __attribute((weak));
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute((weak)) weak_asm_f2(ശൂന്യം) asm("weak_asm_f2x")                    ;
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute((weak)) weak_asm_f3(ശൂന്യം) asm("weak_asm_f3x") __attribute((weak));
ബാഹ്യ പൂർണ്ണസംഖ്യ                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
ബാഹ്യ പൂർണ്ണസംഖ്യ __attribute((weak)) weak_asm_v3(ശൂന്യം) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
സ്ഥിതം സ്ഥിരം size_t dummy = 0;
ബാഹ്യ __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
ബാഹ്യ __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
ബാഹ്യ __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

പൂർണ്ണസംഖ്യ some_lib_func(ശൂന്യം);
പൂർണ്ണസംഖ്യ dummy_impl_of_slf(ശൂന്യം) { തിരികെ 444; }
#ifndef __clang__
പൂർണ്ണസംഖ്യ some_lib_func(ശൂന്യം) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

പൂർണ്ണസംഖ്യ weak_toolate() __attribute__((weak));
പൂർണ്ണസംഖ്യ weak_toolate() { തിരികെ 0; }

ശൂന്യം __attribute__((weak)) weak_test(ശൂന്യം)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != ശൂന്യ);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != ശൂന്യ);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != ശൂന്യ);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != ശൂന്യ);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != ശൂന്യ);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != ശൂന്യ);
#ifdef __clang__
	printf("some_lib_func=444\n");
#അല്ലെങ്കിൽ
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_f2() { തിരികെ 222; }
പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_f3() { തിരികെ 333; }
പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_v2 = 222;
പൂർണ്ണസംഖ്യ __attribute__((weak)) weak_v3 = 333;
#endif

ശൂന്യം const_func(സ്ഥിരം പൂർണ്ണസംഖ്യ a)
{
}

ശൂന്യം const_warn_test(ശൂന്യം)
{
    const_func(1);
}

ഘടന condstruct {
  പൂർണ്ണസംഖ്യ i;
};

പൂർണ്ണസംഖ്യ getme (ഘടന condstruct *s, പൂർണ്ണസംഖ്യ i)
{
  പൂർണ്ണസംഖ്യ i1 = (i == 0 ? 0 : s)->i;
  പൂർണ്ണസംഖ്യ i2 = (i == 0 ? s : 0)->i;
  പൂർണ്ണസംഖ്യ i3 = (i == 0 ? (ശൂന്യം*)0 : s)->i;
  പൂർണ്ണസംഖ്യ i4 = (i == 0 ? s : (ശൂന്യം*)0)->i;
  തിരികെ i1 + i2 + i3 + i4;
}

ഘടന global_data
{
  പൂർണ്ണസംഖ്യ a[40];
  പൂർണ്ണസംഖ്യ *b[40];
};

ഘടന global_data global_data;

പൂർണ്ണസംഖ്യ global_data_getstuff (പൂർണ്ണസംഖ്യ *, പൂർണ്ണസംഖ്യ);

ശൂന്യം global_data_callit (പൂർണ്ണസംഖ്യ i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

പൂർണ്ണസംഖ്യ global_data_getstuff (പൂർണ്ണസംഖ്യ *p, പൂർണ്ണസംഖ്യ i)
{
  തിരികെ *p + i;
}

ശൂന്യം global_data_test (ശൂന്യം)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

ഘടന cmpcmpS
{
  unsigned അക്ഷരം fill : 3;
  unsigned അക്ഷരം b1 : 1;
  unsigned അക്ഷരം b2 : 1;
  unsigned അക്ഷരം fill2 : 3;
};

പൂർണ്ണസംഖ്യ glob1, glob2, glob3;

ശൂന്യം compare_comparisons (ഘടന cmpcmpS *s)
{
  എങ്കിൽ (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

ശൂന്യം cmp_comparison_test(ശൂന്യം)
{
  ഘടന cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

പൂർണ്ണസംഖ്യ fcompare (ഇരട്ട a, ഇരട്ട b, പൂർണ്ണസംഖ്യ code)
{
  തിരഞ്ഞെടുപ്പ് (code) {
    അവസ്ഥ 0: തിരികെ a == b;
    അവസ്ഥ 1: തിരികെ a != b;
    അവസ്ഥ 2: തിരികെ a < b;
    അവസ്ഥ 3: തിരികെ a >= b;
    അവസ്ഥ 4: തിരികെ a > b;
    അവസ്ഥ 5: തിരികെ a <= b;
  }
  തിരികെ 0;
}

ശൂന്യം math_cmp_test(ശൂന്യം)
{
  ഇരട്ട nan = 0.0/0.0;
  ഇരട്ട one = 1.0;
  ഇരട്ട two = 2.0;
  പൂർണ്ണസംഖ്യ comp = 0;
  പൂർണ്ണസംഖ്യ v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  എങ്കിൽ (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  എങ്കിൽ (a op b) \
    bug (a,b,op,iop,2); \
  എങ്കിൽ (a iop b) \
    ; \
  അല്ലെങ്കിൽ \
    bug (a,b,op,iop,3); \
  എങ്കിൽ ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  എങ്കിൽ ((a iop b) || comp) \
    ; \
  അല്ലെങ്കിൽ \
    bug (a,b,op,iop,5); \
  എങ്കിൽ (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  എങ്കിൽ (!fcompare (nan, nan, 1))
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

ഇരട്ട get100 () { തിരികെ 100.0; }

ശൂന്യം callsave_test(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ i, s; ഇരട്ട *d; ഇരട്ട t;
  s = വലുപ്പം (ഇരട്ട);
  printf ("callsavetest: %d\n", s);
  d = alloca (വലുപ്പം(ഇരട്ട));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


ശൂന്യം bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (അക്ഷരം *)__builtin_frame_address(3) + str_offset);
}
ശൂന്യം bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (അക്ഷരം *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
ശൂന്യം bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (അക്ഷരം *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

ശൂന്യം builtin_frame_address_test(ശൂന്യം)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    അക്ഷരം str[] = "__builtin_frame_address";
    അക്ഷരം *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

അക്ഷരം via_volatile (അക്ഷരം i)
{
  അക്ഷരം അസ്ഥിര vi;
  vi = i;
  തിരികെ vi;
}

ശൂന്യം volatile_test(ശൂന്യം)
{
    എങ്കിൽ (via_volatile (42) != 42)
      printf (" broken\n");
    അല്ലെങ്കിൽ
      printf (" ok\n");
}

ഘടന __attribute__((__packed__)) Spacked {
    അക്ഷരം a;
    short b;
    പൂർണ്ണസംഖ്യ c;
};
ഘടന Spacked spacked;
തരനിർവചനം ഘടന __attribute__((__packed__)) {
    അക്ഷരം a;
    short b;
    പൂർണ്ണസംഖ്യ c;
} Spacked2;
Spacked2 spacked2;
തരനിർവചനം ഘടന Spacked3_s {
    അക്ഷരം a;
    short b;
    പൂർണ്ണസംഖ്യ c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
ഘടന gate_struct64 {
    unsigned short offset_താഴെയുള്ള;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_നടുവ്;
    unsigned offset_മുകളിലെ;
    unsigned zero1;
} __attribute__((packed));
തരനിർവചനം ഘടന gate_struct64 gate_desc;
gate_desc a_gate_desc;
ശൂന്യം attrib_test(ശൂന്യം)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", വലുപ്പം(ഘടന Spacked),
	 വലുപ്പം(spacked), വലുപ്പം(Spacked2), വലുപ്പം(spacked2));
  printf("attr: %d %d\n", വലുപ്പം(Spacked3), വലുപ്പം(spacked3));
  printf("attr: %d %d\n", വലുപ്പം(gate_desc), വലുപ്പം(a_gate_desc));
#endif
}
ബാഹ്യ __attribute__((__unused__)) അക്ഷരം * __attribute__((__unused__)) *
strange_attrib_placement (ശൂന്യം);

ശൂന്യം * __attribute__((__unused__)) get_void_ptr (ശൂന്യം *a)
{
  തിരികെ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
സ്ഥിതം വരിയിൽ
പൂർണ്ണസംഖ്യ __get_order(unsigned long long size)
{
  പൂർണ്ണസംഖ്യ order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      ഘടന S { പൂർണ്ണസംഖ്യ i : 1; } s; // constructed for this '1'
    }
  order = size;
  തിരികെ order;
}

/* This just forces the above inline function to be actually emitted.  */
പൂർണ്ണസംഖ്യ force_get_order(unsigned long s)
{
    തിരികെ __get_order(s);
}

#define pv(m) printf(വലുപ്പം (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
ശൂന്യം bounds_check1_test (ശൂന്യം)
{
    ഘടന s {
        പൂർണ്ണസംഖ്യ x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
ശൂന്യം map_add(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ d, പൂർണ്ണസംഖ്യ e, പൂർണ്ണസംഖ്യ f, പൂർണ്ണസംഖ്യ g, പൂർണ്ണസംഖ്യ h, പൂർണ്ണസംഖ്യ i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

ശൂന്യം func_arg_test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ a = 0;
    പൂർണ്ണസംഖ്യ b = 1;
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
ശൂന്യം whitespace_test(ശൂന്യം)
{
    അക്ഷരം *str;
    പൂർണ്ണസംഖ്യ tcc_test = 1;

#എങ്കിൽ 1
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
#അല്ലെങ്കിൽ
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#എങ്കിൽ 0
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
#എങ്കിൽ 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(വ്യഞ്ജകം_test);
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
    RUN(വ്യഞ്ജകം_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_വ്യഞ്ജകം_test);
    RUN(വ്യഞ്ജകം_cmp_test);
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
    RUN(statement_വ്യഞ്ജകം_test);
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

    തിരികെ 0;
}
