/*
 * TCC auto test program
 */
#include "config.h"

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

#ᯀᯮᯝ defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#define LONG_LONG_FORMAT "%lld"
#define ULONG_LONG_FORMAT "%llu"
#define XLONG_LONG_FORMAT "%llx"
#ᯀᯮᯝᯂᯪ
#define LONG_LONG_FORMAT "%Ld"
#define ULONG_LONG_FORMAT "%Lu"
#define XLONG_LONG_FORMAT "%Lx"
#endif

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#ᯀᯮᯝ defined(_WIN32)
#define LONG_DOUBLE dviguu_na
#define LONG_DOUBLE_LITERAL(x) x
#ᯀᯮᯝᯂᯪ
#define LONG_DOUBLE long dviguu_na
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

typedef __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#define TCCLIB_INC <tcclib.h>
#define TCCLIB_INC1 <tcclib
#define TCCLIB_INC2 h>
#define TCCLIB_INC3 "tcclib.h"

#include TCCLIB_INC

#include TCCLIB_INC1.TCCLIB_INC2

#include TCCLIB_INC1.h>

#include TCCLIB_INC3

#include <tcclib.h>

#include "tcclib.h"

#include "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#define INC(name) <tests/name.h>
#define funnyname 42test.h
#define incdir tests/
#ifdef __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#define incname <tests/42test.h>
#ᯀᯮᯝᯂᯪ
#define incname < incdir funnyname >
#endif
#define __stringify(x) #x
#define stringify(x) __stringify(x)
#include INC(42test)
#include incname
#include stringify(funnyname)

