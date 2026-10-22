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
#define LONG_DOUBLE दीर्घ द्विगुण
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
शून्य अङ्क(पूर्णाङ्क n);
शून्य forward_ref(शून्य);
पूर्णाङ्क isid(पूर्णाङ्क c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
शून्य funny_पङ्क्ति_continuation (पूर्णाङ्क, ..\
. );

#define A 2
#define N 1234 + A
#define pf म_लिखो
#define M1(a, b)  (a) + (b)

#define str\
(s) # s
#define glue(a, b) a ## b
#define xglue(a, b) glue(a, b)
#define HIGHLOW "hello"
#define तल्लो_2 तल्लो_2 ", world"

स्थिर पूर्णाङ्क onetwothree = 123;
#define onetwothree4 onetwothree
#define onetwothree xglue(onetwothree,4)

#define min(a, b) ((a) < (b) ? (a) : (b))

#ifdef C99_MACROS
#define dprintf(level,...) म_लिखो(__VA_ARGS__)
#endif

/* gcc vararg macros */
#define dprintf1(level, fmt, args...) म_लिखो(fmt, ## args)

#define MACRO_NOARGS()

#define TEST_CALL(f, ...) f(__VA_ARGS__)
#define TEST_CONST()      123

#define AAA 3
#undef AAA
#define AAA 4

#यदि 1
#define B3 1
#अथवायदि 1
#define B3 2
#अथवायदि 0
#define B3 3
#अन्यथा
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

पूर्णाङ्क qq(पूर्णाङ्क x)
{
    फर्काऊ x + 40;
}
#define qq(x) x

#define spin_lock(lock) गर { } जबसम्म (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

शून्य macro_test(शून्य)
{
    pf("N=%d\n", N);
    म_लिखो("aaa=%d\n", AAA);

    म_लिखो("min=%d\n", min(1, min(2, -1)));

    म_लिखो("s1=%s\n", glue(माथिल्लो_2, तल्लो_2));
    म_लिखो("s2=%s\n", xglue(माथिल्लो_2, तल्लो_2));
    म_लिखो("s3=%s\n", str("c"));
    म_लिखो("s4=%s\n", str(a1));
    म_लिखो("B3=%d\n", B3);

    म_लिखो("onetwothree=%d\n", onetwothree);

#ifdef A
    म_लिखो("A defined\n");
#endif
#ifdef B
    म_लिखो("B defined\n");
#endif
#ifdef A
    म_लिखो("A defined\n");
#अन्यथा
    म_लिखो("A not defined\n");
#endif
#ifdef B
    म_लिखो("B defined\n");
#अन्यथा
    म_लिखो("B not defined\n");
#endif

#ifdef A
    म_लिखो("A defined\n");
#ifdef B
    म_लिखो("B1 defined\n");
#अन्यथा
    म_लिखो("B1 not defined\n");
#endif
#अन्यथा
    म_लिखो("A not defined\n");
#ifdef B
    म_लिखो("B2 defined\n");
#अन्यथा
    म_लिखो("B2 not defined\n");
#endif
#endif

#यदि 1+1
    म_लिखो("test true1\n");
#endif
#यदि 0
    म_लिखो("test true2\n");
#endif
#यदि 1-1
    म_लिखो("test true3\n");
#endif
#यदि defined(A)
    म_लिखो("test trueA\n");
#endif
#यदि defined(B)
    म_लिखो("test trueB\n");
#endif

#यदि 0
    म_लिखो("test 0\n");
#अथवायदि 0
    म_लिखो("test 1\n");
#अथवायदि 2
    म_लिखो("test 2\n");
#अन्यथा
    म_लिखो("test 3\n");
#endif

    MACRO_NOARGS();

    म_लिखो("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#ifdef C99_MACROS
    म_लिखो("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#endif
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    म_लिखो("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    म_लिखो("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        पूर्णाङ्क a;
        a = 1;
        glue(a+, +);
        म_लिखो("a=%d\n", a);
        glue(a <, <= 2);
        म_लिखो("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(सन्देश) म_लिखो("%s\n",सन्देश)

#define MF_t म_लिखो("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    म_लिखो("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#define qq1(x) 1
    म_लिखो("qq1=%d\n", qq1( ));

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

    म_लिखो("basefromheader %s\n", get_basefile_from_header());
    म_लिखो("base %s\n", __BASE_FILE__);
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      अचर वर्ण *fn = get_file_from_header();
      यदि (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      म_लिखो("filefromheader %s\n", fn);
    }
#endif

    म_लिखो("file %s\n", __FILE__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_second = 1;
    have_included_42test_h_third = 1;

    /* Check that we don't complain about stray \ here */
    म_लिखो("print a backslash: %s\n", stringify(\\));
}


स्थिर शून्य print_अङ्क(वर्ण *fn, पूर्णाङ्क पङ्क्ति, पूर्णाङ्क अङ्क) {
    म_लिखो("fn %s, line %d, num %d\n", fn, पङ्क्ति, अङ्क);
}

शून्य recursive_macro_test(शून्य)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    म_लिखो("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_अङ्क(x) print_अङ्क(__FILE__,__LINE__,x)
    print_अङ्क(123);
    WRAP(print_अङ्क(123));
    WRAP(WRAP(print_अङ्क(123)));

स्थिर संरचना recursive_macro { पूर्णाङ्क rm_field; } G;
#define rm_field (G.rm_field)
    म_लिखो("rm_field = %d\n", rm_field);
    म_लिखो("rm_field = %d\n", WRAP(rm_field));
    WRAP((म_लिखो("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#यदि __TINYC__
पूर्णाङ्क op(a, b)
{
    फर्काऊ a / b;
}

पूर्णाङ्क ret(a)
{
    यदि (a == 2)
        फर्काऊ 1;
    यदि (a == 3)
        फर्काऊ 2;
    फर्काऊ 0;
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
संरचना str_SS {अचिन्हित वर्ण a[3], b; };
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
    माला_दो("string_test2");
    माला_दो(str_ag1);
    माला_दो(str_ag2);
    /*puts(str_bg1);*/
    माला_दो(str_ag3);
    माला_दो(str_x);
    माला_दो(str_sinit15.a);
    माला_दो(str_sinit16[0].a);
    माला_दो(a3);
    माला_दो(a4);
    माला_दो(p);
    माला_दो("world");
    म_लिखो("%s\n", "bla");
    माला_दो(str_ar[0]);
    माला_दो(str_ar[1]);
    माला_दो(ss.a);
    माला_दो(i >= 0 ? "one" : "two");
    माला_दो(pa1);
    माला_दो(pa2);
}

शून्य ps(अचर वर्ण *s)
{
    पूर्णाङ्क c;
    जबसम्म (1) {
        c = *s;
        यदि (c == 0)
            रोक;
        म_लिखो("%c", c);
        s++;
    }
}

अचर वर्ण foo1_string[] = "\
bar\n\
test\14\
1";

शून्य string_test()
{
    अचिन्हित पूर्णाङ्क b;
    म_लिखो("string:\n");
    म_लिखो("\141\1423\143\n");/* dezdez test */
    म_लिखो("\x41\x42\x43\x3a\n");
    म_लिखो("c=%c\n", 'r');
    म_लिखो("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    म_लिखो("foo1_string='%s'\n", foo1_string);
#यदि 0
    म_लिखो("wstring=%S\n", L"abc");
    म_लिखो("wstring=%S\n", L"abc" L"def" "ghi");
    म_लिखो("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    म_लिखो("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    जबसम्म ((b = b + 1) < 96) {
        म_लिखो("%c", b);
    }
    म_लिखो("\n");
    म_लिखो("fib=%d\n", fib(33));
    b = 262144;
    जबसम्म (b != 0x80000000) {
        अङ्क(b);
        b = b * 2;
    }
    string_test2();
}


शून्य if1t(पूर्णाङ्क n, पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c)
{
    यदि (a && b) म_लिखो("if1t: %d 1 %d %d\n", n, a, b);
    यदि (a && !b) म_लिखो("if1t: %d 2 %d %d\n", n, a, b);
    यदि (!a && b) म_लिखो("if1t: %d 3 %d %d\n", n, a, b);
    यदि (!a && !b) म_लिखो("if1t: %d 4 %d %d\n", n, a, b);
    यदि (a || b) म_लिखो("if1t: %d 5 %d %d\n", n, a, b);
    यदि (a || !b) म_लिखो("if1t: %d 6 %d %d\n", n, a, b);
    यदि (!a || b) म_लिखो("if1t: %d 7 %d %d\n", n, a, b);
    यदि (!a || !b) म_लिखो("if1t: %d 8 %d %d\n", n, a, b);
    यदि (a && b || c) म_लिखो("if1t: %d 9 %d %d %d\n", n, a, b, c);
    यदि (a || b && c) म_लिखो("if1t: %d 10 %d %d %d\n", n, a, b, c);
    यदि (a > b - 1 && c) म_लिखो("if1t: %d 11 %d %d %d\n", n, a, b, c);
    यदि (a > b - 1 || c) म_लिखो("if1t: %d 12 %d %d %d\n", n, a, b, c);
    यदि (a > 0 && 1) म_लिखो("if1t: %d 13 %d %d %d\n", n, a, b, c);
    यदि (a > 0 || 0) म_लिखो("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

शून्य if2t(शून्य)
{
    यदि (0 && 1 || म_लिखो("if2t:ok\n") || 1)
      म_लिखो("if2t:ok2\n");
    म_लिखो("if2t:ok3\n");
}

शून्य if3t(शून्य)
{
    चञ्चल दीर्घ दीर्घ i = 1;
    यदि (i <= 18446744073709551615ULL)
      ;
    अन्यथा
      म_लिखो ("if3t:wrong 1\n");
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
    जबसम्म (i < 10)
        म_लिखो("%d", i++);
    म_लिखो("\n");
    लागि(i = 0; i < 10;i++)
        म_लिखो("%d", i);
    म_लिखो("\n");
    i = 0;
    गर {
        म_लिखो("%d", i++);
    } जबसम्म (i < 10);
    म_लिखो("\n");

    वर्ण गन्ती_2 = 123;
    /* c99 for loop init test */
    लागि (माप_प्रकार गन्ती_2 = 1; गन्ती_2 < 3; गन्ती_2++)
        म_लिखो("count=%d\n", गन्ती_2);
    म_लिखो("count = %d\n", गन्ती_2);

    /* break/continue tests */
    i = 0;
    जबसम्म (1) {
        यदि (i == 6)
            रोक;
        i++;
        यदि (i == 3)
            जारी;
        म_लिखो("%d", i);
    }
    म_लिखो("\n");

    /* break/continue tests */
    i = 0;
    गर {
        यदि (i == 6)
            रोक;
        i++;
        यदि (i == 3)
            जारी;
        म_लिखो("%d", i);
    } जबसम्म(1);
    म_लिखो("\n");

    लागि(i = 0;i < 10;i++) {
        यदि (i == 3)
            जारी;
        म_लिखो("%d", i);
    }
    म_लिखो("\n");
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

    म_लिखो("\ngoto:\n");
    i = 0;
    /* This is a normal decl.  */
    typedef_and_label x;
    /* This needs to parse as label, not as start of decl.  */
 typedef_and_label:
 s_loop:
    यदि (i >= 10) 
        गच्छ s_end;
    म_लिखो("%d", i);
    i++;
    गच्छ s_loop;
 s_end:
    म_लिखो("\n");

    /* we also test computed gotos (GCC extension) */
    लागि(i=0;i<3;i++) {
        गच्छ *label_table[i];
    label1:
        म_लिखो("label1\n");
        गच्छ next;
    label2:
        म_लिखो("label2\n");
        गच्छ next;
    label3:
        म_लिखो("label3\n");
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
    EL_large = ((अचिन्हित दीर्घ)0xf000 << 31) << 1,
};

गणना { BIASU = -1U<<31 };
गणना { BIASS = -1 << 31 };

स्थिर पूर्णाङ्क getint(पूर्णाङ्क i)
{
  यदि (i)
    फर्काऊ 0;
  अन्यथा
    फर्काऊ (पूर्णाङ्क)(-1U << 31);
}

शून्य enum_test()
{
    गणना test b1;
    /* The following should give no warning */
    अचिन्हित *p = &b1;
    संरचना S_enum s = {E7};
    म_लिखो("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    म_लिखो("b1=%d\n", b1);
    म_लिखो("enum large: %ld\n", EL_large);

    यदि (getint(0) == BIASU)
      म_लिखो("enum unsigned: ok\n");
    अन्यथा
      म_लिखो("enum unsigned: wrong\n");
    यदि (getint(0) == BIASS)
      म_लिखो("enum unsigned: ok\n");
    अन्यथा
      म_लिखो("enum unsigned: wrong\n");
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
    म_लिखो("a=%d\n", *a);
    mytype2 = 2;
    म_लिखो("mytype2=%d\n", mytype2);
}

शून्य forward_test()
{
    forward_ref();
    forward_ref();
}


शून्य forward_ref(शून्य)
{
    म_लिखो("forward ok\n");
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
    म_लिखो("g1=%d\n", g);
}

शून्य scope_test()
{
    g = 2;
    f1(1);
    म_लिखो("g2=%d\n", g);
    {
        पूर्णाङ्क g;
        g = 3;
        म_लिखो("g3=%d\n", g);
        {
            पूर्णाङ्क g;
            g = 4;
            म_लिखो("g4=%d\n", g);
        }
    }
    म_लिखो("g5=%d\n", g);
}

पूर्णाङ्क st2_i;
पूर्णाङ्क *st2_p = &st2_i;
शून्य scope2_test()
{
    वर्ण a[50];
    st2_i = 42;
    लागि (पूर्णाङ्क st2_i = 1; st2_i < 10; st2_i++) {
        बाह्य पूर्णाङ्क st2_i;
        st2_i++;
        म_लिखो("exloc: %d\n", st2_i);
    }
    म_लिखो("exloc: %d\n", *st2_p);
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

    म_लिखो("sizeof(a) = %d\n", परिमाण(a));
    म_लिखो("sizeof(\"a\") = %d\n", परिमाण("a"));
#ifdef C99_MACROS
    म_लिखो("sizeof(__func__) = %d\n", परिमाण(__func__));
#endif
    म_लिखो("sizeof tab %d\n", परिमाण(tab));
    म_लिखो("sizeof tab2 %d\n", परिमाण tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    म_लिखो("%d %d %d\n", tab[0], tab[1], tab[2]);
    लागि(i=0;i<3;i++)
        लागि(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    लागि(i=0;i<3*2;i++) {
        म_लिखो(" %3d", ((पूर्णाङ्क *)tab2)[i]);
    }
    म_लिखो("\n");
    म_लिखो("sizeof(size_t)=%d\n", परिमाण(माप_प्रकार));
    म_लिखो("sizeof(ptrdiff_t)=%d\n", परिमाण(सूचक_भेद_प्रकार));
}

शून्य अभिव्यक्ति_test()
{
    पूर्णाङ्क a, b;
    a = 0;
    म_लिखो("%d\n", a += 1);
    म_लिखो("%d\n", a -= 2);
    म_लिखो("%d\n", a *= 31232132);
    म_लिखो("%d\n", a /= 4);
    म_लिखो("%d\n", a %= 20);
    म_लिखो("%d\n", a &= 6);
    म_लिखो("%d\n", a ^= 7);
    म_लिखो("%d\n", a |= 8);
    म_लिखो("%d\n", a >>= 3);
    म_लिखो("%d\n", a <<= 4);

    a = 22321;
    b = -22321;
    म_लिखो("%d\n", a + 1);
    म_लिखो("%d\n", a - 2);
    म_लिखो("%d\n", a * 312);
    म_लिखो("%d\n", a / 4);
    म_लिखो("%d\n", b / 4);
    म_लिखो("%d\n", (अचिन्हित)b / 4);
    म_लिखो("%d\n", a % 20);
    म_लिखो("%d\n", b % 20);
    म_लिखो("%d\n", (अचिन्हित)b % 20);
    म_लिखो("%d\n", a & 6);
    म_लिखो("%d\n", a ^ 7);
    म_लिखो("%d\n", a | 8);
    म_लिखो("%d\n", a >> 3);
    म_लिखो("%d\n", b >> 3);
    म_लिखो("%d\n", (अचिन्हित)b >> 3);
    म_लिखो("%d\n", a << 4);
    म_लिखो("%d\n", ~a);
    म_लिखो("%d\n", -a);
    म_लिखो("%d\n", +a);

    म_लिखो("%d\n", 12 + 1);
    म_लिखो("%d\n", 12 - 2);
    म_लिखो("%d\n", 12 * 312);
    म_लिखो("%d\n", 12 / 4);
    म_लिखो("%d\n", 12 % 20);
    म_लिखो("%d\n", 12 & 6);
    म_लिखो("%d\n", 12 ^ 7);
    म_लिखो("%d\n", 12 | 8);
    म_लिखो("%d\n", 12 >> 2);
    म_लिखो("%d\n", 12 << 4);
    म_लिखो("%d\n", ~12);
    म_लिखो("%d\n", -12);
    म_लिखो("%d\n", +12);
    म_लिखो("%d %d %d %d\n", 
           isid('a'), 
           isid('g'), 
           isid('T'), 
           isid('('));
}

पूर्णाङ्क isid(पूर्णाङ्क c)
{
    फर्काऊ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
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
    म_लिखो("res= %d %d\n", a, b);
}

पूर्णाङ्क const_len_ar[परिमाण(1/0)]; /* div-by-zero, but in unevaluated context */

शून्य constant_अभिव्यक्ति_test()
{
    पूर्णाङ्क a;
    a = 3;
    म_लिखो("%d\n", a * 16);
    म_लिखो("%d\n", a * 1);
    म_लिखो("%d\n", a + 0);
    म_लिखो("%d\n", परिमाण(const_len_ar));
}

पूर्णाङ्क tab4[10];

शून्य अभिव्यक्ति_ptr_test()
{
    पूर्णाङ्क arr[10], *p, *q;
    पूर्णाङ्क i = -1;

    p = tab4;
    q = tab4 + 10;
    म_लिखो("diff=%d\n", q - p);
    p++;
    म_लिखो("inc=%d\n", p - tab4);
    p--;
    म_लिखो("dec=%d\n", p - tab4);
    ++p;
    म_लिखो("inc=%d\n", p - tab4);
    --p;
    म_लिखो("dec=%d\n", p - tab4);
    म_लिखो("add=%d\n", p + 3 - tab4);
    म_लिखो("add=%d\n", 3 + p - tab4);

    /* check if 64bit support is ok */
    q = p = 0;
    q += i;
    म_लिखो("%p %p %ld\n", q, p, p-q);
    म_लिखो("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    i = 0xf0000000;
    p += i;
    म_लिखो("%p %p %ld\n", q, p, p-q);
    म_लिखो("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p = (पूर्णाङ्क *)((वर्ण *)p + 0xf0000000);
    म_लिखो("%p %p %ld\n", q, p, p-q);
    म_लिखो("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    म_लिखो("%p %p %ld\n", q, p, p-q);
    म_लिखो("%d %d %d %d %d %d\n",
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
        म_लिखो("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (पूर्णाङ्क*)0x100000000UL + i;
    i = ((दीर्घ)p) >> 32;
    म_लिखो("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    म_लिखो ("%d\n", (पूर्णाङ्क)((p - q) / 3));
}

शून्य अभिव्यक्ति_cmp_test()
{
    पूर्णाङ्क a, b;
    a = -1;
    b = 1;
    म_लिखो("%d\n", a == a);
    म_लिखो("%d\n", a != a);

    म_लिखो("%d\n", a < b);
    म_लिखो("%d\n", a <= b);
    म_लिखो("%d\n", a <= a);
    म_लिखो("%d\n", b >= a);
    म_लिखो("%d\n", a >= a);
    म_लिखो("%d\n", b > a);

    म_लिखो("%d\n", (अचिन्हित)a < b);
    म_लिखो("%d\n", (अचिन्हित)a <= b);
    म_लिखो("%d\n", (अचिन्हित)a <= a);
    म_लिखो("%d\n", (अचिन्हित)b >= a);
    म_लिखो("%d\n", (अचिन्हित)a >= a);
    म_लिखो("%d\n", (अचिन्हित)b > a);
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
    अचिन्हित दीर्घ flags;
    सङ्घ {
	शून्य *u1;
	पूर्णाङ्क *u2;
    };

    संरचना {
	सङ्घ {
	    अचिन्हित दीर्घ index;
	    शून्य *freelist;
	};
	सङ्घ {
	    अचिन्हित दीर्घ counters;
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
	    अचिन्हित दीर्घ compound_head;
	    अचिन्हित पूर्णाङ्क compound_dtor;
	    अचिन्हित पूर्णाङ्क compound_order;
	};
    };
} __attribute__((aligned(2 * परिमाण(दीर्घ))));

प्रकारनिर्देश अचिन्हित दीर्घ दीर्घ __attribute__((aligned(4))) unaligned_u64;

संरचना aligntest9 {
    अचिन्हित पूर्णाङ्क buf_nr;
    unaligned_u64 start_lba;
};

संरचना aligntest10 {
    अचिन्हित पूर्णाङ्क buf_nr;
    अचिन्हित दीर्घ दीर्घ start_lba;
};

शून्य struct_test()
{
    struct1 *s;
    सङ्घ union2 u;
    संरचना Large ls;

    म_लिखो("sizes: %d %d %d %d\n",
           परिमाण(संरचना struct1),
           परिमाण(संरचना struct2),
           परिमाण(सङ्घ union1),
           परिमाण(सङ्घ union2));
    म_लिखो("offsets: %d\n", (पूर्णाङ्क)((वर्ण*)&st1.u.v1 - (वर्ण*)&st1));
    st1.f1 = 1;
    st1.f2 = 2;
    st1.f3 = 3;
    म_लिखो("st1: %d %d %d\n",
           st1.f1, st1.f2, st1.f3);
    st1.u.v1 = 1;
    st1.u.v2 = 2;
    म_लिखो("union1: %d\n", st1.u.v1);
    u.w1 = 1;
    u.w2 = 2;
    म_लिखो("union2: %d\n", u.w1);
    s = &st2;
    s->f1 = 3;
    s->f2 = 2;
    s->f3 = 1;
    म_लिखो("st2: %d %d %d\n",
           s->f1, s->f2, s->f3);
    म_लिखो("str_addr=%x\n", (पूर्णाङ्क)(uintptr_t)st1.str - (पूर्णाङ्क)(uintptr_t)&st1.f1);

    /* align / size tests */
    म_लिखो("aligntest1 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest1), __alignof__(संरचना aligntest1));
    म_लिखो("aligntest2 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest2), __alignof__(संरचना aligntest2));
    म_लिखो("aligntest3 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest3), __alignof__(संरचना aligntest3));
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    म_लिखो("aligntest4 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest4), __alignof__(संरचना aligntest4));
#endif
    म_लिखो("aligntest5 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest5), __alignof__(संरचना aligntest5));
    म_लिखो("aligntest6 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest6), __alignof__(संरचना aligntest6));
    म_लिखो("aligntest7 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest7), __alignof__(संरचना aligntest7));
    म_लिखो("aligntest8 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest8), __alignof__(संरचना aligntest8));
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    म_लिखो("aligntest9 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest9), __alignof__(संरचना aligntest9));
#endif
    म_लिखो("aligntest10 sizeof=%d alignof=%d\n",
           परिमाण(संरचना aligntest10), __alignof__(संरचना aligntest10));
    म_लिखो("altest5 sizeof=%d alignof=%d\n",
           परिमाण(altest5), __alignof__(altest5));
    म_लिखो("altest6 sizeof=%d alignof=%d\n",
           परिमाण(altest6), __alignof__(altest6));
    म_लिखो("altest7 sizeof=%d alignof=%d\n",
           परिमाण(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#यदि !(defined _WIN32 && CC_NAME == CC_clang)
    म_लिखो("sizeof(struct empty) = %d\n", परिमाण(संरचना empty));
#endif
    म_लिखो("alignof(struct empty) = %d\n", __alignof__(संरचना empty));

    म_लिखो("Large: sizeof=%d\n", परिमाण(ls));
    स_रखो(&ls, 0, परिमाण(ls));
    ls.compound_head = 42;
    म_लिखो("Large: offsetof(compound_head)=%d\n", (पूर्णाङ्क)((वर्ण*)&ls.compound_head - (वर्ण*)&ls));
}

/* simulate char/short return value with undefined upper bits */
स्थिर पूर्णाङ्क __csf(पूर्णाङ्क x) { फर्काऊ x; }
स्थिर शून्य *_csf = __csf;
#define csf(t,n) ((t(*)(पूर्णाङ्क))_csf)(n)

/* XXX: depend on endianness */
शून्य char_short_test()
{
    पूर्णाङ्क var1, var2;
    चिन्हित वर्ण var3;
    दीर्घ दीर्घ var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    म_लिखो("s8=%d %d\n", 
           *(चिन्हित वर्ण *)&var1, *(चिन्हित वर्ण *)&var2);
    म_लिखो("u8=%d %d\n", 
           *(अचिन्हित वर्ण *)&var1, *(अचिन्हित वर्ण *)&var2);
    म_लिखो("s16=%d %d\n", 
           *(लघु *)&var1, *(लघु *)&var2);
    म_लिखो("u16=%d %d\n", 
           *(अचिन्हित लघु *)&var1, *(अचिन्हित लघु *)&var2);
    म_लिखो("s32=%d %d\n", 
           *(पूर्णाङ्क *)&var1, *(पूर्णाङ्क *)&var2);
    म_लिखो("u32=%d %d\n", 
           *(अचिन्हित पूर्णाङ्क *)&var1, *(अचिन्हित पूर्णाङ्क *)&var2);
    *(चिन्हित वर्ण *)&var1 = 0x08;
    म_लिखो("var1=%x\n", var1);
    *(लघु *)&var1 = 0x0809;
    म_लिखो("var1=%x\n", var1);
    *(पूर्णाङ्क *)&var1 = 0x08090a0b;
    म_लिखो("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    म_लिखो("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    म_लिखो("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    म_लिखो("promote char/short cast VA %d %d\n", (चिन्हित वर्ण)(var1 + 1), (चिन्हित वर्ण)(var4 + 1));
#यदि !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(अचिन्हित वर्ण,0x89898989);
    var4 = csf(चिन्हित वर्ण,0xabababab);
#ifdef __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#endif
    म_लिखो("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    म_लिखो("promote char/short fumcret VA %d %d %d %d\n",
        csf(अचिन्हित लघु,0xcdcdcdcd),
        csf(लघु,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#endif
    var3 = -10;
    var1 = (चिन्हित वर्ण)(अचिन्हित वर्ण)(var3 + 1);
    var4 = (चिन्हित वर्ण)(अचिन्हित वर्ण)(var3 + 1);
    म_लिखो("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (अचिन्हित)(पूर्णाङ्क)(var4 + 1);
    म_लिखो("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (अचिन्हित)(चिन्हित वर्ण)(var4 + 1);
    म_लिखो("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
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
    फर्काऊ TOUPPER(a);
}

स्थिर अचिन्हित पूर्णाङ्क calc_vm_flags(अचिन्हित पूर्णाङ्क prot)
{
  अचिन्हित पूर्णाङ्क prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  फर्काऊ prot_bits;
}

गणना cast_enum { FIRST, LAST };

स्थिर शून्य tst_cast(गणना cast_enum ce)
{
    म_लिखो("%d\n", ce);
}

शून्य bool_test()
{
    पूर्णाङ्क *s, a, b, t, f, i;

    a = 0;
    s = (शून्य*)0;
    म_लिखो("!s=%d\n", !s);

    यदि (!s || !s[0])
        a = 1;
    म_लिखो("a=%d\n", a);

    म_लिखो("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    म_लिखो("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    म_लिखो("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#यदि 1 && 1
    म_लिखो("a1\n");
#endif
#यदि 1 || 0
    म_लिखो("a2\n");
#endif
#यदि 1 ? 0 : 1
    म_लिखो("a3\n");
#endif
#यदि 0 ? 0 : 1
    म_लिखो("a4\n");
#endif

    a = 4;
    म_लिखो("b=%d\n", a + (0 ? 1 : a / 2));

    /* test register spilling */
    a = 10;
    b = 10;
    a = (a + b) * ((a < b) ?
                   ((b - a) * (a - b)): a + b);
    म_लिखो("a=%d\n", a);

    /* test complex || or && expressions */
    t = 1;
    f = 0;
    a = 32;
    म_लिखो("exp=%d\n", f == (32 <= a && a <= 3));
    म_लिखो("r=%d\n", (t || f) + (t && f));

    /* check that types of casted &&/|| are preserved (here the unsignedness) */
    t = 1;
    म_लिखो("type of bool: %d\n", (पूर्णाङ्क) ( (~ ((अचिन्हित पूर्णाङ्क) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    म_लिखो("type of cond: %d\n", (~(t ? 0U : (अचिन्हित पूर्णाङ्क)0)) / 2 );
    /* test ? : cast */
    {
        पूर्णाङ्क aspect_on;
        पूर्णाङ्क aspect_native = 65536;
        द्विगुण bfu_aspect = 1.0;
        पूर्णाङ्क aspect;
        लागि(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            म_लिखो("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        स्थिर पूर्णाङ्क v1 = 34 ? : -1; /* constant case */
        स्थिर पूर्णाङ्क v2 = 0 ? : -1; /* constant case */
        पूर्णाङ्क a = 30;
        
        म_लिखो("%d %d\n", v1, v2);
        म_लिखो("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    लागि(i=0;i<256;i++) {
        यदि (toupper1 (i) != TOUPPER (i))
            म_लिखो("error %d\n", i);
    }
    म_लिखो ("bits = 0x%x\n", calc_vm_flags (0x1));
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
  म_लिखो ("oo:%d\n", i);
  पूर्णाङ्क j = 1 ? defined_function() : undefined_function();
  म_लिखो ("oo:%d\n", j);
  यदि (0)
    म_लिखो("oo:%d\n", undefined_function());
  अन्यथा
    म_लिखो("oo:%d\n", defined_function());
  यदि (1)
    म_लिखो("oo:%d\n", defined_function());
  अन्यथा
    म_लिखो("oo:%d\n", undefined_function());
  जबसम्म (1) {
      म_लिखो("oow:%d\n", defined_function());
      रोक;
      म_लिखो("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  विकल्प (j)
    पक्ष 1: रोक;
  म_लिखो ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  जबसम्म (1)
    रोक;
  म_लिखो ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  गर
    रोक;
  जबसम्म (1);
  म_लिखो ("ool2:%d\n", defined_function());
  लागि (;;)
    रोक;
  म_लिखो ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  जबसम्म (1) {
	{
	  रोक;
	}
      म_लिखो ("ool4:%d\n", undefined_function());
  }
  j = 1;
  जबसम्म (j) {
      यदि (j == 0)
	रोक; /* this break shouldn't disable code outside the if. */
      म_लिखो("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  जबसम्म (j) {
      यदि (1)
	j--;
      अन्यथा
	breakhere: रोक;
      म_लिखो("ool6:%d\n", defined_function());
      गच्छ breakhere;
  }
  j = 1;
  जबसम्म (j) {
      j--;
      जारी;
      म_लिखो("ool7:%d\n", undefined_function());
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
		     गर { } जबसम्म (0);
		     0;
		     }) );
      undefined_function();
  }

  यदि (0) {
      विकल्प (defined_function()) {
          पक्ष 0: undefined_function(); रोक;
          स्वभाव: undefined_function(); रोक;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  यदि (1)
    फर्काऊ;
  म_लिखो ("oor:%d\n", undefined_function());
}

पूर्णाङ्क defined_function(शून्य)
{
  स्थिर पूर्णाङ्क i = 40;
  फर्काऊ i++;
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
वर्ण अचर * अचर cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
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

    म_लिखो("cinit3 : %s\n", cinit3);
    म_लिखो("cinit4 : %d\n", cinit4);
    म_लिखो("cinit51 : %d\n", (पूर्णाङ्क)cinit51);
    म_लिखो("cinit52 : %d\n", *(पूर्णाङ्क*)cinit52);
    म_लिखो("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    म_लिखो("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    म_लिखो("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (पूर्णाङ्क []){1, 2, 3};
    लागि(i=0;i<3;i++)
        म_लिखो(" %d", p[i]);
    म_लिखो("\n");

    लागि(i=0;i<3;i++)
        म_लिखो("%d", cinit2[i]);
    म_लिखो("\n");

    q = "tralala1";
    म_लिखो("q1=%s\n", q);

    q = (वर्ण *){ "tralala2" };
    म_लिखो("q2=%s\n", q);

    q3 = (वर्ण *){ q };
    म_लिखो("q3=%s\n", q3);

    q = (वर्ण []){ "tralala3" };
    म_लिखो("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (पूर्णाङ्क []){1, 2, cinit1 + 3};
    लागि(i=0;i<3;i++)
        म_लिखो(" %d", p[i]);
    म_लिखो("\n");

    लागि(i=0;i<3;i++) {
        p = (पूर्णाङ्क []){1, 2, 4 + i};
        म_लिखो("%d %d %d\n", 
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
    फर्काऊ a + b;
}

पूर्णाङ्क kr_func2(a, b)
{
    फर्काऊ a + b;
}

kr_test()
{
    म_लिखो("func1=%d\n", kr_func1(3, 4));
    म_लिखो("func2=%d\n", kr_func2(3, 4));
    फर्काऊ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
वर्ण invalid_function_def()[] {फर्काऊ 0;}

#अन्यथा
# define kr_test() म_लिखो("func1=7\nfunc2=7\n")
#endif

शून्य अङ्क(पूर्णाङ्क n)
{
    वर्ण *tab, *p;
    tab = (वर्ण*)दो_स्मृति(20); 
    p = tab;
    जबसम्म (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        यदि (n == 0)
            रोक;
    }
    जबसम्म (p != tab) {
        p--;
        म_लिखो("%c", *p);
    }
    म_लिखो("\n");
    मुक्त(tab);
}

/* structure assignment tests */
संरचना structa1 {
    पूर्णाङ्क f1;
    वर्ण f2;
};

शून्य struct_assign_test1(संरचना structa1 s1, पूर्णाङ्क t, भिन्न f)
{
    म_लिखो("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

संरचना structa1 struct_assign_test2(संरचना structa1 s1, पूर्णाङ्क t)
{
    s1.f1 += t;
    s1.f2 -= t;
    फर्काऊ s1;
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
    म_लिखो("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    म_लिखो("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    स्थिर संरचना {
        शून्य (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    म_लिखो("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    म_लिखो("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

शून्य cast1(वर्ण a, लघु b, अचिन्हित वर्ण c, अचिन्हित लघु d)
{
    म_लिखो("%d %d %d %d\n", a, b, c, d);
}

वर्ण bcast;
लघु scast;

शून्य cast_test()
{
    पूर्णाङ्क a;
    वर्ण c;
    वर्ण tab[10];
    अचिन्हित b,d;
    लघु s;
    वर्ण *p = रिक्त;
    अचिन्हित दीर्घ ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    म_लिखो("%d %d %d %d\n",
           (वर्ण)(a + 1),
           (लघु)(a + 1),
           (अचिन्हित वर्ण)(a + 1),
           (अचिन्हित लघु)(a + 1));
    म_लिखो("%d %d %d %d\n",
           (वर्ण)0xfffff,
           (लघु)0xfffff,
           (अचिन्हित वर्ण)0xfffff,
           (अचिन्हित लघु)0xfffff);

    a = (bcast = 128) + 1;
    म_लिखो("%d\n", a);
    a = (scast = 65536) + 1;
    म_लिखो("%d\n", a);
    
    म_लिखो("sizeof(c) = %d, sizeof((int)c) = %d\n", परिमाण(c), परिमाण((पूर्णाङ्क)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (लघु)b;
    म_लिखो("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (वर्ण)b;
    म_लिखो("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    म_लिखो("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    म_लिखो("sizeof(+(char)'a') = %d\n", परिमाण(+(वर्ण)'a'));
    म_लिखो("sizeof(-(char)'a') = %d\n", परिमाण(-(वर्ण)'a'));
    म_लिखो("sizeof(~(char)'a') = %d\n", परिमाण(-(वर्ण)'a'));

#यदि CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    म_लिखो("%d %d %ld %ld %lld %lld\n",
           (पूर्णाङ्क)p, (अचिन्हित पूर्णाङ्क)p,
           (दीर्घ)p, (अचिन्हित दीर्घ)p,
           (दीर्घ दीर्घ)p, (अचिन्हित दीर्घ दीर्घ)p);
#endif

    /* from integers to pointers */
    म_लिखो("%p %p %p %p\n",
           (शून्य *)a, (शून्य *)b, (शून्य *)c, (शून्य *)d);

    /* int to int with sign set */
    म_लिखो("0x%lx\n", (अचिन्हित दीर्घ)(पूर्णाङ्क)ul);
}

/* initializers tests */
संरचना structinit1 {
    पूर्णाङ्क f1;
    वर्ण f2;
    लघु f3;
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
    अचर संरचना complexinit0 *b;
};

अचर स्थिर संरचना complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (अचर संरचना complexinit0[]) {
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
संरचना bf_SS {अचिन्हित पूर्णाङ्क bit:1,bits31:31; };
संरचना bf_SS bf_init = { .bit = 1 };
संरचना bfn_SS {पूर्णाङ्क a,b; संरचना bf_SS c; पूर्णाङ्क d,e; };
संरचना bfn_SS bfn_init = { .c.bit = 1 };
संरचना bfa_SS {पूर्णाङ्क a,b; संरचना bf_SS c[3]; पूर्णाङ्क d,e; };
संरचना bfa_SS bfa_init = { .c[1].bit = 1 };
संरचना bf_SS bfaa_init[3] = { [1].bit = 1 };
संरचना bf_SS bfaa_vinit[] = { [2].bit = 1 };
संरचना b2_SS {दीर्घ दीर्घ पूर्णाङ्क field : 52; दीर्घ दीर्घ पूर्णाङ्क pad : 12; };
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
    
    म_लिखो("sinit1=%d\n", sinit1);
    म_लिखो("sinit2=%d\n", sinit2);
    म_लिखो("sinit3=%d %d %d %d\n", 
           परिमाण(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    म_लिखो("sinit6=%d\n", परिमाण(sinit6));
    म_लिखो("sinit7=%d %d %d %d\n", 
           परिमाण(sinit7),
           sinit7[0],
           sinit7[1],
           sinit7[2]
           );
    म_लिखो("sinit8=%s\n", sinit8);
    म_लिखो("sinit9=%d %d %d\n", 
           sinit9.f1,
           sinit9.f2,
           sinit9.f3
           );
    म_लिखो("sinit10=%d %d %d\n", 
           sinit10.f1,
           sinit10.f2,
           sinit10.f3
           );
    म_लिखो("sinit11=%d %d %d %d %d %d\n", 
           sinit11.f1,
           sinit11.f2,
           sinit11.f3,
           sinit11.farray[0],
           sinit11.farray[1],
           sinit11.farray[2]
           );

    लागि(i=0;i<3;i++)
        लागि(j=0;j<2;j++)
            म_लिखो("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    म_लिखो("linit1=%d\n", linit1);
    म_लिखो("linit2=%d\n", linit2);
    म_लिखो("linit6=%d\n", परिमाण(linit6));
    म_लिखो("linit8=%d %s\n", परिमाण(linit8), linit8);

    म_लिखो("sinit12=%s\n", sinit12);
    म_लिखो("sinit13=%d %s %s %s\n",
           परिमाण(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    म_लिखो("sinit14=%s\n", sinit14);

    लागि(i=0;i<10;i++) म_लिखो(" %d", linit12[i]);
    म_लिखो("\n");
    लागि(i=0;i<10;i++) म_लिखो(" %d", linit13[i]);
    म_लिखो("\n");
    लागि(i=0;i<10;i++) म_लिखो(" %d", linit14[i]);
    म_लिखो("\n");
    लागि(i=0;i<10;i++) म_लिखो(" %d", linit15[i]);
    म_लिखो("\n");
    म_लिखो("%d %d %d %d\n", 
           linit16.a1,
           linit16.a2,
           linit16.a3,
           linit16.a4);
    /* test that initialisation is done after variable declare */
    म_लिखो("linit17=%d\n", linit17);
    म_लिखो("sinit15=%d\n", sinit15[0]);
    म_लिखो("sinit16=%d %d\n", sinit16[0].a[0], sinit16[1].a[0]);
    म_लिखो("sinit17=%s %d %s %d\n",
           sinit17[0].s, sinit17[0].len,
           sinit17[1].s, sinit17[1].len);
    लागि(i=0;i<10;i++)
        म_लिखो("%x ", sinit18[i]);
    म_लिखो("\n");
    /* complex init check */
    म_लिखो("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    म_लिखो("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    म_लिखो("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", परिमाण cix20, परिमाण cix21, परिमाण cix22);

    म_लिखो("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    म_लिखो("arrtype2: %d %d\n", परिमाण(sinit19), परिमाण(sinit20));
    म_लिखो("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    म_लिखो("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    म_लिखो("arrtype5: %d %d\n", परिमाण(sinit21), परिमाण(sinit22));
    म_लिखो("arrtype6: %d\n", परिमाण(arrtype2));

    म_लिखो("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    म_लिखो("sinit24=%d\n", sinit24);
    म_लिखो("linit18= %d %d\n", linit18[0], linit18[1]);
    म_लिखो ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    म_लिखो ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    म_लिखो ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    म_लिखो ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    लागि (i = 0; i < 3; i++)
        म_लिखो ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    लागि (i = 0; i < 3; i++)
        म_लिखो ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    लागि (i = 0; i < 3; i++)
        म_लिखो ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    लागि (i = 0; i < 3; i++)
        म_लिखो ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    लागि (i = 0; i < 3; i++)
        म_लिखो ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    लागि (i = 0; i < 3; i++)
        म_लिखो ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

शून्य switch_uc(अचिन्हित वर्ण uc)
{
	विकल्प (uc) {
	    पक्ष 0xfb ... 0xfe:
		म_लिखो("ucsw:1\n");
		रोक;
	    पक्ष 0xff:
		म_लिखो("ucsw:2\n");
		रोक;
	    पक्ष 0 ... 5:
		म_लिखो("ucsw:3\n");
		रोक;
	    स्वभाव:
		म_लिखो("ucsw: broken!\n");
	}
}

शून्य switch_sc(चिन्हित वर्ण sc)
{
	विकल्प (sc) {
	    पक्ष -5 ... -2:
		म_लिखो("scsw:1\n");
		रोक;
	    पक्ष -1:
		म_लिखो("scsw:2\n");
		रोक;
	    पक्ष 0 ... 5:
		म_लिखो("scsw:3\n");
		रोक;
	    स्वभाव:
		म_लिखो("scsw: broken!\n");
	}
}

शून्य switch_test()
{
    पूर्णाङ्क i;
    अचिन्हित दीर्घ दीर्घ ull;
    दीर्घ दीर्घ ll;

    लागि(i=0;i<15;i++) {
        विकल्प(i) {
        पक्ष 0:
        पक्ष 1:
            म_लिखो("a");
            रोक;
        स्वभाव:
            म_लिखो("%d", i);
            रोक;
        पक्ष 8 ... 12:
            म_लिखो("c");
            रोक;
        पक्ष 3:
            म_लिखो("b");
            रोक;
        पक्ष 0xc33c6b9fU:
        पक्ष 0x7c9eeeb9U:
            रोक;
        }
    }
    म_लिखो("\n");

    लागि (i = 1; i <= 5; i++) {
	ull = (अचिन्हित दीर्घ दीर्घ)i << 61;
	विकल्प (ull) {
	    पक्ष 1ULL << 61:
		म_लिखो("ullsw:1\n");
		रोक;
	    पक्ष 2ULL << 61:
		म_लिखो("ullsw:2\n");
		रोक;
	    पक्ष 3ULL << 61:
		म_लिखो("ullsw:3\n");
		रोक;
	    पक्ष 4ULL << 61:
		म_लिखो("ullsw:4\n");
		रोक;
	    पक्ष 5ULL << 61:
		म_लिखो("ullsw:5\n");
		रोक;
	    स्वभाव:
		म_लिखो("ullsw: broken!\n");
	}
    }

    लागि (i = 1; i <= 5; i++) {
	ll = (दीर्घ दीर्घ)i << 61;
	विकल्प (ll) {
	    पक्ष 1LL << 61:
		म_लिखो("llsw:1\n");
		रोक;
	    पक्ष 2LL << 61:
		म_लिखो("llsw:2\n");
		रोक;
	    पक्ष 3LL << 61:
		म_लिखो("llsw:3\n");
		रोक;
	    पक्ष 4LL << 61:
		म_लिखो("llsw:4\n");
		रोक;
	    पक्ष 5LL << 61:
		म_लिखो("llsw:5\n");
		रोक;
	    स्वभाव:
		म_लिखो("llsw: broken!\n");
	}
    }

    लागि (i = -5; i <= 5; i++) {
	switch_uc((अचिन्हित वर्ण)i);
    }

    लागि (i = -5; i <= 5; i++) {
	switch_sc ((चिन्हित वर्ण)i);
    }
}

/* ISOC99 _Bool type */
शून्य c99_bool_test(शून्य)
{
#ifdef BOOL_ISOC99
    पूर्णाङ्क a;
    _Bool b, b2;

    म_लिखो("sizeof(_Bool) = %d\n", परिमाण(_Bool));
    a = 3;
    म_लिखो("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    म_लिखो("b = %d\n", b);
    b++;
    म_लिखो("b = %d\n", b);
    b2 = 0;
    म_लिखो("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           परिमाण ((चञ्चल पूर्णाङ्क)a ? b : b2));
#endif
}

शून्य bitfield_test(शून्य)
{
    पूर्णाङ्क a;
    लघु sa;
    अचिन्हित वर्ण ca;
    संरचना sbf1 {
        पूर्णाङ्क f1 : 3;
        पूर्णाङ्क : 2;
        पूर्णाङ्क f2 : 1;
        पूर्णाङ्क : 0;
        पूर्णाङ्क f3 : 5;
        पूर्णाङ्क f4 : 7;
        अचिन्हित पूर्णाङ्क f5 : 7;
    } st1;
    म_लिखो("sizeof(st1) = %d\n", परिमाण(st1));

    st1.f1 = 3;
    st1.f2 = 1;
    st1.f3 = 15;
    a = 120;
    st1.f4 = a;
    st1.f5 = a;
    st1.f5++;
    म_लिखो("%d %d %d %d %d\n",
           st1.f1, st1.f2, st1.f3, st1.f4, st1.f5);
    sa = st1.f5;
    ca = st1.f5;
    म_लिखो("%d %d\n", sa, ca);

    st1.f1 = 7;
    यदि (st1.f1 == -1) 
        म_लिखो("st1.f1 == -1\n");
    अन्यथा 
        म_लिखो("st1.f1 != -1\n");
    यदि (st1.f2 == -1) 
        म_लिखो("st1.f2 == -1\n");
    अन्यथा 
        म_लिखो("st1.f2 != -1\n");

    संरचना sbf2 {
        दीर्घ दीर्घ f1 : 45;
        दीर्घ दीर्घ : 2;
        दीर्घ दीर्घ f2 : 35;
        अचिन्हित दीर्घ दीर्घ f3 : 38;
    } st2;
    st2.f1 = 0x123456789ULL;
    a = 120;
    st2.f2 = (दीर्घ दीर्घ)a << 25;
    st2.f3 = a;
    st2.f2++;
    म_लिखो("%lld %lld %lld\n", st2.f1, st2.f2, st2.f3);

#यदि 0
    Disabled लागि now until further clarification re GCC compatibility
    संरचना sbf3 {
        पूर्णाङ्क f1 : 7;
        पूर्णाङ्क f2 : 1;
        वर्ण f3;
        पूर्णाङ्क f4 : 8;
        पूर्णाङ्क f5 : 1;
        पूर्णाङ्क f6 : 16;
    } st3;
    म_लिखो("sizeof(st3) = %d\n", परिमाण(st3));
#endif

    संरचना sbf4 {
	पूर्णाङ्क x : 31;
	वर्ण y : 2;
    } st4;
    st4.y = 1;
    म_लिखो("st4.y == %d\n", st4.y);
    संरचना sbf5 {
	पूर्णाङ्क a;
	वर्ण b;
	पूर्णाङ्क x : 12, y : 4, : 0, : 4, z : 3;
	वर्ण c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    म_लिखो("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    संरचना sbf6 {
	लघु x : 12;
	अचिन्हित वर्ण y : 2;
    } st6;
    st6.y = 1;
    म_लिखो("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#अन्यथा
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
द्विगुण म_से_भग्न(अचर वर्ण *nptr, वर्ण **endptr);

#यदि defined(_WIN32)
भिन्न strtof(अचर वर्ण *nptr, वर्ण **endptr) {फर्काऊ (भिन्न)म_से_भग्न(nptr, endptr);}
LONG_DOUBLE strtold(अचर वर्ण *nptr, वर्ण **endptr) {फर्काऊ (LONG_DOUBLE)म_से_भग्न(nptr, endptr);}
#अन्यथा
भिन्न strtof(अचर वर्ण *nptr, वर्ण **endptr);
LONG_DOUBLE strtold(अचर वर्ण *nptr, वर्ण **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
शून्य prefix ## cmp(type a, type b)\
{\
    म_लिखो("%d %d %d %d %d %d\n",\
           a == b,\
           a != b,\
           a < b,\
           a > b,\
           a >= b,\
           a <= b);\
    म_लिखो(fmt " " fmt " " fmt " " fmt " " fmt " " fmt " " fmt "\n",\
           a,\
           b,\
           a + b,\
           a - b,\
           a * b,\
           a / b,\
           -a);\
    म_लिखो(fmt "\n", ++a);\
    म_लिखो(fmt "\n", a++);\
    म_लिखो(fmt "\n", a);\
    b = 0;\
    म_लिखो("%d %d\n", !a, !b);\
}\
शून्य prefix ## fcast(type a)\
{\
    भिन्न fa;\
    द्विगुण da;\
    LONG_DOUBLE la;\
    पूर्णाङ्क ia;\
    दीर्घ दीर्घ llia;\
    अचिन्हित पूर्णाङ्क ua;\
    अचिन्हित दीर्घ दीर्घ llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    म_लिखो("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (पूर्णाङ्क)a;\
    llia = (दीर्घ दीर्घ)a;\
    a = (a >= 0) ? a : -a;\
    ua = (अचिन्हित पूर्णाङ्क)a;\
    llua = (अचिन्हित दीर्घ दीर्घ)a;\
    म_लिखो("ftoi: %d %u %lld %llu\n", ia, ua, llia, llua);\
    ia = -1234;\
    ua = 0x81234500;\
    llia = -0x123456789012345LL;\
    llua = 0xf123456789012345LLU;\
    b = ia;\
    म_लिखो("itof: " fmt "\n", b);\
    b = ua;\
    म_लिखो("utof: " fmt "\n", b);\
    b = llia;\
    म_लिखो("lltof: " fmt "\n", b);\
    b = llua;\
    यदि (CC_NAME != CC_clang) म_लिखो("ulltof: " fmt "\n", b);\
}\
\
भिन्न prefix ## retf(type a) { फर्काऊ a; }\
द्विगुण prefix ## retd(type a) { फर्काऊ a; }\
LONG_DOUBLE prefix ## retld(type a) { फर्काऊ a; }\
\
शून्य prefix ## call(शून्य)\
{\
    म_लिखो("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    म_लिखो("double: %f\n", prefix ## retd(42.123456789));\
    म_लिखो("long double: %Lf\n", prefix ## retld(42.123456789));\
    म_लिखो("strto%s: %f\n", #prefix, (द्विगुण)strto ## prefix("1.2", रिक्त));\
}\
\
शून्य prefix ## signed_zeros(शून्य) \
{\
  type x = 0.0, y = -0.0, n, p;\
  यदि (x == y)\
    म_लिखो ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  अन्यथा\
    म_लिखो ("x != y; this is wrong!\n");\
\
  n = -x;\
  यदि (x == n)\
    म_लिखो ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  अन्यथा\
    म_लिखो ("x != -x; this is wrong!\n");\
\
  p = +y;\
  यदि (x == p)\
    म_लिखो ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    म_लिखो ("x != +y; this is wrong!\n");\
  p = -y;\
  यदि (x == p)\
    म_लिखो ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    म_लिखो ("x != -y; this is wrong!\n");\
}\
शून्य prefix ## nan(शून्य)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    म_लिखो("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
शून्य prefix ## test(शून्य)\
{\
    म_लिखो("testing '%s'\n", #typename);\
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
FTEST(ld, दीर्घ द्विगुण, LONG_DOUBLE, "%Lf")

द्विगुण ftab1[3] = { 1.2, 3.4, -5.6 };


शून्य float_test(शून्य)
{
#यदि !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    चञ्चल भिन्न fa, fb;
    चञ्चल द्विगुण da, db;
    पूर्णाङ्क a;
    अचिन्हित पूर्णाङ्क b;
    स्थिर द्विगुण nan2 = 0.0/0.0;
    स्थिर द्विगुण inf1 = 1.0/0.0;
    स्थिर द्विगुण inf2 = 1e5000;
    चञ्चल LONG_DOUBLE la;

    म_लिखो("sizeof(float) = %d\n", परिमाण(भिन्न));
    म_लिखो("sizeof(double) = %d\n", परिमाण(द्विगुण));
    म_लिखो("sizeof(long double) = %d\n", परिमाण(LONG_DOUBLE));
    ftest();
    dtest();
    ldtest();
    म_लिखो("%f %f %f\n", ftab1[0], ftab1[1], ftab1[2]);
    म_लिखो("%f %f %f\n", 2.12, .5, 2.3e10);
    //    printf("%f %f %f\n", 0x1234p12, 0x1e23.23p10, 0x12dp-10);
    da = 123;
    म_लिखो("da=%f\n", da);
    fa = 123;
    म_लिखो("fa=%f\n", fa);
    a = 4000000000;
    da = a;
    म_लिखो("da = %f\n", da);
    b = 4000000000;
    db = b;
    म_लिखो("db = %f\n", db);
    म_लिखो("nan != nan = %d, inf1 = %f, inf2 = %f\n", nan2 != nan2, inf1, inf2);
    da = 0x0.88p-1022;  /* a subnormal */
    la = da;
    म_लिखो ("da subnormal = %a\n", da);
    म_लिखो ("da subnormal = %.40g\n", da);
    म_लिखो ("la subnormal = %La\n", la);
    म_लिखो ("la subnormal = %.40Lg\n", la);
    da /= 2;
    la = da;
    म_लिखो ("da/2 subnormal = %a\n", da);
    म_लिखो ("da/2 subnormal = %.40g\n", da);
    म_लिखो ("la/2 subnormal = %La\n", la);
    म_लिखो ("la/2 subnormal = %.40Lg\n", la);
    fa = 0x0.88p-126f;  /* a subnormal */
    la = fa;
    म_लिखो ("fa subnormal = %a\n", fa);
    म_लिखो ("fa subnormal = %.40g\n", fa);
    म_लिखो ("la subnormal = %La\n", la);
    म_लिखो ("la subnormal = %.40Lg\n", la);
    fa /= 2;
    la = fa;
    म_लिखो ("fa/2 subnormal = %a\n", fa);
    म_लिखो ("fa/2 subnormal = %.40g\n", fa);
    म_लिखो ("la/2 subnormal = %La\n", la);
    म_लिखो ("la/2 subnormal = %.40Lg\n", la);
#endif
}

पूर्णाङ्क fib(पूर्णाङ्क n)
{
    यदि (n <= 2)
        फर्काऊ 1;
    अन्यथा
        फर्काऊ fib(n-1) + fib(n-2);
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
    दीर्घ diff;

    func = &अङ्क;
    (*func)(12345);
    func = अङ्क;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = अङ्क;
    st1.func(12346);
    म_लिखो("sizeof1 = %d\n", परिमाण(funcptr_test));
    म_लिखो("sizeof2 = %d\n", परिमाण funcptr_test);
    म_लिखो("sizeof3 = %d\n", परिमाण(&funcptr_test));
    म_लिखो("sizeof4 = %d\n", परिमाण &funcptr_test);
    a = 0;
    func = अङ्क + a;
    diff = func - अङ्क;
    func(42);
    (func + diff)(42);
    (अङ्क + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    म_लिखो("aligned_function (should be zero): %d\n", ((पूर्णाङ्क)(uintptr_t)func) & 15);
}

शून्य lloptest(दीर्घ दीर्घ a, दीर्घ दीर्घ b)
{
    अचिन्हित दीर्घ दीर्घ ua, ub;

    ua = a;
    ub = b;
    /* arith */
    म_लिखो("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    यदि (b != 0) {
        म_लिखो("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*द्विआधारी*/
    म_लिखो("bin: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a & b,
           a | b,
           a ^ b);

    /* tests */
    म_लिखो("test: %d %d %d %d %d %d\n",
           a == b,
           a != b,
           a < b,
           a > b,
           a >= b,
           a <= b);
    
    म_लिखो("utest: %d %d %d %d %d %d\n",
           ua == ub,
           ua != ub,
           ua < ub,
           ua > ub,
           ua >= ub,
           ua <= ub);

    /* arith2 */
    a++;
    b++;
    म_लिखो("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    म_लिखो("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a++, b++);
    म_लिखो("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", --a, --b);
    म_लिखो("arith2: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    b = ub = 0;
    म_लिखो("not: %d %d %d %d\n", !a, !ua, !b, !ub);
}

शून्य llshift(दीर्घ दीर्घ a, पूर्णाङ्क b)
{
    म_लिखो("shift: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (अचिन्हित दीर्घ दीर्घ)a >> b,
           a >> b,
           a << b);
    म_लिखो("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (अचिन्हित दीर्घ दीर्घ)a >> 3,
           a >> 3,
           a << 3);
    म_लिखो("shiftc: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           (अचिन्हित दीर्घ दीर्घ)a >> 35,
           a >> 35,
           a << 35);
}

शून्य llfloat(शून्य)
{
    भिन्न fa;
    द्विगुण da;
    LONG_DOUBLE lda;
    दीर्घ दीर्घ la, lb, lc;
    अचिन्हित दीर्घ दीर्घ ula, ulb, ulc;
    la = 0x12345678;
    ula = 0x72345678;
    la = (la << 20) | 0x12345;
    ula = ula << 33;
    म_लिखो("la=" LONG_LONG_FORMAT " ula=" ULONG_LONG_FORMAT "\n", la, ula);

    fa = la;
    da = la;
    lda = la;
    म_लिखो("lltof: %f %f %Lf\n", fa, da, lda);

    la = fa;
    lb = da;
    lc = lda;
    म_लिखो("ftoll: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", la, lb, lc);

    fa = ula;
    da = ula;
    lda = ula;
    म_लिखो("ulltof: %f %f %Lf\n", fa, da, lda);

    ula = fa;
    ulb = da;
    ulc = lda;
    म_लिखो("ftoull: " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT " " ULONG_LONG_FORMAT "\n", ula, ulb, ulc);
}

दीर्घ दीर्घ llfunc1(पूर्णाङ्क a)
{
    फर्काऊ a * 2;
}

संरचना S {
    पूर्णाङ्क id; 
    वर्ण item;
};

दीर्घ दीर्घ पूर्णाङ्क मान(संरचना S *v)
{
    फर्काऊ ((दीर्घ दीर्घ पूर्णाङ्क)v->item);
}

दीर्घ दीर्घ llfunc2(दीर्घ दीर्घ x, दीर्घ दीर्घ y, पूर्णाङ्क z)
{
    फर्काऊ x * y * z;
}

शून्य check_opl_save_regs(वर्ण *a, दीर्घ दीर्घ b, पूर्णाङ्क c)
{
    *a = b < 0 && !c;
}

शून्य longlong_test(शून्य)
{
    दीर्घ दीर्घ a, b, c;
    पूर्णाङ्क ia;
    अचिन्हित पूर्णाङ्क ua;
    म_लिखो("sizeof(long long) = %d\n", परिमाण(दीर्घ दीर्घ));
    ia = -1;
    ua = -2;
    a = ia;
    b = ua;
    म_लिखो(LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n", a, b);
    म_लिखो(LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " "XLONG_LONG_FORMAT"\n",
           (दीर्घ दीर्घ)1,
           (दीर्घ दीर्घ)-2,
           1LL,
           0x1234567812345679);
    a = llfunc1(-3);
    म_लिखो(LONG_LONG_FORMAT "\n", a);

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
    म_लिखो(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          संरचना S a;

          a.item = 3;
          म_लिखो("%lld\n", मान(&a));
    }
    lloptest(0x80000000, 0);

    {
        दीर्घ दीर्घ *p, v, **pp;
        v = 1;
        p = &v;
        p[0]++;
        म_लिखो("another long long spill test : %lld\n", *p);
        pp = &p;

        v = llfunc2(**pp, **pp, ia);
        म_लिखो("a long long function (arm-)reg-args test : %lld\n", v);
    }
    a = 68719476720LL;
    b = 4294967295LL;
    म_लिखो("%d %d %d %d\n", a > b, a < b, a >= b, a <= b);

    म_लिखो(LONG_LONG_FORMAT "\n", 0x123456789LLU);

    /* long long pointer deref in argument passing test */
    a = 0x123;
    दीर्घ दीर्घ *p = &a;
    llshift(*p, 5);

    /* shortening followed by widening */
    अचिन्हित दीर्घ दीर्घ u = 0x8000000000000001ULL;
    u = (अचिन्हित)(u + 1);
    म_लिखो("long long u=" ULONG_LONG_FORMAT "\n", u);
    u = 0x11223344aa998877ULL;
    u = (अचिन्हित)(पूर्णाङ्क)(u + 1);
    म_लिखो("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    वर्ण cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    म_लिखो("check_opl_save_regs: %d\n", cc);
}

शून्य manyarg_test(शून्य)
{
    LONG_DOUBLE ld = 1234567891234LL;
    म_लिखो("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0);
    म_लिखो("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    म_लिखो("%Lf %d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f\n",
           ld, 1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0);
    म_लिखो("%d %d %d %d %d %d %d %d %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8, ld);
    म_लिखो("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           LONG_LONG_FORMAT " " LONG_LONG_FORMAT "%f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
    म_लिखो("%d %d %d %d %d %d %d %d %f %f %f %f %f %f %f %f %f %f "
           "%Lf " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " %f %f %Lf\n",
           1, 2, 3, 4, 5, 6, 7, 8,
           0.1, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0,
           ld, 1234567891234LL, 987654321986LL,
           42.0, 43.0, ld);
}

शून्य*
va_arg_with_struct_ptr(बहु_सूची ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        संरचना X { पूर्णाङ्क _x; };
        संरचना X *x = बहु_तर्क(ap, संरचना X *);
        फर्काऊ x;
}

शून्य vprintf1(अचर वर्ण *fmt, ...)
{
    बहु_सूची ap, aq;
    अचर वर्ण *p;
    पूर्णाङ्क c, i;
    द्विगुण d;
    दीर्घ दीर्घ ll;
    LONG_DOUBLE ld;

    बहु_शुरू(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    लागि(;;) {
        c = *p;
        यदि (c == '\0')
            रोक;
        p++;
        यदि (c == '%') {
            c = *p;
            विकल्प(c) {
            पक्ष '\0':
                गच्छ the_end;
            पक्ष 'd':
                i = बहु_तर्क(ap, पूर्णाङ्क);
                म_लिखो("%d", i);
                रोक;
            पक्ष 'f':
                d = बहु_तर्क(ap, द्विगुण);
                म_लिखो("%f", d);
                रोक;
            पक्ष 'l':
                ll = बहु_तर्क(ap, दीर्घ दीर्घ);
                म_लिखो(LONG_LONG_FORMAT, ll);
                रोक;
            पक्ष 'F':
                ld = बहु_तर्क(ap, LONG_DOUBLE);
                म_लिखो("%Lf", ld);
                रोक;
            }
            p++;
        } अन्यथा {
            अक्षर_दो(c);
        }
    }
 the_end:
    बहु_पूर्ण(aq);
    बहु_पूर्ण(ap);
}

संरचना myspace {
    लघु पूर्णाङ्क profile;
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
    बहु_सूची ap;
    लघु पूर्णाङ्क validate;

    बहु_शुरू(ap, bob);
    alex1    = बहु_तर्क(ap, संरचना myspace2);
    alex2    = बहु_तर्क(ap, संरचना myspace3);
    alex3    = बहु_तर्क(ap, संरचना myspace4);
    bill     = बहु_तर्क(ap, संरचना myspace);
    george   = बहु_तर्क(ap, संरचना myspace);
    validate = बहु_तर्क(ap, पूर्णाङ्क);
    म_लिखो("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    बहु_पूर्ण(ap);
    फर्काऊ (संरचना mytest) {};
}

शून्य stdarg_for_libc(अचर वर्ण *fmt, ...)
{
    बहु_सूची args;
    बहु_शुरू(args, fmt);
    भ_लिखो(fmt, args);
    बहु_पूर्ण(args);
}

शून्य stdarg_syntax(पूर्णाङ्क n, ...)
{
    पूर्णाङ्क i;
    बहु_सूची ap;
    यदि (1)
      बहु_शुरू(ap, n);
    अन्यथा
      ;
    i = बहु_तर्क(ap, पूर्णाङ्क);
    म_लिखो("stdarg_void_expr: %d\n", i);
    (बहु_पूर्ण(ap));
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
    बहु_सूची args;

    म_लिखो ("stdarg_double_struct: %d\n", posd);
    बहु_शुरू(args,posd);
    लागि(i = 0; i < nargs; i++) {
        यदि (i == posd) {
            d = बहु_तर्क (args, द्विगुण);
            म_लिखो ("d %d = %g\n", i, d);
        }
        अन्यथा {
            pi = बहु_तर्क (args, point);
            म_लिखो ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    बहु_पूर्ण(args);
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
    म_लिखो("in getmyaddress\n");
}

#ifdef __LP64__
दीर्घ __pa_symbol(शून्य)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       फर्काऊ ((दीर्घ)(((अचिन्हित दीर्घ)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
शून्य relocation_test(शून्य)
{
    शून्य (*fptr)(शून्य) = (शून्य (*)(शून्य))theaddress;
    म_लिखो("*rel1=%d\n", *rel1);
    म_लिखो("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    म_लिखो("pa_symbol: %d\n", (दीर्घ)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

शून्य old_style_f(a,b,c)
     पूर्णाङ्क a, b;
     द्विगुण c;
{
    म_लिखो("a=%d b=%d b=%f\n", a, b, c);
}

शून्य decl_func1(पूर्णाङ्क cmpfn())
{
    म_लिखो("cmpfn=%lx\n", (दीर्घ)cmpfn);
}

शून्य decl_func2(cmpfn)
पूर्णाङ्क cmpfn();
{
    म_लिखो("cmpfn=%lx\n", (दीर्घ)cmpfn);
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
    म_नकल(p,"123456789012345");
    म_लिखो("alloca: p is %s\n", p);
    वर्ण *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    म_लिखो("alloca: %s\n", म_नकल(alloca(म_माप(demo)+1),demo) );
}

शून्य *bounds_checking_is_enabled()
{
    वर्ण ca[10], *cp = ca-1;
    फर्काऊ (ca != cp + 1) ? cp : रिक्त;
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
    
    म_लिखो("Test C99 VLA 1 (sizeof): ");
    म_लिखो("%s\n", (परिमाण tab1 == size1 * size2 * 2 * परिमाण(पूर्णाङ्क)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    म_लिखो("Test C99 VLA 2 (ptrs subtract): ");
    म_लिखो("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (परिमाण(पूर्णाङ्क) * 2)) ? "PASSED" : "FAILED");
    म_लिखो("Test C99 VLA 3 (ptr add): ");
    म_लिखो("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * परिमाण(पूर्णाङ्क)) ? "PASSED" : "FAILED");
    म_लिखो("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    म_लिखो("%s\n", (*((पूर्णाङ्क *) (tab1_ptr + (size1 * 2 + 1) * परिमाण(पूर्णाङ्क))) == 42) ? "PASSED" : "FAILED");

    म_लिखो("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    यदि (bad_ptr = bounds_checking_is_enabled()) {
        पूर्णाङ्क *t1 = &tab1[size1 * size2 - 1][3];
        पूर्णाङ्क *t2 = &tab2[9][3];
        म_लिखो("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        वर्ण*c1 = 1 + परिमाण(tab1) + (वर्ण*)tab1;
        वर्ण*c2 = 1 + परिमाण(tab2) + (वर्ण*)tab2;
        म_लिखो("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        पूर्णाङ्क *i1 = tab1[-1];
        पूर्णाङ्क *i2 = tab2[-1];
        म_लिखो("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        पूर्णाङ्क *x1 = tab1[size1 * size2 + 1];
        पूर्णाङ्क *x2 = tab2[10 + 1];
        म_लिखो("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } अन्यथा {
        म_लिखो("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    म_लिखो("\n");
}

शून्य c99_vla_test_2(पूर्णाङ्क d, पूर्णाङ्क h, पूर्णाङ्क w)
{
    पूर्णाङ्क x, y, z;
    पूर्णाङ्क (*arr)[h][w] = दो_स्मृति(परिमाण(पूर्णाङ्क) * d*h*w);
    पूर्णाङ्क c = 1;
    स्थिर पूर्णाङ्क (*starr)[h][w];

    म_लिखो("Test C99 VLA 6 (pointer)\n");

    लागि (z=0; z<d; z++) {
        लागि (y=0; y<h; y++) {
            लागि (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    लागि (z=0; z<d; z++) {
        लागि (y=0; y<h; y++) {
            लागि (x=0; x<w; x++) {
                म_लिखो(" %2d", arr[z][y][x]);
            }
            माला_दो("");
        }
        माला_दो("");
    }
    starr = &arr[1];
    म_लिखो(" sizes : %d %d %d\n"
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
    म_लिखो ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3b(पूर्णाङ्क s, पूर्णाङ्क arr[s][3][4])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3c(पूर्णाङ्क s, पूर्णाङ्क arr[2][s][4])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3d(पूर्णाङ्क s, पूर्णाङ्क arr[2][3][s])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

शून्य c99_vla_test_3e(पूर्णाङ्क s, पूर्णाङ्क arr[][3][--s])
{
    म_लिखो ("%d %d %d\n", परिमाण arr, s, arr[1][2][3]);
}

शून्य c99_vla_test_3(शून्य)
{
    पूर्णाङ्क a[2][3][4];

    स_रखो (a, 0, परिमाण(a));
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

    म_लिखो("sizeof(int) = %d\n", परिमाण(पूर्णाङ्क));
    म_लिखो("sizeof(unsigned int) = %d\n", परिमाण(अचिन्हित पूर्णाङ्क));
    म_लिखो("sizeof(long) = %d\n", परिमाण(दीर्घ));
    म_लिखो("sizeof(unsigned long) = %d\n", परिमाण(अचिन्हित दीर्घ));
    म_लिखो("sizeof(short) = %d\n", परिमाण(लघु));
    म_लिखो("sizeof(unsigned short) = %d\n", परिमाण(अचिन्हित लघु));
    म_लिखो("sizeof(char) = %d\n", परिमाण(वर्ण));
    म_लिखो("sizeof(unsigned char) = %d\n", परिमाण(अचिन्हित वर्ण));
    म_लिखो("sizeof(func) = %d\n", परिमाण sizeof_test());
    a = 1;
    म_लिखो("sizeof(a++) = %d\n", परिमाण a++);
    म_लिखो("a=%d\n", a);
    ptr = रिक्त;
    म_लिखो("sizeof(**ptr) = %d\n", परिमाण (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    म_लिखो("sizeof(sizeof(int) = %d\n", परिमाण(परिमाण(पूर्णाङ्क)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -परिमाण(uintptr_t);
    म_लिखो ("%lu %lu\n", t, t2);

    /* some alignof tests */
    म_लिखो("__alignof__(int) = %d\n", __alignof__(पूर्णाङ्क));
    म_लिखो("__alignof__(unsigned int) = %d\n", __alignof__(अचिन्हित पूर्णाङ्क));
    म_लिखो("__alignof__(short) = %d\n", __alignof__(लघु));
    म_लिखो("__alignof__(unsigned short) = %d\n", __alignof__(अचिन्हित लघु));
    म_लिखो("__alignof__(char) = %d\n", __alignof__(वर्ण));
    म_लिखो("__alignof__(unsigned char) = %d\n", __alignof__(अचिन्हित वर्ण));
    म_लिखो("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    म_लिखो("sizeof(char[1+2*a]) = %d\n", परिमाण(वर्ण[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    म_लिखो("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   परिमाण( (संरचना {पूर्णाङ्क i; पूर्णाङ्क j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    म_लिखो("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   परिमाण (संरचना {लघु i; लघु j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    म_लिखो("sizeof(t && 0) = %d\n", परिमाण(t && 0));
    म_लिखो("sizeof(1 && 1) = %d\n", परिमाण(1 && 1));
    म_लिखो("sizeof(t || 1) = %d\n", परिमाण(t || 1));
    म_लिखो("sizeof(0 || 0) = %d\n", परिमाण(0 || 0));

    पूर्णाङ्क arr[4], fn();
    म_लिखो("sizeof(0, arr) = %d\n", परिमाण(0, arr));
    म_लिखो("sizeof(0, fn) = %d\n", परिमाण(0, fn));
}

शून्य typeof_test(शून्य)
{
    द्विगुण a;
    typeof(a) b;
    typeof(भिन्न) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    म_लिखो("a=%f b=%f c=%f\n", a, b, c);
}


संरचना hlist_गाँठो;
संरचना hlist_head {
    संरचना hlist_गाँठो *first, *last;
};

शून्य consume_ulong (अचिन्हित दीर्घ i)
{
    i = 0;
}

शून्य statement_अभिव्यक्ति_test(शून्य)
{
    पूर्णाङ्क a, i;

    /* Basic stmt expr test */
    a = 0;
    लागि(i=0;i<10;i++) {
        a += 1 + 
            ( { पूर्णाङ्क b, j; 
                b = 0; 
                लागि(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    म_लिखो("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    शून्य *v = (शून्य*)39;
    typeof(({
	    (संरचना hlist_गाँठो *)v;
	    })) x;
    typeof (x)
	ptr = (संरचना hlist_गाँठो *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            स्थिर अचर वर्ण *t some_attr = str; \
            t;                                    \
          })
    म_लिखो ("stmtexpr: %s %s\n",
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
	   दीर्घ pre = 48;
	   T t = { (शून्य*)43, (शून्य*)44 };
	   दीर्घ post = 49;
	   t;
	   });
    म_लिखो ("stmtexpr: %d %d %d\n", t, b, c);
    म_लिखो ("stmtexpr: %ld %ld\n", (दीर्घ)h.first, (दीर्घ)h.last);

    /* Test that we can give out addresses of local labels.  */
    consume_ulong(({ __label__ __here; __here: (अचिन्हित दीर्घ)&&__here; }));

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
    म_लिखो("stmtexpr: %d should be 2\n", i);
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
        म_लिखो("aa1\n");
        गच्छ l3;
    l2:
        म_लिखो("aa3\n");
        गच्छ l4;
    l1:
        म_लिखो("aa2\n");
        गच्छ l2;
    l3:;
        1;
    });
    म_लिखो("a=%d\n", a);
    फर्काऊ;
 l4:
    म_लिखो("bb1\n");
    गच्छ l2;
 l1:
    म_लिखो("bb2\n");
    गच्छ l4;
}

/* inline assembler test */
#यदि (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

प्रकारनिर्देश __SIZE_TYPE__ word;

/* from linux kernel */
स्थिर वर्ण * strncat1(वर्ण * dest,अचर वर्ण * src,माप_प्रकार गन्ती_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (गन्ती_2)
	: "memory");
फर्काऊ dest;
}

स्थिर वर्ण * strncat2(वर्ण * dest,अचर वर्ण * src,माप_प्रकार गन्ती_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (गन्ती_2)
	: "memory");
फर्काऊ dest;
}

स्थिर अन्तःस्थ शून्य * memcpy1(शून्य * to, अचर शून्य * from, माप_प्रकार n)
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
फर्काऊ (to);
}

स्थिर अन्तःस्थ शून्य * memcpy2(शून्य * to, अचर शून्य * from, माप_प्रकार n)
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
फर्काऊ (to);
}

स्थिर __inline__ शून्य sigaddset1(अचिन्हित पूर्णाङ्क *set, पूर्णाङ्क _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

स्थिर __inline__ शून्य sigdelset1(अचिन्हित पूर्णाङ्क *set, पूर्णाङ्क _sig)
{
	यंत्र("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
स्थिर __inline__ __const__ अचिन्हित पूर्णाङ्क swab32(अचिन्हित पूर्णाङ्क x)
{
        फर्काऊ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#अन्यथा
स्थिर __inline__ __const__ अचिन्हित पूर्णाङ्क swab32(अचिन्हित पूर्णाङ्क x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	फर्काऊ x;
}
#endif

स्थिर __inline__ अचिन्हित दीर्घ दीर्घ mul64(अचिन्हित पूर्णाङ्क a, अचिन्हित पूर्णाङ्क b)
{
    अचिन्हित दीर्घ दीर्घ res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    अचिन्हित पूर्णाङ्क resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((अचिन्हित दीर्घ दीर्घ)resh << 32) | resl;
#अन्यथा
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    फर्काऊ res;
}

स्थिर __inline__ अचिन्हित दीर्घ दीर्घ inc64(अचिन्हित दीर्घ दीर्घ a)
{
    अचिन्हित दीर्घ दीर्घ res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#अन्यथा
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    फर्काऊ res;
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
    अचिन्हित पूर्णाङ्क a[2];
    a[0] = 0;
    __asm__ चञ्चल ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(संरचना struct123 *)r->addr));
    फर्काऊ ret + a[0];
}

#ifdef __x86_64__
पूर्णाङ्क fls64(अचिन्हित दीर्घ दीर्घ x)
{
  पूर्णाङ्क bitpos = -1;
  यंत्र("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  फर्काऊ bitpos + 1;
}
#endif

शून्य other_constraints_test(शून्य)
{
    word ret;
    पूर्णाङ्क var;
#यदि CC_NAME != CC_clang
    __asm__ चञ्चल ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    म_लिखो ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
शून्य base_func(शून्य)
{
  म_लिखो ("asmc: base\n");
}

#ifndef __APPLE__
बाह्य शून्य override_func1 (शून्य);
बाह्य शून्य override_func2 (शून्य);

यंत्र(".weak override_func1\n.set override_func1, base_func");
यंत्र(".set override_func1, base_func");
यंत्र(".set override_func2, base_func");

शून्य override_func2 (शून्य)
{
  म_लिखो ("asmc: override2\n");
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
  बाह्य पूर्णाङ्क some_चिह्न;
  यंत्र चञ्चल (".globl some_symbol\n"
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
  फर्काऊ str;
#अन्यथा
  फर्काऊ (वर्ण *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
बाह्य अचिन्हित वर्ण alld_stuff[];
यंत्र(".data\n"
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
  म_लिखो ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
शून्य asm_local_statics (शून्य)
{
  स्थिर पूर्णाङ्क localint = 41;
  यंत्र("incl %0" : "+m" (localint));
  म_लिखो ("asm_local_statics: %d\n", localint);
}

स्थिर
अचिन्हित पूर्णाङ्क set;

शून्य fancy_copy (अचिन्हित *in, अचिन्हित *out)
{
  यंत्र चञ्चल ("" : "=r" (*out) : "0" (*in));
}

शून्य fancy_copy2 (अचिन्हित *in, अचिन्हित *out)
{
  यंत्र चञ्चल ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#यदि defined __x86_64__
शून्य clobber_r12(शून्य)
{
    यंत्र चञ्चल("mov $1, %%r12" ::: "r12");
}
#endif

शून्य test_माथिल्लो_clobbers_really(शून्य)
{
#यदि defined __x86_64__
    पञ्जिका word val यंत्र("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    यंत्र चञ्चल("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    यंत्र चञ्चल("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    म_लिखो("asmhc: 0x%x\n", val2);
#endif
}

शून्य test_माथिल्लो_clobbers(शून्य)
{
#यदि defined __x86_64__
    word x1, x2;
    यंत्र चञ्चल("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_माथिल्लो_clobbers_really();
    यंत्र चञ्चल("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    यंत्र चञ्चल("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

स्थिर दीर्घ cpu_सङ्ख्या;
शून्य trace_console(दीर्घ len, दीर्घ len2)
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
              दीर्घ pscr_ret__;
              विकल्प(len) {
                पक्ष 4:
                    {
                       दीर्घ pfo_ret__;
                       विकल्प (len2) {
                         पक्ष 8:	म_लिखो("bla"); pfo_ret__ = 42; रोक;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  रोक;
                पक्ष 8:
                    {
                       दीर्घ pfo_ret__;
                       विकल्प (len2) {
                         पक्ष 1:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	रोक;
                         पक्ष 2:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	रोक;
                         पक्ष 4:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	रोक;
                         पक्ष 8:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_सङ्ख्या));	रोक;
                         स्वभाव: म_लिखो("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  रोक;
              }
              pscr_ret__;
            }))
      {
        म_लिखो("huh?\n");
      }
#endif
}

शून्य test_asm_dead_code(शून्य)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  यंत्र चञ्चल ("" : "=D" (rdi) : "0" (0));
  (शून्य)परिमाण (({
      पूर्णाङ्क var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      यंत्र चञ्चल ("movl $0,(%0)" : : "D" (&var) : "memory");
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
  यंत्र चञ्चल ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#यदि 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#अन्यथा
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  म_लिखो("asmd: %s\n", s);
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
    लागि (x = 1;; ++x) {
        पूर्णाङ्क r = x;
        विकल्प (x) {
        पक्ष 1:
            यंत्र(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        पक्ष 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            यंत्र(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#अन्यथा
            यंत्र(".text; mov $123, %eax; jmp p0");
#endif
	पक्ष 3:
#यदि !defined(_WIN32) && !defined(__clang__)
            यंत्र(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#अन्यथा
            यंत्र(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            यंत्र(".text; mov X"RX",%eax; jmp p0");
        पक्ष 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            यंत्र(".text; mov $789,%eax; jmp p0");
#अन्यथा
#ifndef _WIN32
            यंत्र(".data; X=.; .int 789; Y=.; .int 999; .previous");
#अन्यथा
            यंत्र(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            यंत्र(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        पक्ष 0:
	    यंत्र(".text; p0=.; mov %%eax,%0;" : "=m"(r)); रोक;
	}
        यदि (r == x)
            रोक;
        म_लिखो("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

शून्य asm_pcrel_test(शून्य)
{
    अचिन्हित o1, o2;
    /* subtract text-section label from forward or other-section label */
    यंत्र("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    यंत्र("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    यंत्र("mov %%eax,%0" : "=m"(o2));
    म_लिखो("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

शून्य asm_test(शून्य)
{
    वर्ण buf[128];
    अचिन्हित पूर्णाङ्क val, val2;
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
    पञ्जिका पूर्णाङ्क regvar यंत्र("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    यंत्र चञ्चल ("mov $0x1E-1,%eax");

    /* test the no operand case */
    यंत्र चञ्चल ("xorl %eax, %eax");

    memcpy1(buf, "hello", 6);
    strncat1(buf, " worldXXXXX", 3);
    म_लिखो("%s\n", buf);

    memcpy2(buf, "hello", 6);
    strncat2(buf, " worldXXXXX", 3);
    म_लिखो("%s\n", buf);

    /* 'A' constraint test */
    म_लिखो("mul64=0x%Lx\n", mul64(0x12345678, 0xabcd1234));
    म_लिखो("inc64=0x%Lx\n", inc64(0x12345678ffffffff));

    s1.a = 42;
    s1.b = 43;
    म_लिखो("mconstraint: %d", mconstraint_test(&s2));
    म_लिखो(" %d %d\n", s1.a, s1.b);
    other_constraints_test();
    set = 0xff;
    sigdelset1(&set, 2);
    sigaddset1(&set, 16);
    /* NOTE: we test here if C labels are correctly restored after the
       asm statement */
    गच्छ label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(set) : "Ir"(20) : "cc");
    म_लिखो("set=0x%x\n", set);
    val = 0x01020304;
    म_लिखो("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#ifndef _WIN32
#ifndef __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    यंत्र चञ्चल(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    म_लिखो("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#endif
#endif
    asm_local_statics();
#ifndef __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    यंत्र चञ्चल("" : "=r" (asmret) : "0"(s2));
    यदि (asmret != s2.addr)
      म_लिखो("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    यंत्र चञ्चल("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    यदि (!somebool)
      म_लिखो("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    म_लिखो ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    म_लिखो ("fancycpy2(%d)=%d\n", val, val2);
    यंत्र चञ्चल ("mov $0x4243, %%esi" : "=r" (regvar));
    म_लिखो ("regvar=%x\n", regvar);
    test_माथिल्लो_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    फर्काऊ;
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
    म_लिखो("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

पूर्णाङ्क constant_p_var;

पूर्णाङ्क func(शून्य);


/* __builtin_clz and __builtin_ctz return random values for 0 */
स्थिर शून्य builtin_test_bits(अचिन्हित दीर्घ दीर्घ x, पूर्णाङ्क cnt[])
{
#यदि GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    यदि ((अचिन्हित पूर्णाङ्क) x) cnt[3] += __builtin_clz(x);
    यदि ((अचिन्हित दीर्घ) x) cnt[4] += __builtin_clzl(x);
    यदि ((अचिन्हित दीर्घ दीर्घ) x) cnt[5] += __builtin_clzll(x);

    यदि ((अचिन्हित पूर्णाङ्क) x) cnt[6] += __builtin_ctz(x);
    यदि ((अचिन्हित दीर्घ) x) cnt[7] += __builtin_ctzl(x);
    यदि ((अचिन्हित दीर्घ दीर्घ) x) cnt[8] += __builtin_ctzll(x);

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
    लघु s;
    पूर्णाङ्क i;
    दीर्घ दीर्घ ll;
#यदि GCC_MAJOR >= 3
    COMPAT_TYPE(पूर्णाङ्क, पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, अचिन्हित पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, वर्ण);
    COMPAT_TYPE(पूर्णाङ्क, अचर पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क, चञ्चल पूर्णाङ्क);
    COMPAT_TYPE(पूर्णाङ्क[2], अचर पूर्णाङ्क[2]);
    COMPAT_TYPE(पूर्णाङ्क[2][3], चञ्चल पूर्णाङ्क[][3]);
    COMPAT_TYPE(पूर्णाङ्क (*)[], अचर पूर्णाङ्क (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (अचर पूर्णाङ्क (*)[2])0 : (पूर्णाङ्क (*)[2])0),
                अचर पूर्णाङ्क (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (अचर पूर्णाङ्क (*)[2][3])0 :
                              (चञ्चल पूर्णाङ्क (*)[2][3])0),
                अचर चञ्चल पूर्णाङ्क (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (चञ्चल पूर्णाङ्क (*)[2][3])0 :
                              (अचर पूर्णाङ्क (*)[2][3])0),
                अचर चञ्चल पूर्णाङ्क (*)[2][3]);
#अन्यथा
    /* clang doesn't combine qualifiers through array types */
    म_लिखो("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    म_लिखो("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    म_लिखो("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(पूर्णाङ्क *, पूर्णाङ्क *);
    COMPAT_TYPE(पूर्णाङ्क *, शून्य *);
    COMPAT_TYPE(पूर्णाङ्क *, अचर पूर्णाङ्क *);
    COMPAT_TYPE(वर्ण *, अचिन्हित वर्ण *);
    COMPAT_TYPE(वर्ण *, चिन्हित वर्ण *);
    COMPAT_TYPE(वर्ण *, वर्ण *);
    COMPAT_TYPE(वर्ण **, शून्य *);
#endif
    म_लिखो("res1 = %d\n", __builtin_constant_p(1));
    म_लिखो("res2 = %d\n", __builtin_constant_p(1 + 2));
    म_लिखो("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    म_लिखो("res4 = %d\n", __builtin_constant_p(constant_p_var));
    म_लिखो("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    म_लिखो("res6 = %d\n", __builtin_constant_p(i && 1));
    म_लिखो("res7 = %d\n", __builtin_constant_p("hi"));
    म_लिखो("res8 = %d\n", __builtin_constant_p(func()));
#ifndef __clang__
    म_लिखो("res10 = %d\n", __builtin_constant_p(i && 0));
    म_लिखो("res11 = %d\n", __builtin_constant_p(i * 0));
    म_लिखो("res12 = %d\n", __builtin_constant_p(i && 0 ? i : 34));
    म_लिखो("res13 = %d\n", __builtin_constant_p((1,7)));
#अन्यथा
    /* clang doesn't regard these as constant expression */
    म_लिखो("res10 = 1\n");
    म_लिखो("res11 = 1\n");
    म_लिखो("res12 = 1\n");
    म_लिखो("res13 = 0\n");
#endif

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    म_लिखो("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    म_लिखो("bce: %d\n", i);
    i = परिमाण (__builtin_choose_expr (1, ll, s));
    म_लिखो("bce: %d\n", i);
    i = परिमाण (__builtin_choose_expr (0, ll, s));
    म_लिखो("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	पूर्णाङ्क cnt[18];
	अचिन्हित दीर्घ दीर्घ r = 0;

	स_रखो(cnt, 0, परिमाण(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        लागि (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        लागि (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	लागि (i = 0; i < 18; i++)
	    म_लिखो ("%d %d\n", i, cnt[i]);
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

बाह्य पूर्णाङ्क                     weak_asm_f1(शून्य) यंत्र("weak_asm_f1x") __attribute((weak));
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_f2(शून्य) यंत्र("weak_asm_f2x")                    ;
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_f3(शून्य) यंत्र("weak_asm_f3x") __attribute((weak));
बाह्य पूर्णाङ्क                     weak_asm_v1       यंत्र("weak_asm_v1x") __attribute((weak));
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_v2       यंत्र("weak_asm_v2x")                    ;
बाह्य पूर्णाङ्क __attribute((weak)) weak_asm_v3(शून्य) यंत्र("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
स्थिर अचर माप_प्रकार dummy = 0;
बाह्य __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
बाह्य __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
बाह्य __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

पूर्णाङ्क some_lib_func(शून्य);
पूर्णाङ्क dummy_impl_of_slf(शून्य) { फर्काऊ 444; }
#ifndef __clang__
पूर्णाङ्क some_lib_func(शून्य) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

पूर्णाङ्क weak_toolate() __attribute__((weak));
पूर्णाङ्क weak_toolate() { फर्काऊ 0; }

शून्य __attribute__((weak)) weak_test(शून्य)
{
	म_लिखो("weak_f1=%d\n", weak_f1 ? weak_f1() : 123);
	म_लिखो("weak_f2=%d\n", weak_f2 ? weak_f2() : 123);
	म_लिखो("weak_f3=%d\n", weak_f3 ? weak_f3() : 123);
	म_लिखो("weak_v1=%d\n",&weak_v1 ? weak_v1   : 123);
	म_लिखो("weak_v2=%d\n",&weak_v2 ? weak_v2   : 123);
	म_लिखो("weak_v3=%d\n",&weak_v3 ? weak_v3   : 123);

	म_लिखो("weak_fpa=%d\n",&weak_fpa ? weak_fpa() : 123);
	म_लिखो("weak_fpb=%d\n",&weak_fpb ? weak_fpb() : 123);
	म_लिखो("weak_fpc=%d\n",&weak_fpc ? weak_fpc() : 123);
	
	म_लिखो("weak_asm_f1=%d\n", weak_asm_f1 != रिक्त);
	म_लिखो("weak_asm_f2=%d\n", weak_asm_f2 != रिक्त);
	म_लिखो("weak_asm_f3=%d\n", weak_asm_f3 != रिक्त);
	म_लिखो("weak_asm_v1=%d\n",&weak_asm_v1 != रिक्त);
	म_लिखो("weak_asm_v2=%d\n",&weak_asm_v2 != रिक्त);
	म_लिखो("weak_asm_v3=%d\n",&weak_asm_v3 != रिक्त);
#ifdef __clang__
	म_लिखो("some_lib_func=444\n");
#अन्यथा
	म_लिखो("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

पूर्णाङ्क __attribute__((weak)) weak_f2() { फर्काऊ 222; }
पूर्णाङ्क __attribute__((weak)) weak_f3() { फर्काऊ 333; }
पूर्णाङ्क __attribute__((weak)) weak_v2 = 222;
पूर्णाङ्क __attribute__((weak)) weak_v3 = 333;
#endif

शून्य const_func(अचर पूर्णाङ्क a)
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
  फर्काऊ i1 + i2 + i3 + i4;
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
  फर्काऊ *p + i;
}

शून्य global_data_test (शून्य)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  म_लिखो ("%d\n", global_data.a[0]);
}

संरचना cmpcmpS
{
  अचिन्हित वर्ण fill : 3;
  अचिन्हित वर्ण b1 : 1;
  अचिन्हित वर्ण b2 : 1;
  अचिन्हित वर्ण fill2 : 3;
};

पूर्णाङ्क glob1, glob2, glob3;

शून्य compare_comparisons (संरचना cmpcmpS *s)
{
  यदि (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    म_लिखो ("comparing comparisons broken\n");
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
    पक्ष 0: फर्काऊ a == b;
    पक्ष 1: फर्काऊ a != b;
    पक्ष 2: फर्काऊ a < b;
    पक्ष 3: फर्काऊ a >= b;
    पक्ष 4: फर्काऊ a > b;
    पक्ष 5: फर्काऊ a <= b;
  }
  फर्काऊ 0;
}

शून्य math_cmp_test(शून्य)
{
  द्विगुण nan = 0.0/0.0;
  द्विगुण one = 1.0;
  द्विगुण two = 2.0;
  पूर्णाङ्क comp = 0;
  पूर्णाङ्क v;
#define bug(a,b,op,iop,part) म_लिखो("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

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

द्विगुण get100 () { फर्काऊ 100.0; }

शून्य callsave_test(शून्य)
{
  पूर्णाङ्क i, s; द्विगुण *d; द्विगुण t;
  s = परिमाण (द्विगुण);
  म_लिखो ("callsavetest: %d\n", s);
  d = alloca (परिमाण(द्विगुण));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  म_लिखो ("%d\n", i);
}


शून्य bfa3(सूचक_भेद_प्रकार str_offset)
{
    म_लिखो("bfa3: %s\n", (वर्ण *)__builtin_frame_address(3) + str_offset);
}
शून्य bfa2(सूचक_भेद_प्रकार str_offset)
{
    म_लिखो("bfa2: %s\n", (वर्ण *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
शून्य bfa1(सूचक_भेद_प्रकार str_offset)
{
    म_लिखो("bfa1: %s\n", (वर्ण *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

शून्य builtin_frame_address_test(शून्य)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    वर्ण str[] = "__builtin_frame_address";
    वर्ण *fp0 = __builtin_frame_address(0);

    म_लिखो("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

वर्ण via_volatile (वर्ण i)
{
  वर्ण चञ्चल vi;
  vi = i;
  फर्काऊ vi;
}

शून्य volatile_test(शून्य)
{
    यदि (via_volatile (42) != 42)
      म_लिखो (" broken\n");
    अन्यथा
      म_लिखो (" ok\n");
}

संरचना __attribute__((__packed__)) Spacked {
    वर्ण a;
    लघु b;
    पूर्णाङ्क c;
};
संरचना Spacked spacked;
प्रकारनिर्देश संरचना __attribute__((__packed__)) {
    वर्ण a;
    लघु b;
    पूर्णाङ्क c;
} Spacked2;
Spacked2 spacked2;
प्रकारनिर्देश संरचना Spacked3_s {
    वर्ण a;
    लघु b;
    पूर्णाङ्क c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
संरचना gate_struct64 {
    अचिन्हित लघु offset_तल्लो;
    अचिन्हित लघु segment;
    अचिन्हित ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    अचिन्हित लघु offset_बीच;
    अचिन्हित offset_माथिल्लो;
    अचिन्हित zero1;
} __attribute__((packed));
प्रकारनिर्देश संरचना gate_struct64 gate_desc;
gate_desc a_gate_desc;
शून्य attrib_test(शून्य)
{
#ifndef _WIN32
  म_लिखो("attr: %d %d %d %d\n", परिमाण(संरचना Spacked),
	 परिमाण(spacked), परिमाण(Spacked2), परिमाण(spacked2));
  म_लिखो("attr: %d %d\n", परिमाण(Spacked3), परिमाण(spacked3));
  म_लिखो("attr: %d %d\n", परिमाण(gate_desc), परिमाण(a_gate_desc));
#endif
}
बाह्य __attribute__((__unused__)) वर्ण * __attribute__((__unused__)) *
strange_attrib_placement (शून्य);

शून्य * __attribute__((__unused__)) get_void_ptr (शून्य *a)
{
  फर्काऊ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
स्थिर अन्तःस्थ
पूर्णाङ्क __get_order(अचिन्हित दीर्घ दीर्घ size)
{
  पूर्णाङ्क order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      संरचना S { पूर्णाङ्क i : 1; } s; // constructed for this '1'
    }
  order = size;
  फर्काऊ order;
}

/* This just forces the above inline function to be actually emitted.  */
पूर्णाङ्क force_get_order(अचिन्हित दीर्घ s)
{
    फर्काऊ __get_order(s);
}

#define pv(m) म_लिखो(परिमाण (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

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
शून्य map_add(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c, पूर्णाङ्क d, पूर्णाङ्क e, पूर्णाङ्क f, पूर्णाङ्क g, पूर्णाङ्क h, पूर्णाङ्क i)
{
  म_लिखो ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
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
    म_लिखो("len1=%d\n", म_माप("
"));
#ifdef CORRECT_CR_HANDLING
    str = "
";
    म_लिखो("len1=%d str[0]=%d\n", म_माप(str), str[0]);
#endif
    म_लिखो("len1=%d\n", म_माप("a
"));
#अन्यथा
    म_लिखो("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    म_लिखो("__LINE__ defined\n");
#endif

#यदि 0
    /* wrong with GCC */
    म_लिखो("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#line 1111
    म_लिखो("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#line 2222 "test"
    म_लिखो("__LINE__=%d __FILE__=%s\n", __LINE__, __FILE__);
#endif

    म_लिखो("\\
"12\\
063\\
n 456\"\n");

    म_लिखो ("%d\n",
#यदि 1
	    tcc_test
#endif
            );

}

#define RUN(test) माला_दो("---- " #test " ----"), test(), माला_दो("")

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(अभिव्यक्ति_test);
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
    RUN(अभिव्यक्ति_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_अभिव्यक्ति_test);
    RUN(अभिव्यक्ति_cmp_test);
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
    RUN(statement_अभिव्यक्ति_test);
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

    फर्काऊ 0;
}
