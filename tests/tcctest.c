/*
 * TCC auto test program
 */
#அந்தர்பாவ "config.h"

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

#எனில் defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#இல்லையெனில்
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#எனில் defined(_WIN32)
#define LONG_DOUBLE இரட்டை
#define LONG_DOUBLE_LITERAL(x) x
#இல்லையெனில்
#define LONG_DOUBLE long இரட்டை
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

வகைவரை __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#அந்தர்பாவ TCCLIB_INC

#அந்தர்பாவ TCCLIB_INC1.TCCLIB_INC2

#அந்தர்பாவ TCCLIB_INC1.h>

#அந்தர்பாவ TCCLIB_INC3

#அந்தர்பாவ <tcclib.h>

#அந்தர்பாவ "tcclib.h"

#அந்தர்பாவ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#இல்லையெனில்
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#அந்தர்பாவ INC(42test)
#அந்தர்பாவ incname
#அந்தர்பாவ stringify(funnyname)

முழு fib(முழு n);
வெறுமை இலக்கம்(முழு n);
வெறுமை forward_ref(வெறுமை);
முழு isid(முழு c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
வெறுமை funny_வரி_continuation (முழு, ..\
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
#define கீழ்_2 கீழ்_2 ", world"

நிலையான முழு onetwothree = 123;
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

#எனில் 1
#define B3 1
#அல்லதெனில் 1
#define B3 2
#அல்லதெனில் 0
#define B3 3
#இல்லையெனில்
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

முழு qq(முழு x)
{
    திரும்பு x + 40;
}
#define qq(x) x

#define spin_lock(lock) செய் { } போது (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

வெறுமை macro_test(வெறுமை)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(உயர்வு_2, கீழ்_2));
    printf("s2=%s\n", xglue(உயர்வு_2, கீழ்_2));
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
#இல்லையெனில்
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#இல்லையெனில்
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#இல்லையெனில்
    printf("B1 not defined\n");
#endif
#இல்லையெனில்
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#இல்லையெனில்
    printf("B2 not defined\n");
#endif
#endif

#எனில் 1+1
    printf("test true1\n");
#endif
#எனில் 0
    printf("test true2\n");
#endif
#எனில் 1-1
    printf("test true3\n");
#endif
#எனில் defined(A)
    printf("test trueA\n");
#endif
#எனில் defined(B)
    printf("test trueB\n");
#endif

#எனில் 0
    printf("test 0\n");
#அல்லதெனில் 0
    printf("test 1\n");
#அல்லதெனில் 2
    printf("test 2\n");
#இல்லையெனில்
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
        முழு a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(செய்தி) printf("%s\n",செய்தி)

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
#எனில் !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      மாறிலி எழுத்து *fn = get_file_from_header();
      எனில் (fn[0] == '.' && fn[1] == '/')
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


நிலையான வெறுமை print_இலக்கம்(எழுத்து *fn, முழு வரி, முழு இலக்கம்) {
    printf("fn %s, line %d, num %d\n", fn, வரி, இலக்கம்);
}

வெறுமை recursive_macro_test(வெறுமை)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_இலக்கம்(x) print_இலக்கம்(__FILE__,__LINE__,x)
    print_இலக்கம்(123);
    WRAP(print_இலக்கம்(123));
    WRAP(WRAP(print_இலக்கம்(123)));

நிலையான கட்டமைப்பு recursive_macro { முழு rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#எனில் __TINYC__
முழு op(a, b)
{
    திரும்பு a / b;
}

முழு ret(a)
{
    எனில் (a == 2)
        திரும்பு 1;
    எனில் (a == 3)
        திரும்பு 2;
    திரும்பு 0;
}
#endif

#எனில் !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
எழுத்து str_ag1[] = "b";
எழுத்து str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
எழுத்து str_ag3[] = { "ab"[1], 0 };
எழுத்து str_x[2] = { "xy" "z"[2], 0 };
#endif
எழுத்து *str_ar[] = { "one", "two" };
கட்டமைப்பு str_SS {unsigned எழுத்து a[3], b; };
கட்டமைப்பு str_SS str_sinit15 = { "r" };
கட்டமைப்பு str_SS str_sinit16[] = { { "q" }, 2 };

நிலையான வெறுமை string_test2()
{
    எழுத்து *p = "hello";
    எழுத்து a3[2] = { "p" };
    எழுத்து a4[2] = { "ab" "c"[2], 0 };
    எழுத்து *pa1 = "def" + 1;
    எழுத்து *pa2 = { "xyz" + 1 };
    முழு i = 0;
    கட்டமைப்பு str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    எழுத்து str_ag3[] = { "ab"[1], 0 };
    எழுத்து str_x[2] = { "xy" "z"[2], 0 };
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

வெறுமை ps(மாறிலி எழுத்து *s)
{
    முழு c;
    போது (1) {
        c = *s;
        எனில் (c == 0)
            நிறுத்து;
        printf("%c", c);
        s++;
    }
}

மாறிலி எழுத்து foo1_string[] = "\
bar\n\
test\14\
1";

வெறுமை string_test()
{
    unsigned முழு b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#எனில் 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    போது ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    போது (b != 0x80000000) {
        இலக்கம்(b);
        b = b * 2;
    }
    string_test2();
}


வெறுமை if1t(முழு n, முழு a, முழு b, முழு c)
{
    எனில் (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    எனில் (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    எனில் (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    எனில் (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    எனில் (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    எனில் (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    எனில் (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    எனில் (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    எனில் (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    எனில் (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    எனில் (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    எனில் (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    எனில் (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    எனில் (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

வெறுமை if2t(வெறுமை)
{
    எனில் (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

வெறுமை if3t(வெறுமை)
{
    நிலையற்ற long long i = 1;
    எனில் (i <= 18446744073709551615ULL)
      ;
    இல்லையெனில்
      printf ("if3t:wrong 1\n");
}

வெறுமை if_test(வெறுமை)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

வெறுமை loop_test()
{
    முழு i;
    i = 0;
    போது (i < 10)
        printf("%d", i++);
    printf("\n");
    க்கு(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    செய் {
        printf("%d", i++);
    } போது (i < 10);
    printf("\n");

    எழுத்து மொத்தம்_2 = 123;
    /* c99 for loop init test */
    க்கு (size_t மொத்தம்_2 = 1; மொத்தம்_2 < 3; மொத்தம்_2++)
        printf("count=%d\n", மொத்தம்_2);
    printf("count = %d\n", மொத்தம்_2);

    /* break/continue tests */
    i = 0;
    போது (1) {
        எனில் (i == 6)
            நிறுத்து;
        i++;
        எனில் (i == 3)
            தொடர்;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    செய் {
        எனில் (i == 6)
            நிறுத்து;
        i++;
        எனில் (i == 3)
            தொடர்;
        printf("%d", i);
    } போது(1);
    printf("\n");

    க்கு(i = 0;i < 10;i++) {
        எனில் (i == 3)
            தொடர்;
        printf("%d", i);
    }
    printf("\n");
}

வகைவரை முழு typedef_and_label;

வெறுமை goto_test()
{
    முழு i;
    நிலையான வெறுமை *label_table[3] = { &&label1, &&label2, &&label3 };
    கட்டமைப்பு {
        முழு bla;
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
    எனில் (i >= 10) 
        செல் s_end;
    printf("%d", i);
    i++;
    செல் s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    க்கு(i=0;i<3;i++) {
        செல் *label_table[i];
    label1:
        printf("label1\n");
        செல் next;
    label2:
        printf("label2\n");
        செல் next;
    label3:
        printf("label3\n");
    next: ;
    }
}

எண்ணிக்கை {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

எண்ணிக்கை test {
    E5 = 1000,
};

கட்டமைப்பு S_enum {
    எண்ணிக்கை {E6 = 42, E7, E8} e:8;
};

எண்ணிக்கை ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

எண்ணிக்கை { BIASU = -1U<<31 };
எண்ணிக்கை { BIASS = -1 << 31 };

நிலையான முழு getint(முழு i)
{
  எனில் (i)
    திரும்பு 0;
  இல்லையெனில்
    திரும்பு (முழு)(-1U << 31);
}

வெறுமை enum_test()
{
    எண்ணிக்கை test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    கட்டமைப்பு S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    எனில் (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    இல்லையெனில்
      printf("enum unsigned: wrong\n");
    எனில் (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    இல்லையெனில்
      printf("enum unsigned: wrong\n");
}

வகைவரை முழு *my_ptr;

வகைவரை முழு mytype1;
வகைவரை முழு mytype2;

வெறுமை typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    முழு b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

வெறுமை forward_test()
{
    forward_ref();
    forward_ref();
}


வெறுமை forward_ref(வெறுமை)
{
    printf("forward ok\n");
}

வகைவரை கட்டமைப்பு struct1 {
    முழு f1;
    முழு f2, f3;
    ஒன்றிப்பு union1 {
        முழு v1;
        முழு v2;
    } u;
    எழுத்து str[3];
} struct1;

கட்டமைப்பு struct2 {
    முழு a;
    எழுத்து b;
};

ஒன்றிப்பு union2 {
    முழு w1;
    முழு w2;
};

கட்டமைப்பு struct1 st1, st2;

கட்டமைப்பு empty_mem {
    /* nothing */ ;
    முழு x;
};

முழு tab[3];
முழு tab2[3][2];

முழு g;

வெறுமை f1(முழு g)
{
    printf("g1=%d\n", g);
}

வெறுமை scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        முழு g;
        g = 3;
        printf("g3=%d\n", g);
        {
            முழு g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

முழு st2_i;
முழு *st2_p = &st2_i;
வெறுமை scope2_test()
{
    எழுத்து a[50];
    st2_i = 42;
    க்கு (முழு st2_i = 1; st2_i < 10; st2_i++) {
        வெளி முழு st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
வெளி முழு st_global1;
முழு st_global1=42;
வெளி முழு st_global1;
முழு st_global1;
வெளி முழு st_global2;
முழு st_global2;
வெளி முழு st_global2;
முழு st_global2;

வெறுமை array_test()
{
    முழு i, j, a[4];

    printf("sizeof(a) = %d\n", அளவு(a));
    printf("sizeof(\"a\") = %d\n", அளவு("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", அளவு(__func__));
#endif
    printf("sizeof tab %d\n", அளவு(tab));
    printf("sizeof tab2 %d\n", அளவு tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    க்கு(i=0;i<3;i++)
        க்கு(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    க்கு(i=0;i<3*2;i++) {
        printf(" %3d", ((முழு *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", அளவு(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", அளவு(ptrdiff_t));
}

வெறுமை கோவை_test()
{
    முழு a, b;
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

முழு isid(முழு c)
{
    திரும்பு (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

முழு vstack[10], *vstack_ptr;

வெறுமை vpush(முழு vt, முழு vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

வெறுமை vpop(முழு *ft, முழு *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

வெறுமை expr2_test()
{
    முழு a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

முழு const_len_ar[அளவு(1/0)]; /* div-by-zero, but in unevaluated context */

வெறுமை constant_கோவை_test()
{
    முழு a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", அளவு(const_len_ar));
}

முழு tab4[10];

வெறுமை கோவை_ptr_test()
{
    முழு arr[10], *p, *q;
    முழு i = -1;

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
    p = (முழு *)((எழுத்து *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        கட்டமைப்பு size12 {
            முழு i, j, k;
        };
        கட்டமைப்பு size12 s[2], *sp = s;
        முழு i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (முழு*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (முழு)((p - q) / 3));
}

வெறுமை கோவை_cmp_test()
{
    முழு a, b;
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

கட்டமைப்பு empty {
};

கட்டமைப்பு aligntest1 {
    எழுத்து a[10];
};

கட்டமைப்பு aligntest2 {
    முழு a;
    எழுத்து b[10];
};

கட்டமைப்பு aligntest3 {
    இரட்டை a, b;
};

கட்டமைப்பு aligntest4 {
    இரட்டை a[0];
};

கட்டமைப்பு __attribute__((aligned(16))) aligntest5
{
    முழு i;
};
கட்டமைப்பு aligntest6
{
    முழு i;
} __attribute__((aligned(16)));
கட்டமைப்பு aligntest7
{
    முழு i;
};
கட்டமைப்பு aligntest5 altest5[2];
கட்டமைப்பு aligntest6 altest6[2];
முழு pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
கட்டமைப்பு aligntest7 altest7[2] __attribute__((aligned(16)));

கட்டமைப்பு aligntest8
{
  முழு i;
} __attribute__((aligned(4096)));

கட்டமைப்பு Large {
    unsigned long flags;
    ஒன்றிப்பு {
	வெறுமை *u1;
	முழு *u2;
    };

    கட்டமைப்பு {
	ஒன்றிப்பு {
	    unsigned long index;
	    வெறுமை *freelist;
	};
	ஒன்றிப்பு {
	    unsigned long counters;
	    கட்டமைப்பு {
		முழு bla;
	    };
	};
    };

    ஒன்றிப்பு {
	கட்டமைப்பு {
	    long u3;
	    long u4;
	};
	வெறுமை *u5;
	கட்டமைப்பு {
	    unsigned long compound_head;
	    unsigned முழு compound_dtor;
	    unsigned முழு compound_order;
	};
    };
} __attribute__((aligned(2 * அளவு(long))));

வகைவரை unsigned long long __attribute__((aligned(4))) unaligned_u64;

கட்டமைப்பு aligntest9 {
    unsigned முழு buf_nr;
    unaligned_u64 start_lba;
};

கட்டமைப்பு aligntest10 {
    unsigned முழு buf_nr;
    unsigned long long start_lba;
};

வெறுமை struct_test()
{
    struct1 *s;
    ஒன்றிப்பு union2 u;
    கட்டமைப்பு Large ls;

    printf("sizes: %d %d %d %d\n",
           அளவு(கட்டமைப்பு struct1),
           அளவு(கட்டமைப்பு struct2),
           அளவு(ஒன்றிப்பு union1),
           அளவு(ஒன்றிப்பு union2));
    printf("offsets: %d\n", (முழு)((எழுத்து*)&st1.u.v1 - (எழுத்து*)&st1));
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
    printf("str_addr=%x\n", (முழு)(uintptr_t)st1.str - (முழு)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest1), __alignof__(கட்டமைப்பு aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest2), __alignof__(கட்டமைப்பு aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest3), __alignof__(கட்டமைப்பு aligntest3));
#எனில் !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest4), __alignof__(கட்டமைப்பு aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest5), __alignof__(கட்டமைப்பு aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest6), __alignof__(கட்டமைப்பு aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest7), __alignof__(கட்டமைப்பு aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest8), __alignof__(கட்டமைப்பு aligntest8));
#எனில் !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest9), __alignof__(கட்டமைப்பு aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           அளவு(கட்டமைப்பு aligntest10), __alignof__(கட்டமைப்பு aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           அளவு(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           அளவு(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           அளவு(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#எனில் !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", அளவு(கட்டமைப்பு empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(கட்டமைப்பு empty));

    printf("Large: sizeof=%d\n", அளவு(ls));
    memset(&ls, 0, அளவு(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (முழு)((எழுத்து*)&ls.compound_head - (எழுத்து*)&ls));
}

/* simulate char/short return value with undefined upper bits */
நிலையான முழு __csf(முழு x) { திரும்பு x; }
நிலையான வெறுமை *_csf = __csf;
#define csf(t,n) ((t(*)(முழு))_csf)(n)

/* XXX: depend on endianness */
வெறுமை char_short_test()
{
    முழு var1, var2;
    signed எழுத்து var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed எழுத்து *)&var1, *(signed எழுத்து *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned எழுத்து *)&var1, *(unsigned எழுத்து *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(முழு *)&var1, *(முழு *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned முழு *)&var1, *(unsigned முழு *)&var2);
    *(signed எழுத்து *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(முழு *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed எழுத்து)(var1 + 1), (signed எழுத்து)(var4 + 1));
#எனில் !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned எழுத்து,0x89898989);
    var4 = csf(signed எழுத்து,0xabababab);
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
    var1 = (signed எழுத்து)(unsigned எழுத்து)(var3 + 1);
    var4 = (signed எழுத்து)(unsigned எழுத்து)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(முழு)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed எழுத்து)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

வகைவரை கட்டமைப்பு Sym {
    முழு v;
    முழு t;
    முழு c;
    கட்டமைப்பு Sym *next;
    கட்டமைப்பு Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

நிலையான முழு toupper1(முழு a)
{
    திரும்பு TOUPPER(a);
}

நிலையான unsigned முழு calc_vm_flags(unsigned முழு prot)
{
  unsigned முழு prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  திரும்பு prot_bits;
}

எண்ணிக்கை cast_enum { FIRST, LAST };

நிலையான வெறுமை tst_cast(எண்ணிக்கை cast_enum ce)
{
    printf("%d\n", ce);
}

வெறுமை bool_test()
{
    முழு *s, a, b, t, f, i;

    a = 0;
    s = (வெறுமை*)0;
    printf("!s=%d\n", !s);

    எனில் (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#எனில் 1 && 1
    printf("a1\n");
#endif
#எனில் 1 || 0
    printf("a2\n");
#endif
#எனில் 1 ? 0 : 1
    printf("a3\n");
#endif
#எனில் 0 ? 0 : 1
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
    printf("type of bool: %d\n", (முழு) ( (~ ((unsigned முழு) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned முழு)0)) / 2 );
    /* test ? : cast */
    {
        முழு aspect_on;
        முழு aspect_native = 65536;
        இரட்டை bfu_aspect = 1.0;
        முழு aspect;
        க்கு(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        நிலையான முழு v1 = 34 ? : -1; /* constant case */
        நிலையான முழு v2 = 0 ? : -1; /* constant case */
        முழு a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    க்கு(i=0;i<256;i++) {
        எனில் (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

வெளி முழு undefined_function(வெறுமை);
வெளி முழு defined_function(வெறுமை);

#ifdef __clang__
முழு undefined_function(வெறுமை) {}
#endif

நிலையான உள்வரி வெறுமை refer_to_undefined(வெறுமை)
{
  undefined_function();
}

வெறுமை optimize_out_test(வெறுமை)
{
  முழு i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  முழு j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  எனில் (0)
    printf("oo:%d\n", undefined_function());
  இல்லையெனில்
    printf("oo:%d\n", defined_function());
  எனில் (1)
    printf("oo:%d\n", defined_function());
  இல்லையெனில்
    printf("oo:%d\n", undefined_function());
  போது (1) {
      printf("oow:%d\n", defined_function());
      நிறுத்து;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  தேர்வு (j)
    நிலை 1: நிறுத்து;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  போது (1)
    நிறுத்து;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  செய்
    நிறுத்து;
  போது (1);
  printf ("ool2:%d\n", defined_function());
  க்கு (;;)
    நிறுத்து;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  போது (1) {
	{
	  நிறுத்து;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  போது (j) {
      எனில் (j == 0)
	நிறுத்து; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  போது (j) {
      எனில் (1)
	j--;
      இல்லையெனில்
	breakhere: நிறுத்து;
      printf("ool6:%d\n", defined_function());
      செல் breakhere;
  }
  j = 1;
  போது (j) {
      j--;
      தொடர்;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  எனில் (0 && undefined_function())
    undefined_function();
  எனில் (defined_function() && 0)
    undefined_function();
  எனில் (0 && 0)
    undefined_function();
  எனில் (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  எனில் (1 || undefined_function())
    ;
  இல்லையெனில்
    undefined_function();
  எனில் (defined_function() || 1)
    ;
  இல்லையெனில்
    undefined_function();
  எனில் (1 || 1)
    ;
  இல்லையெனில்
    undefined_function();
  எனில் (defined_function() || 1 || undefined_function())
    ;
  இல்லையெனில்
    undefined_function();

  எனில் (defined_function() && 0)
    refer_to_undefined();

  எனில் (0) {
      (வெறுமை)அளவு( ({
		     செய் { } போது (0);
		     0;
		     }) );
      undefined_function();
  }

  எனில் (0) {
      தேர்வு (defined_function()) {
          நிலை 0: undefined_function(); நிறுத்து;
          இயல்பு: undefined_function(); நிறுத்து;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  எனில் (1)
    திரும்பு;
  printf ("oor:%d\n", undefined_function());
}

முழு defined_function(வெறுமை)
{
  நிலையான முழு i = 40;
  திரும்பு i++;
}

/* GCC accepts that */
நிலையான முழு tab_reinit[];
நிலையான முழு tab_reinit[10];

நிலையான முழு tentative_ar[];
நிலையான முழு tentative_ar[] = {1,2,3};

முழு cinit1; /* a global variable can be defined several times without error ! */
முழு cinit1; 
முழு cinit1 = 0;
முழு *cinit2 = (முழு []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
எழுத்து மாறிலி * மாறிலி cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
வெறுமை *cinit52 = &(வெறுமை*){ (வெறுமை*) 52 };

#எனில் __TINYC__ || __GNUC__ >= 6
முழு cinit4 = (முழு){44};
வெறுமை *cinit51 = (வெறுமை*){ (வெறுமை*) 51 };
கட்டமைப்பு _c6 { முழு a,b; } cinit6 = (கட்டமைப்பு _c6){61,62}, *cinit7 = &(கட்டமைப்பு _c6){71,72};
#இல்லையெனில்
முழு cinit4 = 44;
வெறுமை *cinit51 = (வெறுமை*)51;
கட்டமைப்பு _c6 { முழு a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

வெறுமை compound_literal_test(வெறுமை)
{
    முழு *p, i;
    எழுத்து *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (முழு)cinit51);
    printf("cinit52 : %d\n", *(முழு*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (முழு []){1, 2, 3};
    க்கு(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    க்கு(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (எழுத்து *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (எழுத்து *){ q };
    printf("q3=%s\n", q3);

    q = (எழுத்து []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (முழு []){1, 2, cinit1 + 3};
    க்கு(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    க்கு(i=0;i<3;i++) {
        p = (முழு []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#எனில் __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    திரும்பு a + b;
}

முழு kr_func2(a, b)
{
    திரும்பு a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    திரும்பு 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
எழுத்து invalid_function_def()[] {திரும்பு 0;}

#இல்லையெனில்
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

வெறுமை இலக்கம்(முழு n)
{
    எழுத்து *tab, *p;
    tab = (எழுத்து*)malloc(20); 
    p = tab;
    போது (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        எனில் (n == 0)
            நிறுத்து;
    }
    போது (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    விடுவி(tab);
}

/* structure assignment tests */
கட்டமைப்பு structa1 {
    முழு f1;
    எழுத்து f2;
};

வெறுமை struct_assign_test1(கட்டமைப்பு structa1 s1, முழு t, தசம f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

கட்டமைப்பு structa1 struct_assign_test2(கட்டமைப்பு structa1 s1, முழு t)
{
    s1.f1 += t;
    s1.f2 -= t;
    திரும்பு s1;
}

வெறுமை struct_assign_test(வெறுமை)
{
    கட்டமைப்பு S {
      கட்டமைப்பு structa1 lsta1, lsta2;
      முழு i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    நிலையான கட்டமைப்பு {
        வெறுமை (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

வெறுமை cast1(எழுத்து a, short b, unsigned எழுத்து c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

எழுத்து bcast;
short scast;

வெறுமை cast_test()
{
    முழு a;
    எழுத்து c;
    எழுத்து tab[10];
    unsigned b,d;
    short s;
    எழுத்து *p = வெற்று;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (எழுத்து)(a + 1),
           (short)(a + 1),
           (unsigned எழுத்து)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (எழுத்து)0xfffff,
           (short)0xfffff,
           (unsigned எழுத்து)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", அளவு(c), அளவு((முழு)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (எழுத்து)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", அளவு(+(எழுத்து)'a'));
    printf("sizeof(-(char)'a') = %d\n", அளவு(-(எழுத்து)'a'));
    printf("sizeof(~(char)'a') = %d\n", அளவு(-(எழுத்து)'a'));

#எனில் CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (முழு)p, (unsigned முழு)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (வெறுமை *)a, (வெறுமை *)b, (வெறுமை *)c, (வெறுமை *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(முழு)ul);
}

/* initializers tests */
கட்டமைப்பு structinit1 {
    முழு f1;
    எழுத்து f2;
    short f3;
    முழு farray[3];
};

முழு sinit1 = 2;
முழு sinit2 = { 3 };
முழு sinit3[3] = { 1, 2, {3}, };
முழு sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
முழு sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
முழு sinit6[] = { 1, 2, 3 };
முழு sinit7[] = { [2] = 3, [0] = 1, 2 };
எழுத்து sinit8[] = "hello" "trala";

கட்டமைப்பு structinit1 sinit9 = { 1, 2, 3 };
கட்டமைப்பு structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
கட்டமைப்பு structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

எழுத்து *sinit12 = "hello world";
எழுத்து *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
எழுத்து sinit14[10] = { "abc" };
முழு sinit15[3] = { அளவு(sinit15), 1, 2 };

கட்டமைப்பு { முழு a[3], b; } sinit16[] = { { 1 }, 2 };

கட்டமைப்பு bar {
        எழுத்து *s;
        முழு len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

முழு sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

கட்டமைப்பு complexinit0 {
    முழு a;
    முழு b;
};

கட்டமைப்பு complexinit {
    முழு a;
    மாறிலி கட்டமைப்பு complexinit0 *b;
};

மாறிலி நிலையான கட்டமைப்பு complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (மாறிலி கட்டமைப்பு complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

கட்டமைப்பு complexinit2 {
	முழு a;
	முழு b[];
};

கட்டமைப்பு complexinit2 cix20;

கட்டமைப்பு complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

கட்டமைப்பு complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

வகைவரை முழு arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
வகைவரை முழு arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
முழு sinit23[2] = { "astring" ? அளவு("astring") : -1,
		   &sinit23 ? 42 : -1 };

முழு sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
கட்டமைப்பு bf_SS {unsigned முழு bit:1,bits31:31; };
கட்டமைப்பு bf_SS bf_init = { .bit = 1 };
கட்டமைப்பு bfn_SS {முழு a,b; கட்டமைப்பு bf_SS c; முழு d,e; };
கட்டமைப்பு bfn_SS bfn_init = { .c.bit = 1 };
கட்டமைப்பு bfa_SS {முழு a,b; கட்டமைப்பு bf_SS c[3]; முழு d,e; };
கட்டமைப்பு bfa_SS bfa_init = { .c[1].bit = 1 };
கட்டமைப்பு bf_SS bfaa_init[3] = { [1].bit = 1 };
கட்டமைப்பு bf_SS bfaa_vinit[] = { [2].bit = 1 };
கட்டமைப்பு b2_SS {long long முழு field : 52; long long முழு pad : 12; };
கட்டமைப்பு b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

வெளி முழு external_inited = 42;

வெறுமை init_test(வெறுமை)
{
    முழு linit1 = 2;
    முழு linit2 = { 3 };
    முழு linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    முழு linit6[] = { 1, 2, 3 };
    முழு i, j;
    எழுத்து linit8[] = "hello" "trala";
    முழு linit12[10] = { 1, 2 };
    முழு linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    எழுத்து linit14[10] = "abc";
    முழு linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    கட்டமைப்பு linit16 { முழு a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    முழு linit17 = அளவு(linit17);
    முழு zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    முழு linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    கட்டமைப்பு bf_SS bf_finit = { .bit = 1 };
    கட்டமைப்பு bfn_SS bfn_finit = { .c.bit = 1 };
    கட்டமைப்பு bfa_SS bfa_finit = { .c[1].bit = 1 };
    கட்டமைப்பு bf_SS bfaa_finit[3] = { [1].bit = 1 };
    கட்டமைப்பு bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    கட்டமைப்பு b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           அளவு(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", அளவு(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           அளவு(sinit7),
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

    க்கு(i=0;i<3;i++)
        க்கு(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", அளவு(linit6));
    printf("linit8=%d %s\n", அளவு(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           அளவு(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    க்கு(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    க்கு(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    க்கு(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    க்கு(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    க்கு(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", அளவு cix20, அளவு cix21, அளவு cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", அளவு(sinit19), அளவு(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", அளவு(sinit21), அளவு(sinit22));
    printf("arrtype6: %d\n", அளவு(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    க்கு (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    க்கு (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    க்கு (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    க்கு (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    க்கு (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    க்கு (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

வெறுமை switch_uc(unsigned எழுத்து uc)
{
	தேர்வு (uc) {
	    நிலை 0xfb ... 0xfe:
		printf("ucsw:1\n");
		நிறுத்து;
	    நிலை 0xff:
		printf("ucsw:2\n");
		நிறுத்து;
	    நிலை 0 ... 5:
		printf("ucsw:3\n");
		நிறுத்து;
	    இயல்பு:
		printf("ucsw: broken!\n");
	}
}

வெறுமை switch_sc(signed எழுத்து sc)
{
	தேர்வு (sc) {
	    நிலை -5 ... -2:
		printf("scsw:1\n");
		நிறுத்து;
	    நிலை -1:
		printf("scsw:2\n");
		நிறுத்து;
	    நிலை 0 ... 5:
		printf("scsw:3\n");
		நிறுத்து;
	    இயல்பு:
		printf("scsw: broken!\n");
	}
}

வெறுமை switch_test()
{
    முழு i;
    unsigned long long ull;
    long long ll;

    க்கு(i=0;i<15;i++) {
        தேர்வு(i) {
        நிலை 0:
        நிலை 1:
            printf("a");
            நிறுத்து;
        இயல்பு:
            printf("%d", i);
            நிறுத்து;
        நிலை 8 ... 12:
            printf("c");
            நிறுத்து;
        நிலை 3:
            printf("b");
            நிறுத்து;
        நிலை 0xc33c6b9fU:
        நிலை 0x7c9eeeb9U:
            நிறுத்து;
        }
    }
    printf("\n");

    க்கு (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	தேர்வு (ull) {
	    நிலை 1ULL << 61:
		printf("ullsw:1\n");
		நிறுத்து;
	    நிலை 2ULL << 61:
		printf("ullsw:2\n");
		நிறுத்து;
	    நிலை 3ULL << 61:
		printf("ullsw:3\n");
		நிறுத்து;
	    நிலை 4ULL << 61:
		printf("ullsw:4\n");
		நிறுத்து;
	    நிலை 5ULL << 61:
		printf("ullsw:5\n");
		நிறுத்து;
	    இயல்பு:
		printf("ullsw: broken!\n");
	}
    }

    க்கு (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	தேர்வு (ll) {
	    நிலை 1LL << 61:
		printf("llsw:1\n");
		நிறுத்து;
	    நிலை 2LL << 61:
		printf("llsw:2\n");
		நிறுத்து;
	    நிலை 3LL << 61:
		printf("llsw:3\n");
		நிறுத்து;
	    நிலை 4LL << 61:
		printf("llsw:4\n");
		நிறுத்து;
	    நிலை 5LL << 61:
		printf("llsw:5\n");
		நிறுத்து;
	    இயல்பு:
		printf("llsw: broken!\n");
	}
    }

    க்கு (i = -5; i <= 5; i++) {
	switch_uc((unsigned எழுத்து)i);
    }

    க்கு (i = -5; i <= 5; i++) {
	switch_sc ((signed எழுத்து)i);
    }
}

/* ISOC99 _Bool type */
வெறுமை c99_bool_test(வெறுமை)
{
#ifdef BOOL_ISOC99
    முழு a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", அளவு(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           அளவு ((நிலையற்ற முழு)a ? b : b2));
#endif
}

வெறுமை bitfield_test(வெறுமை)
{
    முழு a;
    short sa;
    unsigned எழுத்து ca;
    கட்டமைப்பு sbf1 {
        முழு f1 : 3;
        முழு : 2;
        முழு f2 : 1;
        முழு : 0;
        முழு f3 : 5;
        முழு f4 : 7;
        unsigned முழு f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", அளவு(st1));

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
    எனில் (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    இல்லையெனில் 
        printf("st1.f1 != -1\n");
    எனில் (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    இல்லையெனில் 
        printf("st1.f2 != -1\n");

    கட்டமைப்பு sbf2 {
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

#எனில் 0
    Disabled க்கு now until further clarification re GCC compatibility
    கட்டமைப்பு sbf3 {
        முழு f1 : 7;
        முழு f2 : 1;
        எழுத்து f3;
        முழு f4 : 8;
        முழு f5 : 1;
        முழு f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", அளவு(st3));
#endif

    கட்டமைப்பு sbf4 {
	முழு x : 31;
	எழுத்து y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    கட்டமைப்பு sbf5 {
	முழு a;
	எழுத்து b;
	முழு x : 12, y : 4, : 0, : 4, z : 3;
	எழுத்து c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    கட்டமைப்பு sbf6 {
	short x : 12;
	unsigned எழுத்து y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#இல்லையெனில்
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
இரட்டை strtod(மாறிலி எழுத்து *nptr, எழுத்து **endptr);

#எனில் defined(_WIN32)
தசம strtof(மாறிலி எழுத்து *nptr, எழுத்து **endptr) {திரும்பு (தசம)strtod(nptr, endptr);}
LONG_DOUBLE strtold(மாறிலி எழுத்து *nptr, எழுத்து **endptr) {திரும்பு (LONG_DOUBLE)strtod(nptr, endptr);}
#இல்லையெனில்
தசம strtof(மாறிலி எழுத்து *nptr, எழுத்து **endptr);
LONG_DOUBLE strtold(மாறிலி எழுத்து *nptr, எழுத்து **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
வெறுமை prefix ## cmp(type a, type b)\
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
வெறுமை prefix ## fcast(type a)\
{\
    தசம fa;\
    இரட்டை da;\
    LONG_DOUBLE la;\
    முழு ia;\
    long long llia;\
    unsigned முழு ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (முழு)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned முழு)a;\
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
    எனில் (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
தசம prefix ## retf(type a) { திரும்பு a; }\
இரட்டை prefix ## retd(type a) { திரும்பு a; }\
LONG_DOUBLE prefix ## retld(type a) { திரும்பு a; }\
\
வெறுமை prefix ## call(வெறுமை)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (இரட்டை)strto ## prefix("1.2", வெற்று));\
}\
\
வெறுமை prefix ## signed_zeros(வெறுமை) \
{\
  type x = 0.0, y = -0.0, n, p;\
  எனில் (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  இல்லையெனில்\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  எனில் (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  இல்லையெனில்\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  எனில் (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  இல்லையெனில்\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  எனில் (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  இல்லையெனில்\
    printf ("x != -y; this is wrong!\n");\
}\
வெறுமை prefix ## nan(வெறுமை)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
வெறுமை prefix ## test(வெறுமை)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    எனில் (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, தசம, தசம, "%f")
FTEST(d, இரட்டை, இரட்டை, "%f")
FTEST(ld, long இரட்டை, LONG_DOUBLE, "%Lf")

இரட்டை ftab1[3] = { 1.2, 3.4, -5.6 };


வெறுமை float_test(வெறுமை)
{
#எனில் !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    நிலையற்ற தசம fa, fb;
    நிலையற்ற இரட்டை da, db;
    முழு a;
    unsigned முழு b;
    நிலையான இரட்டை nan2 = 0.0/0.0;
    நிலையான இரட்டை inf1 = 1.0/0.0;
    நிலையான இரட்டை inf2 = 1e5000;
    நிலையற்ற LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", அளவு(தசம));
    printf("sizeof(double) = %d\n", அளவு(இரட்டை));
    printf("sizeof(long double) = %d\n", அளவு(LONG_DOUBLE));
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

முழு fib(முழு n)
{
    எனில் (n <= 2)
        திரும்பு 1;
    இல்லையெனில்
        திரும்பு fib(n-1) + fib(n-2);
}

#எனில் __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#இல்லையெனில்
வெறுமை __attribute__((aligned(16))) aligned_function(முழு i) {}
#endif

வெறுமை funcptr_test()
{
    வெறுமை (*func)(முழு);
    முழு a;
    கட்டமைப்பு {
        முழு dummy;
        வெறுமை (*func)(முழு);
    } st1;
    long diff;

    func = &இலக்கம்;
    (*func)(12345);
    func = இலக்கம்;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = இலக்கம்;
    st1.func(12346);
    printf("sizeof1 = %d\n", அளவு(funcptr_test));
    printf("sizeof2 = %d\n", அளவு funcptr_test);
    printf("sizeof3 = %d\n", அளவு(&funcptr_test));
    printf("sizeof4 = %d\n", அளவு &funcptr_test);
    a = 0;
    func = இலக்கம் + a;
    diff = func - இலக்கம்;
    func(42);
    (func + diff)(42);
    (இலக்கம் + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((முழு)(uintptr_t)func) & 15);
}

வெறுமை lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    எனில் (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*இருமம்*/
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

வெறுமை llshift(long long a, முழு b)
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

வெறுமை llfloat(வெறுமை)
{
    தசம fa;
    இரட்டை da;
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

long long llfunc1(முழு a)
{
    திரும்பு a * 2;
}

கட்டமைப்பு S {
    முழு id; 
    எழுத்து item;
};

long long முழு மதிப்பு(கட்டமைப்பு S *v)
{
    திரும்பு ((long long முழு)v->item);
}

long long llfunc2(long long x, long long y, முழு z)
{
    திரும்பு x * y * z;
}

வெறுமை check_opl_save_regs(எழுத்து *a, long long b, முழு c)
{
    *a = b < 0 && !c;
}

வெறுமை longlong_test(வெறுமை)
{
    long long a, b, c;
    முழு ia;
    unsigned முழு ua;
    printf("sizeof(long long) = %d\n", அளவு(long long));
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
#எனில் 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          கட்டமைப்பு S a;

          a.item = 3;
          printf("%lld\n", மதிப்பு(&a));
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
    u = (unsigned)(முழு)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    எழுத்து cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

வெறுமை manyarg_test(வெறுமை)
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

வெறுமை*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        கட்டமைப்பு X { முழு _x; };
        கட்டமைப்பு X *x = va_arg(ap, கட்டமைப்பு X *);
        திரும்பு x;
}

வெறுமை vprintf1(மாறிலி எழுத்து *fmt, ...)
{
    va_list ap, aq;
    மாறிலி எழுத்து *p;
    முழு c, i;
    இரட்டை d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    க்கு(;;) {
        c = *p;
        எனில் (c == '\0')
            நிறுத்து;
        p++;
        எனில் (c == '%') {
            c = *p;
            தேர்வு(c) {
            நிலை '\0':
                செல் the_end;
            நிலை 'd':
                i = va_arg(ap, முழு);
                printf("%d", i);
                நிறுத்து;
            நிலை 'f':
                d = va_arg(ap, இரட்டை);
                printf("%f", d);
                நிறுத்து;
            நிலை 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                நிறுத்து;
            நிலை 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                நிறுத்து;
            }
            p++;
        } இல்லையெனில் {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

கட்டமைப்பு myspace {
    short முழு profile;
};
கட்டமைப்பு myspace2 {
#எனில் CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    எழுத்து a[1];
#இல்லையெனில்
    எழுத்து a[0];
#endif
};
கட்டமைப்பு myspace3 {
    எழுத்து a[1];
};
கட்டமைப்பு myspace4 {
    எழுத்து a[2];
};
கட்டமைப்பு mytest {
    வெறுமை *foo, *bar, *baz;
};

கட்டமைப்பு mytest stdarg_for_struct(கட்டமைப்பு myspace bob, ...)
{
    கட்டமைப்பு myspace george, bill;
    கட்டமைப்பு myspace2 alex1;
    கட்டமைப்பு myspace3 alex2;
    கட்டமைப்பு myspace4 alex3;
    va_list ap;
    short முழு validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, கட்டமைப்பு myspace2);
    alex2    = va_arg(ap, கட்டமைப்பு myspace3);
    alex3    = va_arg(ap, கட்டமைப்பு myspace4);
    bill     = va_arg(ap, கட்டமைப்பு myspace);
    george   = va_arg(ap, கட்டமைப்பு myspace);
    validate = va_arg(ap, முழு);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    திரும்பு (கட்டமைப்பு mytest) {};
}

வெறுமை stdarg_for_libc(மாறிலி எழுத்து *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

வெறுமை stdarg_syntax(முழு n, ...)
{
    முழு i;
    va_list ap;
    எனில் (1)
      va_start(ap, n);
    இல்லையெனில்
      ;
    i = va_arg(ap, முழு);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

வகைவரை கட்டமைப்பு{
    இரட்டை x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

நிலையான வெறுமை stdarg_double_struct(முழு nargs, முழு posd,...)
{
    முழு i;
    இரட்டை d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    க்கு(i = 0; i < nargs; i++) {
        எனில் (i == posd) {
            d = va_arg (args, இரட்டை);
            printf ("d %d = %g\n", i, d);
        }
        இல்லையெனில் {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

வெறுமை stdarg_test(வெறுமை)
{
    LONG_DOUBLE ld = 1234567891234LL;
    கட்டமைப்பு myspace bob;
    கட்டமைப்பு myspace2 bob2;
    கட்டமைப்பு myspace3 bob3;
    கட்டமைப்பு myspace4 bob4;

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
#எனில் !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

முழு reltab[3] = { 1, 2, 3 };

முழு *rel1 = &reltab[1];
முழு *rel2 = &reltab[2];

வெறுமை getmyaddress(வெறுமை)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(வெறுமை)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       திரும்பு ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
வெறுமை relocation_test(வெறுமை)
{
    வெறுமை (*fptr)(வெறுமை) = (வெறுமை (*)(வெறுமை))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

வெறுமை old_style_f(a,b,c)
     முழு a, b;
     இரட்டை c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

வெறுமை decl_func1(முழு cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

வெறுமை decl_func2(cmpfn)
முழு cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

வெறுமை old_style_function_test(வெறுமை)
{
#எனில் CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#இல்லையெனில்
    old_style_f((வெறுமை *)1, 2, 3.0);
#endif
    decl_func1(வெற்று);
    decl_func2(வெற்று);
}

வெறுமை alloca_test()
{
    எழுத்து *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    எழுத்து *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

வெறுமை *bounds_checking_is_enabled()
{
    எழுத்து ca[10], *cp = ca-1;
    திரும்பு (ca != cp + 1) ? cp : வெற்று;
}

வகைவரை முழு constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

வெறுமை c99_vla_test_1(முழு size1, முழு size2)
{
    முழு size = size1 * size2;
    முழு tab1[size][2], tab2[10][2];
    வெறுமை *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (அளவு tab1 == size1 * size2 * 2 * அளவு(முழு)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (அளவு(முழு) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * அளவு(முழு)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((முழு *) (tab1_ptr + (size1 * 2 + 1) * அளவு(முழு))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    எனில் (bad_ptr = bounds_checking_is_enabled()) {
        முழு *t1 = &tab1[size1 * size2 - 1][3];
        முழு *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        எழுத்து*c1 = 1 + அளவு(tab1) + (எழுத்து*)tab1;
        எழுத்து*c2 = 1 + அளவு(tab2) + (எழுத்து*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        முழு *i1 = tab1[-1];
        முழு *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        முழு *x1 = tab1[size1 * size2 + 1];
        முழு *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } இல்லையெனில் {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

வெறுமை c99_vla_test_2(முழு d, முழு h, முழு w)
{
    முழு x, y, z;
    முழு (*arr)[h][w] = malloc(அளவு(முழு) * d*h*w);
    முழு c = 1;
    நிலையான முழு (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    க்கு (z=0; z<d; z++) {
        க்கு (y=0; y<h; y++) {
            க்கு (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    க்கு (z=0; z<d; z++) {
        க்கு (y=0; y<h; y++) {
            க்கு (x=0; x<w; x++) {
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
        அளவு (*arr), அளவு (*arr)[0], அளவு (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == அளவு (*arr + 1) - அளவு arr,
        0 == அளவு அளவு *arr - அளவு arr,
        starr[0][2][3] == arr[1][2][3]
        );
    விடுவி (arr);
}

வெறுமை c99_vla_test_3a (முழு arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

வெறுமை c99_vla_test_3b(முழு s, முழு arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

வெறுமை c99_vla_test_3c(முழு s, முழு arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

வெறுமை c99_vla_test_3d(முழு s, முழு arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

வெறுமை c99_vla_test_3e(முழு s, முழு arr[][3][--s])
{
    printf ("%d %d %d\n", அளவு arr, s, arr[1][2][3]);
}

வெறுமை c99_vla_test_3(வெறுமை)
{
    முழு a[2][3][4];

    memset (a, 0, அளவு(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

வெறுமை c99_vla_test(வெறுமை)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


வெறுமை sizeof_test(வெறுமை)
{
    முழு a;
    முழு **ptr;

    printf("sizeof(int) = %d\n", அளவு(முழு));
    printf("sizeof(unsigned int) = %d\n", அளவு(unsigned முழு));
    printf("sizeof(long) = %d\n", அளவு(long));
    printf("sizeof(unsigned long) = %d\n", அளவு(unsigned long));
    printf("sizeof(short) = %d\n", அளவு(short));
    printf("sizeof(unsigned short) = %d\n", அளவு(unsigned short));
    printf("sizeof(char) = %d\n", அளவு(எழுத்து));
    printf("sizeof(unsigned char) = %d\n", அளவு(unsigned எழுத்து));
    printf("sizeof(func) = %d\n", அளவு sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", அளவு a++);
    printf("a=%d\n", a);
    ptr = வெற்று;
    printf("sizeof(**ptr) = %d\n", அளவு (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", அளவு(அளவு(முழு)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -அளவு(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(முழு));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned முழு));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(எழுத்து));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned எழுத்து));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", அளவு(எழுத்து[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   அளவு( (கட்டமைப்பு {முழு i; முழு j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   அளவு (கட்டமைப்பு {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", அளவு(t && 0));
    printf("sizeof(1 && 1) = %d\n", அளவு(1 && 1));
    printf("sizeof(t || 1) = %d\n", அளவு(t || 1));
    printf("sizeof(0 || 0) = %d\n", அளவு(0 || 0));

    முழு arr[4], fn();
    printf("sizeof(0, arr) = %d\n", அளவு(0, arr));
    printf("sizeof(0, fn) = %d\n", அளவு(0, fn));
}

வெறுமை typeof_test(வெறுமை)
{
    இரட்டை a;
    typeof(a) b;
    typeof(தசம) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


கட்டமைப்பு hlist_முனை;
கட்டமைப்பு hlist_head {
    கட்டமைப்பு hlist_முனை *first, *last;
};

வெறுமை consume_ulong (unsigned long i)
{
    i = 0;
}

வெறுமை statement_கோவை_test(வெறுமை)
{
    முழு a, i;

    /* Basic stmt expr test */
    a = 0;
    க்கு(i=0;i<10;i++) {
        a += 1 + 
            ( { முழு b, j; 
                b = 0; 
                க்கு(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    வெறுமை *v = (வெறுமை*)39;
    typeof(({
	    (கட்டமைப்பு hlist_முனை *)v;
	    })) x;
    typeof (x)
	ptr = (கட்டமைப்பு hlist_முனை *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            நிலையான மாறிலி எழுத்து *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    முழு t = 40;
    முழு b = ({ முழு t = 41; t; });
    முழு c = ({ முழு t = 42; t; });

    /* Test that aggregate return values work.  */
    கட்டமைப்பு hlist_head h
	= ({
	   வகைவரை கட்டமைப்பு hlist_head T;
	   long pre = 48;
	   T t = { (வெறுமை*)43, (வெறுமை*)44 };
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
       LBL: எனில் (i++ == 0) செல் LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      செல் LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

வெறுமை local_label_test(வெறுமை)
{
    முழு a;
    செல் l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        செல் l1;
    l4:
        printf("aa1\n");
        செல் l3;
    l2:
        printf("aa3\n");
        செல் l4;
    l1:
        printf("aa2\n");
        செல் l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    திரும்பு;
 l4:
    printf("bb1\n");
    செல் l2;
 l1:
    printf("bb2\n");
    செல் l4;
}

/* inline assembler test */
#எனில் (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

வகைவரை __SIZE_TYPE__ word;

/* from linux kernel */
நிலையான எழுத்து * strncat1(எழுத்து * dest,மாறிலி எழுத்து * src,size_t மொத்தம்_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (மொத்தம்_2)
	: "memory");
திரும்பு dest;
}

நிலையான எழுத்து * strncat2(எழுத்து * dest,மாறிலி எழுத்து * src,size_t மொத்தம்_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (மொத்தம்_2)
	: "memory");
திரும்பு dest;
}

நிலையான உள்வரி வெறுமை * memcpy1(வெறுமை * to, மாறிலி வெறுமை * from, size_t n)
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
திரும்பு (to);
}

நிலையான உள்வரி வெறுமை * memcpy2(வெறுமை * to, மாறிலி வெறுமை * from, size_t n)
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
திரும்பு (to);
}

நிலையான __inline__ வெறுமை sigaddset1(unsigned முழு *set, முழு _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

நிலையான __inline__ வெறுமை sigdelset1(unsigned முழு *set, முழு _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
நிலையான __inline__ __const__ unsigned முழு swab32(unsigned முழு x)
{
        திரும்பு ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#இல்லையெனில்
நிலையான __inline__ __const__ unsigned முழு swab32(unsigned முழு x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	திரும்பு x;
}
#endif

நிலையான __inline__ unsigned long long mul64(unsigned முழு a, unsigned முழு b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned முழு resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#இல்லையெனில்
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    திரும்பு res;
}

நிலையான __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#இல்லையெனில்
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    திரும்பு res;
}

கட்டமைப்பு struct123 {
    முழு a;
    முழு b;
};
கட்டமைப்பு struct1231 {
    word addr;
};

word mconstraint_test(கட்டமைப்பு struct1231 *r)
{
    word ret;
    unsigned முழு a[2];
    a[0] = 0;
    __asm__ நிலையற்ற ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(கட்டமைப்பு struct123 *)r->addr));
    திரும்பு ret + a[0];
}

#ifdef __x86_64__
முழு fls64(unsigned long long x)
{
  முழு bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  திரும்பு bitpos + 1;
}
#endif

வெறுமை other_constraints_test(வெறுமை)
{
    word ret;
    முழு var;
#எனில் CC_NAME != CC_clang
    __asm__ நிலையற்ற ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
வெறுமை base_func(வெறுமை)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
வெளி வெறுமை override_func1 (வெறுமை);
வெளி வெறுமை override_func2 (வெறுமை);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

வெறுமை override_func2 (வெறுமை)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
வெளி முழு bug_table[] __attribute__((section("__bug_table")));
எழுத்து * get_asm_string (வெறுமை)
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
  வெளி முழு some_குறியீடு;
  asm நிலையற்ற (".globl some_symbol\n"
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
  எழுத்து * str = ((எழுத்து*)bug_table) + bug_table[1];
  திரும்பு str;
#இல்லையெனில்
  திரும்பு (எழுத்து *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
வெளி unsigned எழுத்து alld_stuff[];
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

வெறுமை asm_local_label_diff (வெறுமை)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
வெறுமை asm_local_statics (வெறுமை)
{
  நிலையான முழு localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

நிலையான
unsigned முழு set;

வெறுமை fancy_copy (unsigned *in, unsigned *out)
{
  asm நிலையற்ற ("" : "=r" (*out) : "0" (*in));
}

வெறுமை fancy_copy2 (unsigned *in, unsigned *out)
{
  asm நிலையற்ற ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#எனில் defined __x86_64__
வெறுமை clobber_r12(வெறுமை)
{
    asm நிலையற்ற("mov $1, %%r12" ::: "r12");
}
#endif

வெறுமை test_உயர்வு_clobbers_really(வெறுமை)
{
#எனில் defined __x86_64__
    பதிவு word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm நிலையற்ற("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm நிலையற்ற("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

வெறுமை test_உயர்வு_clobbers(வெறுமை)
{
#எனில் defined __x86_64__
    word x1, x2;
    asm நிலையற்ற("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_உயர்வு_clobbers_really();
    asm நிலையற்ற("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm நிலையற்ற("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

நிலையான long cpu_எண்;
வெறுமை trace_console(long len, long len2)
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
    எனில் (0
        &&
            ({
              long pscr_ret__;
              தேர்வு(len) {
                நிலை 4:
                    {
                       long pfo_ret__;
                       தேர்வு (len2) {
                         நிலை 8:	printf("bla"); pfo_ret__ = 42; நிறுத்து;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  நிறுத்து;
                நிலை 8:
                    {
                       long pfo_ret__;
                       தேர்வு (len2) {
                         நிலை 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_எண்));	நிறுத்து;
                         நிலை 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_எண்));	நிறுத்து;
                         நிலை 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_எண்));	நிறுத்து;
                         நிலை 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_எண்));	நிறுத்து;
                         இயல்பு: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  நிறுத்து;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

வெறுமை test_asm_dead_code(வெறுமை)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm நிலையற்ற ("" : "=D" (rdi) : "0" (0));
  (வெறுமை)அளவு (({
      முழு var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm நிலையற்ற ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

வெறுமை test_asm_call(வெறுமை)
{
#எனில் defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  நிலையான எழுத்து str[] = "PATH";
  எழுத்து *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm நிலையற்ற ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#எனில் 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#இல்லையெனில்
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#எனில் defined __x86_64__
# define RX "(%rip)"
#இல்லையெனில்
# define RX
#endif

வெறுமை asm_dot_test(வெறுமை)
{
#ifndef __APPLE__
    முழு x;
    க்கு (x = 1;; ++x) {
        முழு r = x;
        தேர்வு (x) {
        நிலை 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        நிலை 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#இல்லையெனில்
            asm(".text; mov $123, %eax; jmp p0");
#endif
	நிலை 3:
#எனில் !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#இல்லையெனில்
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        நிலை 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#இல்லையெனில்
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#இல்லையெனில்
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        நிலை 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); நிறுத்து;
	}
        எனில் (r == x)
            நிறுத்து;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

வெறுமை asm_pcrel_test(வெறுமை)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

வெறுமை asm_test(வெறுமை)
{
    எழுத்து buf[128];
    unsigned முழு val, val2;
    கட்டமைப்பு struct123 s1;
    கட்டமைப்பு struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    முழு base_func = 42;
    வெறுமை override_func3 (வெறுமை);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    பதிவு முழு regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm நிலையற்ற ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm நிலையற்ற ("xorl %eax, %eax");

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
    செல் label1;
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
    asm நிலையற்ற(".weak override_func3\n.set override_func3, base_func");
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
    asm நிலையற்ற("" : "=r" (asmret) : "0"(s2));
    எனில் (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm நிலையற்ற("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    எனில் (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm நிலையற்ற ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_உயர்வு_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    திரும்பு;
 label1:
    செல் label2;
}

#இல்லையெனில்

வெறுமை asm_test(வெறுமை)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

முழு constant_p_var;

முழு func(வெறுமை);


/* __builtin_clz and __builtin_ctz return random values for 0 */
நிலையான வெறுமை builtin_test_bits(unsigned long long x, முழு cnt[])
{
#எனில் GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    எனில் ((unsigned முழு) x) cnt[3] += __builtin_clz(x);
    எனில் ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    எனில் ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    எனில் ((unsigned முழு) x) cnt[6] += __builtin_ctz(x);
    எனில் ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    எனில் ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#எனில் GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

வெறுமை builtin_test(வெறுமை)
{
    short s;
    முழு i;
    long long ll;
#எனில் GCC_MAJOR >= 3
    COMPAT_TYPE(முழு, முழு);
    COMPAT_TYPE(முழு, unsigned முழு);
    COMPAT_TYPE(முழு, எழுத்து);
    COMPAT_TYPE(முழு, மாறிலி முழு);
    COMPAT_TYPE(முழு, நிலையற்ற முழு);
    COMPAT_TYPE(முழு[2], மாறிலி முழு[2]);
    COMPAT_TYPE(முழு[2][3], நிலையற்ற முழு[][3]);
    COMPAT_TYPE(முழு (*)[], மாறிலி முழு (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (மாறிலி முழு (*)[2])0 : (முழு (*)[2])0),
                மாறிலி முழு (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (மாறிலி முழு (*)[2][3])0 :
                              (நிலையற்ற முழு (*)[2][3])0),
                மாறிலி நிலையற்ற முழு (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (நிலையற்ற முழு (*)[2][3])0 :
                              (மாறிலி முழு (*)[2][3])0),
                மாறிலி நிலையற்ற முழு (*)[2][3]);
#இல்லையெனில்
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(முழு *, முழு *);
    COMPAT_TYPE(முழு *, வெறுமை *);
    COMPAT_TYPE(முழு *, மாறிலி முழு *);
    COMPAT_TYPE(எழுத்து *, unsigned எழுத்து *);
    COMPAT_TYPE(எழுத்து *, signed எழுத்து *);
    COMPAT_TYPE(எழுத்து *, எழுத்து *);
    COMPAT_TYPE(எழுத்து **, வெறுமை *);
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
#இல்லையெனில்
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
    i = அளவு (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = அளவு (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	முழு cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, அளவு(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        க்கு (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        க்கு (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	க்கு (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#எனில் defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
வெறுமை weak_test(வெறுமை) {}
#இல்லையெனில்
வெளி முழு __attribute__((weak)) weak_f1(வெறுமை);
வெளி முழு __attribute__((weak)) weak_f2(வெறுமை);
வெளி முழு                       weak_f3(வெறுமை);
வெளி முழு __attribute__((weak)) weak_v1;
வெளி முழு __attribute__((weak)) weak_v2;
வெளி முழு                       weak_v3;

வெளி முழு                           (*weak_fpa)() __attribute__((weak));
வெளி முழு __attribute__((weak))     (*weak_fpb)();
வெளி     __attribute__((weak)) முழு (*weak_fpc)();

வெளி முழு                     weak_asm_f1(வெறுமை) asm("weak_asm_f1x") __attribute((weak));
வெளி முழு __attribute((weak)) weak_asm_f2(வெறுமை) asm("weak_asm_f2x")                    ;
வெளி முழு __attribute((weak)) weak_asm_f3(வெறுமை) asm("weak_asm_f3x") __attribute((weak));
வெளி முழு                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
வெளி முழு __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
வெளி முழு __attribute((weak)) weak_asm_v3(வெறுமை) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
நிலையான மாறிலி size_t dummy = 0;
வெளி __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
வெளி __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
வெளி __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

முழு some_lib_func(வெறுமை);
முழு dummy_impl_of_slf(வெறுமை) { திரும்பு 444; }
#ifndef __clang__
முழு some_lib_func(வெறுமை) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

முழு weak_toolate() __attribute__((weak));
முழு weak_toolate() { திரும்பு 0; }

வெறுமை __attribute__((weak)) weak_test(வெறுமை)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != வெற்று);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != வெற்று);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != வெற்று);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != வெற்று);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != வெற்று);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != வெற்று);
#ifdef __clang__
	printf("some_lib_func=444\n");
#இல்லையெனில்
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

முழு __attribute__((weak)) weak_f2() { திரும்பு 222; }
முழு __attribute__((weak)) weak_f3() { திரும்பு 333; }
முழு __attribute__((weak)) weak_v2 = 222;
முழு __attribute__((weak)) weak_v3 = 333;
#endif

வெறுமை const_func(மாறிலி முழு a)
{
}

வெறுமை const_warn_test(வெறுமை)
{
    const_func(1);
}

கட்டமைப்பு condstruct {
  முழு i;
};

முழு getme (கட்டமைப்பு condstruct *s, முழு i)
{
  முழு i1 = (i == 0 ? 0 : s)->i;
  முழு i2 = (i == 0 ? s : 0)->i;
  முழு i3 = (i == 0 ? (வெறுமை*)0 : s)->i;
  முழு i4 = (i == 0 ? s : (வெறுமை*)0)->i;
  திரும்பு i1 + i2 + i3 + i4;
}

கட்டமைப்பு global_data
{
  முழு a[40];
  முழு *b[40];
};

கட்டமைப்பு global_data global_data;

முழு global_data_getstuff (முழு *, முழு);

வெறுமை global_data_callit (முழு i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

முழு global_data_getstuff (முழு *p, முழு i)
{
  திரும்பு *p + i;
}

வெறுமை global_data_test (வெறுமை)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

கட்டமைப்பு cmpcmpS
{
  unsigned எழுத்து fill : 3;
  unsigned எழுத்து b1 : 1;
  unsigned எழுத்து b2 : 1;
  unsigned எழுத்து fill2 : 3;
};

முழு glob1, glob2, glob3;

வெறுமை compare_comparisons (கட்டமைப்பு cmpcmpS *s)
{
  எனில் (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

வெறுமை cmp_comparison_test(வெறுமை)
{
  கட்டமைப்பு cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

முழு fcompare (இரட்டை a, இரட்டை b, முழு code)
{
  தேர்வு (code) {
    நிலை 0: திரும்பு a == b;
    நிலை 1: திரும்பு a != b;
    நிலை 2: திரும்பு a < b;
    நிலை 3: திரும்பு a >= b;
    நிலை 4: திரும்பு a > b;
    நிலை 5: திரும்பு a <= b;
  }
  திரும்பு 0;
}

வெறுமை math_cmp_test(வெறுமை)
{
  இரட்டை nan = 0.0/0.0;
  இரட்டை one = 1.0;
  இரட்டை two = 2.0;
  முழு comp = 0;
  முழு v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  எனில் (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  எனில் (a op b) \
    bug (a,b,op,iop,2); \
  எனில் (a iop b) \
    ; \
  இல்லையெனில் \
    bug (a,b,op,iop,3); \
  எனில் ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  எனில் ((a iop b) || comp) \
    ; \
  இல்லையெனில் \
    bug (a,b,op,iop,5); \
  எனில் (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  எனில் (!fcompare (nan, nan, 1))
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

இரட்டை get100 () { திரும்பு 100.0; }

வெறுமை callsave_test(வெறுமை)
{
  முழு i, s; இரட்டை *d; இரட்டை t;
  s = அளவு (இரட்டை);
  printf ("callsavetest: %d\n", s);
  d = alloca (அளவு(இரட்டை));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


வெறுமை bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (எழுத்து *)__builtin_frame_address(3) + str_offset);
}
வெறுமை bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (எழுத்து *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
வெறுமை bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (எழுத்து *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

வெறுமை builtin_frame_address_test(வெறுமை)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    எழுத்து str[] = "__builtin_frame_address";
    எழுத்து *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

எழுத்து via_volatile (எழுத்து i)
{
  எழுத்து நிலையற்ற vi;
  vi = i;
  திரும்பு vi;
}

வெறுமை volatile_test(வெறுமை)
{
    எனில் (via_volatile (42) != 42)
      printf (" broken\n");
    இல்லையெனில்
      printf (" ok\n");
}

கட்டமைப்பு __attribute__((__packed__)) Spacked {
    எழுத்து a;
    short b;
    முழு c;
};
கட்டமைப்பு Spacked spacked;
வகைவரை கட்டமைப்பு __attribute__((__packed__)) {
    எழுத்து a;
    short b;
    முழு c;
} Spacked2;
Spacked2 spacked2;
வகைவரை கட்டமைப்பு Spacked3_s {
    எழுத்து a;
    short b;
    முழு c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
கட்டமைப்பு gate_struct64 {
    unsigned short offset_கீழ்;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_நடு;
    unsigned offset_உயர்வு;
    unsigned zero1;
} __attribute__((packed));
வகைவரை கட்டமைப்பு gate_struct64 gate_desc;
gate_desc a_gate_desc;
வெறுமை attrib_test(வெறுமை)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", அளவு(கட்டமைப்பு Spacked),
	 அளவு(spacked), அளவு(Spacked2), அளவு(spacked2));
  printf("attr: %d %d\n", அளவு(Spacked3), அளவு(spacked3));
  printf("attr: %d %d\n", அளவு(gate_desc), அளவு(a_gate_desc));
#endif
}
வெளி __attribute__((__unused__)) எழுத்து * __attribute__((__unused__)) *
strange_attrib_placement (வெறுமை);

வெறுமை * __attribute__((__unused__)) get_void_ptr (வெறுமை *a)
{
  திரும்பு a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
நிலையான உள்வரி
முழு __get_order(unsigned long long size)
{
  முழு order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      கட்டமைப்பு S { முழு i : 1; } s; // constructed for this '1'
    }
  order = size;
  திரும்பு order;
}

/* This just forces the above inline function to be actually emitted.  */
முழு force_get_order(unsigned long s)
{
    திரும்பு __get_order(s);
}

#define pv(m) printf(அளவு (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
வெறுமை bounds_check1_test (வெறுமை)
{
    கட்டமைப்பு s {
        முழு x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
வெறுமை map_add(முழு a, முழு b, முழு c, முழு d, முழு e, முழு f, முழு g, முழு h, முழு i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

வெறுமை func_arg_test(வெறுமை)
{
    முழு a = 0;
    முழு b = 1;
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
வெறுமை whitespace_test(வெறுமை)
{
    எழுத்து *str;
    முழு tcc_test = 1;

#எனில் 1
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
#இல்லையெனில்
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#எனில் 0
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
#எனில் 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

முழு முதன்மை(முழு argc, எழுத்து **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(கோவை_test);
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
    RUN(கோவை_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_கோவை_test);
    RUN(கோவை_cmp_test);
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
    RUN(statement_கோவை_test);
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

    திரும்பு 0;
}