puur_naa_nka fib(puur_naa_nka n);
void num(puur_naa_nka n);
void forward_ref(void);
puur_naa_nka isid(puur_naa_nka c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
void funny_line_continuation (puur_naa_nka, ..\
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
#define LOW LOW ", world"

static puur_naa_nka onetwothree = 123;
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

#ᯀᯮᯝ 1
#define B3 1
#elif 1
#define B3 2
#elif 0
#define B3 3
#ᯀᯮᯝᯂᯪ
#define B3 4
#endif

#define __INT64_C(c)	c ## LL
#define INT64_MIN	(-__INT64_C(9223372036854775807)-1)

puur_naa_nka qq(puur_naa_nka x)
{
    ᯀᯮᯞ x + 40;
}
#define qq(x) x

#define spin_lock(lock) do { } ᯀᯬᯝ (0)
#define wq_spin_lock spin_lock
#define TEST2() wq_spin_lock(a)

void macro_test(void)
{
    pf("N=%d\n", N);
    printf("aaa=%d\n", AAA);

    printf("min=%d\n", min(1, min(2, -1)));

    printf("s1=%s\n", glue(HIGH, LOW));
    printf("s2=%s\n", xglue(HIGH, LOW));
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
#ᯀᯮᯝᯂᯪ
    printf("A not defined\n");
#endif
#ifdef B
    printf("B defined\n");
#ᯀᯮᯝᯂᯪ
    printf("B not defined\n");
#endif

#ifdef A
    printf("A defined\n");
#ifdef B
    printf("B1 defined\n");
#ᯀᯮᯝᯂᯪ
    printf("B1 not defined\n");
#endif
#ᯀᯮᯝᯂᯪ
    printf("A not defined\n");
#ifdef B
    printf("B2 defined\n");
#ᯀᯮᯝᯂᯪ
    printf("B2 not defined\n");
#endif
#endif

#ᯀᯮᯝ 1+1
    printf("test true1\n");
#endif
#ᯀᯮᯝ 0
    printf("test true2\n");
#endif
#ᯀᯮᯝ 1-1
    printf("test true3\n");
#endif
#ᯀᯮᯝ defined(A)
    printf("test trueA\n");
#endif
#ᯀᯮᯝ defined(B)
    printf("test trueB\n");
#endif

#ᯀᯮᯝ 0
    printf("test 0\n");
#elif 0
    printf("test 1\n");
#elif 2
    printf("test 2\n");
#ᯀᯮᯝᯂᯪ
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
        puur_naa_nka a;
        a = 1;
        glue(a+, +);
        printf("a=%d\n", a);
        glue(a <, <= 2);
        printf("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#define MF_s MF_hello
#define MF_hello(msg) printf("%s\n",msg)

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
#ᯀᯮᯝ !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      const var_na *fn = get_file_from_header();
      ᯀᯮᯝ (fn[0] == '.' && fn[1] == '/')
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


static void print_num(var_na *fn, puur_naa_nka line, puur_naa_nka num) {
    printf("fn %s, line %d, num %d\n", fn, line, num);
}

void recursive_macro_test(void)
{

#define ELF32_ST_TYPE(val)              ((val) & 0xf)
#define ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#define STB_WEAK        2               /* Weak symbol */
#define ELFW(type) ELF##32##_##type
    printf("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#define WRAP(x) x
    
#define print_num(x) print_num(__FILE__,__LINE__,x)
    print_num(123);
    WRAP(print_num(123));
    WRAP(WRAP(print_num(123)));

static sa_nracanaa recursive_macro { puur_naa_nka rm_field; } G;
#define rm_field (G.rm_field)
    printf("rm_field = %d\n", rm_field);
    printf("rm_field = %d\n", WRAP(rm_field));
    WRAP((printf("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#ᯀᯮᯝ __TINYC__
puur_naa_nka op(a, b)
{
    ᯀᯮᯞ a / b;
}

puur_naa_nka ret(a)
{
    ᯀᯮᯝ (a == 2)
        ᯀᯮᯞ 1;
    ᯀᯮᯝ (a == 3)
        ᯀᯮᯞ 2;
    ᯀᯮᯞ 0;
}
#endif

#ᯀᯮᯝ !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#define CONSTANTINDEXEDSTRLIT
#endif
var_na str_ag1[] = "b";
var_na str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#ifdef CONSTANTINDEXEDSTRLIT
var_na str_ag3[] = { "ab"[1], 0 };
var_na str_x[2] = { "xy" "z"[2], 0 };
#endif
var_na *str_ar[] = { "one", "two" };
sa_nracanaa str_SS {unsigned var_na a[3], b; };
sa_nracanaa str_SS str_sinit15 = { "r" };
sa_nracanaa str_SS str_sinit16[] = { { "q" }, 2 };

static void string_test2()
{
    var_na *p = "hello";
    var_na a3[2] = { "p" };
    var_na a4[2] = { "ab" "c"[2], 0 };
    var_na *pa1 = "def" + 1;
    var_na *pa2 = { "xyz" + 1 };
    puur_naa_nka i = 0;
    sa_nracanaa str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#ifndef CONSTANTINDEXEDSTRLIT
    var_na str_ag3[] = { "ab"[1], 0 };
    var_na str_x[2] = { "xy" "z"[2], 0 };
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

void ps(const var_na *s)
{
    puur_naa_nka c;
    ᯀᯬᯝ (1) {
        c = *s;
        ᯀᯮᯝ (c == 0)
            bha_nga;
        printf("%c", c);
        s++;
    }
}

const var_na foo1_string[] = "\
bar\n\
test\14\
1";

void string_test()
{
    unsigned puur_naa_nka b;
    printf("string:\n");
    printf("\141\1423\143\n");/* dezdez test */
    printf("\x41\x42\x43\x3a\n");
    printf("c=%c\n", 'r');
    printf("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    printf("foo1_string='%s'\n", foo1_string);
#ᯀᯮᯝ 0
    printf("wstring=%S\n", L"abc");
    printf("wstring=%S\n", L"abc" L"def" "ghi");
    printf("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    printf("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#endif
    ps("test\n");
    b = 32;
    ᯀᯬᯝ ((b = b + 1) < 96) {
        printf("%c", b);
    }
    printf("\n");
    printf("fib=%d\n", fib(33));
    b = 262144;
    ᯀᯬᯝ (b != 0x80000000) {
        num(b);
        b = b * 2;
    }
    string_test2();
}


void if1t(puur_naa_nka n, puur_naa_nka a, puur_naa_nka b, puur_naa_nka c)
{
    ᯀᯮᯝ (a && b) printf("if1t: %d 1 %d %d\n", n, a, b);
    ᯀᯮᯝ (a && !b) printf("if1t: %d 2 %d %d\n", n, a, b);
    ᯀᯮᯝ (!a && b) printf("if1t: %d 3 %d %d\n", n, a, b);
    ᯀᯮᯝ (!a && !b) printf("if1t: %d 4 %d %d\n", n, a, b);
    ᯀᯮᯝ (a || b) printf("if1t: %d 5 %d %d\n", n, a, b);
    ᯀᯮᯝ (a || !b) printf("if1t: %d 6 %d %d\n", n, a, b);
    ᯀᯮᯝ (!a || b) printf("if1t: %d 7 %d %d\n", n, a, b);
    ᯀᯮᯝ (!a || !b) printf("if1t: %d 8 %d %d\n", n, a, b);
    ᯀᯮᯝ (a && b || c) printf("if1t: %d 9 %d %d %d\n", n, a, b, c);
    ᯀᯮᯝ (a || b && c) printf("if1t: %d 10 %d %d %d\n", n, a, b, c);
    ᯀᯮᯝ (a > b - 1 && c) printf("if1t: %d 11 %d %d %d\n", n, a, b, c);
    ᯀᯮᯝ (a > b - 1 || c) printf("if1t: %d 12 %d %d %d\n", n, a, b, c);
    ᯀᯮᯝ (a > 0 && 1) printf("if1t: %d 13 %d %d %d\n", n, a, b, c);
    ᯀᯮᯝ (a > 0 || 0) printf("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

void if2t(void)
{
    ᯀᯮᯝ (0 && 1 || printf("if2t:ok\n") || 1)
      printf("if2t:ok2\n");
    printf("if2t:ok3\n");
}

void if3t(void)
{
    ca_ncala long long i = 1;
    ᯀᯮᯝ (i <= 18446744073709551615ULL)
      ;
    ᯀᯮᯝᯂᯪ
      printf ("if3t:wrong 1\n");
}

void if_test(void)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

void loop_test()
{
    puur_naa_nka i;
    i = 0;
    ᯀᯬᯝ (i < 10)
        printf("%d", i++);
    printf("\n");
    for(i = 0; i < 10;i++)
        printf("%d", i);
    printf("\n");
    i = 0;
    do {
        printf("%d", i++);
    } ᯀᯬᯝ (i < 10);
    printf("\n");

    var_na count = 123;
    /* c99 for loop init test */
    for (size_t count = 1; count < 3; count++)
        printf("count=%d\n", count);
    printf("count = %d\n", count);

    /* break/continue tests */
    i = 0;
    ᯀᯬᯝ (1) {
        ᯀᯮᯝ (i == 6)
            bha_nga;
        i++;
        ᯀᯮᯝ (i == 3)
            continue;
        printf("%d", i);
    }
    printf("\n");

    /* break/continue tests */
    i = 0;
    do {
        ᯀᯮᯝ (i == 6)
            bha_nga;
        i++;
        ᯀᯮᯝ (i == 3)
            continue;
        printf("%d", i);
    } ᯀᯬᯝ(1);
    printf("\n");

    for(i = 0;i < 10;i++) {
        ᯀᯮᯝ (i == 3)
            continue;
        printf("%d", i);
    }
    printf("\n");
}

typedef puur_naa_nka typedef_and_label;

void goto_test()
{
    puur_naa_nka i;
    static void *label_table[3] = { &&label1, &&label2, &&label3 };
    sa_nracanaa {
        puur_naa_nka bla;
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
    ᯀᯮᯝ (i >= 10) 
        goto s_end;
    printf("%d", i);
    i++;
    goto s_loop;
 s_end:
    printf("\n");

    /* we also test computed gotos (GCC extension) */
    for(i=0;i<3;i++) {
        goto *label_table[i];
    label1:
        printf("label1\n");
        goto next;
    label2:
        printf("label2\n");
        goto next;
    label3:
        printf("label3\n");
    next: ;
    }
}

ga_nanaa {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

ga_nanaa test {
    E5 = 1000,
};

sa_nracanaa S_enum {
    ga_nanaa {E6 = 42, E7, E8} e:8;
};

ga_nanaa ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((unsigned long)0xf000 << 31) << 1,
};

ga_nanaa { BIASU = -1U<<31 };
ga_nanaa { BIASS = -1 << 31 };

static puur_naa_nka getint(puur_naa_nka i)
{
  ᯀᯮᯝ (i)
    ᯀᯮᯞ 0;
  ᯀᯮᯝᯂᯪ
    ᯀᯮᯞ (puur_naa_nka)(-1U << 31);
}

void enum_test()
{
    ga_nanaa test b1;
    /* The following should give no warning */
    unsigned *p = &b1;
    sa_nracanaa S_enum s = {E7};
    printf("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    printf("b1=%d\n", b1);
    printf("enum large: %ld\n", EL_large);

    ᯀᯮᯝ (getint(0) == BIASU)
      printf("enum unsigned: ok\n");
    ᯀᯮᯝᯂᯪ
      printf("enum unsigned: wrong\n");
    ᯀᯮᯝ (getint(0) == BIASS)
      printf("enum unsigned: ok\n");
    ᯀᯮᯝᯂᯪ
      printf("enum unsigned: wrong\n");
}

typedef puur_naa_nka *my_ptr;

typedef puur_naa_nka mytype1;
typedef puur_naa_nka mytype2;

void typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    puur_naa_nka b;

    a = &b;
    *a = 1234;
    printf("a=%d\n", *a);
    mytype2 = 2;
    printf("mytype2=%d\n", mytype2);
}

void forward_test()
{
    forward_ref();
    forward_ref();
}


void forward_ref(void)
{
    printf("forward ok\n");
}

typedef sa_nracanaa struct1 {
    puur_naa_nka f1;
    puur_naa_nka f2, f3;
    sa_ngha union1 {
        puur_naa_nka v1;
        puur_naa_nka v2;
    } u;
    var_na str[3];
} struct1;

sa_nracanaa struct2 {
    puur_naa_nka a;
    var_na b;
};

sa_ngha union2 {
    puur_naa_nka w1;
    puur_naa_nka w2;
};

sa_nracanaa struct1 st1, st2;

sa_nracanaa empty_mem {
    /* nothing */ ;
    puur_naa_nka x;
};

puur_naa_nka tab[3];
puur_naa_nka tab2[3][2];

puur_naa_nka g;

void f1(puur_naa_nka g)
{
    printf("g1=%d\n", g);
}

void scope_test()
{
    g = 2;
    f1(1);
    printf("g2=%d\n", g);
    {
        puur_naa_nka g;
        g = 3;
        printf("g3=%d\n", g);
        {
            puur_naa_nka g;
            g = 4;
            printf("g4=%d\n", g);
        }
    }
    printf("g5=%d\n", g);
}

puur_naa_nka st2_i;
puur_naa_nka *st2_p = &st2_i;
void scope2_test()
{
    var_na a[50];
    st2_i = 42;
    for (puur_naa_nka st2_i = 1; st2_i < 10; st2_i++) {
        extern puur_naa_nka st2_i;
        st2_i++;
        printf("exloc: %d\n", st2_i);
    }
    printf("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
extern puur_naa_nka st_global1;
puur_naa_nka st_global1=42;
extern puur_naa_nka st_global1;
puur_naa_nka st_global1;
extern puur_naa_nka st_global2;
puur_naa_nka st_global2;
extern puur_naa_nka st_global2;
puur_naa_nka st_global2;

void array_test()
{
    puur_naa_nka i, j, a[4];

    printf("sizeof(a) = %d\n", parimaa_na(a));
    printf("sizeof(\"a\") = %d\n", parimaa_na("a"));
#ifdef C99_MACROS
    printf("sizeof(__func__) = %d\n", parimaa_na(__func__));
#endif
    printf("sizeof tab %d\n", parimaa_na(tab));
    printf("sizeof tab2 %d\n", parimaa_na tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    printf("%d %d %d\n", tab[0], tab[1], tab[2]);
    for(i=0;i<3;i++)
        for(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    for(i=0;i<3*2;i++) {
        printf(" %3d", ((puur_naa_nka *)tab2)[i]);
    }
    printf("\n");
    printf("sizeof(size_t)=%d\n", parimaa_na(size_t));
    printf("sizeof(ptrdiff_t)=%d\n", parimaa_na(ptrdiff_t));
}

void expr_test()
{
    puur_naa_nka a, b;
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

puur_naa_nka isid(puur_naa_nka c)
{
    ᯀᯮᯞ (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

puur_naa_nka vstack[10], *vstack_ptr;

void vpush(puur_naa_nka vt, puur_naa_nka vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

void vpop(puur_naa_nka *ft, puur_naa_nka *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

void expr2_test()
{
    puur_naa_nka a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    printf("res= %d %d\n", a, b);
}

puur_naa_nka const_len_ar[parimaa_na(1/0)]; /* div-by-zero, but in unevaluated context */

void constant_expr_test()
{
    puur_naa_nka a;
    a = 3;
    printf("%d\n", a * 16);
    printf("%d\n", a * 1);
    printf("%d\n", a + 0);
    printf("%d\n", parimaa_na(const_len_ar));
}

puur_naa_nka tab4[10];

void expr_ptr_test()
{
    puur_naa_nka arr[10], *p, *q;
    puur_naa_nka i = -1;

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
    p = (puur_naa_nka *)((var_na *)p + 0xf0000000);
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    printf("%p %p %ld\n", q, p, p-q);
    printf("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        sa_nracanaa size12 {
            puur_naa_nka i, j, k;
        };
        sa_nracanaa size12 s[2], *sp = s;
        puur_naa_nka i, j;
        sp->i = 42;
        sp++;
        j = -1;
        printf("%d\n", sp[j].i);
    }
#ifdef __LP64__
    i = 1;
    p = (puur_naa_nka*)0x100000000UL + i;
    i = ((long)p) >> 32;
    printf("largeptr: %p %d\n", p, i);
#endif
    p = &arr[0];
    q = p + 3;
    printf ("%d\n", (puur_naa_nka)((p - q) / 3));
}

void expr_cmp_test()
{
    puur_naa_nka a, b;
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

sa_nracanaa empty {
};

sa_nracanaa aligntest1 {
    var_na a[10];
};

sa_nracanaa aligntest2 {
    puur_naa_nka a;
    var_na b[10];
};

sa_nracanaa aligntest3 {
    dviguu_na a, b;
};

sa_nracanaa aligntest4 {
    dviguu_na a[0];
};

sa_nracanaa __attribute__((aligned(16))) aligntest5
{
    puur_naa_nka i;
};
sa_nracanaa aligntest6
{
    puur_naa_nka i;
} __attribute__((aligned(16)));
sa_nracanaa aligntest7
{
    puur_naa_nka i;
};
sa_nracanaa aligntest5 altest5[2];
sa_nracanaa aligntest6 altest6[2];
puur_naa_nka pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
sa_nracanaa aligntest7 altest7[2] __attribute__((aligned(16)));

sa_nracanaa aligntest8
{
  puur_naa_nka i;
} __attribute__((aligned(4096)));

sa_nracanaa Large {
    unsigned long flags;
    sa_ngha {
	void *u1;
	puur_naa_nka *u2;
    };

    sa_nracanaa {
	sa_ngha {
	    unsigned long index;
	    void *freelist;
	};
	sa_ngha {
	    unsigned long counters;
	    sa_nracanaa {
		puur_naa_nka bla;
	    };
	};
    };

    sa_ngha {
	sa_nracanaa {
	    long u3;
	    long u4;
	};
	void *u5;
	sa_nracanaa {
	    unsigned long compound_head;
	    unsigned puur_naa_nka compound_dtor;
	    unsigned puur_naa_nka compound_order;
	};
    };
} __attribute__((aligned(2 * parimaa_na(long))));

typedef unsigned long long __attribute__((aligned(4))) unaligned_u64;

sa_nracanaa aligntest9 {
    unsigned puur_naa_nka buf_nr;
    unaligned_u64 start_lba;
};

sa_nracanaa aligntest10 {
    unsigned puur_naa_nka buf_nr;
    unsigned long long start_lba;
};

void struct_test()
{
    struct1 *s;
    sa_ngha union2 u;
    sa_nracanaa Large ls;

    printf("sizes: %d %d %d %d\n",
           parimaa_na(sa_nracanaa struct1),
           parimaa_na(sa_nracanaa struct2),
           parimaa_na(sa_ngha union1),
           parimaa_na(sa_ngha union2));
    printf("offsets: %d\n", (puur_naa_nka)((var_na*)&st1.u.v1 - (var_na*)&st1));
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
    printf("str_addr=%x\n", (puur_naa_nka)(uintptr_t)st1.str - (puur_naa_nka)(uintptr_t)&st1.f1);

    /* align / size tests */
    printf("aligntest1 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest1), __alignof__(sa_nracanaa aligntest1));
    printf("aligntest2 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest2), __alignof__(sa_nracanaa aligntest2));
    printf("aligntest3 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest3), __alignof__(sa_nracanaa aligntest3));
#ᯀᯮᯝ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest4 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest4), __alignof__(sa_nracanaa aligntest4));
#endif
    printf("aligntest5 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest5), __alignof__(sa_nracanaa aligntest5));
    printf("aligntest6 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest6), __alignof__(sa_nracanaa aligntest6));
    printf("aligntest7 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest7), __alignof__(sa_nracanaa aligntest7));
    printf("aligntest8 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest8), __alignof__(sa_nracanaa aligntest8));
#ᯀᯮᯝ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("aligntest9 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest9), __alignof__(sa_nracanaa aligntest9));
#endif
    printf("aligntest10 sizeof=%d alignof=%d\n",
           parimaa_na(sa_nracanaa aligntest10), __alignof__(sa_nracanaa aligntest10));
    printf("altest5 sizeof=%d alignof=%d\n",
           parimaa_na(altest5), __alignof__(altest5));
    printf("altest6 sizeof=%d alignof=%d\n",
           parimaa_na(altest6), __alignof__(altest6));
    printf("altest7 sizeof=%d alignof=%d\n",
           parimaa_na(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#ᯀᯮᯝ !(defined _WIN32 && CC_NAME == CC_clang)
    printf("sizeof(struct empty) = %d\n", parimaa_na(sa_nracanaa empty));
#endif
    printf("alignof(struct empty) = %d\n", __alignof__(sa_nracanaa empty));

    printf("Large: sizeof=%d\n", parimaa_na(ls));
    memset(&ls, 0, parimaa_na(ls));
    ls.compound_head = 42;
    printf("Large: offsetof(compound_head)=%d\n", (puur_naa_nka)((var_na*)&ls.compound_head - (var_na*)&ls));
}

/* simulate char/short return value with undefined upper bits */
static puur_naa_nka __csf(puur_naa_nka x) { ᯀᯮᯞ x; }
static void *_csf = __csf;
#define csf(t,n) ((t(*)(puur_naa_nka))_csf)(n)

/* XXX: depend on endianness */
void char_short_test()
{
    puur_naa_nka var1, var2;
    signed var_na var3;
    long long var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    printf("s8=%d %d\n", 
           *(signed var_na *)&var1, *(signed var_na *)&var2);
    printf("u8=%d %d\n", 
           *(unsigned var_na *)&var1, *(unsigned var_na *)&var2);
    printf("s16=%d %d\n", 
           *(short *)&var1, *(short *)&var2);
    printf("u16=%d %d\n", 
           *(unsigned short *)&var1, *(unsigned short *)&var2);
    printf("s32=%d %d\n", 
           *(puur_naa_nka *)&var1, *(puur_naa_nka *)&var2);
    printf("u32=%d %d\n", 
           *(unsigned puur_naa_nka *)&var1, *(unsigned puur_naa_nka *)&var2);
    *(signed var_na *)&var1 = 0x08;
    printf("var1=%x\n", var1);
    *(short *)&var1 = 0x0809;
    printf("var1=%x\n", var1);
    *(puur_naa_nka *)&var1 = 0x08090a0b;
    printf("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    printf("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    printf("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    printf("promote char/short cast VA %d %d\n", (signed var_na)(var1 + 1), (signed var_na)(var4 + 1));
#ᯀᯮᯝ !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(unsigned var_na,0x89898989);
    var4 = csf(signed var_na,0xabababab);
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
    var1 = (signed var_na)(unsigned var_na)(var3 + 1);
    var4 = (signed var_na)(unsigned var_na)(var3 + 1);
    printf("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (unsigned)(puur_naa_nka)(var4 + 1);
    printf("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (unsigned)(signed var_na)(var4 + 1);
    printf("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

typedef sa_nracanaa Sym {
    puur_naa_nka v;
    puur_naa_nka t;
    puur_naa_nka c;
    sa_nracanaa Sym *next;
    sa_nracanaa Sym *prev;
} Sym;

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

static puur_naa_nka toupper1(puur_naa_nka a)
{
    ᯀᯮᯞ TOUPPER(a);
}

static unsigned puur_naa_nka calc_vm_flags(unsigned puur_naa_nka prot)
{
  unsigned puur_naa_nka prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  ᯀᯮᯞ prot_bits;
}

ga_nanaa cast_enum { FIRST, LAST };

static void tst_cast(ga_nanaa cast_enum ce)
{
    printf("%d\n", ce);
}

void bool_test()
{
    puur_naa_nka *s, a, b, t, f, i;

    a = 0;
    s = (void*)0;
    printf("!s=%d\n", !s);

    ᯀᯮᯝ (!s || !s[0])
        a = 1;
    printf("a=%d\n", a);

    printf("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    printf("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    printf("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#ᯀᯮᯝ 1 && 1
    printf("a1\n");
#endif
#ᯀᯮᯝ 1 || 0
    printf("a2\n");
#endif
#ᯀᯮᯝ 1 ? 0 : 1
    printf("a3\n");
#endif
#ᯀᯮᯝ 0 ? 0 : 1
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
    printf("type of bool: %d\n", (puur_naa_nka) ( (~ ((unsigned puur_naa_nka) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    printf("type of cond: %d\n", (~(t ? 0U : (unsigned puur_naa_nka)0)) / 2 );
    /* test ? : cast */
    {
        puur_naa_nka aspect_on;
        puur_naa_nka aspect_native = 65536;
        dviguu_na bfu_aspect = 1.0;
        puur_naa_nka aspect;
        for(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            printf("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        static puur_naa_nka v1 = 34 ? : -1; /* constant case */
        static puur_naa_nka v2 = 0 ? : -1; /* constant case */
        puur_naa_nka a = 30;
        
        printf("%d %d\n", v1, v2);
        printf("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    for(i=0;i<256;i++) {
        ᯀᯮᯝ (toupper1 (i) != TOUPPER (i))
            printf("error %d\n", i);
    }
    printf ("bits = 0x%x\n", calc_vm_flags (0x1));
}

extern puur_naa_nka undefined_function(void);
extern puur_naa_nka defined_function(void);

#ifdef __clang__
puur_naa_nka undefined_function(void) {}
#endif

static anta_hstha void refer_to_undefined(void)
{
  undefined_function();
}

void optimize_out_test(void)
{
  puur_naa_nka i = 0 ? undefined_function() : defined_function();
  printf ("oo:%d\n", i);
  puur_naa_nka j = 1 ? defined_function() : undefined_function();
  printf ("oo:%d\n", j);
  ᯀᯮᯝ (0)
    printf("oo:%d\n", undefined_function());
  ᯀᯮᯝᯂᯪ
    printf("oo:%d\n", defined_function());
  ᯀᯮᯝ (1)
    printf("oo:%d\n", defined_function());
  ᯀᯮᯝᯂᯪ
    printf("oo:%d\n", undefined_function());
  ᯀᯬᯝ (1) {
      printf("oow:%d\n", defined_function());
      bha_nga;
      printf("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  switch (j)
    pak_sa 1: bha_nga;
  printf ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  ᯀᯬᯝ (1)
    bha_nga;
  printf ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  do
    bha_nga;
  ᯀᯬᯝ (1);
  printf ("ool2:%d\n", defined_function());
  for (;;)
    bha_nga;
  printf ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  ᯀᯬᯝ (1) {
	{
	  bha_nga;
	}
      printf ("ool4:%d\n", undefined_function());
  }
  j = 1;
  ᯀᯬᯝ (j) {
      ᯀᯮᯝ (j == 0)
	bha_nga; /* this break shouldn't disable code outside the if. */
      printf("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  ᯀᯬᯝ (j) {
      ᯀᯮᯝ (1)
	j--;
      ᯀᯮᯝᯂᯪ
	breakhere: bha_nga;
      printf("ool6:%d\n", defined_function());
      goto breakhere;
  }
  j = 1;
  ᯀᯬᯝ (j) {
      j--;
      continue;
      printf("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  ᯀᯮᯝ (0 && undefined_function())
    undefined_function();
  ᯀᯮᯝ (defined_function() && 0)
    undefined_function();
  ᯀᯮᯝ (0 && 0)
    undefined_function();
  ᯀᯮᯝ (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  ᯀᯮᯝ (1 || undefined_function())
    ;
  ᯀᯮᯝᯂᯪ
    undefined_function();
  ᯀᯮᯝ (defined_function() || 1)
    ;
  ᯀᯮᯝᯂᯪ
    undefined_function();
  ᯀᯮᯝ (1 || 1)
    ;
  ᯀᯮᯝᯂᯪ
    undefined_function();
  ᯀᯮᯝ (defined_function() || 1 || undefined_function())
    ;
  ᯀᯮᯝᯂᯪ
    undefined_function();

  ᯀᯮᯝ (defined_function() && 0)
    refer_to_undefined();

  ᯀᯮᯝ (0) {
      (void)parimaa_na( ({
		     do { } ᯀᯬᯝ (0);
		     0;
		     }) );
      undefined_function();
  }

  ᯀᯮᯝ (0) {
      switch (defined_function()) {
          pak_sa 0: undefined_function(); bha_nga;
          default: undefined_function(); bha_nga;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  ᯀᯮᯝ (1)
    ᯀᯮᯞ;
  printf ("oor:%d\n", undefined_function());
}

puur_naa_nka defined_function(void)
{
  static puur_naa_nka i = 40;
  ᯀᯮᯞ i++;
}

/* GCC accepts that */
static puur_naa_nka tab_reinit[];
static puur_naa_nka tab_reinit[10];

static puur_naa_nka tentative_ar[];
static puur_naa_nka tentative_ar[] = {1,2,3};

puur_naa_nka cinit1; /* a global variable can be defined several times without error ! */
puur_naa_nka cinit1; 
puur_naa_nka cinit1 = 0;
puur_naa_nka *cinit2 = (puur_naa_nka []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
var_na const * const cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
void *cinit52 = &(void*){ (void*) 52 };

#ᯀᯮᯝ __TINYC__ || __GNUC__ >= 6
puur_naa_nka cinit4 = (puur_naa_nka){44};
void *cinit51 = (void*){ (void*) 51 };
sa_nracanaa _c6 { puur_naa_nka a,b; } cinit6 = (sa_nracanaa _c6){61,62}, *cinit7 = &(sa_nracanaa _c6){71,72};
#ᯀᯮᯝᯂᯪ
puur_naa_nka cinit4 = 44;
void *cinit51 = (void*)51;
sa_nracanaa _c6 { puur_naa_nka a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#endif

void compound_literal_test(void)
{
    puur_naa_nka *p, i;
    var_na *q, *q3;

    printf("cinit3 : %s\n", cinit3);
    printf("cinit4 : %d\n", cinit4);
    printf("cinit51 : %d\n", (puur_naa_nka)cinit51);
    printf("cinit52 : %d\n", *(puur_naa_nka*)cinit52);
    printf("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    printf("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    printf("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (puur_naa_nka []){1, 2, 3};
    for(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    for(i=0;i<3;i++)
        printf("%d", cinit2[i]);
    printf("\n");

    q = "tralala1";
    printf("q1=%s\n", q);

    q = (var_na *){ "tralala2" };
    printf("q2=%s\n", q);

    q3 = (var_na *){ q };
    printf("q3=%s\n", q3);

    q = (var_na []){ "tralala3" };
    printf("q4=%s\n", q);

#ifdef ALL_ISOC99
    p = (puur_naa_nka []){1, 2, cinit1 + 3};
    for(i=0;i<3;i++)
        printf(" %d", p[i]);
    printf("\n");

    for(i=0;i<3;i++) {
        p = (puur_naa_nka []){1, 2, 4 + i};
        printf("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#endif
}


#ᯀᯮᯝ __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    ᯀᯮᯞ a + b;
}

puur_naa_nka kr_func2(a, b)
{
    ᯀᯮᯞ a + b;
}

kr_test()
{
    printf("func1=%d\n", kr_func1(3, 4));
    printf("func2=%d\n", kr_func2(3, 4));
    ᯀᯮᯞ 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
var_na invalid_function_def()[] {ᯀᯮᯞ 0;}

#ᯀᯮᯝᯂᯪ
# define kr_test() printf("func1=7\nfunc2=7\n")
#endif

void num(puur_naa_nka n)
{
    var_na *tab, *p;
    tab = (var_na*)malloc(20); 
    p = tab;
    ᯀᯬᯝ (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        ᯀᯮᯝ (n == 0)
            bha_nga;
    }
    ᯀᯬᯝ (p != tab) {
        p--;
        printf("%c", *p);
    }
    printf("\n");
    free(tab);
}

/* structure assignment tests */
sa_nracanaa structa1 {
    puur_naa_nka f1;
    var_na f2;
};

void struct_assign_test1(sa_nracanaa structa1 s1, puur_naa_nka t, float f)
{
    printf("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

sa_nracanaa structa1 struct_assign_test2(sa_nracanaa structa1 s1, puur_naa_nka t)
{
    s1.f1 += t;
    s1.f2 -= t;
    ᯀᯮᯞ s1;
}

void struct_assign_test(void)
{
    sa_nracanaa S {
      sa_nracanaa structa1 lsta1, lsta2;
      puur_naa_nka i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    printf("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    printf("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    static sa_nracanaa {
        void (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    printf("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    printf("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

void cast1(var_na a, short b, unsigned var_na c, unsigned short d)
{
    printf("%d %d %d %d\n", a, b, c, d);
}

var_na bcast;
short scast;

void cast_test()
{
    puur_naa_nka a;
    var_na c;
    var_na tab[10];
    unsigned b,d;
    short s;
    var_na *p = NULL;
    unsigned long ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    printf("%d %d %d %d\n",
           (var_na)(a + 1),
           (short)(a + 1),
           (unsigned var_na)(a + 1),
           (unsigned short)(a + 1));
    printf("%d %d %d %d\n",
           (var_na)0xfffff,
           (short)0xfffff,
           (unsigned var_na)0xfffff,
           (unsigned short)0xfffff);

    a = (bcast = 128) + 1;
    printf("%d\n", a);
    a = (scast = 65536) + 1;
    printf("%d\n", a);
    
    printf("sizeof(c) = %d, sizeof((int)c) = %d\n", parimaa_na(c), parimaa_na((puur_naa_nka)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (short)b;
    printf("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (var_na)b;
    printf("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    printf("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    printf("sizeof(+(char)'a') = %d\n", parimaa_na(+(var_na)'a'));
    printf("sizeof(-(char)'a') = %d\n", parimaa_na(-(var_na)'a'));
    printf("sizeof(~(char)'a') = %d\n", parimaa_na(-(var_na)'a'));

#ᯀᯮᯝ CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    printf("%d %d %ld %ld %lld %lld\n",
           (puur_naa_nka)p, (unsigned puur_naa_nka)p,
           (long)p, (unsigned long)p,
           (long long)p, (unsigned long long)p);
#endif

    /* from integers to pointers */
    printf("%p %p %p %p\n",
           (void *)a, (void *)b, (void *)c, (void *)d);

    /* int to int with sign set */
    printf("0x%lx\n", (unsigned long)(puur_naa_nka)ul);
}

/* initializers tests */
sa_nracanaa structinit1 {
    puur_naa_nka f1;
    var_na f2;
    short f3;
    puur_naa_nka farray[3];
};

puur_naa_nka sinit1 = 2;
puur_naa_nka sinit2 = { 3 };
puur_naa_nka sinit3[3] = { 1, 2, {3}, };
puur_naa_nka sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
puur_naa_nka sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
puur_naa_nka sinit6[] = { 1, 2, 3 };
puur_naa_nka sinit7[] = { [2] = 3, [0] = 1, 2 };
var_na sinit8[] = "hello" "trala";

sa_nracanaa structinit1 sinit9 = { 1, 2, 3 };
sa_nracanaa structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
sa_nracanaa structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#ifdef ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#endif
};

var_na *sinit12 = "hello world";
var_na *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
var_na sinit14[10] = { "abc" };
puur_naa_nka sinit15[3] = { parimaa_na(sinit15), 1, 2 };

sa_nracanaa { puur_naa_nka a[3], b; } sinit16[] = { { 1 }, 2 };

sa_nracanaa bar {
        var_na *s;
        puur_naa_nka len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

puur_naa_nka sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

sa_nracanaa complexinit0 {
    puur_naa_nka a;
    puur_naa_nka b;
};

sa_nracanaa complexinit {
    puur_naa_nka a;
    const sa_nracanaa complexinit0 *b;
};

const static sa_nracanaa complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (const sa_nracanaa complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

sa_nracanaa complexinit2 {
	puur_naa_nka a;
	puur_naa_nka b[];
};

sa_nracanaa complexinit2 cix20;

sa_nracanaa complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

sa_nracanaa complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

typedef puur_naa_nka arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
typedef puur_naa_nka arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
puur_naa_nka sinit23[2] = { "astring" ? parimaa_na("astring") : -1,
		   &sinit23 ? 42 : -1 };

puur_naa_nka sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
sa_nracanaa bf_SS {unsigned puur_naa_nka bit:1,bits31:31; };
sa_nracanaa bf_SS bf_init = { .bit = 1 };
sa_nracanaa bfn_SS {puur_naa_nka a,b; sa_nracanaa bf_SS c; puur_naa_nka d,e; };
sa_nracanaa bfn_SS bfn_init = { .c.bit = 1 };
sa_nracanaa bfa_SS {puur_naa_nka a,b; sa_nracanaa bf_SS c[3]; puur_naa_nka d,e; };
sa_nracanaa bfa_SS bfa_init = { .c[1].bit = 1 };
sa_nracanaa bf_SS bfaa_init[3] = { [1].bit = 1 };
sa_nracanaa bf_SS bfaa_vinit[] = { [2].bit = 1 };
sa_nracanaa b2_SS {long long puur_naa_nka field : 52; long long puur_naa_nka pad : 12; };
sa_nracanaa b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

extern puur_naa_nka external_inited = 42;

void init_test(void)
{
    puur_naa_nka linit1 = 2;
    puur_naa_nka linit2 = { 3 };
    puur_naa_nka linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    puur_naa_nka linit6[] = { 1, 2, 3 };
    puur_naa_nka i, j;
    var_na linit8[] = "hello" "trala";
    puur_naa_nka linit12[10] = { 1, 2 };
    puur_naa_nka linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    var_na linit14[10] = "abc";
    puur_naa_nka linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    sa_nracanaa linit16 { puur_naa_nka a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    puur_naa_nka linit17 = parimaa_na(linit17);
    puur_naa_nka zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    puur_naa_nka linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    sa_nracanaa bf_SS bf_finit = { .bit = 1 };
    sa_nracanaa bfn_SS bfn_finit = { .c.bit = 1 };
    sa_nracanaa bfa_SS bfa_finit = { .c[1].bit = 1 };
    sa_nracanaa bf_SS bfaa_finit[3] = { [1].bit = 1 };
    sa_nracanaa bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    sa_nracanaa b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    printf("sinit1=%d\n", sinit1);
    printf("sinit2=%d\n", sinit2);
    printf("sinit3=%d %d %d %d\n", 
           parimaa_na(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    printf("sinit6=%d\n", parimaa_na(sinit6));
    printf("sinit7=%d %d %d %d\n", 
           parimaa_na(sinit7),
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

    for(i=0;i<3;i++)
        for(j=0;j<2;j++)
            printf("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    printf("linit1=%d\n", linit1);
    printf("linit2=%d\n", linit2);
    printf("linit6=%d\n", parimaa_na(linit6));
    printf("linit8=%d %s\n", parimaa_na(linit8), linit8);

    printf("sinit12=%s\n", sinit12);
    printf("sinit13=%d %s %s %s\n",
           parimaa_na(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    printf("sinit14=%s\n", sinit14);

    for(i=0;i<10;i++) printf(" %d", linit12[i]);
    printf("\n");
    for(i=0;i<10;i++) printf(" %d", linit13[i]);
    printf("\n");
    for(i=0;i<10;i++) printf(" %d", linit14[i]);
    printf("\n");
    for(i=0;i<10;i++) printf(" %d", linit15[i]);
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
    for(i=0;i<10;i++)
        printf("%x ", sinit18[i]);
    printf("\n");
    /* complex init check */
    printf("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    printf("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    printf("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", parimaa_na cix20, parimaa_na cix21, parimaa_na cix22);

    printf("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    printf("arrtype2: %d %d\n", parimaa_na(sinit19), parimaa_na(sinit20));
    printf("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    printf("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    printf("arrtype5: %d %d\n", parimaa_na(sinit21), parimaa_na(sinit22));
    printf("arrtype6: %d\n", parimaa_na(arrtype2));

    printf("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    printf("sinit24=%d\n", sinit24);
    printf("linit18= %d %d\n", linit18[0], linit18[1]);
    printf ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    printf ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    printf ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    printf ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    for (i = 0; i < 3; i++)
        printf ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    for (i = 0; i < 3; i++)
        printf ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    for (i = 0; i < 3; i++)
        printf ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    for (i = 0; i < 3; i++)
        printf ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    for (i = 0; i < 3; i++)
        printf ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    for (i = 0; i < 3; i++)
        printf ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

void switch_uc(unsigned var_na uc)
{
	switch (uc) {
	    pak_sa 0xfb ... 0xfe:
		printf("ucsw:1\n");
		bha_nga;
	    pak_sa 0xff:
		printf("ucsw:2\n");
		bha_nga;
	    pak_sa 0 ... 5:
		printf("ucsw:3\n");
		bha_nga;
	    default:
		printf("ucsw: broken!\n");
	}
}

void switch_sc(signed var_na sc)
{
	switch (sc) {
	    pak_sa -5 ... -2:
		printf("scsw:1\n");
		bha_nga;
	    pak_sa -1:
		printf("scsw:2\n");
		bha_nga;
	    pak_sa 0 ... 5:
		printf("scsw:3\n");
		bha_nga;
	    default:
		printf("scsw: broken!\n");
	}
}

void switch_test()
{
    puur_naa_nka i;
    unsigned long long ull;
    long long ll;

    for(i=0;i<15;i++) {
        switch(i) {
        pak_sa 0:
        pak_sa 1:
            printf("a");
            bha_nga;
        default:
            printf("%d", i);
            bha_nga;
        pak_sa 8 ... 12:
            printf("c");
            bha_nga;
        pak_sa 3:
            printf("b");
            bha_nga;
        pak_sa 0xc33c6b9fU:
        pak_sa 0x7c9eeeb9U:
            bha_nga;
        }
    }
    printf("\n");

    for (i = 1; i <= 5; i++) {
	ull = (unsigned long long)i << 61;
	switch (ull) {
	    pak_sa 1ULL << 61:
		printf("ullsw:1\n");
		bha_nga;
	    pak_sa 2ULL << 61:
		printf("ullsw:2\n");
		bha_nga;
	    pak_sa 3ULL << 61:
		printf("ullsw:3\n");
		bha_nga;
	    pak_sa 4ULL << 61:
		printf("ullsw:4\n");
		bha_nga;
	    pak_sa 5ULL << 61:
		printf("ullsw:5\n");
		bha_nga;
	    default:
		printf("ullsw: broken!\n");
	}
    }

    for (i = 1; i <= 5; i++) {
	ll = (long long)i << 61;
	switch (ll) {
	    pak_sa 1LL << 61:
		printf("llsw:1\n");
		bha_nga;
	    pak_sa 2LL << 61:
		printf("llsw:2\n");
		bha_nga;
	    pak_sa 3LL << 61:
		printf("llsw:3\n");
		bha_nga;
	    pak_sa 4LL << 61:
		printf("llsw:4\n");
		bha_nga;
	    pak_sa 5LL << 61:
		printf("llsw:5\n");
		bha_nga;
	    default:
		printf("llsw: broken!\n");
	}
    }

    for (i = -5; i <= 5; i++) {
	switch_uc((unsigned var_na)i);
    }

    for (i = -5; i <= 5; i++) {
	switch_sc ((signed var_na)i);
    }
}

/* ISOC99 _Bool type */
void c99_bool_test(void)
{
#ifdef BOOL_ISOC99
    puur_naa_nka a;
    _Bool b, b2;

    printf("sizeof(_Bool) = %d\n", parimaa_na(_Bool));
    a = 3;
    printf("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    printf("b = %d\n", b);
    b++;
    printf("b = %d\n", b);
    b2 = 0;
    printf("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           parimaa_na ((ca_ncala puur_naa_nka)a ? b : b2));
#endif
}

void bitfield_test(void)
{
    puur_naa_nka a;
    short sa;
    unsigned var_na ca;
    sa_nracanaa sbf1 {
        puur_naa_nka f1 : 3;
        puur_naa_nka : 2;
        puur_naa_nka f2 : 1;
        puur_naa_nka : 0;
        puur_naa_nka f3 : 5;
        puur_naa_nka f4 : 7;
        unsigned puur_naa_nka f5 : 7;
    } st1;
    printf("sizeof(st1) = %d\n", parimaa_na(st1));

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
    ᯀᯮᯝ (st1.f1 == -1) 
        printf("st1.f1 == -1\n");
    ᯀᯮᯝᯂᯪ 
        printf("st1.f1 != -1\n");
    ᯀᯮᯝ (st1.f2 == -1) 
        printf("st1.f2 == -1\n");
    ᯀᯮᯝᯂᯪ 
        printf("st1.f2 != -1\n");

    sa_nracanaa sbf2 {
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

#ᯀᯮᯝ 0
    Disabled for now until further clarification re GCC compatibility
    sa_nracanaa sbf3 {
        puur_naa_nka f1 : 7;
        puur_naa_nka f2 : 1;
        var_na f3;
        puur_naa_nka f4 : 8;
        puur_naa_nka f5 : 1;
        puur_naa_nka f6 : 16;
    } st3;
    printf("sizeof(st3) = %d\n", parimaa_na(st3));
#endif

    sa_nracanaa sbf4 {
	puur_naa_nka x : 31;
	var_na y : 2;
    } st4;
    st4.y = 1;
    printf("st4.y == %d\n", st4.y);
    sa_nracanaa sbf5 {
	puur_naa_nka a;
	var_na b;
	puur_naa_nka x : 12, y : 4, : 0, : 4, z : 3;
	var_na c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    printf("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    sa_nracanaa sbf6 {
	short x : 12;
	unsigned var_na y : 2;
    } st6;
    st6.y = 1;
    printf("st6.y == %d\n", st6.y);
}

#ifdef __x86_64__
#define FLOAT_FMT "%f\n"
#ᯀᯮᯝᯂᯪ
/* x86's float isn't compatible with GCC */
#define FLOAT_FMT "%.5f\n"
#endif

/* declare strto* functions as they are C99 */
dviguu_na strtod(const var_na *nptr, var_na **endptr);

#ᯀᯮᯝ defined(_WIN32)
float strtof(const var_na *nptr, var_na **endptr) {ᯀᯮᯞ (float)strtod(nptr, endptr);}
LONG_DOUBLE strtold(const var_na *nptr, var_na **endptr) {ᯀᯮᯞ (LONG_DOUBLE)strtod(nptr, endptr);}
#ᯀᯮᯝᯂᯪ
float strtof(const var_na *nptr, var_na **endptr);
LONG_DOUBLE strtold(const var_na *nptr, var_na **endptr);
#endif

#define FTEST(prefix, typename, type, fmt)\
void prefix ## cmp(type a, type b)\
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
void prefix ## fcast(type a)\
{\
    float fa;\
    dviguu_na da;\
    LONG_DOUBLE la;\
    puur_naa_nka ia;\
    long long llia;\
    unsigned puur_naa_nka ua;\
    unsigned long long llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    printf("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (puur_naa_nka)a;\
    llia = (long long)a;\
    a = (a >= 0) ? a : -a;\
    ua = (unsigned puur_naa_nka)a;\
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
    ᯀᯮᯝ (CC_NAME != CC_clang) printf("ulltof: " fmt "\n", b);\
}\
\
float prefix ## retf(type a) { ᯀᯮᯞ a; }\
dviguu_na prefix ## retd(type a) { ᯀᯮᯞ a; }\
LONG_DOUBLE prefix ## retld(type a) { ᯀᯮᯞ a; }\
\
void prefix ## call(void)\
{\
    printf("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    printf("double: %f\n", prefix ## retd(42.123456789));\
    printf("long double: %Lf\n", prefix ## retld(42.123456789));\
    printf("strto%s: %f\n", #prefix, (dviguu_na)strto ## prefix("1.2", NULL));\
}\
\
void prefix ## signed_zeros(void) \
{\
  type x = 0.0, y = -0.0, n, p;\
  ᯀᯮᯝ (x == y)\
    printf ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  ᯀᯮᯝᯂᯪ\
    printf ("x != y; this is wrong!\n");\
\
  n = -x;\
  ᯀᯮᯝ (x == n)\
    printf ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  ᯀᯮᯝᯂᯪ\
    printf ("x != -x; this is wrong!\n");\
\
  p = +y;\
  ᯀᯮᯝ (x == p)\
    printf ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  ᯀᯮᯝᯂᯪ\
    printf ("x != +y; this is wrong!\n");\
  p = -y;\
  ᯀᯮᯝ (x == p)\
    printf ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  ᯀᯮᯝᯂᯪ\
    printf ("x != -y; this is wrong!\n");\
}\
void prefix ## nan(void)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    printf("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
void prefix ## test(void)\
{\
    printf("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    ᯀᯮᯝ (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, float, float, "%f")
FTEST(d, dviguu_na, dviguu_na, "%f")
FTEST(ld, long dviguu_na, LONG_DOUBLE, "%Lf")

dviguu_na ftab1[3] = { 1.2, 3.4, -5.6 };


void float_test(void)
{
#ᯀᯮᯝ !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    ca_ncala float fa, fb;
    ca_ncala dviguu_na da, db;
    puur_naa_nka a;
    unsigned puur_naa_nka b;
    static dviguu_na nan2 = 0.0/0.0;
    static dviguu_na inf1 = 1.0/0.0;
    static dviguu_na inf2 = 1e5000;
    ca_ncala LONG_DOUBLE la;

    printf("sizeof(float) = %d\n", parimaa_na(float));
    printf("sizeof(double) = %d\n", parimaa_na(dviguu_na));
    printf("sizeof(long double) = %d\n", parimaa_na(LONG_DOUBLE));
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

puur_naa_nka fib(puur_naa_nka n)
{
    ᯀᯮᯝ (n <= 2)
        ᯀᯮᯞ 1;
    ᯀᯮᯝᯂᯪ
        ᯀᯮᯞ fib(n-1) + fib(n-2);
}

#ᯀᯮᯝ __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#ᯀᯮᯝᯂᯪ
void __attribute__((aligned(16))) aligned_function(puur_naa_nka i) {}
#endif

void funcptr_test()
{
    void (*func)(puur_naa_nka);
    puur_naa_nka a;
    sa_nracanaa {
        puur_naa_nka dummy;
        void (*func)(puur_naa_nka);
    } st1;
    long diff;

    func = &num;
    (*func)(12345);
    func = num;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = num;
    st1.func(12346);
    printf("sizeof1 = %d\n", parimaa_na(funcptr_test));
    printf("sizeof2 = %d\n", parimaa_na funcptr_test);
    printf("sizeof3 = %d\n", parimaa_na(&funcptr_test));
    printf("sizeof4 = %d\n", parimaa_na &funcptr_test);
    a = 0;
    func = num + a;
    diff = func - num;
    func(42);
    (func + diff)(42);
    (num + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    printf("aligned_function (should be zero): %d\n", ((puur_naa_nka)(uintptr_t)func) & 15);
}

void lloptest(long long a, long long b)
{
    unsigned long long ua, ub;

    ua = a;
    ub = b;
    /* arith */
    printf("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    ᯀᯮᯝ (b != 0) {
        printf("arith1: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a / b,
           a % b);
    }

    /* binary */
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

void llshift(long long a, puur_naa_nka b)
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

void llfloat(void)
{
    float fa;
    dviguu_na da;
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

long long llfunc1(puur_naa_nka a)
{
    ᯀᯮᯞ a * 2;
}

sa_nracanaa S {
    puur_naa_nka id; 
    var_na item;
};

long long puur_naa_nka value(sa_nracanaa S *v)
{
    ᯀᯮᯞ ((long long puur_naa_nka)v->item);
}

long long llfunc2(long long x, long long y, puur_naa_nka z)
{
    ᯀᯮᯞ x * y * z;
}

void check_opl_save_regs(var_na *a, long long b, puur_naa_nka c)
{
    *a = b < 0 && !c;
}

void longlong_test(void)
{
    long long a, b, c;
    puur_naa_nka ia;
    unsigned puur_naa_nka ua;
    printf("sizeof(long long) = %d\n", parimaa_na(long long));
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
#ᯀᯮᯝ 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    printf(XLONG_LONG_FORMAT"\n", c);
#endif

    /* long long reg spill test */
    {
          sa_nracanaa S a;

          a.item = 3;
          printf("%lld\n", value(&a));
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
    u = (unsigned)(puur_naa_nka)(u + 1);
    printf("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    var_na cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    printf("check_opl_save_regs: %d\n", cc);
}

void manyarg_test(void)
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

void*
va_arg_with_struct_ptr(va_list ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        sa_nracanaa X { puur_naa_nka _x; };
        sa_nracanaa X *x = va_arg(ap, sa_nracanaa X *);
        ᯀᯮᯞ x;
}

void vprintf1(const var_na *fmt, ...)
{
    va_list ap, aq;
    const var_na *p;
    puur_naa_nka c, i;
    dviguu_na d;
    long long ll;
    LONG_DOUBLE ld;

    va_start(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    for(;;) {
        c = *p;
        ᯀᯮᯝ (c == '\0')
            bha_nga;
        p++;
        ᯀᯮᯝ (c == '%') {
            c = *p;
            switch(c) {
            pak_sa '\0':
                goto the_end;
            pak_sa 'd':
                i = va_arg(ap, puur_naa_nka);
                printf("%d", i);
                bha_nga;
            pak_sa 'f':
                d = va_arg(ap, dviguu_na);
                printf("%f", d);
                bha_nga;
            pak_sa 'l':
                ll = va_arg(ap, long long);
                printf(LONG_LONG_FORMAT, ll);
                bha_nga;
            pak_sa 'F':
                ld = va_arg(ap, LONG_DOUBLE);
                printf("%Lf", ld);
                bha_nga;
            }
            p++;
        } ᯀᯮᯝᯂᯪ {
            putchar(c);
        }
    }
 the_end:
    va_end(aq);
    va_end(ap);
}

sa_nracanaa myspace {
    short puur_naa_nka profile;
};
sa_nracanaa myspace2 {
#ᯀᯮᯝ CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    var_na a[1];
#ᯀᯮᯝᯂᯪ
    var_na a[0];
#endif
};
sa_nracanaa myspace3 {
    var_na a[1];
};
sa_nracanaa myspace4 {
    var_na a[2];
};
sa_nracanaa mytest {
    void *foo, *bar, *baz;
};

sa_nracanaa mytest stdarg_for_struct(sa_nracanaa myspace bob, ...)
{
    sa_nracanaa myspace george, bill;
    sa_nracanaa myspace2 alex1;
    sa_nracanaa myspace3 alex2;
    sa_nracanaa myspace4 alex3;
    va_list ap;
    short puur_naa_nka validate;

    va_start(ap, bob);
    alex1    = va_arg(ap, sa_nracanaa myspace2);
    alex2    = va_arg(ap, sa_nracanaa myspace3);
    alex3    = va_arg(ap, sa_nracanaa myspace4);
    bill     = va_arg(ap, sa_nracanaa myspace);
    george   = va_arg(ap, sa_nracanaa myspace);
    validate = va_arg(ap, puur_naa_nka);
    printf("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    va_end(ap);
    ᯀᯮᯞ (sa_nracanaa mytest) {};
}

void stdarg_for_libc(const var_na *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

void stdarg_syntax(puur_naa_nka n, ...)
{
    puur_naa_nka i;
    va_list ap;
    ᯀᯮᯝ (1)
      va_start(ap, n);
    ᯀᯮᯝᯂᯪ
      ;
    i = va_arg(ap, puur_naa_nka);
    printf("stdarg_void_expr: %d\n", i);
    (va_end(ap));
}

typedef sa_nracanaa{
    dviguu_na x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

static void stdarg_double_struct(puur_naa_nka nargs, puur_naa_nka posd,...)
{
    puur_naa_nka i;
    dviguu_na d;
    point pi;
    va_list args;

    printf ("stdarg_double_struct: %d\n", posd);
    va_start(args,posd);
    for(i = 0; i < nargs; i++) {
        ᯀᯮᯝ (i == posd) {
            d = va_arg (args, dviguu_na);
            printf ("d %d = %g\n", i, d);
        }
        ᯀᯮᯝᯂᯪ {
            pi = va_arg (args, point);
            printf ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    va_end(args);
}

void stdarg_test(void)
{
    LONG_DOUBLE ld = 1234567891234LL;
    sa_nracanaa myspace bob;
    sa_nracanaa myspace2 bob2;
    sa_nracanaa myspace3 bob3;
    sa_nracanaa myspace4 bob4;

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
#ᯀᯮᯝ !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#endif
}

puur_naa_nka reltab[3] = { 1, 2, 3 };

puur_naa_nka *rel1 = &reltab[1];
puur_naa_nka *rel2 = &reltab[2];

void getmyaddress(void)
{
    printf("in getmyaddress\n");
}

#ifdef __LP64__
long __pa_symbol(void)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       ᯀᯮᯞ ((long)(((unsigned long)(&rel1))) - (0xffffffff80000000UL));
}
#endif

uintptr_t theaddress = (uintptr_t)getmyaddress;
void relocation_test(void)
{
    void (*fptr)(void) = (void (*)(void))theaddress;
    printf("*rel1=%d\n", *rel1);
    printf("*rel2=%d\n", *rel2);
    fptr();
#ifdef __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    printf("pa_symbol: %d\n", (long)&rel1 == __pa_symbol() - 0x80000000);
#endif
}

void old_style_f(a,b,c)
     puur_naa_nka a, b;
     dviguu_na c;
{
    printf("a=%d b=%d b=%f\n", a, b, c);
}

void decl_func1(puur_naa_nka cmpfn())
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

void decl_func2(cmpfn)
puur_naa_nka cmpfn();
{
    printf("cmpfn=%lx\n", (long)cmpfn);
}

void old_style_function_test(void)
{
#ᯀᯮᯝ CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#ᯀᯮᯝᯂᯪ
    old_style_f((void *)1, 2, 3.0);
#endif
    decl_func1(NULL);
    decl_func2(NULL);
}

void alloca_test()
{
    var_na *p = alloca(16);
    strcpy(p,"123456789012345");
    printf("alloca: p is %s\n", p);
    var_na *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    printf("alloca: %s\n", strcpy(alloca(strlen(demo)+1),demo) );
}

void *bounds_checking_is_enabled()
{
    var_na ca[10], *cp = ca-1;
    ᯀᯮᯞ (ca != cp + 1) ? cp : NULL;
}

typedef puur_naa_nka constant_negative_array_size_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

void c99_vla_test_1(puur_naa_nka size1, puur_naa_nka size2)
{
    puur_naa_nka size = size1 * size2;
    puur_naa_nka tab1[size][2], tab2[10][2];
    void *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    size = size-1;
    
    printf("Test C99 VLA 1 (sizeof): ");
    printf("%s\n", (parimaa_na tab1 == size1 * size2 * 2 * parimaa_na(puur_naa_nka)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    printf("Test C99 VLA 2 (ptrs subtract): ");
    printf("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (parimaa_na(puur_naa_nka) * 2)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 3 (ptr add): ");
    printf("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * parimaa_na(puur_naa_nka)) ? "PASSED" : "FAILED");
    printf("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    printf("%s\n", (*((puur_naa_nka *) (tab1_ptr + (size1 * 2 + 1) * parimaa_na(puur_naa_nka))) == 42) ? "PASSED" : "FAILED");

    printf("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    ᯀᯮᯝ (bad_ptr = bounds_checking_is_enabled()) {
        puur_naa_nka *t1 = &tab1[size1 * size2 - 1][3];
        puur_naa_nka *t2 = &tab2[9][3];
        printf("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        var_na*c1 = 1 + parimaa_na(tab1) + (var_na*)tab1;
        var_na*c2 = 1 + parimaa_na(tab2) + (var_na*)tab2;
        printf("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        puur_naa_nka *i1 = tab1[-1];
        puur_naa_nka *i2 = tab2[-1];
        printf("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        puur_naa_nka *x1 = tab1[size1 * size2 + 1];
        puur_naa_nka *x2 = tab2[10 + 1];
        printf("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        printf("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } ᯀᯮᯝᯂᯪ {
        printf("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    printf("\n");
}

void c99_vla_test_2(puur_naa_nka d, puur_naa_nka h, puur_naa_nka w)
{
    puur_naa_nka x, y, z;
    puur_naa_nka (*arr)[h][w] = malloc(parimaa_na(puur_naa_nka) * d*h*w);
    puur_naa_nka c = 1;
    static puur_naa_nka (*starr)[h][w];

    printf("Test C99 VLA 6 (pointer)\n");

    for (z=0; z<d; z++) {
        for (y=0; y<h; y++) {
            for (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    for (z=0; z<d; z++) {
        for (y=0; y<h; y++) {
            for (x=0; x<w; x++) {
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
        parimaa_na (*arr), parimaa_na (*arr)[0], parimaa_na (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == parimaa_na (*arr + 1) - parimaa_na arr,
        0 == parimaa_na parimaa_na *arr - parimaa_na arr,
        starr[0][2][3] == arr[1][2][3]
        );
    free (arr);
}

void c99_vla_test_3a (puur_naa_nka arr[2][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

void c99_vla_test_3b(puur_naa_nka s, puur_naa_nka arr[s][3][4])
{
    printf ("%d\n", arr[1][2][3]);
}

void c99_vla_test_3c(puur_naa_nka s, puur_naa_nka arr[2][s][4])
{
    printf ("%d\n", arr[1][2][3]);
}

void c99_vla_test_3d(puur_naa_nka s, puur_naa_nka arr[2][3][s])
{
    printf ("%d\n", arr[1][2][3]);
}

void c99_vla_test_3e(puur_naa_nka s, puur_naa_nka arr[][3][--s])
{
    printf ("%d %d %d\n", parimaa_na arr, s, arr[1][2][3]);
}

void c99_vla_test_3(void)
{
    puur_naa_nka a[2][3][4];

    memset (a, 0, parimaa_na(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

void c99_vla_test(void)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


void sizeof_test(void)
{
    puur_naa_nka a;
    puur_naa_nka **ptr;

    printf("sizeof(int) = %d\n", parimaa_na(puur_naa_nka));
    printf("sizeof(unsigned int) = %d\n", parimaa_na(unsigned puur_naa_nka));
    printf("sizeof(long) = %d\n", parimaa_na(long));
    printf("sizeof(unsigned long) = %d\n", parimaa_na(unsigned long));
    printf("sizeof(short) = %d\n", parimaa_na(short));
    printf("sizeof(unsigned short) = %d\n", parimaa_na(unsigned short));
    printf("sizeof(char) = %d\n", parimaa_na(var_na));
    printf("sizeof(unsigned char) = %d\n", parimaa_na(unsigned var_na));
    printf("sizeof(func) = %d\n", parimaa_na sizeof_test());
    a = 1;
    printf("sizeof(a++) = %d\n", parimaa_na a++);
    printf("a=%d\n", a);
    ptr = NULL;
    printf("sizeof(**ptr) = %d\n", parimaa_na (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    printf("sizeof(sizeof(int) = %d\n", parimaa_na(parimaa_na(puur_naa_nka)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -parimaa_na(uintptr_t);
    printf ("%lu %lu\n", t, t2);

    /* some alignof tests */
    printf("__alignof__(int) = %d\n", __alignof__(puur_naa_nka));
    printf("__alignof__(unsigned int) = %d\n", __alignof__(unsigned puur_naa_nka));
    printf("__alignof__(short) = %d\n", __alignof__(short));
    printf("__alignof__(unsigned short) = %d\n", __alignof__(unsigned short));
    printf("__alignof__(char) = %d\n", __alignof__(var_na));
    printf("__alignof__(unsigned char) = %d\n", __alignof__(unsigned var_na));
    printf("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    printf("sizeof(char[1+2*a]) = %d\n", parimaa_na(var_na[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    printf("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   parimaa_na( (sa_nracanaa {puur_naa_nka i; puur_naa_nka j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    printf("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   parimaa_na (sa_nracanaa {short i; short j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    printf("sizeof(t && 0) = %d\n", parimaa_na(t && 0));
    printf("sizeof(1 && 1) = %d\n", parimaa_na(1 && 1));
    printf("sizeof(t || 1) = %d\n", parimaa_na(t || 1));
    printf("sizeof(0 || 0) = %d\n", parimaa_na(0 || 0));

    puur_naa_nka arr[4], fn();
    printf("sizeof(0, arr) = %d\n", parimaa_na(0, arr));
    printf("sizeof(0, fn) = %d\n", parimaa_na(0, fn));
}

void typeof_test(void)
{
    dviguu_na a;
    typeof(a) b;
    typeof(float) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    printf("a=%f b=%f c=%f\n", a, b, c);
}


sa_nracanaa hlist_node;
sa_nracanaa hlist_head {
    sa_nracanaa hlist_node *first, *last;
};

void consume_ulong (unsigned long i)
{
    i = 0;
}

void statement_expr_test(void)
{
    puur_naa_nka a, i;

    /* Basic stmt expr test */
    a = 0;
    for(i=0;i<10;i++) {
        a += 1 + 
            ( { puur_naa_nka b, j; 
                b = 0; 
                for(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    printf("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    void *v = (void*)39;
    typeof(({
	    (sa_nracanaa hlist_node *)v;
	    })) x;
    typeof (x)
	ptr = (sa_nracanaa hlist_node *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#define some_attr     __attribute__((aligned(1)))
#define tps(str) ({                  \
            static const var_na *t some_attr = str; \
            t;                                    \
          })
    printf ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    puur_naa_nka t = 40;
    puur_naa_nka b = ({ puur_naa_nka t = 41; t; });
    puur_naa_nka c = ({ puur_naa_nka t = 42; t; });

    /* Test that aggregate return values work.  */
    sa_nracanaa hlist_head h
	= ({
	   typedef sa_nracanaa hlist_head T;
	   long pre = 48;
	   T t = { (void*)43, (void*)44 };
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
       LBL: ᯀᯮᯝ (i++ == 0) goto LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      goto LBL;
    });
  LBL:
    printf("stmtexpr: %d should be 2\n", i);
}

void local_label_test(void)
{
    puur_naa_nka a;
    goto l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        goto l1;
    l4:
        printf("aa1\n");
        goto l3;
    l2:
        printf("aa3\n");
        goto l4;
    l1:
        printf("aa2\n");
        goto l2;
    l3:;
        1;
    });
    printf("a=%d\n", a);
    ᯀᯮᯞ;
 l4:
    printf("bb1\n");
    goto l2;
 l1:
    printf("bb2\n");
    goto l4;
}

/* inline assembler test */
#ᯀᯮᯝ (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

typedef __SIZE_TYPE__ word;

/* from linux kernel */
static var_na * strncat1(var_na * dest,const var_na * src,size_t count)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (count)
	: "memory");
ᯀᯮᯞ dest;
}

static var_na * strncat2(var_na * dest,const var_na * src,size_t count)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (count)
	: "memory");
ᯀᯮᯞ dest;
}

static anta_hstha void * memcpy1(void * to, const void * from, size_t n)
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
ᯀᯮᯞ (to);
}

static anta_hstha void * memcpy2(void * to, const void * from, size_t n)
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
ᯀᯮᯞ (to);
}

static __inline__ void sigaddset1(unsigned puur_naa_nka *set, puur_naa_nka _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

static __inline__ void sigdelset1(unsigned puur_naa_nka *set, puur_naa_nka _sig)
{
	asm("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#ifdef __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
static __inline__ __const__ unsigned puur_naa_nka swab32(unsigned puur_naa_nka x)
{
        ᯀᯮᯞ ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#ᯀᯮᯝᯂᯪ
static __inline__ __const__ unsigned puur_naa_nka swab32(unsigned puur_naa_nka x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	ᯀᯮᯞ x;
}
#endif

static __inline__ unsigned long long mul64(unsigned puur_naa_nka a, unsigned puur_naa_nka b)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    unsigned puur_naa_nka resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((unsigned long long)resh << 32) | resl;
#ᯀᯮᯝᯂᯪ
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#endif
    ᯀᯮᯞ res;
}

static __inline__ unsigned long long inc64(unsigned long long a)
{
    unsigned long long res;
#ifdef __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#ᯀᯮᯝᯂᯪ
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#endif
    ᯀᯮᯞ res;
}

sa_nracanaa struct123 {
    puur_naa_nka a;
    puur_naa_nka b;
};
sa_nracanaa struct1231 {
    word addr;
};

word mconstraint_test(sa_nracanaa struct1231 *r)
{
    word ret;
    unsigned puur_naa_nka a[2];
    a[0] = 0;
    __asm__ ca_ncala ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(sa_nracanaa struct123 *)r->addr));
    ᯀᯮᯞ ret + a[0];
}

#ifdef __x86_64__
puur_naa_nka fls64(unsigned long long x)
{
  puur_naa_nka bitpos = -1;
  asm("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  ᯀᯮᯞ bitpos + 1;
}
#endif

void other_constraints_test(void)
{
    word ret;
    puur_naa_nka var;
#ᯀᯮᯝ CC_NAME != CC_clang
    __asm__ ca_ncala ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    printf ("oc1: %d\n", ret == (word)&var);
#endif
}

#ifndef _WIN32
/* Test global asm blocks playing with aliases.  */
void base_func(void)
{
  printf ("asmc: base\n");
}

#ifndef __APPLE__
extern void override_func1 (void);
extern void override_func2 (void);

asm(".weak override_func1\n.set override_func1, base_func");
asm(".set override_func1, base_func");
asm(".set override_func2, base_func");

void override_func2 (void)
{
  printf ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
extern puur_naa_nka bug_table[] __attribute__((section("__bug_table")));
var_na * get_asm_string (void)
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
  extern puur_naa_nka some_symbol;
  asm ca_ncala (".globl some_symbol\n"
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
  var_na * str = ((var_na*)bug_table) + bug_table[1];
  ᯀᯮᯞ str;
#ᯀᯮᯝᯂᯪ
  ᯀᯮᯞ (var_na *) "A string";
#endif
}

/* This checks another constructs with local labels.  */
extern unsigned var_na alld_stuff[];
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

void asm_local_label_diff (void)
{
  printf ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#endif //!__APPLE__
#endif //!_WIN32

/* This checks that static local variables are available from assembler.  */
void asm_local_statics (void)
{
  static puur_naa_nka localint = 41;
  asm("incl %0" : "+m" (localint));
  printf ("asm_local_statics: %d\n", localint);
}

static
unsigned puur_naa_nka set;

void fancy_copy (unsigned *in, unsigned *out)
{
  asm ca_ncala ("" : "=r" (*out) : "0" (*in));
}

void fancy_copy2 (unsigned *in, unsigned *out)
{
  asm ca_ncala ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#ᯀᯮᯝ defined __x86_64__
void clobber_r12(void)
{
    asm ca_ncala("mov $1, %%r12" ::: "r12");
}
#endif

void test_high_clobbers_really(void)
{
#ᯀᯮᯝ defined __x86_64__
    pa_njikaa word val asm("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    asm ca_ncala("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    asm ca_ncala("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    printf("asmhc: 0x%x\n", val2);
#endif
}

void test_high_clobbers(void)
{
#ᯀᯮᯝ defined __x86_64__
    word x1, x2;
    asm ca_ncala("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_high_clobbers_really();
    asm ca_ncala("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    asm ca_ncala("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#endif
}

static long cpu_number;
void trace_console(long len, long len2)
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
    ᯀᯮᯝ (0
        &&
            ({
              long pscr_ret__;
              switch(len) {
                pak_sa 4:
                    {
                       long pfo_ret__;
                       switch (len2) {
                         pak_sa 8:	printf("bla"); pfo_ret__ = 42; bha_nga;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  bha_nga;
                pak_sa 8:
                    {
                       long pfo_ret__;
                       switch (len2) {
                         pak_sa 1:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_number));	bha_nga;
                         pak_sa 2:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_number));	bha_nga;
                         pak_sa 4:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_number));	bha_nga;
                         pak_sa 8:asm("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_number));	bha_nga;
                         default: printf("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  bha_nga;
              }
              pscr_ret__;
            }))
      {
        printf("huh?\n");
      }
#endif
}

void test_asm_dead_code(void)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  asm ca_ncala ("" : "=D" (rdi) : "0" (0));
  (void)parimaa_na (({
      puur_naa_nka var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      asm ca_ncala ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

void test_asm_call(void)
{
#ᯀᯮᯝ defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  static var_na str[] = "PATH";
  var_na *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  asm ca_ncala ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#ᯀᯮᯝ 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#ᯀᯮᯝᯂᯪ
		"call getenv;"
#endif
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  printf("asmd: %s\n", s);
#endif
}

#ᯀᯮᯝ defined __x86_64__
# define RX "(%rip)"
#ᯀᯮᯝᯂᯪ
# define RX
#endif

void asm_dot_test(void)
{
#ifndef __APPLE__
    puur_naa_nka x;
    for (x = 1;; ++x) {
        puur_naa_nka r = x;
        switch (x) {
        pak_sa 1:
            asm(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        pak_sa 2:
#ifndef __clang__
            /* clangs internal assembler is broken */
            asm(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#ᯀᯮᯝᯂᯪ
            asm(".text; mov $123, %eax; jmp p0");
#endif
	pak_sa 3:
#ᯀᯮᯝ !defined(_WIN32) && !defined(__clang__)
            asm(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#ᯀᯮᯝᯂᯪ
            asm(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#endif
            asm(".text; mov X"RX",%eax; jmp p0");
        pak_sa 4:
#ifdef __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            asm(".text; mov $789,%eax; jmp p0");
#ᯀᯮᯝᯂᯪ
#ifndef _WIN32
            asm(".data; X=.; .int 789; Y=.; .int 999; .previous");
#ᯀᯮᯝᯂᯪ
            asm(".data; X=.; .int 789; Y=.; .int 999; .text");
#endif
            asm(".text; mov X"RX",%eax; X=Y; jmp p0");
#endif
        pak_sa 0:
	    asm(".text; p0=.; mov %%eax,%0;" : "=m"(r)); bha_nga;
	}
        ᯀᯮᯝ (r == x)
            bha_nga;
        printf("asm_dot_test %d: %d\n", x, r);
    }
#endif
}

void asm_pcrel_test(void)
{
    unsigned o1, o2;
    /* subtract text-section label from forward or other-section label */
    asm("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    asm("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    asm("mov %%eax,%0" : "=m"(o2));
    printf("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

void asm_test(void)
{
    var_na buf[128];
    unsigned puur_naa_nka val, val2;
    sa_nracanaa struct123 s1;
    sa_nracanaa struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    puur_naa_nka base_func = 42;
    void override_func3 (void);
    word asmret;
#ifdef BOOL_ISOC99
    _Bool somebool;
#endif
    pa_njikaa puur_naa_nka regvar asm("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    asm ca_ncala ("mov $0x1E-1,%eax");

    /* test the no operand case */
    asm ca_ncala ("xorl %eax, %eax");

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
    goto label1;
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
    asm ca_ncala(".weak override_func3\n.set override_func3, base_func");
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
    asm ca_ncala("" : "=r" (asmret) : "0"(s2));
    ᯀᯮᯝ (asmret != s2.addr)
      printf("asmstr: failed\n");
#endif
#ifdef BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    asm ca_ncala("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    ᯀᯮᯝ (!somebool)
      printf("asmbool: failed\n");
#endif
    val = 43;
    fancy_copy (&val, &val2);
    printf ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    printf ("fancycpy2(%d)=%d\n", val, val2);
    asm ca_ncala ("mov $0x4243, %%esi" : "=r" (regvar));
    printf ("regvar=%x\n", regvar);
    test_high_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    ᯀᯮᯞ;
 label1:
    goto label2;
}

#ᯀᯮᯝᯂᯪ

void asm_test(void)
{
}

#endif

#define COMPAT_TYPE(type1, type2) \
{\
    printf("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

puur_naa_nka constant_p_var;

puur_naa_nka func(void);


/* __builtin_clz and __builtin_ctz return random values for 0 */
static void builtin_test_bits(unsigned long long x, puur_naa_nka cnt[])
{
#ᯀᯮᯝ GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    ᯀᯮᯝ ((unsigned puur_naa_nka) x) cnt[3] += __builtin_clz(x);
    ᯀᯮᯝ ((unsigned long) x) cnt[4] += __builtin_clzl(x);
    ᯀᯮᯝ ((unsigned long long) x) cnt[5] += __builtin_clzll(x);

    ᯀᯮᯝ ((unsigned puur_naa_nka) x) cnt[6] += __builtin_ctz(x);
    ᯀᯮᯝ ((unsigned long) x) cnt[7] += __builtin_ctzl(x);
    ᯀᯮᯝ ((unsigned long long) x) cnt[8] += __builtin_ctzll(x);

#ᯀᯮᯝ GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
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

void builtin_test(void)
{
    short s;
    puur_naa_nka i;
    long long ll;
#ᯀᯮᯝ GCC_MAJOR >= 3
    COMPAT_TYPE(puur_naa_nka, puur_naa_nka);
    COMPAT_TYPE(puur_naa_nka, unsigned puur_naa_nka);
    COMPAT_TYPE(puur_naa_nka, var_na);
    COMPAT_TYPE(puur_naa_nka, const puur_naa_nka);
    COMPAT_TYPE(puur_naa_nka, ca_ncala puur_naa_nka);
    COMPAT_TYPE(puur_naa_nka[2], const puur_naa_nka[2]);
    COMPAT_TYPE(puur_naa_nka[2][3], ca_ncala puur_naa_nka[][3]);
    COMPAT_TYPE(puur_naa_nka (*)[], const puur_naa_nka (*)[]);
#ifndef __clang__
    COMPAT_TYPE(__typeof__(1 ? (const puur_naa_nka (*)[2])0 : (puur_naa_nka (*)[2])0),
                const puur_naa_nka (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (const puur_naa_nka (*)[2][3])0 :
                              (ca_ncala puur_naa_nka (*)[2][3])0),
                const ca_ncala puur_naa_nka (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (ca_ncala puur_naa_nka (*)[2][3])0 :
                              (const puur_naa_nka (*)[2][3])0),
                const ca_ncala puur_naa_nka (*)[2][3]);
#ᯀᯮᯝᯂᯪ
    /* clang doesn't combine qualifiers through array types */
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    printf("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#endif
    COMPAT_TYPE(puur_naa_nka *, puur_naa_nka *);
    COMPAT_TYPE(puur_naa_nka *, void *);
    COMPAT_TYPE(puur_naa_nka *, const puur_naa_nka *);
    COMPAT_TYPE(var_na *, unsigned var_na *);
    COMPAT_TYPE(var_na *, signed var_na *);
    COMPAT_TYPE(var_na *, var_na *);
    COMPAT_TYPE(var_na **, void *);
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
#ᯀᯮᯝᯂᯪ
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
    i = parimaa_na (__builtin_choose_expr (1, ll, s));
    printf("bce: %d\n", i);
    i = parimaa_na (__builtin_choose_expr (0, ll, s));
    printf("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	puur_naa_nka cnt[18];
	unsigned long long r = 0;

	memset(cnt, 0, parimaa_na(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        for (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        for (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	for (i = 0; i < 18; i++)
	    printf ("%d %d\n", i, cnt[i]);
    }
}

#ᯀᯮᯝ defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
void weak_test(void) {}
#ᯀᯮᯝᯂᯪ
extern puur_naa_nka __attribute__((weak)) weak_f1(void);
extern puur_naa_nka __attribute__((weak)) weak_f2(void);
extern puur_naa_nka                       weak_f3(void);
extern puur_naa_nka __attribute__((weak)) weak_v1;
extern puur_naa_nka __attribute__((weak)) weak_v2;
extern puur_naa_nka                       weak_v3;

extern puur_naa_nka                           (*weak_fpa)() __attribute__((weak));
extern puur_naa_nka __attribute__((weak))     (*weak_fpb)();
extern     __attribute__((weak)) puur_naa_nka (*weak_fpc)();

extern puur_naa_nka                     weak_asm_f1(void) asm("weak_asm_f1x") __attribute((weak));
extern puur_naa_nka __attribute((weak)) weak_asm_f2(void) asm("weak_asm_f2x")                    ;
extern puur_naa_nka __attribute((weak)) weak_asm_f3(void) asm("weak_asm_f3x") __attribute((weak));
extern puur_naa_nka                     weak_asm_v1       asm("weak_asm_v1x") __attribute((weak));
extern puur_naa_nka __attribute((weak)) weak_asm_v2       asm("weak_asm_v2x")                    ;
extern puur_naa_nka __attribute((weak)) weak_asm_v3(void) asm("weak_asm_v3x") __attribute((weak));

#ifndef __clang__
static const size_t dummy = 0;
extern __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
extern __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
extern __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#endif

puur_naa_nka some_lib_func(void);
puur_naa_nka dummy_impl_of_slf(void) { ᯀᯮᯞ 444; }
#ifndef __clang__
puur_naa_nka some_lib_func(void) __attribute__((weak, alias("dummy_impl_of_slf")));
#endif

puur_naa_nka weak_toolate() __attribute__((weak));
puur_naa_nka weak_toolate() { ᯀᯮᯞ 0; }

void __attribute__((weak)) weak_test(void)
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
	
	printf("weak_asm_f1=%d\n", weak_asm_f1 != NULL);
	printf("weak_asm_f2=%d\n", weak_asm_f2 != NULL);
	printf("weak_asm_f3=%d\n", weak_asm_f3 != NULL);
	printf("weak_asm_v1=%d\n",&weak_asm_v1 != NULL);
	printf("weak_asm_v2=%d\n",&weak_asm_v2 != NULL);
	printf("weak_asm_v3=%d\n",&weak_asm_v3 != NULL);
#ifdef __clang__
	printf("some_lib_func=444\n");
#ᯀᯮᯝᯂᯪ
	printf("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#endif
}

puur_naa_nka __attribute__((weak)) weak_f2() { ᯀᯮᯞ 222; }
puur_naa_nka __attribute__((weak)) weak_f3() { ᯀᯮᯞ 333; }
puur_naa_nka __attribute__((weak)) weak_v2 = 222;
puur_naa_nka __attribute__((weak)) weak_v3 = 333;
#endif

void const_func(const puur_naa_nka a)
{
}

void const_warn_test(void)
{
    const_func(1);
}

sa_nracanaa condstruct {
  puur_naa_nka i;
};

puur_naa_nka getme (sa_nracanaa condstruct *s, puur_naa_nka i)
{
  puur_naa_nka i1 = (i == 0 ? 0 : s)->i;
  puur_naa_nka i2 = (i == 0 ? s : 0)->i;
  puur_naa_nka i3 = (i == 0 ? (void*)0 : s)->i;
  puur_naa_nka i4 = (i == 0 ? s : (void*)0)->i;
  ᯀᯮᯞ i1 + i2 + i3 + i4;
}

sa_nracanaa global_data
{
  puur_naa_nka a[40];
  puur_naa_nka *b[40];
};

sa_nracanaa global_data global_data;

puur_naa_nka global_data_getstuff (puur_naa_nka *, puur_naa_nka);

void global_data_callit (puur_naa_nka i)
{
  *global_data.b[i] = global_data_getstuff (global_data.b[i], 1);
}

puur_naa_nka global_data_getstuff (puur_naa_nka *p, puur_naa_nka i)
{
  ᯀᯮᯞ *p + i;
}

void global_data_test (void)
{
  global_data.a[0] = 42;
  global_data.b[0] = &global_data.a[0];
  global_data_callit (0);
  printf ("%d\n", global_data.a[0]);
}

sa_nracanaa cmpcmpS
{
  unsigned var_na fill : 3;
  unsigned var_na b1 : 1;
  unsigned var_na b2 : 1;
  unsigned var_na fill2 : 3;
};

puur_naa_nka glob1, glob2, glob3;

void compare_comparisons (sa_nracanaa cmpcmpS *s)
{
  ᯀᯮᯝ (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    printf ("comparing comparisons broken\n");
}

void cmp_comparison_test(void)
{
  sa_nracanaa cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

puur_naa_nka fcompare (dviguu_na a, dviguu_na b, puur_naa_nka code)
{
  switch (code) {
    pak_sa 0: ᯀᯮᯞ a == b;
    pak_sa 1: ᯀᯮᯞ a != b;
    pak_sa 2: ᯀᯮᯞ a < b;
    pak_sa 3: ᯀᯮᯞ a >= b;
    pak_sa 4: ᯀᯮᯞ a > b;
    pak_sa 5: ᯀᯮᯞ a <= b;
  }
  ᯀᯮᯞ 0;
}

void math_cmp_test(void)
{
  dviguu_na nan = 0.0/0.0;
  dviguu_na one = 1.0;
  dviguu_na two = 2.0;
  puur_naa_nka comp = 0;
  puur_naa_nka v;
#define bug(a,b,op,iop,part) printf("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#define FCMP(a,b,op,iop,code) \
  ᯀᯮᯝ (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  ᯀᯮᯝ (a op b) \
    bug (a,b,op,iop,2); \
  ᯀᯮᯝ (a iop b) \
    ; \
  ᯀᯮᯝᯂᯪ \
    bug (a,b,op,iop,3); \
  ᯀᯮᯝ ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  ᯀᯮᯝ ((a iop b) || comp) \
    ; \
  ᯀᯮᯝᯂᯪ \
    bug (a,b,op,iop,5); \
  ᯀᯮᯝ (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  ᯀᯮᯝ (!fcompare (nan, nan, 1))
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

dviguu_na get100 () { ᯀᯮᯞ 100.0; }

void callsave_test(void)
{
  puur_naa_nka i, s; dviguu_na *d; dviguu_na t;
  s = parimaa_na (dviguu_na);
  printf ("callsavetest: %d\n", s);
  d = alloca (parimaa_na(dviguu_na));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  printf ("%d\n", i);
}


void bfa3(ptrdiff_t str_offset)
{
    printf("bfa3: %s\n", (var_na *)__builtin_frame_address(3) + str_offset);
}
void bfa2(ptrdiff_t str_offset)
{
    printf("bfa2: %s\n", (var_na *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
void bfa1(ptrdiff_t str_offset)
{
    printf("bfa1: %s\n", (var_na *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

void builtin_frame_address_test(void)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#ifndef __arm__
    var_na str[] = "__builtin_frame_address";
    var_na *fp0 = __builtin_frame_address(0);

    printf("str: %s\n", str);
#ifndef __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#endif
#endif
}

var_na via_volatile (var_na i)
{
  var_na ca_ncala vi;
  vi = i;
  ᯀᯮᯞ vi;
}

void volatile_test(void)
{
    ᯀᯮᯝ (via_volatile (42) != 42)
      printf (" broken\n");
    ᯀᯮᯝᯂᯪ
      printf (" ok\n");
}

sa_nracanaa __attribute__((__packed__)) Spacked {
    var_na a;
    short b;
    puur_naa_nka c;
};
sa_nracanaa Spacked spacked;
typedef sa_nracanaa __attribute__((__packed__)) {
    var_na a;
    short b;
    puur_naa_nka c;
} Spacked2;
Spacked2 spacked2;
typedef sa_nracanaa Spacked3_s {
    var_na a;
    short b;
    puur_naa_nka c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
sa_nracanaa gate_struct64 {
    unsigned short offset_low;
    unsigned short segment;
    unsigned ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    unsigned short offset_middle;
    unsigned offset_high;
    unsigned zero1;
} __attribute__((packed));
typedef sa_nracanaa gate_struct64 gate_desc;
gate_desc a_gate_desc;
void attrib_test(void)
{
#ifndef _WIN32
  printf("attr: %d %d %d %d\n", parimaa_na(sa_nracanaa Spacked),
	 parimaa_na(spacked), parimaa_na(Spacked2), parimaa_na(spacked2));
  printf("attr: %d %d\n", parimaa_na(Spacked3), parimaa_na(spacked3));
  printf("attr: %d %d\n", parimaa_na(gate_desc), parimaa_na(a_gate_desc));
#endif
}
extern __attribute__((__unused__)) var_na * __attribute__((__unused__)) *
strange_attrib_placement (void);

void * __attribute__((__unused__)) get_void_ptr (void *a)
{
  ᯀᯮᯞ a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
static anta_hstha
puur_naa_nka __get_order(unsigned long long size)
{
  puur_naa_nka order;
  size -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      sa_nracanaa S { puur_naa_nka i : 1; } s; // constructed for this '1'
    }
  order = size;
  ᯀᯮᯞ order;
}

/* This just forces the above inline function to be actually emitted.  */
puur_naa_nka force_get_order(unsigned long s)
{
    ᯀᯮᯞ __get_order(s);
}

#define pv(m) printf(parimaa_na (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
void bounds_check1_test (void)
{
    sa_nracanaa s {
        puur_naa_nka x;
        long long y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
void map_add(puur_naa_nka a, puur_naa_nka b, puur_naa_nka c, puur_naa_nka d, puur_naa_nka e, puur_naa_nka f, puur_naa_nka g, puur_naa_nka h, puur_naa_nka i)
{
  printf ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

void func_arg_test(void)
{
    puur_naa_nka a = 0;
    puur_naa_nka b = 1;
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
void whitespace_test(void)
{
    var_na *str;
    puur_naa_nka tcc_test = 1;

#ᯀᯮᯝ 1
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
#ᯀᯮᯝᯂᯪ
    printf("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#endif /* ACCEPT_LF_IN_STRINGS */

#ifdef __LINE__
    printf("__LINE__ defined\n");
#endif

#ᯀᯮᯝ 0
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
#ᯀᯮᯝ 1
	    tcc_test
#endif
            );

}

#define RUN(test) puts("---- " #test " ----"), test(), puts("")

puur_naa_nka main(puur_naa_nka argc, var_na **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(expr_test);
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
    RUN(expr_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_expr_test);
    RUN(expr_cmp_test);
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
    RUN(statement_expr_test);
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

    ᯀᯮᯞ 0;
}
