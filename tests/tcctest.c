/*
 * TCC auto test program
 */
#अन्तर्भाव "config.h"

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

#यदि defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#अन्यथा
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#यदि defined(_WIN32)
#define LONG_DOUBLE द्विगुण
#define LONG_DOUBLE_LITERAL(x) x
#अन्यथा
#define LONG_DOUBLE long द्विगुण
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

प्रकारनिर्देश __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#अन्तर्भाव TCCLIB_INC

#अन्तर्भाव TCCLIB_INC1.TCCLIB_INC2

#अन्तर्भाव TCCLIB_INC1.h>

#अन्तर्भाव TCCLIB_INC3

#अन्तर्भाव <tcclib.h>

#अन्तर्भाव "tcclib.h"

#अन्तर्भाव "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#अन्यथा
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#अन्तर्भाव INC(42test)
#अन्तर्भाव incname
#अन्तर्भाव stringify(funnyname)

पूर्णाङ्क fib(पूर्णाङ्क n);
शून्य अंक(पूर्णाङ्क n);
शून्य forward_ref(शून्य);
पूर्णाङ्क isid(पूर्णाङ्क c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
शून्य funny_ओळ_continuation (पूर्णाङ्क, ..\
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
#define खालचा_2 खालचा_2 ", world"

स्थिर पूर्णाङ्क onetwothree = 123;
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

#यदि 1
#define B3 1
#नोचेद्यदि 1
#define B3 2
#नोचेद्यदि 0
#define B3 3
#अन्यथा
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

पूर्णाङ्क qq(पूर्णाङ्क x)
{
    प्रत्यागम x + 40;
}
#define qq(x) x

#define spin_lock(lock) कुरु { } यावत् (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

शून्य macro_test(शून्य)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(वरचा_2, खालचा_2));
    printf("s2=%s\n", xglue(वरचा_2, खालचा_2));
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
#अन्यथा
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#अन्यथा
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#अन्यथा
    printf("B1 not defined\n");
#endif
#अन्यथा
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#अन्यथा
    printf("B2 not defined\n");
#endif
#endif

#यदि 1+1
    printf("test true1\n");
#endif
#यदि 0
    printf("test true2\n");
#endif
#यदि 1-1
    printf("test true3\n");
#endif
#यदि defined(A)
    printf("test trueA\n");
#endif
#यदि defined(B)
    printf("test trueB\n");
#endif

#यदि 0
    printf("test 0\n");
#नोचेद्यदि 0
    printf("test 1\n");
#नोचेद्यदि 2
    printf("test 2\n");
#अन्यथा
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
        पूर्णाङ्क a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(संदेश) printf("%s\n",संदेश)

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
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      ध्रुव वर्ण *fn = get_file_from_header();
      यदि (fn[0] == '.' && fn[1] == '/')
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


स्थिर शून्य print_अंक(वर्ण *fn, पूर्णाङ्क ओळ, पूर्णाङ्क अंक) {
    printf("fn %s, line %d, num %d\n", fn, ओळ, अंक);
}

शून्य recursive_macro_test(शून्य)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_अंक(x) print_अंक(__FILE__,__LINE__,x)
    print_अंक(123);
    WRAP(print_अंक(123));
    WRAP(WRAP(print_अंक(123)));

स्थिर संरचना recursive_macro { पूर्णाङ्क rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
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
#endif

#यदि !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
वर्ण str_ag1[] = "b";
वर्ण str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
वर्ण str_ag3[] = { "ab"[1], 0 };
वर्ण str_x[2] = { "xy" "z"[2], 0 };
#endif
वर्ण *str_ar[] = { "one", "two" };
संरचना str_SS {unsigned वर्ण a[3], b; };
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
#ifndef CONSTANTINDEXEDSTRLIT
    वर्ण str_ag3[] = { "ab"[1], 0 };
    वर्ण str_x[2] = { "xy" "z"[2], 0 };
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

शून्य ps(ध्रुव वर्ण *s)
{
    पूर्णाङ्क c;
    यावत् (1) {
        c = *s;
        यदि (c == 0)
            भङ्ग;
        printf("%c", c);
        s++;
    }
}

ध्रुव वर्ण foo1_string[] = "\
bar\n\
test\14\
1";

शून्य string_test()
{
    unsigned पूर्णाङ्क b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#यदि 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    यावत् ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    यावत् (b != 0x80000000) {
        अंक(b);
        b = b * 2;
    }
    string_test2();
}


शून्य if1t(पूर्णाङ्क n, पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c)
{
    यदि (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    यदि (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    यदि (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    यदि (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    यदि (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    यदि (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    यदि (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    यदि (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    यदि (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    यदि (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    यदि (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    यदि (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    यदि (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    यदि (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

शून्य if2t(शून्य)
{
    यदि (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

शून्य if3t(शून्य)
{
    चञ्चल long long i = 1;
    यदि (i <= 18446744073709551615ULL)
      ;
    अन्यथा
      printf ("if3t:wrong 1\n");
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
        printf("%d", i++);
    printf("\n");
    प्रति(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    कुरु {
        printf("%d", i++);
    } यावत् (i < 10);
    printf("\n");

    वर्ण मोजणी_2 = 123;
    /* c99 for loop init test */
    प्रति (size_t मोजणी_2 = 1; मोजणी_2 < 3; मोजणी_2++)
        printf("count=%d\n", मोजणी_2);
    printf("count = %d\n", मोजणी_2);

    /* break/continue tests */
    i = 0;
    यावत् (1) {
        यदि (i == 6)
            भङ्ग;
        i++;
        यदि (i == 3)
            अनुवर्त;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    कुरु {
        यदि (i == 6)
            भङ्ग;
        i++;
        यदि (i == 3)
            अनुवर्त;
        printf("%d", i);
    } यावत्(1);
    printf("\n");

    प्रति(i = 0;i < 10;i++) {
        यदि (i == 3)
            अनुवर्त;
        printf("%d", i);
    }
    printf("\n");
}

प्रकारनिर्देश पूर्णाङ्क typedef_and_label;

शून्य goto_test()
{
    पूर्णाङ्क i;
    स्थिर शून्य *label_table[3] = { &&label1, &&label2, &&label3 };
    संरचना {
        पूर्णाङ्क bla;
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
    यदि (i >= 10) 
        गच्छ s_end;
    printf("%d", i);
    i++;
    गच्छ s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    प्रति(i=0;i<3;i++) {
        गच्छ *label_table[i];
    label1:
        printf("label1\n");
        गच्छ next;
    label2:
        printf("label2\n");
        गच्छ next;
    label3:
        printf("label3\n");
    next: ;
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
    EL_large = ((unsigned long)0xf000 << 31) << 1,
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
    unsigned *p = &b1;
    संरचना S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    यदि (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    अन्यथा
      printf("enum unsigned: wrong\n");
    यदि (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    अन्यथा
      printf("enum unsigned: wrong\n");
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
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

शून्य forward_test()
{
    forward_ref();
    forward_ref();
}


शून्य forward_ref(शून्य)
{
    printf("forward ok\n");
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

संरचना empty_mem {
    /* nothing */ ;
    पूर्णाङ्क x;
};

पूर्णाङ्क tab[3];
पूर्णाङ्क tab2[3][2];

पूर्णाङ्क g;

शून्य f1(पूर्णाङ्क g)
{
    printf("g1=%d\n", g);
}

शून्य scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        पूर्णाङ्क g;
        g = 3;
        printf("g3=%d\n", g);
        {
            पूर्णाङ्क g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
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
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
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

    printf("sizeof(a) = %d\n", परिमाण(a));
    printf("sizeof(\"a\") = %d\n", परिमाण("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", परिमाण(__func__));
#endif
    printf("sizeof tab %d\n", परिमाण(tab));
    printf("sizeof tab2 %d\n", परिमाण tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    प्रति(i=0;i<3;i++)
        प्रति(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    प्रति(i=0;i<3*2;i++) {
        printf(" %3d", ((पूर्णाङ्क *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", परिमाण(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", परिमाण(ptrdiff_t));
}

शून्य अभिव्यक्ती_test()
{
    पूर्णाङ्क a, b;
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
    printf("res= %d %d\n", a, b);
}

पूर्णाङ्क const_len_ar[परिमाण(1/0)]; /* div-by-zero, but in unevaluated context */

शून्य constant_अभिव्यक्ती_test()
{
    पूर्णाङ्क a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", परिमाण(const_len_ar));
}

पूर्णाङ्क tab4[10];

शून्य अभिव्यक्ती_ptr_test()
{
    पूर्णाङ्क arr[10], *p, *q;
    पूर्णाङ्क i = -1;

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
    p = (पूर्णाङ्क *)((वर्ण *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
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
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (पूर्णाङ्क*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (पूर्णाङ्क)((p - q) / 3));
}

शून्य अभिव्यक्ती_cmp_test()
{
    पूर्णाङ्क a, b;
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

संरचना empty {
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
    unsigned long flags;
    सङ्घ {
	शून्य *u1;
	पूर्णाङ्क *u2;
    };

    संरचना {
	सङ्घ {
	    unsigned long index;
	    शून्य *freelist;
	};
	सङ्घ {
	    unsigned long counters;
	    संरचना {
		पूर्णाङ्क bla;
	    };
	};
    };

    सङ्घ {
	संरचना {
	    long u3;
	    long u4;
	};
	शून्य *u5;
	संरचना {
	    unsigned long compound_head;
	    unsigned पूर्णाङ्क compound_dtor;
	    unsigned पूर्णाङ्क compound_order;
	};
    };
} __attribute__((aligned(2 * परिमाण(long))));

प्रकारनिर्देश unsigned long long __attribute__((aligned(4))) unaligned_u64;

संरचना aligntest9 {
    unsigned पूर्णाङ्क buf_nr;
    unaligned_u64 start_lba;
};

संरचना aligntest10 {
    unsigned पूर्णाङ्क buf_nr;
    unsigned long long start_lba;
};

शून्य struct_test()
{
    struct1 *s;
    सङ्घ union2 u;
    संरचना Large ls;

    printf("sizes: %d %d %d %d\n",
           परिमाण(संरचना struct1),
           परिमाण(संरचना struct2),
           परिमाण(सङ्घ union1),
           परिमाण(सङ्घ union2));
    printf("offsets: %d\n", (पूर्णाङ्क)((वर्ण*)&st1.u.v1 - (वर्ण*)&st1));
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
    printf("str_addr=%x\n", (पूर्णाङ्क)(uintptr_t)st1.str - (पूर्णाङ्क)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest1), __alignof__(संरचना aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest2), __alignof__(संरचना aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest3), __alignof__(संरचना aligntest3));
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest4), __alignof__(संरचना aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest5), __alignof__(संरचना aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest6), __alignof__(संरचना aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest7), __alignof__(संरचना aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest8), __alignof__(संरचना aligntest8));
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest9), __alignof__(संरचना aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest10), __alignof__(संरचना aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           परिमाण(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           परिमाण(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           परिमाण(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", परिमाण(संरचना empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(संरचना empty));

    printf("Large: sizeof=%d\n", परिमाण(ls));
    memset(&ls, 0, परिमाण(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (पूर्णाङ्क)((वर्ण*)&ls.compound_head - (वर्ण*)&ls));
}

/* simulate char/short return value with undefined upper bits */
स्थिर पूर्णाङ्क __csf(पूर्णाङ्क x) { प्रत्यागम x; }
स्थिर शून्य *_csf = __csf;
#define csf(t,n) ((t(*)(पूर्णाङ्क))_csf)(n)

/* XXX: depend on endianness */
शून्य char_short_test()
{
    पूर्णाङ्क var1, var2;
    signed वर्ण var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed वर्ण *)&var1, *(signed वर्ण *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned वर्ण *)&var1, *(unsigned वर्ण *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(पूर्णाङ्क *)&var1, *(पूर्णाङ्क *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned पूर्णाङ्क *)&var1, *(unsigned पूर्णाङ्क *)&var2);
    *(signed वर्ण *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(पूर्णाङ्क *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed वर्ण)(var1 + 1), (signed वर्ण)(var4 + 1));
#यदि !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned वर्ण,0x89898989);
    var4 = csf(signed वर्ण,0xabababab);
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
    var1 = (signed वर्ण)(unsigned वर्ण)(var3 + 1);
    var4 = (signed वर्ण)(unsigned वर्ण)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(पूर्णाङ्क)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed वर्ण)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

प्रकारनिर्देश संरचना Sym {
    पूर्णाङ्क v;
    पूर्णाङ्क t;
    पूर्णाङ्क c;
    संरचना Sym *next;
    संरचना Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

स्थिर पूर्णाङ्क toupper1(पूर्णाङ्क a)
{
    प्रत्यागम TOUPPER(a);
}

स्थिर unsigned पूर्णाङ्क calc_vm_flags(unsigned पूर्णाङ्क prot)
{
  unsigned पूर्णाङ्क prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  प्रत्यागम prot_bits;
}

गणना cast_enum { FIRST, LAST };

स्थिर शून्य tst_cast(गणना cast_enum ce)
{
    printf("%d\n", ce);
}

शून्य bool_test()
{
    पूर्णाङ्क *s, a, b, t, f, i;

    a = 0;
    s = (शून्य*)0;
    printf("!s=%d\n", !s);

    यदि (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#यदि 1 && 1
    printf("a1\n");
#endif
#यदि 1 || 0
    printf("a2\n");
#endif
#यदि 1 ? 0 : 1
    printf("a3\n");
#endif
#यदि 0 ? 0 : 1
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
    printf("type of bool: %d\n", (पूर्णाङ्क) ( (~ ((unsigned पूर्णाङ्क) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned पूर्णाङ्क)0)) / 2 );
    /* test ? : cast */
    {
        पूर्णाङ्क aspect_on;
        पूर्णाङ्क aspect_native = 65536;
        द्विगुण bfu_aspect = 1.0;
        पूर्णाङ्क aspect;
        प्रति(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        स्थिर पूर्णाङ्क v1 = 34 ? : -1; /* constant case */
        स्थिर पूर्णाङ्क v2 = 0 ? : -1; /* constant case */
        पूर्णाङ्क a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    प्रति(i=0;i<256;i++) {
        यदि (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

बाह्य पूर्णाङ्क undefined_function(शून्य);
बाह्य पूर्णाङ्क defined_function(शून्य);

#ifdef __clang__
पूर्णाङ्क undefined_function(शून्य) {}
#endif

स्थिर अन्तःस्थ शून्य refer_to_undefined(शून्य)
{
  undefined_function();
}

शून्य optimize_out_test(शून्य)
{
  पूर्णाङ्क i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  पूर्णाङ्क j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  यदि (0)
    printf("oo:%d\n", undefined_function());
  अन्यथा
    printf("oo:%d\n", defined_function());
  यदि (1)
    printf("oo:%d\n", defined_function());
  अन्यथा
    printf("oo:%d\n", undefined_function());
  यावत् (1) {
      printf("oow:%d\n", defined_function());
      भङ्ग;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  विकल्प (j)
    पक्ष 1: भङ्ग;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  यावत् (1)
    भङ्ग;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  कुरु
    भङ्ग;
  यावत् (1);
  printf ("ool2:%d\n", defined_function());
  प्रति (;;)
    भङ्ग;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  यावत् (1) {
	{
	  भङ्ग;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  यावत् (j) {
      यदि (j == 0)
	भङ्ग; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  यावत् (j) {
      यदि (1)
	j--;
      अन्यथा
	breakhere: भङ्ग;
      printf("ool6:%d\n", defined_function());
      गच्छ breakhere;
  }
  j = 1;
  यावत् (j) {
      j--;
      अनुवर्त;
      printf("ool7:%d\n", undefined_function());
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
    refer_to_undefined();

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
  printf ("oor:%d\n", undefined_function());
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
#endif

शून्य compound_literal_test(शून्य)
{
    पूर्णाङ्क *p, i;
    वर्ण *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (पूर्णाङ्क)cinit51);
    printf("cinit52 : %d\n", *(पूर्णाङ्क*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (पूर्णाङ्क []){1, 2, 3};
    प्रति(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    प्रति(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (वर्ण *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (वर्ण *){ q };
    printf("q3=%s\n", q3);

    q = (वर्ण []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (पूर्णाङ्क []){1, 2, cinit1 + 3};
    प्रति(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    प्रति(i=0;i<3;i++) {
        p = (पूर्णाङ्क []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
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
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    प्रत्यागम 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
वर्ण invalid_function_def()[] {प्रत्यागम 0;}

#अन्यथा
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

शून्य अंक(पूर्णाङ्क n)
{
    वर्ण *tab, *p;
    tab = (वर्ण*)malloc(20); 
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
        printf("%c", *p);
    }
    printf("\n");
    मुक्त(tab);
}

/* structure assignment tests */
संरचना structa1 {
    पूर्णाङ्क f1;
    वर्ण f2;
};

शून्य struct_assign_test1(संरचना structa1 s1, पूर्णाङ्क t, भिन्न f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

संरचना structa1 struct_assign_test2(संरचना structa1 s1, पूर्णाङ्क t)
{
    s1.f1 += t;
    s1.f2 -= t;
    प्रत्यागम s1;
}

शून्य struct_assign_test(शून्य)
{
    संरचना S {
      संरचना structa1 lsta1, lsta2;
      पूर्णाङ्क i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    स्थिर संरचना {
        शून्य (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

शून्य cast1(वर्ण a, short b, unsigned वर्ण c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

वर्ण bcast;
short scast;

शून्य cast_test()
{
    पूर्णाङ्क a;
    वर्ण c;
    वर्ण tab[10];
    unsigned b,d;
    short s;
    वर्ण *p = रिक्त;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (वर्ण)(a + 1),
           (short)(a + 1),
           (unsigned वर्ण)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (वर्ण)0xfffff,
           (short)0xfffff,
           (unsigned वर्ण)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", परिमाण(c), परिमाण((पूर्णाङ्क)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (वर्ण)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", परिमाण(+(वर्ण)'a'));
    printf("sizeof(-(char)'a') = %d\n", परिमाण(-(वर्ण)'a'));
    printf("sizeof(~(char)'a') = %d\n", परिमाण(-(वर्ण)'a'));

#यदि CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (पूर्णाङ्क)p, (unsigned पूर्णाङ्क)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (शून्य *)a, (शून्य *)b, (शून्य *)c, (शून्य *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(पूर्णाङ्क)ul);
}

/* initializers tests */
संरचना structinit1 {
    पूर्णाङ्क f1;
    वर्ण f2;
    short f3;
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
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
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
संरचना bf_SS {unsigned पूर्णाङ्क bit:1,bits31:31; };
संरचना bf_SS bf_init = { .bit = 1 };
संरचना bfn_SS {पूर्णाङ्क a,b; संरचना bf_SS c; पूर्णाङ्क d,e; };
संरचना bfn_SS bfn_init = { .c.bit = 1 };
संरचना bfa_SS {पूर्णाङ्क a,b; संरचना bf_SS c[3]; पूर्णाङ्क d,e; };
संरचना bfa_SS bfa_init = { .c[1].bit = 1 };
संरचना bf_SS bfaa_init[3] = { [1].bit = 1 };
संरचना bf_SS bfaa_vinit[] = { [2].bit = 1 };
संरचना b2_SS {long long पूर्णाङ्क field : 52; long long पूर्णाङ्क pad : 12; };
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
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           परिमाण(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", परिमाण(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           परिमाण(sinit7),
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

    प्रति(i=0;i<3;i++)
        प्रति(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", परिमाण(linit6));
    printf("linit8=%d %s\n", परिमाण(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           परिमाण(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    प्रति(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    प्रति(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    प्रति(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    प्रति(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    प्रति(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", परिमाण cix20, परिमाण cix21, परिमाण cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", परिमाण(sinit19), परिमाण(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", परिमाण(sinit21), परिमाण(sinit22));
    printf("arrtype6: %d\n", परिमाण(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    प्रति (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    प्रति (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    प्रति (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    प्रति (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    प्रति (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    प्रति (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

शून्य switch_uc(unsigned वर्ण uc)
{
	विकल्प (uc) {
	    पक्ष 0xfb ... 0xfe:
		printf("ucsw:1\n");
		भङ्ग;
	    पक्ष 0xff:
		printf("ucsw:2\n");
		भङ्ग;
	    पक्ष 0 ... 5:
		printf("ucsw:3\n");
		भङ्ग;
	    स्वभाव:
		printf("ucsw: broken!\n");
	}
}

शून्य switch_sc(signed वर्ण sc)
{
	विकल्प (sc) {
	    पक्ष -5 ... -2:
		printf("scsw:1\n");
		भङ्ग;
	    पक्ष -1:
		printf("scsw:2\n");
		भङ्ग;
	    पक्ष 0 ... 5:
		printf("scsw:3\n");
		भङ्ग;
	    स्वभाव:
		printf("scsw: broken!\n");
	}
}

शून्य switch_test()
{
    पूर्णाङ्क i;
    unsigned long long ull;
    long long ll;

    प्रति(i=0;i<15;i++) {
        विकल्प(i) {
        पक्ष 0:
        पक्ष 1:
            printf("a");
            भङ्ग;
        स्वभाव:
            printf("%d", i);
            भङ्ग;
        पक्ष 8 ... 12:
            printf("c");
            भङ्ग;
        पक्ष 3:
            printf("b");
            भङ्ग;
        पक्ष 0xc33c6b9fU:
        पक्ष 0x7c9eeeb9U:
            भङ्ग;
        }
    }
    printf("\n");

    प्रति (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	विकल्प (ull) {
	    पक्ष 1ULL << 61:
		printf("ullsw:1\n");
		भङ्ग;
	    पक्ष 2ULL << 61:
		printf("ullsw:2\n");
		भङ्ग;
	    पक्ष 3ULL << 61:
		printf("ullsw:3\n");
		भङ्ग;
	    पक्ष 4ULL << 61:
		printf("ullsw:4\n");
		भङ्ग;
	    पक्ष 5ULL << 61:
		printf("ullsw:5\n");
		भङ्ग;
	    स्वभाव:
		printf("ullsw: broken!\n");
	}
    }

    प्रति (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	विकल्प (ll) {
	    पक्ष 1LL << 61:
		printf("llsw:1\n");
		भङ्ग;
	    पक्ष 2LL << 61:
		printf("llsw:2\n");
		भङ्ग;
	    पक्ष 3LL << 61:
		printf("llsw:3\n");
		भङ्ग;
	    पक्ष 4LL << 61:
		printf("llsw:4\n");
		भङ्ग;
	    पक्ष 5LL << 61:
		printf("llsw:5\n");
		भङ्ग;
	    स्वभाव:
		printf("llsw: broken!\n");
	}
    }

    प्रति (i = -5; i <= 5; i++) {
	switch_uc((unsigned वर्ण)i);
    }

    प्रति (i = -5; i <= 5; i++) {
	switch_sc ((signed वर्ण)i);
    }
}

/* ISOC99 _Bool type */
शून्य c99_bool_test(शून्य)
{
#ifdef BOOL_ISOC99
    पूर्णाङ्क a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", परिमाण(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           परिमाण ((चञ्चल पूर्णाङ्क)a ? b : b2));
#endif
}

शून्य bitfield_test(शून्य)
{
    पूर्णाङ्क a;
    short sa;
    unsigned वर्ण ca;
    संरचना sbf1 {
        पूर्णाङ्क f1 : 3;
        पूर्णाङ्क : 2;
        पूर्णाङ्क f2 : 1;
        पूर्णाङ्क : 0;
        पूर्णाङ्क f3 : 5;
        पूर्णाङ्क f4 : 7;
        unsigned पूर्णाङ्क f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", परिमाण(st1));

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
    यदि (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    अन्यथा 
        printf("st1.f1 != -1\n");
    यदि (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    अन्यथा 
        printf("st1.f2 != -1\n");

    संरचना sbf2 {
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
    printf("sizeof(st3) = %d\n", परिमाण(st3));
#endif

    संरचना sbf4 {
	पूर्णाङ्क x : 31;
	वर्ण y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    संरचना sbf5 {
	पूर्णाङ्क a;
	वर्ण b;
	पूर्णाङ्क x : 12, y : 4, : 0, : 4, z : 3;
	वर्ण c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    संरचना sbf6 {
	short x : 12;
	unsigned वर्ण y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#अन्यथा
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
द्विगुण strtod(ध्रुव वर्ण *nptr, वर्ण **endptr);

#यदि defined(_WIN32)
भिन्न strtof(ध्रुव वर्ण *nptr, वर्ण **endptr) {प्रत्यागम (भिन्न)strtod(nptr, endptr);}
LONG_DOUBLE strtold(ध्रुव वर्ण *nptr, वर्ण **endptr) {प्रत्यागम (LONG_DOUBLE)strtod(nptr, endptr);}
#अन्यथा
भिन्न strtof(ध्रुव वर्ण *nptr, वर्ण **endptr);
LONG_DOUBLE strtold(ध्रुव वर्ण *nptr, वर्ण **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
शून्य prefix ## cmp(type a, type b)\
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
शून्य prefix ## fcast(type a)\
{\
    भिन्न fa;\
    द्विगुण da;\
    LONG_DOUBLE la;\
    पूर्णाङ्क ia;\
    long long llia;\
    unsigned पूर्णाङ्क ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (पूर्णाङ्क)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned पूर्णाङ्क)a;\
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
    यदि (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
भिन्न prefix ## retf(type a) { प्रत्यागम a; }\
द्विगुण prefix ## retd(type a) { प्रत्यागम a; }\
LONG_DOUBLE prefix ## retld(type a) { प्रत्यागम a; }\
\
शून्य prefix ## call(शून्य)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (द्विगुण)strto ## prefix("1.2", रिक्त));\
}\
\
शून्य prefix ## signed_zeros(शून्य) \
{\
  type x = 0.0, y = -0.0, n, p;\
  यदि (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  अन्यथा\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  यदि (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  अन्यथा\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  यदि (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  यदि (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    printf ("x != -y; this is wrong!\n");\
}\
शून्य prefix ## nan(शून्य)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
शून्य prefix ## test(शून्य)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    यदि (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, भिन्न, भिन्न, "%f")
FTEST(d, द्विगुण, द्विगुण, "%f")
FTEST(ld, long द्विगुण, LONG_DOUBLE, "%Lf")

द्विगुण ftab1[3] = { 1.2, 3.4, -5.6 };


शून्य float_test(शून्य)
{
#यदि !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    चञ्चल भिन्न fa, fb;
    चञ्चल द्विगुण da, db;
    पूर्णाङ्क a;
    unsigned पूर्णाङ्क b;
    स्थिर द्विगुण nan2 = 0.0/0.0;
    स्थिर द्विगुण inf1 = 1.0/0.0;
    स्थिर द्विगुण inf2 = 1e5000;
    चञ्चल LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", परिमाण(भिन्न));
    printf("sizeof(double) = %d\n", परिमाण(द्विगुण));
    printf("sizeof(long double) = %d\n", परिमाण(LONG_DOUBLE));
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
#endif

शून्य funcptr_test()
{
    शून्य (*func)(पूर्णाङ्क);
    पूर्णाङ्क a;
    संरचना {
        पूर्णाङ्क dummy;
        शून्य (*func)(पूर्णाङ्क);
    } st1;
    long diff;

    func = &अंक;
    (*func)(12345);
    func = अंक;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = अंक;
    st1.func(12346);
    printf("sizeof1 = %d\n", परिमाण(funcptr_test));
    printf("sizeof2 = %d\n", परिमाण funcptr_test);
    printf("sizeof3 = %d\n", परिमाण(&funcptr_test));
    printf("sizeof4 = %d\n", परिमाण &funcptr_test);
    a = 0;
    func = अंक + a;
    diff = func - अंक;
    func(42);
    (func + diff)(42);
    (अंक + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((पूर्णाङ्क)(uintptr_t)func) & 15);
}

शून्य lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    यदि (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*द्विमान*/
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

शून्य llshift(long long a, पूर्णाङ्क b)
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

शून्य llfloat(शून्य)
{
    भिन्न fa;
    द्विगुण da;
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

long long llfunc1(पूर्णाङ्क a)
{
    प्रत्यागम a * 2;
}

संरचना S {
    पूर्णाङ्क id; 
    वर्ण item;
};

long long पूर्णाङ्क मूल्य(संरचना S *v)
{
    प्रत्यागम ((long long पूर्णाङ्क)v->item);
}

long long llfunc2(long long x, long long y, पूर्णाङ्क z)
{
    प्रत्यागम x * y * z;
}

शून्य check_opl_save_regs(वर्ण *a, long long b, पूर्णाङ्क c)
{
    *a = b < 0 && !c;
}

शून्य longlong_test(शून्य)
{
    long long a, b, c;
    पूर्णाङ्क ia;
    unsigned पूर्णाङ्क ua;
    printf("sizeof(long long) = %d\n", परिमाण(long long));
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
#यदि 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          संरचना S a;

          a.item = 3;
          printf("%lld\n", मूल्य(&a));
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
    u = (unsigned)(पूर्णाङ्क)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    वर्ण cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

शून्य manyarg_test(शून्य)
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
    long long ll;
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
                गच्छ the_end;
            पक्ष 'd':
                i = va_arg(ap, पूर्णाङ्क);
                printf("%d", i);
                भङ्ग;
            पक्ष 'f':
                d = va_arg(ap, द्विगुण);
                printf("%f", d);
                भङ्ग;
            पक्ष 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                भङ्ग;
            पक्ष 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                भङ्ग;
            }
            p++;
        } अन्यथा {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

संरचना myspace {
    short पूर्णाङ्क profile;
};
संरचना myspace2 {
#यदि CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    वर्ण a[1];
#अन्यथा
    वर्ण a[0];
#endif
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
    short पूर्णाङ्क validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, संरचना myspace2);
    alex2    = va_arg(ap, संरचना myspace3);
    alex3    = va_arg(ap, संरचना myspace4);
    bill     = va_arg(ap, संरचना myspace);
    george   = va_arg(ap, संरचना myspace);
    validate = va_arg(ap, पूर्णाङ्क);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    प्रत्यागम (संरचना mytest) {};
}

शून्य stdarg_for_libc(ध्रुव वर्ण *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
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
    printf("stdarg_void_expr: %d\n", i);
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
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    प्रति(i = 0; i < nargs; i++) {
        यदि (i == posd) {
            d = va_arg (args, द्विगुण);
            printf ("d %d = %g\n", i, d);
        }
        अन्यथा {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
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
#endif
}

पूर्णाङ्क reltab[3] = { 1, 2, 3 };

पूर्णाङ्क *rel1 = &reltab[1];
पूर्णाङ्क *rel2 = &reltab[2];

शून्य getmyaddress(शून्य)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(शून्य)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       प्रत्यागम ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
शून्य relocation_test(शून्य)
{
    शून्य (*fptr)(शून्य) = (शून्य (*)(शून्य))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

शून्य old_style_f(a,b,c)
     पूर्णाङ्क a, b;
     द्विगुण c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

शून्य decl_func1(पूर्णाङ्क cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

शून्य decl_func2(cmpfn)
पूर्णाङ्क cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
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
#endif
    decl_func1(रिक्त);
    decl_func2(रिक्त);
}

शून्य alloca_test()
{
    वर्ण *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    वर्ण *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

शून्य *bounds_checking_is_enabled()
{
    वर्ण ca[10], *cp = ca-1;
    प्रत्यागम (ca != cp + 1) ? cp : रिक्त;
}

प्रकारनिर्देश पूर्णाङ्क constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

शून्य c99_vla_test_1(पूर्णाङ्क size1, पूर्णाङ्क size2)
{
    पूर्णाङ्क size = size1 * size2;
    पूर्णाङ्क tab1[size][2], tab2[10][2];
    शून्य *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (परिमाण tab1 == size1 * size2 * 2 * परिमाण(पूर्णाङ्क)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (परिमाण(पूर्णाङ्क) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * परिमाण(पूर्णाङ्क)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((पूर्णाङ्क *) (tab1_ptr + (size1 * 2 + 1) * परिमाण(पूर्णाङ्क))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    यदि (bad_ptr = bounds_checking_is_enabled()) {
        पूर्णाङ्क *t1 = &tab1[size1 * size2 - 1][3];
        पूर्णाङ्क *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        वर्ण*c1 = 1 + परिमाण(tab1) + (वर्ण*)tab1;
        वर्ण*c2 = 1 + परिमाण(tab2) + (वर्ण*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        पूर्णाङ्क *i1 = tab1[-1];
        पूर्णाङ्क *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        पूर्णाङ्क *x1 = tab1[size1 * size2 + 1];
        पूर्णाङ्क *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } अन्यथा {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

शून्य c99_vla_test_2(पूर्णाङ्क d, पूर्णाङ्क h, पूर्णाङ्क w)
{
    पूर्णाङ्क x, y, z;
    पूर्णाङ्क (*arr)[h][w] = malloc(परिमाण(पूर्णाङ्क) * d*h*w);
    पूर्णाङ्क c = 1;
    स्थिर पूर्णाङ्क (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

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
    printf ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3b(पूर्णाङ्क s, पूर्णाङ्क arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3c(पूर्णाङ्क s, पूर्णाङ्क arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3d(पूर्णाङ्क s, पूर्णाङ्क arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3e(पूर्णाङ्क s, पूर्णाङ्क arr[][3][--s])
{
    printf ("%d %d %d\n", परिमाण arr, s, arr[1][2][3]);
}

शून्य c99_vla_test_3(शून्य)
{
    पूर्णाङ्क a[2][3][4];

    memset (a, 0, परिमाण(a));
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

    printf("sizeof(int) = %d\n", परिमाण(पूर्णाङ्क));
    printf("sizeof(unsigned int) = %d\n", परिमाण(unsigned पूर्णाङ्क));
    printf("sizeof(long) = %d\n", परिमाण(long));
    printf("sizeof(unsigned long) = %d\n", परिमाण(unsigned long));
    printf("sizeof(short) = %d\n", परिमाण(short));
    printf("sizeof(unsigned short) = %d\n", परिमाण(unsigned short));
    printf("sizeof(char) = %d\n", परिमाण(वर्ण));
    printf("sizeof(unsigned char) = %d\n", परिमाण(unsigned वर्ण));
    printf("sizeof(func) = %d\n", परिमाण sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", परिमाण a++);
    printf("a=%d\n", a);
    ptr = रिक्त;
    printf("sizeof(**ptr) = %d\n", परिमाण (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", परिमाण(परिमाण(पूर्णाङ्क)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -परिमाण(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(पूर्णाङ्क));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned पूर्णाङ्क));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(वर्ण));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned वर्ण));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", परिमाण(वर्ण[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   परिमाण( (संरचना {पूर्णाङ्क i; पूर्णाङ्क j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   परिमाण (संरचना {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", परिमाण(t && 0));
    printf("sizeof(1 && 1) = %d\n", परिमाण(1 && 1));
    printf("sizeof(t || 1) = %d\n", परिमाण(t || 1));
    printf("sizeof(0 || 0) = %d\n", परिमाण(0 || 0));

    पूर्णाङ्क arr[4], fn();
    printf("sizeof(0, arr) = %d\n", परिमाण(0, arr));
    printf("sizeof(0, fn) = %d\n", परिमाण(0, fn));
}

शून्य typeof_test(शून्य)
{
    द्विगुण a;
    typeof(a) b;
    typeof(भिन्न) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


संरचना hlist_गाठ;
संरचना hlist_head {
    संरचना hlist_गाठ *first, *last;
};

शून्य consume_ulong (unsigned long i)
{
    i = 0;
}

शून्य statement_अभिव्यक्ती_test(शून्य)
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
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    शून्य *v = (शून्य*)39;
    typeof(({
	    (संरचना hlist_गाठ *)v;
	    })) x;
    typeof (x)
	ptr = (संरचना hlist_गाठ *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            स्थिर ध्रुव वर्ण *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    पूर्णाङ्क t = 40;
    पूर्णाङ्क b = ({ पूर्णाङ्क t = 41; t; });
    पूर्णाङ्क c = ({ पूर्णाङ्क t = 42; t; });

    /* Test that aggregate return values work.  */
    संरचना hlist_head h
	= ({
	   प्रकारनिर्देश संरचना hlist_head T;
	   long pre = 48;
	   T t = { (शून्य*)43, (शून्य*)44 };
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
       LBL: यदि (i++ == 0) गच्छ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      गच्छ LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
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
        printf("aa1\n");
        गच्छ l3;
    l2:
        printf("aa3\n");
        गच्छ l4;
    l1:
        printf("aa2\n");
        गच्छ l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    प्रत्यागम;
 l4:
    printf("bb1\n");
    गच्छ l2;
 l1:
    printf("bb2\n");
    गच्छ l4;
}

/* inline assembler test */
#यदि (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

प्रकारनिर्देश __SIZE_TYPE__ word;

/* from linux kernel */
स्थिर वर्ण * strncat1(वर्ण * dest,ध्रुव वर्ण * src,size_t मोजणी_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (मोजणी_2)
	: "memory");
प्रत्यागम dest;
}

स्थिर वर्ण * strncat2(वर्ण * dest,ध्रुव वर्ण * src,size_t मोजणी_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (मोजणी_2)
	: "memory");
प्रत्यागम dest;
}

स्थिर अन्तःस्थ शून्य * memcpy1(शून्य * to, ध्रुव शून्य * from, size_t n)
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
प्रत्यागम (to);
}

स्थिर अन्तःस्थ शून्य * memcpy2(शून्य * to, ध्रुव शून्य * from, size_t n)
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
प्रत्यागम (to);
}

स्थिर __inline__ शून्य sigaddset1(unsigned पूर्णाङ्क *set, पूर्णाङ्क _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

स्थिर __inline__ शून्य sigdelset1(unsigned पूर्णाङ्क *set, पूर्णाङ्क _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
स्थिर __inline__ __const__ unsigned पूर्णाङ्क swab32(unsigned पूर्णाङ्क x)
{
        प्रत्यागम ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#अन्यथा
स्थिर __inline__ __const__ unsigned पूर्णाङ्क swab32(unsigned पूर्णाङ्क x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	प्रत्यागम x;
}
#endif

स्थिर __inline__ unsigned long long mul64(unsigned पूर्णाङ्क a, unsigned पूर्णाङ्क b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned पूर्णाङ्क resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#अन्यथा
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    प्रत्यागम res;
}

स्थिर __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#अन्यथा
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
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
    unsigned पूर्णाङ्क a[2];
    a[0] = 0;
    __asm__ चञ्चल ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(संरचना struct123 *)r->addr));
    प्रत्यागम ret + a[0];
}

#ifdef __x86_64__
पूर्णाङ्क fls64(unsigned long long x)
{
  पूर्णाङ्क bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  प्रत्यागम bitpos + 1;
}
#endif

शून्य other_constraints_test(शून्य)
{
    word ret;
    पूर्णाङ्क var;
#यदि CC_NAME != CC_clang
    __asm__ चञ्चल ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
शून्य base_func(शून्य)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
बाह्य शून्य override_func1 (शून्य);
बाह्य शून्य override_func2 (शून्य);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

शून्य override_func2 (शून्य)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
बाह्य पूर्णाङ्क bug_table[] __attribute__((section("__bug_table")));
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
#ifndef __clang__
  बाह्य पूर्णाङ्क some_चिन्ह;
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
  वर्ण * str = ((वर्ण*)bug_table) + bug_table[1];
  प्रत्यागम str;
#अन्यथा
  प्रत्यागम (वर्ण *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
बाह्य unsigned वर्ण alld_stuff[];
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
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
शून्य asm_local_statics (शून्य)
{
  स्थिर पूर्णाङ्क localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

स्थिर
unsigned पूर्णाङ्क set;

शून्य fancy_copy (unsigned *in, unsigned *out)
{
  asm चञ्चल ("" : "=r" (*out) : "0" (*in));
}

शून्य fancy_copy2 (unsigned *in, unsigned *out)
{
  asm चञ्चल ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#यदि defined __x86_64__
शून्य clobber_r12(शून्य)
{
    asm चञ्चल("mov $1, %%r12" ::: "r12");
}
#endif

शून्य test_वरचा_clobbers_really(शून्य)
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
    printf("asmhc: 0x%x\n", val2);
#endif
}

शून्य test_वरचा_clobbers(शून्य)
{
#यदि defined __x86_64__
    word x1, x2;
    asm चञ्चल("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_वरचा_clobbers_really();
    asm चञ्चल("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm चञ्चल("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

स्थिर long cpu_संख्या;
शून्य trace_console(long len, long len2)
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
    यदि (0
        &&
            ({
              long pscr_ret__;
              विकल्प(len) {
                पक्ष 4:
                    {
                       long pfo_ret__;
                       विकल्प (len2) {
                         पक्ष 8:	printf("bla"); pfo_ret__ = 42; भङ्ग;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  भङ्ग;
                पक्ष 8:
                    {
                       long pfo_ret__;
                       विकल्प (len2) {
                         पक्ष 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	भङ्ग;
                         पक्ष 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	भङ्ग;
                         पक्ष 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	भङ्ग;
                         पक्ष 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	भङ्ग;
                         स्वभाव: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  भङ्ग;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

शून्य test_asm_dead_code(शून्य)
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
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#यदि defined __x86_64__
# define RX "(%rip)"
#अन्यथा
# define RX
#endif

शून्य asm_dot_test(शून्य)
{
#ifndef __APPLE__
    पूर्णाङ्क x;
    प्रति (x = 1;; ++x) {
        पूर्णाङ्क r = x;
        विकल्प (x) {
        पक्ष 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        पक्ष 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#अन्यथा
            asm(".text; mov $123, %eax; jmp p0");
#endif
	पक्ष 3:
#यदि !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#अन्यथा
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        पक्ष 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#अन्यथा
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#अन्यथा
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        पक्ष 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); भङ्ग;
	}
        यदि (r == x)
            भङ्ग;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

शून्य asm_pcrel_test(शून्य)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

शून्य asm_test(शून्य)
{
    वर्ण buf[128];
    unsigned पूर्णाङ्क val, val2;
    संरचना struct123 s1;
    संरचना struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    पूर्णाङ्क base_func = 42;
    शून्य override_func3 (शून्य);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    पञ्जिका पूर्णाङ्क regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm चञ्चल ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm चञ्चल ("xorl %eax, %eax");

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
    गच्छ label1;
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
    asm चञ्चल(".weak override_func3\n.set override_func3, base_func");
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
    asm चञ्चल("" : "=r" (asmret) : "0"(s2));
    यदि (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm चञ्चल("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    यदि (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm चञ्चल ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_वरचा_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
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

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

पूर्णाङ्क constant_p_var;

पूर्णाङ्क func(शून्य);


/* __builtin_clz and __builtin_ctz return random values for 0 */
स्थिर शून्य builtin_test_bits(unsigned long long x, पूर्णाङ्क cnt[])
{
#यदि GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    यदि ((unsigned पूर्णाङ्क) x) cnt[3] += __builtin_clz(x);
    यदि ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    यदि ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    यदि ((unsigned पूर्णाङ्क) x) cnt[6] += __builtin_ctz(x);
    यदि ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    यदि ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#यदि GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

शून्य builtin_test(शून्य)
{
    short s;
    पूर्णाङ्क i;
    long long ll;
#यदि GCC_MAJOR >= 3
    COMPAT_TYPE(पूर्णाङ्क, पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, unsigned पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, वर्ण);
    COMPAT_TYPE(पूर्णाङ्क, ध्रुव पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, चञ्चल पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क[2], ध्रुव पूर्णाङ्क[2]);
    COMPAT_TYPE(पूर्णाङ्क[2][3], चञ्चल पूर्णाङ्क[][3]);
    COMPAT_TYPE(पूर्णाङ्क (*)[], ध्रुव पूर्णाङ्क (*)[]);
#ifndef __clang__
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
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(पूर्णाङ्क *, पूर्णाङ्क *);
    COMPAT_TYPE(पूर्णाङ्क *, शून्य *);
    COMPAT_TYPE(पूर्णाङ्क *, ध्रुव पूर्णाङ्क *);
    COMPAT_TYPE(वर्ण *, unsigned वर्ण *);
    COMPAT_TYPE(वर्ण *, signed वर्ण *);
    COMPAT_TYPE(वर्ण *, वर्ण *);
    COMPAT_TYPE(वर्ण **, शून्य *);
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
#अन्यथा
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
    i = परिमाण (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = परिमाण (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	पूर्णाङ्क cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, परिमाण(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        प्रति (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        प्रति (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	प्रति (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
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

#ifndef __clang__
स्थिर ध्रुव size_t dummy = 0;
बाह्य __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
बाह्य __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
बाह्य __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

पूर्णाङ्क some_lib_func(शून्य);
पूर्णाङ्क dummy_impl_of_slf(शून्य) { प्रत्यागम 444; }
#ifndef __clang__
पूर्णाङ्क some_lib_func(शून्य) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

पूर्णाङ्क weak_toolate() __attribute__((weak));
पूर्णाङ्क weak_toolate() { प्रत्यागम 0; }

शून्य __attribute__((weak)) weak_test(शून्य)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != रिक्त);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != रिक्त);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != रिक्त);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != रिक्त);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != रिक्त);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != रिक्त);
#ifdef __clang__
	printf("some_lib_func=444\n");
#अन्यथा
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

पूर्णाङ्क __attribute__((weak)) weak_f2() { प्रत्यागम 222; }
पूर्णाङ्क __attribute__((weak)) weak_f3() { प्रत्यागम 333; }
पूर्णाङ्क __attribute__((weak)) weak_v2 = 222;
पूर्णाङ्क __attribute__((weak)) weak_v3 = 333;
#endif

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

संरचना global_data
{
  पूर्णाङ्क a[40];
  पूर्णाङ्क *b[40];
};

संरचना global_data global_data;

पूर्णाङ्क global_data_getstuff (पूर्णाङ्क *, पूर्णाङ्क);

शून्य global_data_callit (पूर्णाङ्क i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

पूर्णाङ्क global_data_getstuff (पूर्णाङ्क *p, पूर्णाङ्क i)
{
  प्रत्यागम *p + i;
}

शून्य global_data_test (शून्य)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

संरचना cmpcmpS
{
  unsigned वर्ण fill : 3;
  unsigned वर्ण b1 : 1;
  unsigned वर्ण b2 : 1;
  unsigned वर्ण fill2 : 3;
};

पूर्णाङ्क glob1, glob2, glob3;

शून्य compare_comparisons (संरचना cmpcmpS *s)
{
  यदि (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
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

पूर्णाङ्क fcompare (द्विगुण a, द्विगुण b, पूर्णाङ्क code)
{
  विकल्प (code) {
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
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  यदि (fcompare (a,b,code))    \
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
  printf ("callsavetest: %d\n", s);
  d = alloca (परिमाण(द्विगुण));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


शून्य bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (वर्ण *)__builtin_frame_address(3) + str_offset);
}
शून्य bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (वर्ण *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
शून्य bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (वर्ण *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

शून्य builtin_frame_address_test(शून्य)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    वर्ण str[] = "__builtin_frame_address";
    वर्ण *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

वर्ण via_volatile (वर्ण i)
{
  वर्ण चञ्चल vi;
  vi = i;
  प्रत्यागम vi;
}

शून्य volatile_test(शून्य)
{
    यदि (via_volatile (42) != 42)
      printf (" broken\n");
    अन्यथा
      printf (" ok\n");
}

संरचना __attribute__((__packed__)) Spacked {
    वर्ण a;
    short b;
    पूर्णाङ्क c;
};
संरचना Spacked spacked;
प्रकारनिर्देश संरचना __attribute__((__packed__)) {
    वर्ण a;
    short b;
    पूर्णाङ्क c;
} Spacked2;
Spacked2 spacked2;
प्रकारनिर्देश संरचना Spacked3_s {
    वर्ण a;
    short b;
    पूर्णाङ्क c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
संरचना gate_struct64 {
    unsigned short offset_खालचा;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_मधला;
    unsigned offset_वरचा;
    unsigned zero1;
} __attribute__((packed));
प्रकारनिर्देश संरचना gate_struct64 gate_desc;
gate_desc a_gate_desc;
शून्य attrib_test(शून्य)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", परिमाण(संरचना Spacked),
	 परिमाण(spacked), परिमाण(Spacked2), परिमाण(spacked2));
  printf("attr: %d %d\n", परिमाण(Spacked3), परिमाण(spacked3));
  printf("attr: %d %d\n", परिमाण(gate_desc), परिमाण(a_gate_desc));
#endif
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
पूर्णाङ्क __get_order(unsigned long long size)
{
  पूर्णाङ्क order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      संरचना S { पूर्णाङ्क i : 1; } s; // constructed for this '1'
    }
  order = size;
  प्रत्यागम order;
}

/* This just forces the above inline function to be actually emitted.  */
पूर्णाङ्क force_get_order(unsigned long s)
{
    प्रत्यागम __get_order(s);
}

#define pv(m) printf(परिमाण (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
शून्य bounds_check1_test (शून्य)
{
    संरचना s {
        पूर्णाङ्क x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
शून्य map_add(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c, पूर्णाङ्क d, पूर्णाङ्क e, पूर्णाङ्क f, पूर्णाङ्क g, पूर्णाङ्क h, पूर्णाङ्क i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

शून्य func_arg_test(शून्य)
{
    पूर्णाङ्क a = 0;
    पूर्णाङ्क b = 1;
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
शून्य whitespace_test(शून्य)
{
    वर्ण *str;
    पूर्णाङ्क tcc_test = 1;

#यदि 1
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
#अन्यथा
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#यदि 0
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
#यदि 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(अभिव्यक्ती_test);
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
    RUN(अभिव्यक्ती_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_अभिव्यक्ती_test);
    RUN(अभिव्यक्ती_cmp_test);
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
    RUN(statement_अभिव्यक्ती_test);
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

    प्रत्यागम 0;
}
