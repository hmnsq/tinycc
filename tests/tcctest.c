/*
 * TCC auto test program
 */
#અન્તર્ભાવ "config.h"

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

#જો defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#નહીંતર
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#જો defined(_WIN32)
#define LONG_DOUBLE દ્વિગુણ
#define LONG_DOUBLE_LITERAL(x) x
#નહીંતર
#define LONG_DOUBLE long દ્વિગુણ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

પ્રકારવ્યાખ્યા __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#અન્તર્ભાવ TCCLIB_INC

#અન્તર્ભાવ TCCLIB_INC1.TCCLIB_INC2

#અન્તર્ભાવ TCCLIB_INC1.h>

#અન્તર્ભાવ TCCLIB_INC3

#અન્તર્ભાવ <tcclib.h>

#અન્તર્ભાવ "tcclib.h"

#અન્તર્ભાવ "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#નહીંતર
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#અન્તર્ભાવ INC(42test)
#અન્તર્ભાવ incname
#અન્તર્ભાવ stringify(funnyname)

પૂર્ણાંક fib(પૂર્ણાંક n);
શૂન્ય અંક(પૂર્ણાંક n);
શૂન્ય forward_ref(શૂન્ય);
પૂર્ણાંક isid(પૂર્ણાંક c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
શૂન્ય funny_લીટી_continuation (પૂર્ણાંક, ..\
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
#define નીચલું_2 નીચલું_2 ", world"

સ્થિર પૂર્ણાંક onetwothree = 123;
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

#જો 1
#define B3 1
#અથવાજો 1
#define B3 2
#અથવાજો 0
#define B3 3
#નહીંતર
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

પૂર્ણાંક qq(પૂર્ણાંક x)
{
    પાછા x + 40;
}
#define qq(x) x

#define spin_lock(lock) કરો { } જ્યારે (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

શૂન્ય macro_test(શૂન્ય)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(ઉપલું_2, નીચલું_2));
    printf("s2=%s\n", xglue(ઉપલું_2, નીચલું_2));
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
#નહીંતર
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#નહીંતર
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#નહીંતર
    printf("B1 not defined\n");
#endif
#નહીંતર
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#નહીંતર
    printf("B2 not defined\n");
#endif
#endif

#જો 1+1
    printf("test true1\n");
#endif
#જો 0
    printf("test true2\n");
#endif
#જો 1-1
    printf("test true3\n");
#endif
#જો defined(A)
    printf("test trueA\n");
#endif
#જો defined(B)
    printf("test trueB\n");
#endif

#જો 0
    printf("test 0\n");
#અથવાજો 0
    printf("test 1\n");
#અથવાજો 2
    printf("test 2\n");
#નહીંતર
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
        પૂર્ણાંક a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(સંદેશ) printf("%s\n",સંદેશ)

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
#જો !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      અચલ અક્ષર *fn = get_file_from_header();
      જો (fn[0] == '.' && fn[1] == '/')
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


સ્થિર શૂન્ય print_અંક(અક્ષર *fn, પૂર્ણાંક લીટી, પૂર્ણાંક અંક) {
    printf("fn %s, line %d, num %d\n", fn, લીટી, અંક);
}

શૂન્ય recursive_macro_test(શૂન્ય)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_અંક(x) print_અંક(__FILE__,__LINE__,x)
    print_અંક(123);
    WRAP(print_અંક(123));
    WRAP(WRAP(print_અંક(123)));

સ્થિર સંરચના recursive_macro { પૂર્ણાંક rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#જો __TINYC__
પૂર્ણાંક op(a, b)
{
    પાછા a / b;
}

પૂર્ણાંક ret(a)
{
    જો (a == 2)
        પાછા 1;
    જો (a == 3)
        પાછા 2;
    પાછા 0;
}
#endif

#જો !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
અક્ષર str_ag1[] = "b";
અક્ષર str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
અક્ષર str_ag3[] = { "ab"[1], 0 };
અક્ષર str_x[2] = { "xy" "z"[2], 0 };
#endif
અક્ષર *str_ar[] = { "one", "two" };
સંરચના str_SS {unsigned અક્ષર a[3], b; };
સંરચના str_SS str_sinit15 = { "r" };
સંરચના str_SS str_sinit16[] = { { "q" }, 2 };

સ્થિર શૂન્ય string_test2()
{
    અક્ષર *p = "hello";
    અક્ષર a3[2] = { "p" };
    અક્ષર a4[2] = { "ab" "c"[2], 0 };
    અક્ષર *pa1 = "def" + 1;
    અક્ષર *pa2 = { "xyz" + 1 };
    પૂર્ણાંક i = 0;
    સંરચના str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    અક્ષર str_ag3[] = { "ab"[1], 0 };
    અક્ષર str_x[2] = { "xy" "z"[2], 0 };
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

શૂન્ય ps(અચલ અક્ષર *s)
{
    પૂર્ણાંક c;
    જ્યારે (1) {
        c = *s;
        જો (c == 0)
            તોડો;
        printf("%c", c);
        s++;
    }
}

અચલ અક્ષર foo1_string[] = "\
bar\n\
test\14\
1";

શૂન્ય string_test()
{
    unsigned પૂર્ણાંક b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#જો 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    જ્યારે ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    જ્યારે (b != 0x80000000) {
        અંક(b);
        b = b * 2;
    }
    string_test2();
}


શૂન્ય if1t(પૂર્ણાંક n, પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક c)
{
    જો (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    જો (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    જો (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    જો (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    જો (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    જો (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    જો (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    જો (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    જો (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    જો (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    જો (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    જો (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    જો (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    જો (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

શૂન્ય if2t(શૂન્ય)
{
    જો (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

શૂન્ય if3t(શૂન્ય)
{
    અસ્થિર long long i = 1;
    જો (i <= 18446744073709551615ULL)
      ;
    નહીંતર
      printf ("if3t:wrong 1\n");
}

શૂન્ય if_test(શૂન્ય)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

શૂન્ય loop_test()
{
    પૂર્ણાંક i;
    i = 0;
    જ્યારે (i < 10)
        printf("%d", i++);
    printf("\n");
    માટે(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    કરો {
        printf("%d", i++);
    } જ્યારે (i < 10);
    printf("\n");

    અક્ષર ગણતરી_2 = 123;
    /* c99 for loop init test */
    માટે (size_t ગણતરી_2 = 1; ગણતરી_2 < 3; ગણતરી_2++)
        printf("count=%d\n", ગણતરી_2);
    printf("count = %d\n", ગણતરી_2);

    /* break/continue tests */
    i = 0;
    જ્યારે (1) {
        જો (i == 6)
            તોડો;
        i++;
        જો (i == 3)
            ચાલુ;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    કરો {
        જો (i == 6)
            તોડો;
        i++;
        જો (i == 3)
            ચાલુ;
        printf("%d", i);
    } જ્યારે(1);
    printf("\n");

    માટે(i = 0;i < 10;i++) {
        જો (i == 3)
            ચાલુ;
        printf("%d", i);
    }
    printf("\n");
}

પ્રકારવ્યાખ્યા પૂર્ણાંક typedef_and_label;

શૂન્ય goto_test()
{
    પૂર્ણાંક i;
    સ્થિર શૂન્ય *label_table[3] = { &&label1, &&label2, &&label3 };
    સંરચના {
        પૂર્ણાંક bla;
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
    જો (i >= 10) 
        જાઓ s_end;
    printf("%d", i);
    i++;
    જાઓ s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    માટે(i=0;i<3;i++) {
        જાઓ *label_table[i];
    label1:
        printf("label1\n");
        જાઓ next;
    label2:
        printf("label2\n");
        જાઓ next;
    label3:
        printf("label3\n");
    next: ;
    }
}

ગણના {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

ગણના test {
    E5 = 1000,
};

સંરચના S_enum {
    ગણના {E6 = 42, E7, E8} e:8;
};

ગણના ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

ગણના { BIASU = -1U<<31 };
ગણના { BIASS = -1 << 31 };

સ્થિર પૂર્ણાંક getint(પૂર્ણાંક i)
{
  જો (i)
    પાછા 0;
  નહીંતર
    પાછા (પૂર્ણાંક)(-1U << 31);
}

શૂન્ય enum_test()
{
    ગણના test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    સંરચના S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    જો (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    નહીંતર
      printf("enum unsigned: wrong\n");
    જો (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    નહીંતર
      printf("enum unsigned: wrong\n");
}

પ્રકારવ્યાખ્યા પૂર્ણાંક *my_ptr;

પ્રકારવ્યાખ્યા પૂર્ણાંક mytype1;
પ્રકારવ્યાખ્યા પૂર્ણાંક mytype2;

શૂન્ય typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    પૂર્ણાંક b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

શૂન્ય forward_test()
{
    forward_ref();
    forward_ref();
}


શૂન્ય forward_ref(શૂન્ય)
{
    printf("forward ok\n");
}

પ્રકારવ્યાખ્યા સંરચના struct1 {
    પૂર્ણાંક f1;
    પૂર્ણાંક f2, f3;
    સંઘ union1 {
        પૂર્ણાંક v1;
        પૂર્ણાંક v2;
    } u;
    અક્ષર str[3];
} struct1;

સંરચના struct2 {
    પૂર્ણાંક a;
    અક્ષર b;
};

સંઘ union2 {
    પૂર્ણાંક w1;
    પૂર્ણાંક w2;
};

સંરચના struct1 st1, st2;

સંરચના empty_mem {
    /* nothing */ ;
    પૂર્ણાંક x;
};

પૂર્ણાંક tab[3];
પૂર્ણાંક tab2[3][2];

પૂર્ણાંક g;

શૂન્ય f1(પૂર્ણાંક g)
{
    printf("g1=%d\n", g);
}

શૂન્ય scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        પૂર્ણાંક g;
        g = 3;
        printf("g3=%d\n", g);
        {
            પૂર્ણાંક g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

પૂર્ણાંક st2_i;
પૂર્ણાંક *st2_p = &st2_i;
શૂન્ય scope2_test()
{
    અક્ષર a[50];
    st2_i = 42;
    માટે (પૂર્ણાંક st2_i = 1; st2_i < 10; st2_i++) {
        બાહ્ય પૂર્ણાંક st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
બાહ્ય પૂર્ણાંક st_global1;
પૂર્ણાંક st_global1=42;
બાહ્ય પૂર્ણાંક st_global1;
પૂર્ણાંક st_global1;
બાહ્ય પૂર્ણાંક st_global2;
પૂર્ણાંક st_global2;
બાહ્ય પૂર્ણાંક st_global2;
પૂર્ણાંક st_global2;

શૂન્ય array_test()
{
    પૂર્ણાંક i, j, a[4];

    printf("sizeof(a) = %d\n", કદ(a));
    printf("sizeof(\"a\") = %d\n", કદ("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", કદ(__func__));
#endif
    printf("sizeof tab %d\n", કદ(tab));
    printf("sizeof tab2 %d\n", કદ tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    માટે(i=0;i<3;i++)
        માટે(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    માટે(i=0;i<3*2;i++) {
        printf(" %3d", ((પૂર્ણાંક *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", કદ(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", કદ(ptrdiff_t));
}

શૂન્ય પદાવલિ_test()
{
    પૂર્ણાંક a, b;
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

પૂર્ણાંક isid(પૂર્ણાંક c)
{
    પાછા (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

પૂર્ણાંક vstack[10], *vstack_ptr;

શૂન્ય vpush(પૂર્ણાંક vt, પૂર્ણાંક vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

શૂન્ય vpop(પૂર્ણાંક *ft, પૂર્ણાંક *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

શૂન્ય expr2_test()
{
    પૂર્ણાંક a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

પૂર્ણાંક const_len_ar[કદ(1/0)]; /* div-by-zero, but in unevaluated context */

શૂન્ય constant_પદાવલિ_test()
{
    પૂર્ણાંક a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", કદ(const_len_ar));
}

પૂર્ણાંક tab4[10];

શૂન્ય પદાવલિ_ptr_test()
{
    પૂર્ણાંક arr[10], *p, *q;
    પૂર્ણાંક i = -1;

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
    p = (પૂર્ણાંક *)((અક્ષર *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        સંરચના size12 {
            પૂર્ણાંક i, j, k;
        };
        સંરચના size12 s[2], *sp = s;
        પૂર્ણાંક i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (પૂર્ણાંક*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (પૂર્ણાંક)((p - q) / 3));
}

શૂન્ય પદાવલિ_cmp_test()
{
    પૂર્ણાંક a, b;
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

સંરચના empty {
};

સંરચના aligntest1 {
    અક્ષર a[10];
};

સંરચના aligntest2 {
    પૂર્ણાંક a;
    અક્ષર b[10];
};

સંરચના aligntest3 {
    દ્વિગુણ a, b;
};

સંરચના aligntest4 {
    દ્વિગુણ a[0];
};

સંરચના __attribute__((aligned(16))) aligntest5
{
    પૂર્ણાંક i;
};
સંરચના aligntest6
{
    પૂર્ણાંક i;
} __attribute__((aligned(16)));
સંરચના aligntest7
{
    પૂર્ણાંક i;
};
સંરચના aligntest5 altest5[2];
સંરચના aligntest6 altest6[2];
પૂર્ણાંક pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
સંરચના aligntest7 altest7[2] __attribute__((aligned(16)));

સંરચના aligntest8
{
  પૂર્ણાંક i;
} __attribute__((aligned(4096)));

સંરચના Large {
    unsigned long flags;
    સંઘ {
	શૂન્ય *u1;
	પૂર્ણાંક *u2;
    };

    સંરચના {
	સંઘ {
	    unsigned long index;
	    શૂન્ય *freelist;
	};
	સંઘ {
	    unsigned long counters;
	    સંરચના {
		પૂર્ણાંક bla;
	    };
	};
    };

    સંઘ {
	સંરચના {
	    long u3;
	    long u4;
	};
	શૂન્ય *u5;
	સંરચના {
	    unsigned long compound_head;
	    unsigned પૂર્ણાંક compound_dtor;
	    unsigned પૂર્ણાંક compound_order;
	};
    };
} __attribute__((aligned(2 * કદ(long))));

પ્રકારવ્યાખ્યા unsigned long long __attribute__((aligned(4))) unaligned_u64;

સંરચના aligntest9 {
    unsigned પૂર્ણાંક buf_nr;
    unaligned_u64 start_lba;
};

સંરચના aligntest10 {
    unsigned પૂર્ણાંક buf_nr;
    unsigned long long start_lba;
};

શૂન્ય struct_test()
{
    struct1 *s;
    સંઘ union2 u;
    સંરચના Large ls;

    printf("sizes: %d %d %d %d\n",
           કદ(સંરચના struct1),
           કદ(સંરચના struct2),
           કદ(સંઘ union1),
           કદ(સંઘ union2));
    printf("offsets: %d\n", (પૂર્ણાંક)((અક્ષર*)&st1.u.v1 - (અક્ષર*)&st1));
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
    printf("str_addr=%x\n", (પૂર્ણાંક)(uintptr_t)st1.str - (પૂર્ણાંક)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest1), __alignof__(સંરચના aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest2), __alignof__(સંરચના aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest3), __alignof__(સંરચના aligntest3));
#જો !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest4), __alignof__(સંરચના aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest5), __alignof__(સંરચના aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest6), __alignof__(સંરચના aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest7), __alignof__(સંરચના aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest8), __alignof__(સંરચના aligntest8));
#જો !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest9), __alignof__(સંરચના aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           કદ(સંરચના aligntest10), __alignof__(સંરચના aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           કદ(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           કદ(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           કદ(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#જો !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", કદ(સંરચના empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(સંરચના empty));

    printf("Large: sizeof=%d\n", કદ(ls));
    memset(&ls, 0, કદ(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (પૂર્ણાંક)((અક્ષર*)&ls.compound_head - (અક્ષર*)&ls));
}

/* simulate char/short return value with undefined upper bits */
સ્થિર પૂર્ણાંક __csf(પૂર્ણાંક x) { પાછા x; }
સ્થિર શૂન્ય *_csf = __csf;
#define csf(t,n) ((t(*)(પૂર્ણાંક))_csf)(n)

/* XXX: depend on endianness */
શૂન્ય char_short_test()
{
    પૂર્ણાંક var1, var2;
    signed અક્ષર var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed અક્ષર *)&var1, *(signed અક્ષર *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned અક્ષર *)&var1, *(unsigned અક્ષર *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(પૂર્ણાંક *)&var1, *(પૂર્ણાંક *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned પૂર્ણાંક *)&var1, *(unsigned પૂર્ણાંક *)&var2);
    *(signed અક્ષર *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(પૂર્ણાંક *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed અક્ષર)(var1 + 1), (signed અક્ષર)(var4 + 1));
#જો !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned અક્ષર,0x89898989);
    var4 = csf(signed અક્ષર,0xabababab);
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
    var1 = (signed અક્ષર)(unsigned અક્ષર)(var3 + 1);
    var4 = (signed અક્ષર)(unsigned અક્ષર)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(પૂર્ણાંક)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed અક્ષર)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

પ્રકારવ્યાખ્યા સંરચના Sym {
    પૂર્ણાંક v;
    પૂર્ણાંક t;
    પૂર્ણાંક c;
    સંરચના Sym *next;
    સંરચના Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

સ્થિર પૂર્ણાંક toupper1(પૂર્ણાંક a)
{
    પાછા TOUPPER(a);
}

સ્થિર unsigned પૂર્ણાંક calc_vm_flags(unsigned પૂર્ણાંક prot)
{
  unsigned પૂર્ણાંક prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  પાછા prot_bits;
}

ગણના cast_enum { FIRST, LAST };

સ્થિર શૂન્ય tst_cast(ગણના cast_enum ce)
{
    printf("%d\n", ce);
}

શૂન્ય bool_test()
{
    પૂર્ણાંક *s, a, b, t, f, i;

    a = 0;
    s = (શૂન્ય*)0;
    printf("!s=%d\n", !s);

    જો (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#જો 1 && 1
    printf("a1\n");
#endif
#જો 1 || 0
    printf("a2\n");
#endif
#જો 1 ? 0 : 1
    printf("a3\n");
#endif
#જો 0 ? 0 : 1
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
    printf("type of bool: %d\n", (પૂર્ણાંક) ( (~ ((unsigned પૂર્ણાંક) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned પૂર્ણાંક)0)) / 2 );
    /* test ? : cast */
    {
        પૂર્ણાંક aspect_on;
        પૂર્ણાંક aspect_native = 65536;
        દ્વિગુણ bfu_aspect = 1.0;
        પૂર્ણાંક aspect;
        માટે(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        સ્થિર પૂર્ણાંક v1 = 34 ? : -1; /* constant case */
        સ્થિર પૂર્ણાંક v2 = 0 ? : -1; /* constant case */
        પૂર્ણાંક a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    માટે(i=0;i<256;i++) {
        જો (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

બાહ્ય પૂર્ણાંક undefined_function(શૂન્ય);
બાહ્ય પૂર્ણાંક defined_function(શૂન્ય);

#ifdef __clang__
પૂર્ણાંક undefined_function(શૂન્ય) {}
#endif

સ્થિર અંતઃરેખ શૂન્ય refer_to_undefined(શૂન્ય)
{
  undefined_function();
}

શૂન્ય optimize_out_test(શૂન્ય)
{
  પૂર્ણાંક i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  પૂર્ણાંક j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  જો (0)
    printf("oo:%d\n", undefined_function());
  નહીંતર
    printf("oo:%d\n", defined_function());
  જો (1)
    printf("oo:%d\n", defined_function());
  નહીંતર
    printf("oo:%d\n", undefined_function());
  જ્યારે (1) {
      printf("oow:%d\n", defined_function());
      તોડો;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  પસંદગી (j)
    સ્થિતિ 1: તોડો;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  જ્યારે (1)
    તોડો;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  કરો
    તોડો;
  જ્યારે (1);
  printf ("ool2:%d\n", defined_function());
  માટે (;;)
    તોડો;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  જ્યારે (1) {
	{
	  તોડો;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  જ્યારે (j) {
      જો (j == 0)
	તોડો; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  જ્યારે (j) {
      જો (1)
	j--;
      નહીંતર
	breakhere: તોડો;
      printf("ool6:%d\n", defined_function());
      જાઓ breakhere;
  }
  j = 1;
  જ્યારે (j) {
      j--;
      ચાલુ;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  જો (0 && undefined_function())
    undefined_function();
  જો (defined_function() && 0)
    undefined_function();
  જો (0 && 0)
    undefined_function();
  જો (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  જો (1 || undefined_function())
    ;
  નહીંતર
    undefined_function();
  જો (defined_function() || 1)
    ;
  નહીંતર
    undefined_function();
  જો (1 || 1)
    ;
  નહીંતર
    undefined_function();
  જો (defined_function() || 1 || undefined_function())
    ;
  નહીંતર
    undefined_function();

  જો (defined_function() && 0)
    refer_to_undefined();

  જો (0) {
      (શૂન્ય)કદ( ({
		     કરો { } જ્યારે (0);
		     0;
		     }) );
      undefined_function();
  }

  જો (0) {
      પસંદગી (defined_function()) {
          સ્થિતિ 0: undefined_function(); તોડો;
          મૂળભૂત: undefined_function(); તોડો;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  જો (1)
    પાછા;
  printf ("oor:%d\n", undefined_function());
}

પૂર્ણાંક defined_function(શૂન્ય)
{
  સ્થિર પૂર્ણાંક i = 40;
  પાછા i++;
}

/* GCC accepts that */
સ્થિર પૂર્ણાંક tab_reinit[];
સ્થિર પૂર્ણાંક tab_reinit[10];

સ્થિર પૂર્ણાંક tentative_ar[];
સ્થિર પૂર્ણાંક tentative_ar[] = {1,2,3};

પૂર્ણાંક cinit1; /* a global variable can be defined several times without error ! */
પૂર્ણાંક cinit1; 
પૂર્ણાંક cinit1 = 0;
પૂર્ણાંક *cinit2 = (પૂર્ણાંક []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
અક્ષર અચલ * અચલ cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
શૂન્ય *cinit52 = &(શૂન્ય*){ (શૂન્ય*) 52 };

#જો __TINYC__ || __GNUC__ >= 6
પૂર્ણાંક cinit4 = (પૂર્ણાંક){44};
શૂન્ય *cinit51 = (શૂન્ય*){ (શૂન્ય*) 51 };
સંરચના _c6 { પૂર્ણાંક a,b; } cinit6 = (સંરચના _c6){61,62}, *cinit7 = &(સંરચના _c6){71,72};
#નહીંતર
પૂર્ણાંક cinit4 = 44;
શૂન્ય *cinit51 = (શૂન્ય*)51;
સંરચના _c6 { પૂર્ણાંક a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

શૂન્ય compound_literal_test(શૂન્ય)
{
    પૂર્ણાંક *p, i;
    અક્ષર *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (પૂર્ણાંક)cinit51);
    printf("cinit52 : %d\n", *(પૂર્ણાંક*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (પૂર્ણાંક []){1, 2, 3};
    માટે(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    માટે(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (અક્ષર *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (અક્ષર *){ q };
    printf("q3=%s\n", q3);

    q = (અક્ષર []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (પૂર્ણાંક []){1, 2, cinit1 + 3};
    માટે(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    માટે(i=0;i<3;i++) {
        p = (પૂર્ણાંક []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#જો __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    પાછા a + b;
}

પૂર્ણાંક kr_func2(a, b)
{
    પાછા a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    પાછા 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
અક્ષર invalid_function_def()[] {પાછા 0;}

#નહીંતર
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

શૂન્ય અંક(પૂર્ણાંક n)
{
    અક્ષર *tab, *p;
    tab = (અક્ષર*)malloc(20); 
    p = tab;
    જ્યારે (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        જો (n == 0)
            તોડો;
    }
    જ્યારે (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    મુક્ત(tab);
}

/* structure assignment tests */
સંરચના structa1 {
    પૂર્ણાંક f1;
    અક્ષર f2;
};

શૂન્ય struct_assign_test1(સંરચના structa1 s1, પૂર્ણાંક t, દશાંશ f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

સંરચના structa1 struct_assign_test2(સંરચના structa1 s1, પૂર્ણાંક t)
{
    s1.f1 += t;
    s1.f2 -= t;
    પાછા s1;
}

શૂન્ય struct_assign_test(શૂન્ય)
{
    સંરચના S {
      સંરચના structa1 lsta1, lsta2;
      પૂર્ણાંક i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    સ્થિર સંરચના {
        શૂન્ય (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

શૂન્ય cast1(અક્ષર a, short b, unsigned અક્ષર c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

અક્ષર bcast;
short scast;

શૂન્ય cast_test()
{
    પૂર્ણાંક a;
    અક્ષર c;
    અક્ષર tab[10];
    unsigned b,d;
    short s;
    અક્ષર *p = ખાલી;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (અક્ષર)(a + 1),
           (short)(a + 1),
           (unsigned અક્ષર)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (અક્ષર)0xfffff,
           (short)0xfffff,
           (unsigned અક્ષર)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", કદ(c), કદ((પૂર્ણાંક)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (અક્ષર)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", કદ(+(અક્ષર)'a'));
    printf("sizeof(-(char)'a') = %d\n", કદ(-(અક્ષર)'a'));
    printf("sizeof(~(char)'a') = %d\n", કદ(-(અક્ષર)'a'));

#જો CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (પૂર્ણાંક)p, (unsigned પૂર્ણાંક)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (શૂન્ય *)a, (શૂન્ય *)b, (શૂન્ય *)c, (શૂન્ય *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(પૂર્ણાંક)ul);
}

/* initializers tests */
સંરચના structinit1 {
    પૂર્ણાંક f1;
    અક્ષર f2;
    short f3;
    પૂર્ણાંક farray[3];
};

પૂર્ણાંક sinit1 = 2;
પૂર્ણાંક sinit2 = { 3 };
પૂર્ણાંક sinit3[3] = { 1, 2, {3}, };
પૂર્ણાંક sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
પૂર્ણાંક sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
પૂર્ણાંક sinit6[] = { 1, 2, 3 };
પૂર્ણાંક sinit7[] = { [2] = 3, [0] = 1, 2 };
અક્ષર sinit8[] = "hello" "trala";

સંરચના structinit1 sinit9 = { 1, 2, 3 };
સંરચના structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
સંરચના structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

અક્ષર *sinit12 = "hello world";
અક્ષર *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
અક્ષર sinit14[10] = { "abc" };
પૂર્ણાંક sinit15[3] = { કદ(sinit15), 1, 2 };

સંરચના { પૂર્ણાંક a[3], b; } sinit16[] = { { 1 }, 2 };

સંરચના bar {
        અક્ષર *s;
        પૂર્ણાંક len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

પૂર્ણાંક sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

સંરચના complexinit0 {
    પૂર્ણાંક a;
    પૂર્ણાંક b;
};

સંરચના complexinit {
    પૂર્ણાંક a;
    અચલ સંરચના complexinit0 *b;
};

અચલ સ્થિર સંરચના complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (અચલ સંરચના complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

સંરચના complexinit2 {
	પૂર્ણાંક a;
	પૂર્ણાંક b[];
};

સંરચના complexinit2 cix20;

સંરચના complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

સંરચના complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

પ્રકારવ્યાખ્યા પૂર્ણાંક arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
પ્રકારવ્યાખ્યા પૂર્ણાંક arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
પૂર્ણાંક sinit23[2] = { "astring" ? કદ("astring") : -1,
		   &sinit23 ? 42 : -1 };

પૂર્ણાંક sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
સંરચના bf_SS {unsigned પૂર્ણાંક bit:1,bits31:31; };
સંરચના bf_SS bf_init = { .bit = 1 };
સંરચના bfn_SS {પૂર્ણાંક a,b; સંરચના bf_SS c; પૂર્ણાંક d,e; };
સંરચના bfn_SS bfn_init = { .c.bit = 1 };
સંરચના bfa_SS {પૂર્ણાંક a,b; સંરચના bf_SS c[3]; પૂર્ણાંક d,e; };
સંરચના bfa_SS bfa_init = { .c[1].bit = 1 };
સંરચના bf_SS bfaa_init[3] = { [1].bit = 1 };
સંરચના bf_SS bfaa_vinit[] = { [2].bit = 1 };
સંરચના b2_SS {long long પૂર્ણાંક field : 52; long long પૂર્ણાંક pad : 12; };
સંરચના b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

બાહ્ય પૂર્ણાંક external_inited = 42;

શૂન્ય init_test(શૂન્ય)
{
    પૂર્ણાંક linit1 = 2;
    પૂર્ણાંક linit2 = { 3 };
    પૂર્ણાંક linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    પૂર્ણાંક linit6[] = { 1, 2, 3 };
    પૂર્ણાંક i, j;
    અક્ષર linit8[] = "hello" "trala";
    પૂર્ણાંક linit12[10] = { 1, 2 };
    પૂર્ણાંક linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    અક્ષર linit14[10] = "abc";
    પૂર્ણાંક linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    સંરચના linit16 { પૂર્ણાંક a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    પૂર્ણાંક linit17 = કદ(linit17);
    પૂર્ણાંક zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    પૂર્ણાંક linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    સંરચના bf_SS bf_finit = { .bit = 1 };
    સંરચના bfn_SS bfn_finit = { .c.bit = 1 };
    સંરચના bfa_SS bfa_finit = { .c[1].bit = 1 };
    સંરચના bf_SS bfaa_finit[3] = { [1].bit = 1 };
    સંરચના bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    સંરચના b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           કદ(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", કદ(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           કદ(sinit7),
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

    માટે(i=0;i<3;i++)
        માટે(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", કદ(linit6));
    printf("linit8=%d %s\n", કદ(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           કદ(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    માટે(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    માટે(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    માટે(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    માટે(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    માટે(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", કદ cix20, કદ cix21, કદ cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", કદ(sinit19), કદ(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", કદ(sinit21), કદ(sinit22));
    printf("arrtype6: %d\n", કદ(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    માટે (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    માટે (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    માટે (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    માટે (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    માટે (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    માટે (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

શૂન્ય switch_uc(unsigned અક્ષર uc)
{
	પસંદગી (uc) {
	    સ્થિતિ 0xfb ... 0xfe:
		printf("ucsw:1\n");
		તોડો;
	    સ્થિતિ 0xff:
		printf("ucsw:2\n");
		તોડો;
	    સ્થિતિ 0 ... 5:
		printf("ucsw:3\n");
		તોડો;
	    મૂળભૂત:
		printf("ucsw: broken!\n");
	}
}

શૂન્ય switch_sc(signed અક્ષર sc)
{
	પસંદગી (sc) {
	    સ્થિતિ -5 ... -2:
		printf("scsw:1\n");
		તોડો;
	    સ્થિતિ -1:
		printf("scsw:2\n");
		તોડો;
	    સ્થિતિ 0 ... 5:
		printf("scsw:3\n");
		તોડો;
	    મૂળભૂત:
		printf("scsw: broken!\n");
	}
}

શૂન્ય switch_test()
{
    પૂર્ણાંક i;
    unsigned long long ull;
    long long ll;

    માટે(i=0;i<15;i++) {
        પસંદગી(i) {
        સ્થિતિ 0:
        સ્થિતિ 1:
            printf("a");
            તોડો;
        મૂળભૂત:
            printf("%d", i);
            તોડો;
        સ્થિતિ 8 ... 12:
            printf("c");
            તોડો;
        સ્થિતિ 3:
            printf("b");
            તોડો;
        સ્થિતિ 0xc33c6b9fU:
        સ્થિતિ 0x7c9eeeb9U:
            તોડો;
        }
    }
    printf("\n");

    માટે (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	પસંદગી (ull) {
	    સ્થિતિ 1ULL << 61:
		printf("ullsw:1\n");
		તોડો;
	    સ્થિતિ 2ULL << 61:
		printf("ullsw:2\n");
		તોડો;
	    સ્થિતિ 3ULL << 61:
		printf("ullsw:3\n");
		તોડો;
	    સ્થિતિ 4ULL << 61:
		printf("ullsw:4\n");
		તોડો;
	    સ્થિતિ 5ULL << 61:
		printf("ullsw:5\n");
		તોડો;
	    મૂળભૂત:
		printf("ullsw: broken!\n");
	}
    }

    માટે (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	પસંદગી (ll) {
	    સ્થિતિ 1LL << 61:
		printf("llsw:1\n");
		તોડો;
	    સ્થિતિ 2LL << 61:
		printf("llsw:2\n");
		તોડો;
	    સ્થિતિ 3LL << 61:
		printf("llsw:3\n");
		તોડો;
	    સ્થિતિ 4LL << 61:
		printf("llsw:4\n");
		તોડો;
	    સ્થિતિ 5LL << 61:
		printf("llsw:5\n");
		તોડો;
	    મૂળભૂત:
		printf("llsw: broken!\n");
	}
    }

    માટે (i = -5; i <= 5; i++) {
	switch_uc((unsigned અક્ષર)i);
    }

    માટે (i = -5; i <= 5; i++) {
	switch_sc ((signed અક્ષર)i);
    }
}

/* ISOC99 _Bool type */
શૂન્ય c99_bool_test(શૂન્ય)
{
#ifdef BOOL_ISOC99
    પૂર્ણાંક a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", કદ(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           કદ ((અસ્થિર પૂર્ણાંક)a ? b : b2));
#endif
}

શૂન્ય bitfield_test(શૂન્ય)
{
    પૂર્ણાંક a;
    short sa;
    unsigned અક્ષર ca;
    સંરચના sbf1 {
        પૂર્ણાંક f1 : 3;
        પૂર્ણાંક : 2;
        પૂર્ણાંક f2 : 1;
        પૂર્ણાંક : 0;
        પૂર્ણાંક f3 : 5;
        પૂર્ણાંક f4 : 7;
        unsigned પૂર્ણાંક f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", કદ(st1));

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
    જો (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    નહીંતર 
        printf("st1.f1 != -1\n");
    જો (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    નહીંતર 
        printf("st1.f2 != -1\n");

    સંરચના sbf2 {
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

#જો 0
    Disabled માટે now until further clarification re GCC compatibility
    સંરચના sbf3 {
        પૂર્ણાંક f1 : 7;
        પૂર્ણાંક f2 : 1;
        અક્ષર f3;
        પૂર્ણાંક f4 : 8;
        પૂર્ણાંક f5 : 1;
        પૂર્ણાંક f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", કદ(st3));
#endif

    સંરચના sbf4 {
	પૂર્ણાંક x : 31;
	અક્ષર y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    સંરચના sbf5 {
	પૂર્ણાંક a;
	અક્ષર b;
	પૂર્ણાંક x : 12, y : 4, : 0, : 4, z : 3;
	અક્ષર c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    સંરચના sbf6 {
	short x : 12;
	unsigned અક્ષર y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#નહીંતર
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
દ્વિગુણ strtod(અચલ અક્ષર *nptr, અક્ષર **endptr);

#જો defined(_WIN32)
દશાંશ strtof(અચલ અક્ષર *nptr, અક્ષર **endptr) {પાછા (દશાંશ)strtod(nptr, endptr);}
LONG_DOUBLE strtold(અચલ અક્ષર *nptr, અક્ષર **endptr) {પાછા (LONG_DOUBLE)strtod(nptr, endptr);}
#નહીંતર
દશાંશ strtof(અચલ અક્ષર *nptr, અક્ષર **endptr);
LONG_DOUBLE strtold(અચલ અક્ષર *nptr, અક્ષર **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
શૂન્ય prefix ## cmp(type a, type b)\
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
શૂન્ય prefix ## fcast(type a)\
{\
    દશાંશ fa;\
    દ્વિગુણ da;\
    LONG_DOUBLE la;\
    પૂર્ણાંક ia;\
    long long llia;\
    unsigned પૂર્ણાંક ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (પૂર્ણાંક)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned પૂર્ણાંક)a;\
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
    જો (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
દશાંશ prefix ## retf(type a) { પાછા a; }\
દ્વિગુણ prefix ## retd(type a) { પાછા a; }\
LONG_DOUBLE prefix ## retld(type a) { પાછા a; }\
\
શૂન્ય prefix ## call(શૂન્ય)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (દ્વિગુણ)strto ## prefix("1.2", ખાલી));\
}\
\
શૂન્ય prefix ## signed_zeros(શૂન્ય) \
{\
  type x = 0.0, y = -0.0, n, p;\
  જો (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  નહીંતર\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  જો (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  નહીંતર\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  જો (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  નહીંતર\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  જો (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  નહીંતર\
    printf ("x != -y; this is wrong!\n");\
}\
શૂન્ય prefix ## nan(શૂન્ય)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
શૂન્ય prefix ## test(શૂન્ય)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    જો (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, દશાંશ, દશાંશ, "%f")
FTEST(d, દ્વિગુણ, દ્વિગુણ, "%f")
FTEST(ld, long દ્વિગુણ, LONG_DOUBLE, "%Lf")

દ્વિગુણ ftab1[3] = { 1.2, 3.4, -5.6 };


શૂન્ય float_test(શૂન્ય)
{
#જો !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    અસ્થિર દશાંશ fa, fb;
    અસ્થિર દ્વિગુણ da, db;
    પૂર્ણાંક a;
    unsigned પૂર્ણાંક b;
    સ્થિર દ્વિગુણ nan2 = 0.0/0.0;
    સ્થિર દ્વિગુણ inf1 = 1.0/0.0;
    સ્થિર દ્વિગુણ inf2 = 1e5000;
    અસ્થિર LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", કદ(દશાંશ));
    printf("sizeof(double) = %d\n", કદ(દ્વિગુણ));
    printf("sizeof(long double) = %d\n", કદ(LONG_DOUBLE));
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

પૂર્ણાંક fib(પૂર્ણાંક n)
{
    જો (n <= 2)
        પાછા 1;
    નહીંતર
        પાછા fib(n-1) + fib(n-2);
}

#જો __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#નહીંતર
શૂન્ય __attribute__((aligned(16))) aligned_function(પૂર્ણાંક i) {}
#endif

શૂન્ય funcptr_test()
{
    શૂન્ય (*func)(પૂર્ણાંક);
    પૂર્ણાંક a;
    સંરચના {
        પૂર્ણાંક dummy;
        શૂન્ય (*func)(પૂર્ણાંક);
    } st1;
    long diff;

    func = &અંક;
    (*func)(12345);
    func = અંક;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = અંક;
    st1.func(12346);
    printf("sizeof1 = %d\n", કદ(funcptr_test));
    printf("sizeof2 = %d\n", કદ funcptr_test);
    printf("sizeof3 = %d\n", કદ(&funcptr_test));
    printf("sizeof4 = %d\n", કદ &funcptr_test);
    a = 0;
    func = અંક + a;
    diff = func - અંક;
    func(42);
    (func + diff)(42);
    (અંક + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((પૂર્ણાંક)(uintptr_t)func) & 15);
}

શૂન્ય lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    જો (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /*દ્વિઅંકી*/
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

શૂન્ય llshift(long long a, પૂર્ણાંક b)
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

શૂન્ય llfloat(શૂન્ય)
{
    દશાંશ fa;
    દ્વિગુણ da;
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

long long llfunc1(પૂર્ણાંક a)
{
    પાછા a * 2;
}

સંરચના S {
    પૂર્ણાંક id; 
    અક્ષર item;
};

long long પૂર્ણાંક કિંમત(સંરચના S *v)
{
    પાછા ((long long પૂર્ણાંક)v->item);
}

long long llfunc2(long long x, long long y, પૂર્ણાંક z)
{
    પાછા x * y * z;
}

શૂન્ય check_opl_save_regs(અક્ષર *a, long long b, પૂર્ણાંક c)
{
    *a = b < 0 && !c;
}

શૂન્ય longlong_test(શૂન્ય)
{
    long long a, b, c;
    પૂર્ણાંક ia;
    unsigned પૂર્ણાંક ua;
    printf("sizeof(long long) = %d\n", કદ(long long));
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
#જો 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          સંરચના S a;

          a.item = 3;
          printf("%lld\n", કિંમત(&a));
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
    u = (unsigned)(પૂર્ણાંક)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    અક્ષર cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

શૂન્ય manyarg_test(શૂન્ય)
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

શૂન્ય*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        સંરચના X { પૂર્ણાંક _x; };
        સંરચના X *x = va_arg(ap, સંરચના X *);
        પાછા x;
}

શૂન્ય vprintf1(અચલ અક્ષર *fmt, ...)
{
    va_list ap, aq;
    અચલ અક્ષર *p;
    પૂર્ણાંક c, i;
    દ્વિગુણ d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    માટે(;;) {
        c = *p;
        જો (c == '\0')
            તોડો;
        p++;
        જો (c == '%') {
            c = *p;
            પસંદગી(c) {
            સ્થિતિ '\0':
                જાઓ the_end;
            સ્થિતિ 'd':
                i = va_arg(ap, પૂર્ણાંક);
                printf("%d", i);
                તોડો;
            સ્થિતિ 'f':
                d = va_arg(ap, દ્વિગુણ);
                printf("%f", d);
                તોડો;
            સ્થિતિ 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                તોડો;
            સ્થિતિ 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                તોડો;
            }
            p++;
        } નહીંતર {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

સંરચના myspace {
    short પૂર્ણાંક profile;
};
સંરચના myspace2 {
#જો CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    અક્ષર a[1];
#નહીંતર
    અક્ષર a[0];
#endif
};
સંરચના myspace3 {
    અક્ષર a[1];
};
સંરચના myspace4 {
    અક્ષર a[2];
};
સંરચના mytest {
    શૂન્ય *foo, *bar, *baz;
};

સંરચના mytest stdarg_for_struct(સંરચના myspace bob, ...)
{
    સંરચના myspace george, bill;
    સંરચના myspace2 alex1;
    સંરચના myspace3 alex2;
    સંરચના myspace4 alex3;
    va_list ap;
    short પૂર્ણાંક validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, સંરચના myspace2);
    alex2    = va_arg(ap, સંરચના myspace3);
    alex3    = va_arg(ap, સંરચના myspace4);
    bill     = va_arg(ap, સંરચના myspace);
    george   = va_arg(ap, સંરચના myspace);
    validate = va_arg(ap, પૂર્ણાંક);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    પાછા (સંરચના mytest) {};
}

શૂન્ય stdarg_for_libc(અચલ અક્ષર *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

શૂન્ય stdarg_syntax(પૂર્ણાંક n, ...)
{
    પૂર્ણાંક i;
    va_list ap;
    જો (1)
      va_start(ap, n);
    નહીંતર
      ;
    i = va_arg(ap, પૂર્ણાંક);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

પ્રકારવ્યાખ્યા સંરચના{
    દ્વિગુણ x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

સ્થિર શૂન્ય stdarg_double_struct(પૂર્ણાંક nargs, પૂર્ણાંક posd,...)
{
    પૂર્ણાંક i;
    દ્વિગુણ d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    માટે(i = 0; i < nargs; i++) {
        જો (i == posd) {
            d = va_arg (args, દ્વિગુણ);
            printf ("d %d = %g\n", i, d);
        }
        નહીંતર {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

શૂન્ય stdarg_test(શૂન્ય)
{
    LONG_DOUBLE ld = 1234567891234LL;
    સંરચના myspace bob;
    સંરચના myspace2 bob2;
    સંરચના myspace3 bob3;
    સંરચના myspace4 bob4;

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
#જો !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

પૂર્ણાંક reltab[3] = { 1, 2, 3 };

પૂર્ણાંક *rel1 = &reltab[1];
પૂર્ણાંક *rel2 = &reltab[2];

શૂન્ય getmyaddress(શૂન્ય)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(શૂન્ય)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       પાછા ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
શૂન્ય relocation_test(શૂન્ય)
{
    શૂન્ય (*fptr)(શૂન્ય) = (શૂન્ય (*)(શૂન્ય))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

શૂન્ય old_style_f(a,b,c)
     પૂર્ણાંક a, b;
     દ્વિગુણ c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

શૂન્ય decl_func1(પૂર્ણાંક cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

શૂન્ય decl_func2(cmpfn)
પૂર્ણાંક cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

શૂન્ય old_style_function_test(શૂન્ય)
{
#જો CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#નહીંતર
    old_style_f((શૂન્ય *)1, 2, 3.0);
#endif
    decl_func1(ખાલી);
    decl_func2(ખાલી);
}

શૂન્ય alloca_test()
{
    અક્ષર *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    અક્ષર *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

શૂન્ય *bounds_checking_is_enabled()
{
    અક્ષર ca[10], *cp = ca-1;
    પાછા (ca != cp + 1) ? cp : ખાલી;
}

પ્રકારવ્યાખ્યા પૂર્ણાંક constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

શૂન્ય c99_vla_test_1(પૂર્ણાંક size1, પૂર્ણાંક size2)
{
    પૂર્ણાંક size = size1 * size2;
    પૂર્ણાંક tab1[size][2], tab2[10][2];
    શૂન્ય *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (કદ tab1 == size1 * size2 * 2 * કદ(પૂર્ણાંક)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (કદ(પૂર્ણાંક) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * કદ(પૂર્ણાંક)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((પૂર્ણાંક *) (tab1_ptr + (size1 * 2 + 1) * કદ(પૂર્ણાંક))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    જો (bad_ptr = bounds_checking_is_enabled()) {
        પૂર્ણાંક *t1 = &tab1[size1 * size2 - 1][3];
        પૂર્ણાંક *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        અક્ષર*c1 = 1 + કદ(tab1) + (અક્ષર*)tab1;
        અક્ષર*c2 = 1 + કદ(tab2) + (અક્ષર*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        પૂર્ણાંક *i1 = tab1[-1];
        પૂર્ણાંક *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        પૂર્ણાંક *x1 = tab1[size1 * size2 + 1];
        પૂર્ણાંક *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } નહીંતર {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

શૂન્ય c99_vla_test_2(પૂર્ણાંક d, પૂર્ણાંક h, પૂર્ણાંક w)
{
    પૂર્ણાંક x, y, z;
    પૂર્ણાંક (*arr)[h][w] = malloc(કદ(પૂર્ણાંક) * d*h*w);
    પૂર્ણાંક c = 1;
    સ્થિર પૂર્ણાંક (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    માટે (z=0; z<d; z++) {
        માટે (y=0; y<h; y++) {
            માટે (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    માટે (z=0; z<d; z++) {
        માટે (y=0; y<h; y++) {
            માટે (x=0; x<w; x++) {
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
        કદ (*arr), કદ (*arr)[0], કદ (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == કદ (*arr + 1) - કદ arr,
        0 == કદ કદ *arr - કદ arr,
        starr[0][2][3] == arr[1][2][3]
        );
    મુક્ત (arr);
}

શૂન્ય c99_vla_test_3a (પૂર્ણાંક arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

શૂન્ય c99_vla_test_3b(પૂર્ણાંક s, પૂર્ણાંક arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

શૂન્ય c99_vla_test_3c(પૂર્ણાંક s, પૂર્ણાંક arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

શૂન્ય c99_vla_test_3d(પૂર્ણાંક s, પૂર્ણાંક arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

શૂન્ય c99_vla_test_3e(પૂર્ણાંક s, પૂર્ણાંક arr[][3][--s])
{
    printf ("%d %d %d\n", કદ arr, s, arr[1][2][3]);
}

શૂન્ય c99_vla_test_3(શૂન્ય)
{
    પૂર્ણાંક a[2][3][4];

    memset (a, 0, કદ(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

શૂન્ય c99_vla_test(શૂન્ય)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


શૂન્ય sizeof_test(શૂન્ય)
{
    પૂર્ણાંક a;
    પૂર્ણાંક **ptr;

    printf("sizeof(int) = %d\n", કદ(પૂર્ણાંક));
    printf("sizeof(unsigned int) = %d\n", કદ(unsigned પૂર્ણાંક));
    printf("sizeof(long) = %d\n", કદ(long));
    printf("sizeof(unsigned long) = %d\n", કદ(unsigned long));
    printf("sizeof(short) = %d\n", કદ(short));
    printf("sizeof(unsigned short) = %d\n", કદ(unsigned short));
    printf("sizeof(char) = %d\n", કદ(અક્ષર));
    printf("sizeof(unsigned char) = %d\n", કદ(unsigned અક્ષર));
    printf("sizeof(func) = %d\n", કદ sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", કદ a++);
    printf("a=%d\n", a);
    ptr = ખાલી;
    printf("sizeof(**ptr) = %d\n", કદ (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", કદ(કદ(પૂર્ણાંક)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -કદ(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(પૂર્ણાંક));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned પૂર્ણાંક));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(અક્ષર));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned અક્ષર));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", કદ(અક્ષર[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   કદ( (સંરચના {પૂર્ણાંક i; પૂર્ણાંક j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   કદ (સંરચના {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", કદ(t && 0));
    printf("sizeof(1 && 1) = %d\n", કદ(1 && 1));
    printf("sizeof(t || 1) = %d\n", કદ(t || 1));
    printf("sizeof(0 || 0) = %d\n", કદ(0 || 0));

    પૂર્ણાંક arr[4], fn();
    printf("sizeof(0, arr) = %d\n", કદ(0, arr));
    printf("sizeof(0, fn) = %d\n", કદ(0, fn));
}

શૂન્ય typeof_test(શૂન્ય)
{
    દ્વિગુણ a;
    typeof(a) b;
    typeof(દશાંશ) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


સંરચના hlist_ગાંઠ;
સંરચના hlist_head {
    સંરચના hlist_ગાંઠ *first, *last;
};

શૂન્ય consume_ulong (unsigned long i)
{
    i = 0;
}

શૂન્ય statement_પદાવલિ_test(શૂન્ય)
{
    પૂર્ણાંક a, i;

    /* Basic stmt expr test */
    a = 0;
    માટે(i=0;i<10;i++) {
        a += 1 + 
            ( { પૂર્ણાંક b, j; 
                b = 0; 
                માટે(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    શૂન્ય *v = (શૂન્ય*)39;
    typeof(({
	    (સંરચના hlist_ગાંઠ *)v;
	    })) x;
    typeof (x)
	ptr = (સંરચના hlist_ગાંઠ *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            સ્થિર અચલ અક્ષર *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    પૂર્ણાંક t = 40;
    પૂર્ણાંક b = ({ પૂર્ણાંક t = 41; t; });
    પૂર્ણાંક c = ({ પૂર્ણાંક t = 42; t; });

    /* Test that aggregate return values work.  */
    સંરચના hlist_head h
	= ({
	   પ્રકારવ્યાખ્યા સંરચના hlist_head T;
	   long pre = 48;
	   T t = { (શૂન્ય*)43, (શૂન્ય*)44 };
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
       LBL: જો (i++ == 0) જાઓ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      જાઓ LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

શૂન્ય local_label_test(શૂન્ય)
{
    પૂર્ણાંક a;
    જાઓ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        જાઓ l1;
    l4:
        printf("aa1\n");
        જાઓ l3;
    l2:
        printf("aa3\n");
        જાઓ l4;
    l1:
        printf("aa2\n");
        જાઓ l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    પાછા;
 l4:
    printf("bb1\n");
    જાઓ l2;
 l1:
    printf("bb2\n");
    જાઓ l4;
}

/* inline assembler test */
#જો (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

પ્રકારવ્યાખ્યા __SIZE_TYPE__ word;

/* from linux kernel */
સ્થિર અક્ષર * strncat1(અક્ષર * dest,અચલ અક્ષર * src,size_t ગણતરી_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ગણતરી_2)
	: "memory");
પાછા dest;
}

સ્થિર અક્ષર * strncat2(અક્ષર * dest,અચલ અક્ષર * src,size_t ગણતરી_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (ગણતરી_2)
	: "memory");
પાછા dest;
}

સ્થિર અંતઃરેખ શૂન્ય * memcpy1(શૂન્ય * to, અચલ શૂન્ય * from, size_t n)
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
પાછા (to);
}

સ્થિર અંતઃરેખ શૂન્ય * memcpy2(શૂન્ય * to, અચલ શૂન્ય * from, size_t n)
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
પાછા (to);
}

સ્થિર __inline__ શૂન્ય sigaddset1(unsigned પૂર્ણાંક *set, પૂર્ણાંક _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

સ્થિર __inline__ શૂન્ય sigdelset1(unsigned પૂર્ણાંક *set, પૂર્ણાંક _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
સ્થિર __inline__ __const__ unsigned પૂર્ણાંક swab32(unsigned પૂર્ણાંક x)
{
        પાછા ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#નહીંતર
સ્થિર __inline__ __const__ unsigned પૂર્ણાંક swab32(unsigned પૂર્ણાંક x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	પાછા x;
}
#endif

સ્થિર __inline__ unsigned long long mul64(unsigned પૂર્ણાંક a, unsigned પૂર્ણાંક b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned પૂર્ણાંક resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#નહીંતર
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    પાછા res;
}

સ્થિર __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#નહીંતર
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    પાછા res;
}

સંરચના struct123 {
    પૂર્ણાંક a;
    પૂર્ણાંક b;
};
સંરચના struct1231 {
    word addr;
};

word mconstraint_test(સંરચના struct1231 *r)
{
    word ret;
    unsigned પૂર્ણાંક a[2];
    a[0] = 0;
    __asm__ અસ્થિર ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(સંરચના struct123 *)r->addr));
    પાછા ret + a[0];
}

#ifdef __x86_64__
પૂર્ણાંક fls64(unsigned long long x)
{
  પૂર્ણાંક bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  પાછા bitpos + 1;
}
#endif

શૂન્ય other_constraints_test(શૂન્ય)
{
    word ret;
    પૂર્ણાંક var;
#જો CC_NAME != CC_clang
    __asm__ અસ્થિર ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
શૂન્ય base_func(શૂન્ય)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
બાહ્ય શૂન્ય override_func1 (શૂન્ય);
બાહ્ય શૂન્ય override_func2 (શૂન્ય);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

શૂન્ય override_func2 (શૂન્ય)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
બાહ્ય પૂર્ણાંક bug_table[] __attribute__((section("__bug_table")));
અક્ષર * get_asm_string (શૂન્ય)
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
  બાહ્ય પૂર્ણાંક some_પ્રતીક;
  asm અસ્થિર (".globl some_symbol\n"
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
  અક્ષર * str = ((અક્ષર*)bug_table) + bug_table[1];
  પાછા str;
#નહીંતર
  પાછા (અક્ષર *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
બાહ્ય unsigned અક્ષર alld_stuff[];
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

શૂન્ય asm_local_label_diff (શૂન્ય)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
શૂન્ય asm_local_statics (શૂન્ય)
{
  સ્થિર પૂર્ણાંક localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

સ્થિર
unsigned પૂર્ણાંક set;

શૂન્ય fancy_copy (unsigned *in, unsigned *out)
{
  asm અસ્થિર ("" : "=r" (*out) : "0" (*in));
}

શૂન્ય fancy_copy2 (unsigned *in, unsigned *out)
{
  asm અસ્થિર ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#જો defined __x86_64__
શૂન્ય clobber_r12(શૂન્ય)
{
    asm અસ્થિર("mov $1, %%r12" ::: "r12");
}
#endif

શૂન્ય test_ઉપલું_clobbers_really(શૂન્ય)
{
#જો defined __x86_64__
    નોંધણી word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm અસ્થિર("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm અસ્થિર("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

શૂન્ય test_ઉપલું_clobbers(શૂન્ય)
{
#જો defined __x86_64__
    word x1, x2;
    asm અસ્થિર("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ઉપલું_clobbers_really();
    asm અસ્થિર("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm અસ્થિર("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

સ્થિર long cpu_સંખ્યા;
શૂન્ય trace_console(long len, long len2)
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
    જો (0
        &&
            ({
              long pscr_ret__;
              પસંદગી(len) {
                સ્થિતિ 4:
                    {
                       long pfo_ret__;
                       પસંદગી (len2) {
                         સ્થિતિ 8:	printf("bla"); pfo_ret__ = 42; તોડો;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  તોડો;
                સ્થિતિ 8:
                    {
                       long pfo_ret__;
                       પસંદગી (len2) {
                         સ્થિતિ 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_સંખ્યા));	તોડો;
                         સ્થિતિ 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_સંખ્યા));	તોડો;
                         સ્થિતિ 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_સંખ્યા));	તોડો;
                         સ્થિતિ 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_સંખ્યા));	તોડો;
                         મૂળભૂત: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  તોડો;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

શૂન્ય test_asm_dead_code(શૂન્ય)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm અસ્થિર ("" : "=D" (rdi) : "0" (0));
  (શૂન્ય)કદ (({
      પૂર્ણાંક var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm અસ્થિર ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

શૂન્ય test_asm_call(શૂન્ય)
{
#જો defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  સ્થિર અક્ષર str[] = "PATH";
  અક્ષર *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm અસ્થિર ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#જો 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#નહીંતર
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#જો defined __x86_64__
# define RX "(%rip)"
#નહીંતર
# define RX
#endif

શૂન્ય asm_dot_test(શૂન્ય)
{
#ifndef __APPLE__
    પૂર્ણાંક x;
    માટે (x = 1;; ++x) {
        પૂર્ણાંક r = x;
        પસંદગી (x) {
        સ્થિતિ 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        સ્થિતિ 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#નહીંતર
            asm(".text; mov $123, %eax; jmp p0");
#endif
	સ્થિતિ 3:
#જો !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#નહીંતર
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        સ્થિતિ 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#નહીંતર
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#નહીંતર
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        સ્થિતિ 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); તોડો;
	}
        જો (r == x)
            તોડો;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

શૂન્ય asm_pcrel_test(શૂન્ય)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

શૂન્ય asm_test(શૂન્ય)
{
    અક્ષર buf[128];
    unsigned પૂર્ણાંક val, val2;
    સંરચના struct123 s1;
    સંરચના struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    પૂર્ણાંક base_func = 42;
    શૂન્ય override_func3 (શૂન્ય);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    નોંધણી પૂર્ણાંક regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm અસ્થિર ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm અસ્થિર ("xorl %eax, %eax");

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
    જાઓ label1;
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
    asm અસ્થિર(".weak override_func3\n.set override_func3, base_func");
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
    asm અસ્થિર("" : "=r" (asmret) : "0"(s2));
    જો (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm અસ્થિર("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    જો (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm અસ્થિર ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_ઉપલું_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    પાછા;
 label1:
    જાઓ label2;
}

#નહીંતર

શૂન્ય asm_test(શૂન્ય)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

પૂર્ણાંક constant_p_var;

પૂર્ણાંક func(શૂન્ય);


/* __builtin_clz and __builtin_ctz return random values for 0 */
સ્થિર શૂન્ય builtin_test_bits(unsigned long long x, પૂર્ણાંક cnt[])
{
#જો GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    જો ((unsigned પૂર્ણાંક) x) cnt[3] += __builtin_clz(x);
    જો ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    જો ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    જો ((unsigned પૂર્ણાંક) x) cnt[6] += __builtin_ctz(x);
    જો ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    જો ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#જો GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

શૂન્ય builtin_test(શૂન્ય)
{
    short s;
    પૂર્ણાંક i;
    long long ll;
#જો GCC_MAJOR >= 3
    COMPAT_TYPE(પૂર્ણાંક, પૂર્ણાંક);
    COMPAT_TYPE(પૂર્ણાંક, unsigned પૂર્ણાંક);
    COMPAT_TYPE(પૂર્ણાંક, અક્ષર);
    COMPAT_TYPE(પૂર્ણાંક, અચલ પૂર્ણાંક);
    COMPAT_TYPE(પૂર્ણાંક, અસ્થિર પૂર્ણાંક);
    COMPAT_TYPE(પૂર્ણાંક[2], અચલ પૂર્ણાંક[2]);
    COMPAT_TYPE(પૂર્ણાંક[2][3], અસ્થિર પૂર્ણાંક[][3]);
    COMPAT_TYPE(પૂર્ણાંક (*)[], અચલ પૂર્ણાંક (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (અચલ પૂર્ણાંક (*)[2])0 : (પૂર્ણાંક (*)[2])0),
                અચલ પૂર્ણાંક (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (અચલ પૂર્ણાંક (*)[2][3])0 :
                              (અસ્થિર પૂર્ણાંક (*)[2][3])0),
                અચલ અસ્થિર પૂર્ણાંક (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (અસ્થિર પૂર્ણાંક (*)[2][3])0 :
                              (અચલ પૂર્ણાંક (*)[2][3])0),
                અચલ અસ્થિર પૂર્ણાંક (*)[2][3]);
#નહીંતર
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(પૂર્ણાંક *, પૂર્ણાંક *);
    COMPAT_TYPE(પૂર્ણાંક *, શૂન્ય *);
    COMPAT_TYPE(પૂર્ણાંક *, અચલ પૂર્ણાંક *);
    COMPAT_TYPE(અક્ષર *, unsigned અક્ષર *);
    COMPAT_TYPE(અક્ષર *, signed અક્ષર *);
    COMPAT_TYPE(અક્ષર *, અક્ષર *);
    COMPAT_TYPE(અક્ષર **, શૂન્ય *);
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
#નહીંતર
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
    i = કદ (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = કદ (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	પૂર્ણાંક cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, કદ(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        માટે (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        માટે (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	માટે (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#જો defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
શૂન્ય weak_test(શૂન્ય) {}
#નહીંતર
બાહ્ય પૂર્ણાંક __attribute__((weak)) weak_f1(શૂન્ય);
બાહ્ય પૂર્ણાંક __attribute__((weak)) weak_f2(શૂન્ય);
બાહ્ય પૂર્ણાંક                       weak_f3(શૂન્ય);
બાહ્ય પૂર્ણાંક __attribute__((weak)) weak_v1;
બાહ્ય પૂર્ણાંક __attribute__((weak)) weak_v2;
બાહ્ય પૂર્ણાંક                       weak_v3;

બાહ્ય પૂર્ણાંક                           (*weak_fpa)() __attribute__((weak));
બાહ્ય પૂર્ણાંક __attribute__((weak))     (*weak_fpb)();
બાહ્ય     __attribute__((weak)) પૂર્ણાંક (*weak_fpc)();

બાહ્ય પૂર્ણાંક                     weak_asm_f1(શૂન્ય) asm("weak_asm_f1x") __attribute((weak));
બાહ્ય પૂર્ણાંક __attribute((weak)) weak_asm_f2(શૂન્ય) asm("weak_asm_f2x")                    ;
બાહ્ય પૂર્ણાંક __attribute((weak)) weak_asm_f3(શૂન્ય) asm("weak_asm_f3x") __attribute((weak));
બાહ્ય પૂર્ણાંક                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
બાહ્ય પૂર્ણાંક __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
બાહ્ય પૂર્ણાંક __attribute((weak)) weak_asm_v3(શૂન્ય) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
સ્થિર અચલ size_t dummy = 0;
બાહ્ય __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
બાહ્ય __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
બાહ્ય __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

પૂર્ણાંક some_lib_func(શૂન્ય);
પૂર્ણાંક dummy_impl_of_slf(શૂન્ય) { પાછા 444; }
#ifndef __clang__
પૂર્ણાંક some_lib_func(શૂન્ય) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

પૂર્ણાંક weak_toolate() __attribute__((weak));
પૂર્ણાંક weak_toolate() { પાછા 0; }

શૂન્ય __attribute__((weak)) weak_test(શૂન્ય)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != ખાલી);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != ખાલી);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != ખાલી);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != ખાલી);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != ખાલી);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != ખાલી);
#ifdef __clang__
	printf("some_lib_func=444\n");
#નહીંતર
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

પૂર્ણાંક __attribute__((weak)) weak_f2() { પાછા 222; }
પૂર્ણાંક __attribute__((weak)) weak_f3() { પાછા 333; }
પૂર્ણાંક __attribute__((weak)) weak_v2 = 222;
પૂર્ણાંક __attribute__((weak)) weak_v3 = 333;
#endif

શૂન્ય const_func(અચલ પૂર્ણાંક a)
{
}

શૂન્ય const_warn_test(શૂન્ય)
{
    const_func(1);
}

સંરચના condstruct {
  પૂર્ણાંક i;
};

પૂર્ણાંક getme (સંરચના condstruct *s, પૂર્ણાંક i)
{
  પૂર્ણાંક i1 = (i == 0 ? 0 : s)->i;
  પૂર્ણાંક i2 = (i == 0 ? s : 0)->i;
  પૂર્ણાંક i3 = (i == 0 ? (શૂન્ય*)0 : s)->i;
  પૂર્ણાંક i4 = (i == 0 ? s : (શૂન્ય*)0)->i;
  પાછા i1 + i2 + i3 + i4;
}

સંરચના global_data
{
  પૂર્ણાંક a[40];
  પૂર્ણાંક *b[40];
};

સંરચના global_data global_data;

પૂર્ણાંક global_data_getstuff (પૂર્ણાંક *, પૂર્ણાંક);

શૂન્ય global_data_callit (પૂર્ણાંક i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

પૂર્ણાંક global_data_getstuff (પૂર્ણાંક *p, પૂર્ણાંક i)
{
  પાછા *p + i;
}

શૂન્ય global_data_test (શૂન્ય)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

સંરચના cmpcmpS
{
  unsigned અક્ષર fill : 3;
  unsigned અક્ષર b1 : 1;
  unsigned અક્ષર b2 : 1;
  unsigned અક્ષર fill2 : 3;
};

પૂર્ણાંક glob1, glob2, glob3;

શૂન્ય compare_comparisons (સંરચના cmpcmpS *s)
{
  જો (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

શૂન્ય cmp_comparison_test(શૂન્ય)
{
  સંરચના cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

પૂર્ણાંક fcompare (દ્વિગુણ a, દ્વિગુણ b, પૂર્ણાંક code)
{
  પસંદગી (code) {
    સ્થિતિ 0: પાછા a == b;
    સ્થિતિ 1: પાછા a != b;
    સ્થિતિ 2: પાછા a < b;
    સ્થિતિ 3: પાછા a >= b;
    સ્થિતિ 4: પાછા a > b;
    સ્થિતિ 5: પાછા a <= b;
  }
  પાછા 0;
}

શૂન્ય math_cmp_test(શૂન્ય)
{
  દ્વિગુણ nan = 0.0/0.0;
  દ્વિગુણ one = 1.0;
  દ્વિગુણ two = 2.0;
  પૂર્ણાંક comp = 0;
  પૂર્ણાંક v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  જો (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  જો (a op b) \
    bug (a,b,op,iop,2); \
  જો (a iop b) \
    ; \
  નહીંતર \
    bug (a,b,op,iop,3); \
  જો ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  જો ((a iop b) || comp) \
    ; \
  નહીંતર \
    bug (a,b,op,iop,5); \
  જો (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  જો (!fcompare (nan, nan, 1))
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

દ્વિગુણ get100 () { પાછા 100.0; }

શૂન્ય callsave_test(શૂન્ય)
{
  પૂર્ણાંક i, s; દ્વિગુણ *d; દ્વિગુણ t;
  s = કદ (દ્વિગુણ);
  printf ("callsavetest: %d\n", s);
  d = alloca (કદ(દ્વિગુણ));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


શૂન્ય bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (અક્ષર *)__builtin_frame_address(3) + str_offset);
}
શૂન્ય bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (અક્ષર *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
શૂન્ય bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (અક્ષર *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

શૂન્ય builtin_frame_address_test(શૂન્ય)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    અક્ષર str[] = "__builtin_frame_address";
    અક્ષર *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

અક્ષર via_volatile (અક્ષર i)
{
  અક્ષર અસ્થિર vi;
  vi = i;
  પાછા vi;
}

શૂન્ય volatile_test(શૂન્ય)
{
    જો (via_volatile (42) != 42)
      printf (" broken\n");
    નહીંતર
      printf (" ok\n");
}

સંરચના __attribute__((__packed__)) Spacked {
    અક્ષર a;
    short b;
    પૂર્ણાંક c;
};
સંરચના Spacked spacked;
પ્રકારવ્યાખ્યા સંરચના __attribute__((__packed__)) {
    અક્ષર a;
    short b;
    પૂર્ણાંક c;
} Spacked2;
Spacked2 spacked2;
પ્રકારવ્યાખ્યા સંરચના Spacked3_s {
    અક્ષર a;
    short b;
    પૂર્ણાંક c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
સંરચના gate_struct64 {
    unsigned short offset_નીચલું;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_મધ્ય;
    unsigned offset_ઉપલું;
    unsigned zero1;
} __attribute__((packed));
પ્રકારવ્યાખ્યા સંરચના gate_struct64 gate_desc;
gate_desc a_gate_desc;
શૂન્ય attrib_test(શૂન્ય)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", કદ(સંરચના Spacked),
	 કદ(spacked), કદ(Spacked2), કદ(spacked2));
  printf("attr: %d %d\n", કદ(Spacked3), કદ(spacked3));
  printf("attr: %d %d\n", કદ(gate_desc), કદ(a_gate_desc));
#endif
}
બાહ્ય __attribute__((__unused__)) અક્ષર * __attribute__((__unused__)) *
strange_attrib_placement (શૂન્ય);

શૂન્ય * __attribute__((__unused__)) get_void_ptr (શૂન્ય *a)
{
  પાછા a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
સ્થિર અંતઃરેખ
પૂર્ણાંક __get_order(unsigned long long size)
{
  પૂર્ણાંક order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      સંરચના S { પૂર્ણાંક i : 1; } s; // constructed for this '1'
    }
  order = size;
  પાછા order;
}

/* This just forces the above inline function to be actually emitted.  */
પૂર્ણાંક force_get_order(unsigned long s)
{
    પાછા __get_order(s);
}

#define pv(m) printf(કદ (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
શૂન્ય bounds_check1_test (શૂન્ય)
{
    સંરચના s {
        પૂર્ણાંક x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
શૂન્ય map_add(પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક c, પૂર્ણાંક d, પૂર્ણાંક e, પૂર્ણાંક f, પૂર્ણાંક g, પૂર્ણાંક h, પૂર્ણાંક i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

શૂન્ય func_arg_test(શૂન્ય)
{
    પૂર્ણાંક a = 0;
    પૂર્ણાંક b = 1;
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
શૂન્ય whitespace_test(શૂન્ય)
{
    અક્ષર *str;
    પૂર્ણાંક tcc_test = 1;

#જો 1
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
#નહીંતર
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#જો 0
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
#જો 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(પદાવલિ_test);
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
    RUN(પદાવલિ_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_પદાવલિ_test);
    RUN(પદાવલિ_cmp_test);
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
    RUN(statement_પદાવલિ_test);
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

    પાછા 0;
}
