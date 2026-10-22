/*
 * TCC auto test program
 */
#समावेश "config.h"

/* identify the configured reference compiler in use */
#घोषणा CC_gcc 1
#घोषणा CC_clang 2
#घोषणा CC_tcc 3

/* Unfortunately, gcc version < 3 does not handle that! */
#घोषणा ALL_ISOC99

/* only gcc 3 handles _Bool correctly */
#घोषणा BOOL_ISOC99

/* __VA_ARGS__ and __func__ support */
#घोषणा C99_MACROS

#अगर defined(_WIN32) \
    || (defined(__arm__) \
        && (defined(__FreeBSD__) \
         || defined(__OpenBSD__) \
         || defined(__NetBSD__) \
         || defined __ANDROID__))
#घोषणा LONG_LONG_FORMAT "%lld"
#घोषणा ULONG_LONG_FORMAT "%llu"
#घोषणा XLONG_LONG_FORMAT "%llx"
#अन्यथा
#घोषणा LONG_LONG_FORMAT "%Ld"
#घोषणा ULONG_LONG_FORMAT "%Lu"
#घोषणा XLONG_LONG_FORMAT "%Lx"
#पूर्ण_अगर

/* MinGW has 80-bit rather than 64-bit long double which isn't
   compatible with printf in msvcrt */
#अगर defined(_WIN32)
#घोषणा LONG_DOUBLE द्विगुन
#घोषणा LONG_DOUBLE_LITERAL(x) x
#अन्यथा
#घोषणा LONG_DOUBLE दीर्घ द्विगुन
#घोषणा LONG_DOUBLE_LITERAL(x) x ## L
#पूर्ण_अगर

प्रकार __SIZE_TYPE__ uintptr_t;

/* test various include syntaxes */

#घोषणा TCCLIB_INC <tcclib.h>
#घोषणा TCCLIB_INC1 <tcclib
#घोषणा TCCLIB_INC2 h>
#घोषणा TCCLIB_INC3 "tcclib.h"

#समावेश TCCLIB_INC

#समावेश TCCLIB_INC1.TCCLIB_INC2

#समावेश TCCLIB_INC1.h>

#समावेश TCCLIB_INC3

#समावेश <tcclib.h>

#समावेश "tcclib.h"

#समावेश "tcctest.h"

/* Test two more ways to include a file named like a pp-number */
#घोषणा INC(name) <tests/name.h>
#घोषणा funnyname 42test.h
#घोषणा incdir tests/
#अगर_घोषित __clang__
/* clang's preprocessor is broken in this regard and adds spaces
   to the tokens 'incdir' and 'funnyname' when expanding */
#घोषणा incname <tests/42test.h>
#अन्यथा
#घोषणा incname < incdir funnyname >
#पूर्ण_अगर
#घोषणा __stringify(x) #x
#घोषणा stringify(x) __stringify(x)
#समावेश INC(42test)
#समावेश incname
#समावेश stringify(funnyname)

पूर्णांक fib(पूर्णांक n);
व्योम अंक(पूर्णांक n);
व्योम forward_ref(व्योम);
पूर्णांक isid(पूर्णांक c);

/* Line joining happens before tokenization, so the following
   must be parsed as ellipsis.  */
व्योम funny_पंक्ति_continuation (पूर्णांक, ..\
. );

#घोषणा A 2
#घोषणा N 1234 + A
#घोषणा pf म_लिखो
#घोषणा M1(a, b)  (a) + (b)

#घोषणा str\
(s) # s
#घोषणा glue(a, b) a ## b
#घोषणा xglue(a, b) glue(a, b)
#घोषणा HIGHLOW "hello"
#घोषणा निचला_2 निचला_2 ", world"

अटल पूर्णांक onetwothree = 123;
#घोषणा onetwothree4 onetwothree
#घोषणा onetwothree xglue(onetwothree,4)

#घोषणा min(a, b) ((a) < (b) ? (a) : (b))

#अगर_घोषित C99_MACROS
#घोषणा dprintf(level,...) म_लिखो(__VA_ARGS__)
#पूर्ण_अगर

/* gcc vararg macros */
#घोषणा dprintf1(level, fmt, args...) म_लिखो(fmt, ## args)

#घोषणा MACRO_NOARGS()

#घोषणा TEST_CALL(f, ...) f(__VA_ARGS__)
#घोषणा TEST_CONST()      123

#घोषणा AAA 3
#अघोषित AAA
#घोषणा AAA 4

#अगर 1
#घोषणा B3 1
#या_अगर 1
#घोषणा B3 2
#या_अगर 0
#घोषणा B3 3
#अन्यथा
#घोषणा B3 4
#पूर्ण_अगर

#घोषणा __INT64_C(c)	c ## LL
#घोषणा INT64_MIN	(-__INT64_C(9223372036854775807)-1)

पूर्णांक qq(पूर्णांक x)
{
    वापस x + 40;
}
#घोषणा qq(x) x

#घोषणा spin_lock(lock) करो { } जबतक (0)
#घोषणा wq_spin_lock spin_lock
#घोषणा TEST2() wq_spin_lock(a)

व्योम macro_test(व्योम)
{
    pf("N=%d\n", N);
    म_लिखो("aaa=%d\n", AAA);

    म_लिखो("min=%d\n", min(1, min(2, -1)));

    म_लिखो("s1=%s\n", glue(ऊपरी_2, निचला_2));
    म_लिखो("s2=%s\n", xglue(ऊपरी_2, निचला_2));
    म_लिखो("s3=%s\n", str("c"));
    म_लिखो("s4=%s\n", str(a1));
    म_लिखो("B3=%d\n", B3);

    म_लिखो("onetwothree=%d\n", onetwothree);

#अगर_घोषित A
    म_लिखो("A defined\n");
#पूर्ण_अगर
#अगर_घोषित B
    म_लिखो("B defined\n");
#पूर्ण_अगर
#अगर_घोषित A
    म_लिखो("A defined\n");
#अन्यथा
    म_लिखो("A not defined\n");
#पूर्ण_अगर
#अगर_घोषित B
    म_लिखो("B defined\n");
#अन्यथा
    म_लिखो("B not defined\n");
#पूर्ण_अगर

#अगर_घोषित A
    म_लिखो("A defined\n");
#अगर_घोषित B
    म_लिखो("B1 defined\n");
#अन्यथा
    म_लिखो("B1 not defined\n");
#पूर्ण_अगर
#अन्यथा
    म_लिखो("A not defined\n");
#अगर_घोषित B
    म_लिखो("B2 defined\n");
#अन्यथा
    म_लिखो("B2 not defined\n");
#पूर्ण_अगर
#पूर्ण_अगर

#अगर 1+1
    म_लिखो("test true1\n");
#पूर्ण_अगर
#अगर 0
    म_लिखो("test true2\n");
#पूर्ण_अगर
#अगर 1-1
    म_लिखो("test true3\n");
#पूर्ण_अगर
#अगर defined(A)
    म_लिखो("test trueA\n");
#पूर्ण_अगर
#अगर defined(B)
    म_लिखो("test trueB\n");
#पूर्ण_अगर

#अगर 0
    म_लिखो("test 0\n");
#या_अगर 0
    म_लिखो("test 1\n");
#या_अगर 2
    म_लिखो("test 2\n");
#अन्यथा
    म_लिखो("test 3\n");
#पूर्ण_अगर

    MACRO_NOARGS();

    म_लिखो("%d\n", TEST_CALL(TEST_CONST));

    /* not strictly preprocessor, but we test it there */
#अगर_घोषित C99_MACROS
    म_लिखो("__func__ = %s\n", __func__);
    dprintf(1, "vaarg=%d\n", 1);
#पूर्ण_अगर
    dprintf1(1, "vaarg1\n");
    dprintf1(1, "vaarg1=%d\n", 2);
    dprintf1(1, "vaarg1=%d %d\n", 1, 2);

    /* gcc extension */
    म_लिखो("func='%s'\n", __FUNCTION__);

    /* complicated macros in glibc */
    म_लिखो("INT64_MIN=" LONG_LONG_FORMAT "\n", INT64_MIN);
    {
        पूर्णांक a;
        a = 1;
        glue(a+, +);
        म_लिखो("a=%d\n", a);
        glue(a <, <= 2);
        म_लिखो("a=%d\n", a);
    }
    
    /* macro function with argument outside the macro string */
#घोषणा MF_s MF_hello
#घोषणा MF_hello(संदेश) म_लिखो("%s\n",संदेश)

#घोषणा MF_t म_लिखो("tralala\n"); MF_hello

    MF_s("hi");
    MF_t("hi");
    
    /* test macro substitution inside args (should not eat stream) */
    म_लिखो("qq=%d\n", qq(qq)(2));

    /* test zero argument case. NOTE: gcc 2.95.x does not accept a
       null argument without a space. gcc 3.2 fixes that. */

#घोषणा qq1(x) 1
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
#अगर !(defined _WIN32 && CC_NAME == CC_clang)
    {
      /* Some compilers (clang) prepend './' to __FILE__ from included
         files.  */
      स्थिर अक्षर *fn = get_file_from_header();
      अगर (fn[0] == '.' && fn[1] == '/')
        fn += 2;
      म_लिखो("filefromheader %s\n", fn);
    }
#पूर्ण_अगर

    म_लिखो("file %s\n", __खाता__);

    /* Check that funnily named include was in fact included */
    have_included_42test_h = 1;
    have_included_42test_h_second = 1;
    have_included_42test_h_third = 1;

    /* Check that we don't complain about stray \ here */
    म_लिखो("print a backslash: %s\n", stringify(\\));
}


अटल व्योम print_अंक(अक्षर *fn, पूर्णांक पंक्ति_2, पूर्णांक अंक) {
    म_लिखो("fn %s, line %d, num %d\n", fn, पंक्ति_2, अंक);
}

व्योम recursive_macro_test(व्योम)
{

#घोषणा ELF32_ST_TYPE(val)              ((val) & 0xf)
#घोषणा ELF32_ST_INFO(bind, type)       (((bind) << 4) + ((type) & 0xf))
#घोषणा STB_WEAK        2               /* Weak symbol */
#घोषणा ELFW(type) ELF##32##_##type
    म_लिखो("%d\n", ELFW(ST_INFO)(STB_WEAK, ELFW(ST_TYPE)(123)));

#घोषणा WRAP(x) x
    
#घोषणा print_अंक(x) print_अंक(__खाता__,__LINE__,x)
    print_अंक(123);
    WRAP(print_अंक(123));
    WRAP(WRAP(print_अंक(123)));

अटल काष्ठा recursive_macro { पूर्णांक rm_field; } G;
#घोषणा rm_field (G.rm_field)
    म_लिखो("rm_field = %d\n", rm_field);
    म_लिखो("rm_field = %d\n", WRAP(rm_field));
    WRAP((म_लिखो("rm_field = %d %d\n", rm_field, WRAP(rm_field))));
}

#अगर __TINYC__
पूर्णांक op(a, b)
{
    वापस a / b;
}

पूर्णांक ret(a)
{
    अगर (a == 2)
        वापस 1;
    अगर (a == 3)
        वापस 2;
    वापस 0;
}
#पूर्ण_अगर

#अगर !defined(__TINYC__) && (__GNUC__ >= 8)
/* Old GCCs don't regard "foo"[1] as constant, even in GNU dialect. */
#घोषणा CONSTANTINDEXEDSTRLIT
#पूर्ण_अगर
अक्षर str_ag1[] = "b";
अक्षर str_ag2[] = { "b" };
/*char str_bg1[] = ("cccc"); GCC accepts this with pedantic warning, TCC not */
#अगर_घोषित CONSTANTINDEXEDSTRLIT
अक्षर str_ag3[] = { "ab"[1], 0 };
अक्षर str_x[2] = { "xy" "z"[2], 0 };
#पूर्ण_अगर
अक्षर *str_ar[] = { "one", "two" };
काष्ठा str_SS {अचिन्हित अक्षर a[3], b; };
काष्ठा str_SS str_sinit15 = { "r" };
काष्ठा str_SS str_sinit16[] = { { "q" }, 2 };

अटल व्योम string_test2()
{
    अक्षर *p = "hello";
    अक्षर a3[2] = { "p" };
    अक्षर a4[2] = { "ab" "c"[2], 0 };
    अक्षर *pa1 = "def" + 1;
    अक्षर *pa2 = { "xyz" + 1 };
    पूर्णांक i = 0;
    काष्ठा str_SS ss = { { [0 ... 1] = 'a' }, 0 };
#अगर_अघोषित CONSTANTINDEXEDSTRLIT
    अक्षर str_ag3[] = { "ab"[1], 0 };
    अक्षर str_x[2] = { "xy" "z"[2], 0 };
#पूर्ण_अगर
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

व्योम ps(स्थिर अक्षर *s)
{
    पूर्णांक c;
    जबतक (1) {
        c = *s;
        अगर (c == 0)
            अवरोध;
        म_लिखो("%c", c);
        s++;
    }
}

स्थिर अक्षर foo1_string[] = "\
bar\n\
test\14\
1";

व्योम string_test()
{
    अचिन्हित पूर्णांक b;
    म_लिखो("string:\n");
    म_लिखो("\141\1423\143\n");/* dezdez test */
    म_लिखो("\x41\x42\x43\x3a\n");
    म_लिखो("c=%c\n", 'r');
    म_लिखो("wc=%C 0x%lx %C\n", L'a', L'\x1234', L'c');
    म_लिखो("foo1_string='%s'\n", foo1_string);
#अगर 0
    म_लिखो("wstring=%S\n", L"abc");
    म_लिखो("wstring=%S\n", L"abc" L"def" "ghi");
    म_लिखो("'\\377'=%d '\\xff'=%d\n", '\377', '\xff');
    म_लिखो("L'\\377'=%d L'\\xff'=%d\n", L'\377', L'\xff');
#पूर्ण_अगर
    ps("test\n");
    b = 32;
    जबतक ((b = b + 1) < 96) {
        म_लिखो("%c", b);
    }
    म_लिखो("\n");
    म_लिखो("fib=%d\n", fib(33));
    b = 262144;
    जबतक (b != 0x80000000) {
        अंक(b);
        b = b * 2;
    }
    string_test2();
}


व्योम if1t(पूर्णांक n, पूर्णांक a, पूर्णांक b, पूर्णांक c)
{
    अगर (a && b) म_लिखो("if1t: %d 1 %d %d\n", n, a, b);
    अगर (a && !b) म_लिखो("if1t: %d 2 %d %d\n", n, a, b);
    अगर (!a && b) म_लिखो("if1t: %d 3 %d %d\n", n, a, b);
    अगर (!a && !b) म_लिखो("if1t: %d 4 %d %d\n", n, a, b);
    अगर (a || b) म_लिखो("if1t: %d 5 %d %d\n", n, a, b);
    अगर (a || !b) म_लिखो("if1t: %d 6 %d %d\n", n, a, b);
    अगर (!a || b) म_लिखो("if1t: %d 7 %d %d\n", n, a, b);
    अगर (!a || !b) म_लिखो("if1t: %d 8 %d %d\n", n, a, b);
    अगर (a && b || c) म_लिखो("if1t: %d 9 %d %d %d\n", n, a, b, c);
    अगर (a || b && c) म_लिखो("if1t: %d 10 %d %d %d\n", n, a, b, c);
    अगर (a > b - 1 && c) म_लिखो("if1t: %d 11 %d %d %d\n", n, a, b, c);
    अगर (a > b - 1 || c) म_लिखो("if1t: %d 12 %d %d %d\n", n, a, b, c);
    अगर (a > 0 && 1) म_लिखो("if1t: %d 13 %d %d %d\n", n, a, b, c);
    अगर (a > 0 || 0) म_लिखो("if1t: %d 14 %d %d %d\n", n, a, b, c);
}

व्योम if2t(व्योम)
{
    अगर (0 && 1 || म_लिखो("if2t:ok\n") || 1)
      म_लिखो("if2t:ok2\n");
    म_लिखो("if2t:ok3\n");
}

व्योम if3t(व्योम)
{
    अस्थिर दीर्घ दीर्घ i = 1;
    अगर (i <= 18446744073709551615ULL)
      ;
    अन्यथा
      म_लिखो ("if3t:wrong 1\n");
}

व्योम if_test(व्योम)
{
    if1t(1, 0, 0, 0);
    if1t(2, 0, 3, 0);
    if1t(3, 2, 0, 0);
    if1t(4, 2, 3, 0);
    if2t();
    if3t();
}

व्योम loop_test()
{
    पूर्णांक i;
    i = 0;
    जबतक (i < 10)
        म_लिखो("%d", i++);
    म_लिखो("\n");
    क्रम(i = 0; i < 10;i++)
        म_लिखो("%d", i);
    म_लिखो("\n");
    i = 0;
    करो {
        म_लिखो("%d", i++);
    } जबतक (i < 10);
    म_लिखो("\n");

    अक्षर गिनती_2 = 123;
    /* c99 for loop init test */
    क्रम (माप_प्रकार गिनती_2 = 1; गिनती_2 < 3; गिनती_2++)
        म_लिखो("count=%d\n", गिनती_2);
    म_लिखो("count = %d\n", गिनती_2);

    /* break/continue tests */
    i = 0;
    जबतक (1) {
        अगर (i == 6)
            अवरोध;
        i++;
        अगर (i == 3)
            जारी;
        म_लिखो("%d", i);
    }
    म_लिखो("\n");

    /* break/continue tests */
    i = 0;
    करो {
        अगर (i == 6)
            अवरोध;
        i++;
        अगर (i == 3)
            जारी;
        म_लिखो("%d", i);
    } जबतक(1);
    म_लिखो("\n");

    क्रम(i = 0;i < 10;i++) {
        अगर (i == 3)
            जारी;
        म_लिखो("%d", i);
    }
    म_लिखो("\n");
}

प्रकार पूर्णांक typedef_and_label;

व्योम goto_test()
{
    पूर्णांक i;
    अटल व्योम *label_table[3] = { &&label1, &&label2, &&label3 };
    काष्ठा {
        पूर्णांक bla;
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
    अगर (i >= 10) 
        जाओ s_end;
    म_लिखो("%d", i);
    i++;
    जाओ s_loop;
 s_end:
    म_लिखो("\n");

    /* we also test computed gotos (GCC extension) */
    क्रम(i=0;i<3;i++) {
        जाओ *label_table[i];
    label1:
        म_लिखो("label1\n");
        जाओ अग्र;
    label2:
        म_लिखो("label2\n");
        जाओ अग्र;
    label3:
        म_लिखो("label3\n");
    अग्र: ;
    }
}

क्रमागत {
    E0,
    E1 = 2,
    E2 = 4,
    E3,
    E4,
};

क्रमागत test {
    E5 = 1000,
};

काष्ठा S_enum {
    क्रमागत {E6 = 42, E7, E8} e:8;
};

क्रमागत ELong {
    /* This is either 0 on L32 machines, or a large number
       on L64 machines.  We should be able to store this.  */
    EL_large = ((अचिन्हित दीर्घ)0xf000 << 31) << 1,
};

क्रमागत { BIASU = -1U<<31 };
क्रमागत { BIASS = -1 << 31 };

अटल पूर्णांक getint(पूर्णांक i)
{
  अगर (i)
    वापस 0;
  अन्यथा
    वापस (पूर्णांक)(-1U << 31);
}

व्योम enum_test()
{
    क्रमागत test b1;
    /* The following should give no warning */
    अचिन्हित *p = &b1;
    काष्ठा S_enum s = {E7};
    म_लिखो("%d %d %d %d %d %d %d\n", s.e,
           E0, E1, E2, E3, E4, E5);
    b1 = 1;
    म_लिखो("b1=%d\n", b1);
    म_लिखो("enum large: %ld\n", EL_large);

    अगर (getint(0) == BIASU)
      म_लिखो("enum unsigned: ok\n");
    अन्यथा
      म_लिखो("enum unsigned: wrong\n");
    अगर (getint(0) == BIASS)
      म_लिखो("enum unsigned: ok\n");
    अन्यथा
      म_लिखो("enum unsigned: wrong\n");
}

प्रकार पूर्णांक *my_ptr;

प्रकार पूर्णांक mytype1;
प्रकार पूर्णांक mytype2;

व्योम typedef_test()
{
    my_ptr a;
    mytype1 mytype2;
    पूर्णांक b;

    a = &b;
    *a = 1234;
    म_लिखो("a=%d\n", *a);
    mytype2 = 2;
    म_लिखो("mytype2=%d\n", mytype2);
}

व्योम forward_test()
{
    forward_ref();
    forward_ref();
}


व्योम forward_ref(व्योम)
{
    म_लिखो("forward ok\n");
}

प्रकार काष्ठा struct1 {
    पूर्णांक f1;
    पूर्णांक f2, f3;
    जोड़ union1 {
        पूर्णांक v1;
        पूर्णांक v2;
    } u;
    अक्षर str[3];
} struct1;

काष्ठा struct2 {
    पूर्णांक a;
    अक्षर b;
};

जोड़ union2 {
    पूर्णांक w1;
    पूर्णांक w2;
};

काष्ठा struct1 st1, st2;

काष्ठा empty_mem {
    /* nothing */ ;
    पूर्णांक x;
};

पूर्णांक tab[3];
पूर्णांक tab2[3][2];

पूर्णांक g;

व्योम f1(पूर्णांक g)
{
    म_लिखो("g1=%d\n", g);
}

व्योम scope_test()
{
    g = 2;
    f1(1);
    म_लिखो("g2=%d\n", g);
    {
        पूर्णांक g;
        g = 3;
        म_लिखो("g3=%d\n", g);
        {
            पूर्णांक g;
            g = 4;
            म_लिखो("g4=%d\n", g);
        }
    }
    म_लिखो("g5=%d\n", g);
}

पूर्णांक st2_i;
पूर्णांक *st2_p = &st2_i;
व्योम scope2_test()
{
    अक्षर a[50];
    st2_i = 42;
    क्रम (पूर्णांक st2_i = 1; st2_i < 10; st2_i++) {
        बाह्य पूर्णांक st2_i;
        st2_i++;
        म_लिखो("exloc: %d\n", st2_i);
    }
    म_लिखो("exloc: %d\n", *st2_p);
}

/* C has tentative definition, and they may be repeated.  */
बाह्य पूर्णांक st_global1;
पूर्णांक st_global1=42;
बाह्य पूर्णांक st_global1;
पूर्णांक st_global1;
बाह्य पूर्णांक st_global2;
पूर्णांक st_global2;
बाह्य पूर्णांक st_global2;
पूर्णांक st_global2;

व्योम array_test()
{
    पूर्णांक i, j, a[4];

    म_लिखो("sizeof(a) = %d\n", माप(a));
    म_लिखो("sizeof(\"a\") = %d\n", माप("a"));
#अगर_घोषित C99_MACROS
    म_लिखो("sizeof(__func__) = %d\n", माप(__func__));
#पूर्ण_अगर
    म_लिखो("sizeof tab %d\n", माप(tab));
    म_लिखो("sizeof tab2 %d\n", माप tab2);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    म_लिखो("%d %d %d\n", tab[0], tab[1], tab[2]);
    क्रम(i=0;i<3;i++)
        क्रम(j=0;j<2;j++)
            tab2[i][j] = 10 * i + j;
    क्रम(i=0;i<3*2;i++) {
        म_लिखो(" %3d", ((पूर्णांक *)tab2)[i]);
    }
    म_लिखो("\n");
    म_लिखो("sizeof(size_t)=%d\n", माप(माप_प्रकार));
    म_लिखो("sizeof(ptrdiff_t)=%d\n", माप(सूचक_भेद_प्रकार));
}

व्योम व्यंजक_test()
{
    पूर्णांक a, b;
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

पूर्णांक isid(पूर्णांक c)
{
    वापस (c >= 'a' & c <= 'z') | (c >= 'A' & c <= 'Z') | c == '_';
}

/**********************/

पूर्णांक vstack[10], *vstack_ptr;

व्योम vpush(पूर्णांक vt, पूर्णांक vc)
{
    *vstack_ptr++ = vt;
    *vstack_ptr++ = vc;
}

व्योम vpop(पूर्णांक *ft, पूर्णांक *fc)
{
    *fc = *--vstack_ptr;
    *ft = *--vstack_ptr;
}

व्योम expr2_test()
{
    पूर्णांक a, b;

    vstack_ptr = vstack;
    vpush(1432432, 2);
    vstack_ptr[-2] &= ~0xffffff80;
    vpop(&a, &b);
    म_लिखो("res= %d %d\n", a, b);
}

पूर्णांक const_len_ar[माप(1/0)]; /* div-by-zero, but in unevaluated context */

व्योम constant_व्यंजक_test()
{
    पूर्णांक a;
    a = 3;
    म_लिखो("%d\n", a * 16);
    म_लिखो("%d\n", a * 1);
    म_लिखो("%d\n", a + 0);
    म_लिखो("%d\n", माप(const_len_ar));
}

पूर्णांक tab4[10];

व्योम व्यंजक_ptr_test()
{
    पूर्णांक arr[10], *p, *q;
    पूर्णांक i = -1;

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
    p = (पूर्णांक *)((अक्षर *)p + 0xf0000000);
    म_लिखो("%p %p %ld\n", q, p, p-q);
    म_लिखो("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    p += 0xf0000000;
    म_लिखो("%p %p %ld\n", q, p, p-q);
    म_लिखो("%d %d %d %d %d %d\n",
           p == q, p != q, p < q, p <= q, p >= q, p > q);
    {
        काष्ठा size12 {
            पूर्णांक i, j, k;
        };
        काष्ठा size12 s[2], *sp = s;
        पूर्णांक i, j;
        sp->i = 42;
        sp++;
        j = -1;
        म_लिखो("%d\n", sp[j].i);
    }
#अगर_घोषित __LP64__
    i = 1;
    p = (पूर्णांक*)0x100000000UL + i;
    i = ((दीर्घ)p) >> 32;
    म_लिखो("largeptr: %p %d\n", p, i);
#पूर्ण_अगर
    p = &arr[0];
    q = p + 3;
    म_लिखो ("%d\n", (पूर्णांक)((p - q) / 3));
}

व्योम व्यंजक_cmp_test()
{
    पूर्णांक a, b;
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

काष्ठा empty {
};

काष्ठा aligntest1 {
    अक्षर a[10];
};

काष्ठा aligntest2 {
    पूर्णांक a;
    अक्षर b[10];
};

काष्ठा aligntest3 {
    द्विगुन a, b;
};

काष्ठा aligntest4 {
    द्विगुन a[0];
};

काष्ठा __attribute__((aligned(16))) aligntest5
{
    पूर्णांक i;
};
काष्ठा aligntest6
{
    पूर्णांक i;
} __attribute__((aligned(16)));
काष्ठा aligntest7
{
    पूर्णांक i;
};
काष्ठा aligntest5 altest5[2];
काष्ठा aligntest6 altest6[2];
पूर्णांक pad1;
/* altest7 is correctly aligned to 16 bytes also with TCC,
   but __alignof__ returns the wrong result (4) because we
   can't store the alignment yet when specified on symbols
   directly (it's stored in the type so we'd need to make
   a copy of it). -- FIXED */
काष्ठा aligntest7 altest7[2] __attribute__((aligned(16)));

काष्ठा aligntest8
{
  पूर्णांक i;
} __attribute__((aligned(4096)));

काष्ठा Large {
    अचिन्हित दीर्घ flags;
    जोड़ {
	व्योम *u1;
	पूर्णांक *u2;
    };

    काष्ठा {
	जोड़ {
	    अचिन्हित दीर्घ सूचकांक;
	    व्योम *freelist;
	};
	जोड़ {
	    अचिन्हित दीर्घ counters;
	    काष्ठा {
		पूर्णांक bla;
	    };
	};
    };

    जोड़ {
	काष्ठा {
	    दीर्घ u3;
	    दीर्घ u4;
	};
	व्योम *u5;
	काष्ठा {
	    अचिन्हित दीर्घ compound_शीर्ष;
	    अचिन्हित पूर्णांक compound_dtor;
	    अचिन्हित पूर्णांक compound_order;
	};
    };
} __attribute__((aligned(2 * माप(दीर्घ))));

प्रकार अचिन्हित दीर्घ दीर्घ __attribute__((aligned(4))) unaligned_u64;

काष्ठा aligntest9 {
    अचिन्हित पूर्णांक buf_nr;
    unaligned_u64 start_lba;
};

काष्ठा aligntest10 {
    अचिन्हित पूर्णांक buf_nr;
    अचिन्हित दीर्घ दीर्घ start_lba;
};

व्योम struct_test()
{
    struct1 *s;
    जोड़ union2 u;
    काष्ठा Large ls;

    म_लिखो("sizes: %d %d %d %d\n",
           माप(काष्ठा struct1),
           माप(काष्ठा struct2),
           माप(जोड़ union1),
           माप(जोड़ union2));
    म_लिखो("offsets: %d\n", (पूर्णांक)((अक्षर*)&st1.u.v1 - (अक्षर*)&st1));
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
    म_लिखो("str_addr=%x\n", (पूर्णांक)(uintptr_t)st1.str - (पूर्णांक)(uintptr_t)&st1.f1);

    /* align / size tests */
    म_लिखो("aligntest1 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest1), __alignof__(काष्ठा aligntest1));
    म_लिखो("aligntest2 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest2), __alignof__(काष्ठा aligntest2));
    म_लिखो("aligntest3 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest3), __alignof__(काष्ठा aligntest3));
#अगर !(defined _WIN32 && CC_NAME == CC_clang)
    म_लिखो("aligntest4 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest4), __alignof__(काष्ठा aligntest4));
#पूर्ण_अगर
    म_लिखो("aligntest5 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest5), __alignof__(काष्ठा aligntest5));
    म_लिखो("aligntest6 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest6), __alignof__(काष्ठा aligntest6));
    म_लिखो("aligntest7 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest7), __alignof__(काष्ठा aligntest7));
    म_लिखो("aligntest8 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest8), __alignof__(काष्ठा aligntest8));
#अगर !(defined _WIN32 && CC_NAME == CC_clang)
    म_लिखो("aligntest9 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest9), __alignof__(काष्ठा aligntest9));
#पूर्ण_अगर
    म_लिखो("aligntest10 sizeof=%d alignof=%d\n",
           माप(काष्ठा aligntest10), __alignof__(काष्ठा aligntest10));
    म_लिखो("altest5 sizeof=%d alignof=%d\n",
           माप(altest5), __alignof__(altest5));
    म_लिखो("altest6 sizeof=%d alignof=%d\n",
           माप(altest6), __alignof__(altest6));
    म_लिखो("altest7 sizeof=%d alignof=%d\n",
           माप(altest7), __alignof__(altest7));
           
    /* empty structures (GCC extension) */
#अगर !(defined _WIN32 && CC_NAME == CC_clang)
    म_लिखो("sizeof(struct empty) = %d\n", माप(काष्ठा empty));
#पूर्ण_अगर
    म_लिखो("alignof(struct empty) = %d\n", __alignof__(काष्ठा empty));

    म_लिखो("Large: sizeof=%d\n", माप(ls));
    स_रखो(&ls, 0, माप(ls));
    ls.compound_शीर्ष = 42;
    म_लिखो("Large: offsetof(compound_head)=%d\n", (पूर्णांक)((अक्षर*)&ls.compound_शीर्ष - (अक्षर*)&ls));
}

/* simulate char/short return value with undefined upper bits */
अटल पूर्णांक __csf(पूर्णांक x) { वापस x; }
अटल व्योम *_csf = __csf;
#घोषणा csf(t,n) ((t(*)(पूर्णांक))_csf)(n)

/* XXX: depend on endianness */
व्योम char_short_test()
{
    पूर्णांक var1, var2;
    चिन्हित अक्षर var3;
    दीर्घ दीर्घ var4;

    var1 = 0x01020304;
    var2 = 0xfffefdfc;
    म_लिखो("s8=%d %d\n", 
           *(चिन्हित अक्षर *)&var1, *(चिन्हित अक्षर *)&var2);
    म_लिखो("u8=%d %d\n", 
           *(अचिन्हित अक्षर *)&var1, *(अचिन्हित अक्षर *)&var2);
    म_लिखो("s16=%d %d\n", 
           *(लघु *)&var1, *(लघु *)&var2);
    म_लिखो("u16=%d %d\n", 
           *(अचिन्हित लघु *)&var1, *(अचिन्हित लघु *)&var2);
    म_लिखो("s32=%d %d\n", 
           *(पूर्णांक *)&var1, *(पूर्णांक *)&var2);
    म_लिखो("u32=%d %d\n", 
           *(अचिन्हित पूर्णांक *)&var1, *(अचिन्हित पूर्णांक *)&var2);
    *(चिन्हित अक्षर *)&var1 = 0x08;
    म_लिखो("var1=%x\n", var1);
    *(लघु *)&var1 = 0x0809;
    म_लिखो("var1=%x\n", var1);
    *(पूर्णांक *)&var1 = 0x08090a0b;
    म_लिखो("var1=%x\n", var1);

    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    var1 = var3 = var1 + 1;
    var4 = var3 = var4 + 1;
    म_लिखो("promote char/short assign %d "LONG_LONG_FORMAT"\n", var1, var4);
    var1 = 0x778899aa;
    var4 = 0x11223344aa998877ULL;
    म_लिखो("promote char/short assign VA %d %d\n", var3 = var1 + 1, var3 = var4 + 1);
    म_लिखो("promote char/short cast VA %d %d\n", (चिन्हित अक्षर)(var1 + 1), (चिन्हित अक्षर)(var4 + 1));
#अगर !defined __arm__ && !defined __riscv
    /* We can't really express GCC behaviour of return type promotion in
       the presence of undefined behaviour (like __csf is).  */
    var1 = csf(अचिन्हित अक्षर,0x89898989);
    var4 = csf(चिन्हित अक्षर,0xabababab);
#अगर_घोषित __clang__
    /* on macos 15 arm64 this prints -1987475063 instead of 137 */
    var1 &= 0xff;
#पूर्ण_अगर
    म_लिखो("promote char/short funcret %d "LONG_LONG_FORMAT"\n", var1, var4);
    म_लिखो("promote char/short fumcret VA %d %d %d %d\n",
        csf(अचिन्हित लघु,0xcdcdcdcd),
        csf(लघु,0xefefefef),
        csf(_Bool,0x33221100),
        csf(_Bool,0x33221101));
#पूर्ण_अगर
    var3 = -10;
    var1 = (चिन्हित अक्षर)(अचिन्हित अक्षर)(var3 + 1);
    var4 = (चिन्हित अक्षर)(अचिन्हित अक्षर)(var3 + 1);
    म_लिखो("promote multicast (char)(unsigned char) %d "LONG_LONG_FORMAT"\n", var1, var4);
    var4 = 0x11223344aa998877ULL;
    var4 = (अचिन्हित)(पूर्णांक)(var4 + 1);
    म_लिखो("promote multicast (unsigned)(int) "LONG_LONG_FORMAT"\n", var4);
    var4 = 0x11223344bbaa9988ULL;
    var4 = (अचिन्हित)(चिन्हित अक्षर)(var4 + 1);
    म_लिखो("promote multicast (unsigned)(char) "LONG_LONG_FORMAT"\n", var4);
}

/******************/

प्रकार काष्ठा Sym {
    पूर्णांक v;
    पूर्णांक t;
    पूर्णांक c;
    काष्ठा Sym *अग्र;
    काष्ठा Sym *पूर्व;
} Sym;

#घोषणा ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#घोषणा TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

अटल पूर्णांक toupper1(पूर्णांक a)
{
    वापस TOUPPER(a);
}

अटल अचिन्हित पूर्णांक calc_vm_flags(अचिन्हित पूर्णांक prot)
{
  अचिन्हित पूर्णांक prot_bits;
  /* This used to segfault in some revisions: */
  prot_bits = ((0x1==0x00000001)?(prot&0x1):(prot&0x1)?0x00000001:0);
  वापस prot_bits;
}

क्रमागत cast_enum { FIRST, LAST };

अटल व्योम tst_cast(क्रमागत cast_enum ce)
{
    म_लिखो("%d\n", ce);
}

व्योम bool_test()
{
    पूर्णांक *s, a, b, t, f, i;

    a = 0;
    s = (व्योम*)0;
    म_लिखो("!s=%d\n", !s);

    अगर (!s || !s[0])
        a = 1;
    म_लिखो("a=%d\n", a);

    म_लिखो("a=%d %d %d\n", 0 || 0, 0 || 1, 1 || 1);
    म_लिखो("a=%d %d %d\n", 0 && 0, 0 && 1, 1 && 1);
    म_लिखो("a=%d %d\n", 1 ? 1 : 0, 0 ? 1 : 0);
#अगर 1 && 1
    म_लिखो("a1\n");
#पूर्ण_अगर
#अगर 1 || 0
    म_लिखो("a2\n");
#पूर्ण_अगर
#अगर 1 ? 0 : 1
    म_लिखो("a3\n");
#पूर्ण_अगर
#अगर 0 ? 0 : 1
    म_लिखो("a4\n");
#पूर्ण_अगर

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
    म_लिखो("type of bool: %d\n", (पूर्णांक) ( (~ ((अचिन्हित पूर्णांक) (t && 1))) / 2) );
    tst_cast(t >= 0 ? FIRST : LAST);

    म_लिखो("type of cond: %d\n", (~(t ? 0U : (अचिन्हित पूर्णांक)0)) / 2 );
    /* test ? : cast */
    {
        पूर्णांक aspect_on;
        पूर्णांक aspect_native = 65536;
        द्विगुन bfu_aspect = 1.0;
        पूर्णांक aspect;
        क्रम(aspect_on = 0; aspect_on < 2; aspect_on++) {
            aspect=aspect_on?(aspect_native*bfu_aspect+0.5):65535UL;
            म_लिखो("aspect=%d\n", aspect);
        }
    }

    /* test ? : GCC extension */
    {
        अटल पूर्णांक v1 = 34 ? : -1; /* constant case */
        अटल पूर्णांक v2 = 0 ? : -1; /* constant case */
        पूर्णांक a = 30;
        
        म_लिखो("%d %d\n", v1, v2);
        म_लिखो("%d %d\n", a - 30 ? : a * 2, a + 1 ? : a * 2);
    }

    /* again complex expression */
    क्रम(i=0;i<256;i++) {
        अगर (toupper1 (i) != TOUPPER (i))
            म_लिखो("error %d\n", i);
    }
    म_लिखो ("bits = 0x%x\n", calc_vm_flags (0x1));
}

बाह्य पूर्णांक undefined_function(व्योम);
बाह्य पूर्णांक defined_function(व्योम);

#अगर_घोषित __clang__
पूर्णांक undefined_function(व्योम) {}
#पूर्ण_अगर

अटल अंतरभूत व्योम refer_to_undefined(व्योम)
{
  undefined_function();
}

व्योम optimize_out_test(व्योम)
{
  पूर्णांक i = 0 ? undefined_function() : defined_function();
  म_लिखो ("oo:%d\n", i);
  पूर्णांक j = 1 ? defined_function() : undefined_function();
  म_लिखो ("oo:%d\n", j);
  अगर (0)
    म_लिखो("oo:%d\n", undefined_function());
  अन्यथा
    म_लिखो("oo:%d\n", defined_function());
  अगर (1)
    म_लिखो("oo:%d\n", defined_function());
  अन्यथा
    म_लिखो("oo:%d\n", undefined_function());
  जबतक (1) {
      म_लिखो("oow:%d\n", defined_function());
      अवरोध;
      म_लिखो("oow:%d\n", undefined_function());
  }
  j = 1;
  /* Following is a switch without {} block intentionally.  */
  चयन (j)
    हाल 1: अवरोध;
  म_लिखो ("oos:%d\n", defined_function());
  /* The following break shouldn't lead to disabled code after
     the while.  */
  जबतक (1)
    अवरोध;
  म_लिखो ("ool1:%d\n", defined_function());
  /* Same for the other types of loops.  */
  करो
    अवरोध;
  जबतक (1);
  म_लिखो ("ool2:%d\n", defined_function());
  क्रम (;;)
    अवरोध;
  म_लिखो ("ool3:%d\n", defined_function());
  /* Normal {} blocks without controlling statements
     shouldn't reactivate code emission */
  जबतक (1) {
	{
	  अवरोध;
	}
      म_लिखो ("ool4:%d\n", undefined_function());
  }
  j = 1;
  जबतक (j) {
      अगर (j == 0)
	अवरोध; /* this break shouldn't disable code outside the if. */
      म_लिखो("ool5:%d\n", defined_function());
      j--;
  }

  j = 1;
  जबतक (j) {
      अगर (1)
	j--;
      अन्यथा
	breakhere: अवरोध;
      म_लिखो("ool6:%d\n", defined_function());
      जाओ breakhere;
  }
  j = 1;
  जबतक (j) {
      j--;
      जारी;
      म_लिखो("ool7:%d\n", undefined_function());
  }

  /* Test that constants in logical && are optimized: */
  i = 0 && undefined_function();
  i = defined_function() && 0 && undefined_function();
  अगर (0 && undefined_function())
    undefined_function();
  अगर (defined_function() && 0)
    undefined_function();
  अगर (0 && 0)
    undefined_function();
  अगर (defined_function() && 0 && undefined_function())
    undefined_function();
  /* The same for || : */
  i = 1 || undefined_function();
  i = defined_function() || 1 || undefined_function();
  अगर (1 || undefined_function())
    ;
  अन्यथा
    undefined_function();
  अगर (defined_function() || 1)
    ;
  अन्यथा
    undefined_function();
  अगर (1 || 1)
    ;
  अन्यथा
    undefined_function();
  अगर (defined_function() || 1 || undefined_function())
    ;
  अन्यथा
    undefined_function();

  अगर (defined_function() && 0)
    refer_to_undefined();

  अगर (0) {
      (व्योम)माप( ({
		     करो { } जबतक (0);
		     0;
		     }) );
      undefined_function();
  }

  अगर (0) {
      चयन (defined_function()) {
          हाल 0: undefined_function(); अवरोध;
          शेष: undefined_function(); अवरोध;
      }
  }

  /* Leave the "if(1)return; printf()" in this order and last in the function */
  अगर (1)
    वापस;
  म_लिखो ("oor:%d\n", undefined_function());
}

पूर्णांक defined_function(व्योम)
{
  अटल पूर्णांक i = 40;
  वापस i++;
}

/* GCC accepts that */
अटल पूर्णांक tab_reinit[];
अटल पूर्णांक tab_reinit[10];

अटल पूर्णांक tentative_ar[];
अटल पूर्णांक tentative_ar[] = {1,2,3};

पूर्णांक cinit1; /* a global variable can be defined several times without error ! */
पूर्णांक cinit1; 
पूर्णांक cinit1 = 0;
पूर्णांक *cinit2 = (पूर्णांक []){3, 2, 1};
uintptr_t cinit3 = (uintptr_t)"AA";
अक्षर स्थिर * स्थिर cinit8[] = { [0 ... 1] = "BB", [2 ... 4] = "CC" };
व्योम *cinit52 = &(व्योम*){ (व्योम*) 52 };

#अगर __TINYC__ || __GNUC__ >= 6
पूर्णांक cinit4 = (पूर्णांक){44};
व्योम *cinit51 = (व्योम*){ (व्योम*) 51 };
काष्ठा _c6 { पूर्णांक a,b; } cinit6 = (काष्ठा _c6){61,62}, *cinit7 = &(काष्ठा _c6){71,72};
#अन्यथा
पूर्णांक cinit4 = 44;
व्योम *cinit51 = (व्योम*)51;
काष्ठा _c6 { पूर्णांक a,b; } cinit6 = { 61,62 }, cinit70 = {71,72}, *cinit7 = &cinit70;
#पूर्ण_अगर

व्योम compound_literal_test(व्योम)
{
    पूर्णांक *p, i;
    अक्षर *q, *q3;

    म_लिखो("cinit3 : %s\n", cinit3);
    म_लिखो("cinit4 : %d\n", cinit4);
    म_लिखो("cinit51 : %d\n", (पूर्णांक)cinit51);
    म_लिखो("cinit52 : %d\n", *(पूर्णांक*)cinit52);
    म_लिखो("cinit6 : %d %d\n", cinit6.a, cinit6.b);
    म_लिखो("cinit7 : %d %d\n", cinit7->a, cinit7->b);
    म_लिखो("cinit8 : %s %s %s %s %s\n", cinit8[0], cinit8[1], cinit8[2], cinit8[3], cinit8[4]);

    p = (पूर्णांक []){1, 2, 3};
    क्रम(i=0;i<3;i++)
        म_लिखो(" %d", p[i]);
    म_लिखो("\n");

    क्रम(i=0;i<3;i++)
        म_लिखो("%d", cinit2[i]);
    म_लिखो("\n");

    q = "tralala1";
    म_लिखो("q1=%s\n", q);

    q = (अक्षर *){ "tralala2" };
    म_लिखो("q2=%s\n", q);

    q3 = (अक्षर *){ q };
    म_लिखो("q3=%s\n", q3);

    q = (अक्षर []){ "tralala3" };
    म_लिखो("q4=%s\n", q);

#अगर_घोषित ALL_ISOC99
    p = (पूर्णांक []){1, 2, cinit1 + 3};
    क्रम(i=0;i<3;i++)
        म_लिखो(" %d", p[i]);
    म_लिखो("\n");

    क्रम(i=0;i<3;i++) {
        p = (पूर्णांक []){1, 2, 4 + i};
        म_लिखो("%d %d %d\n", 
               p[0],
               p[1],
               p[2]);
    }
#पूर्ण_अगर
}


#अगर __TINYC__

/* K & R protos */

kr_func1(a, b)
{
    वापस a + b;
}

पूर्णांक kr_func2(a, b)
{
    वापस a + b;
}

kr_test()
{
    म_लिखो("func1=%d\n", kr_func1(3, 4));
    म_लिखो("func2=%d\n", kr_func2(3, 4));
    वापस 0;
}

/* We try to handle this syntax.  Make at least sure it doesn't segfault.  */
अक्षर invalid_function_def()[] {वापस 0;}

#अन्यथा
# define kr_test() म_लिखो("func1=7\nfunc2=7\n")
#पूर्ण_अगर

व्योम अंक(पूर्णांक n)
{
    अक्षर *tab, *p;
    tab = (अक्षर*)दो_स्मृति(20); 
    p = tab;
    जबतक (1) {
        *p = 48 + (n % 10);
        p++;
        n = n / 10;
        अगर (n == 0)
            अवरोध;
    }
    जबतक (p != tab) {
        p--;
        म_लिखो("%c", *p);
    }
    म_लिखो("\n");
    मुक्त(tab);
}

/* structure assignment tests */
काष्ठा structa1 {
    पूर्णांक f1;
    अक्षर f2;
};

व्योम struct_assign_test1(काष्ठा structa1 s1, पूर्णांक t, भग्न f)
{
    म_लिखो("%d %d %d %f\n", s1.f1, s1.f2, t, f);
}

काष्ठा structa1 struct_assign_test2(काष्ठा structa1 s1, पूर्णांक t)
{
    s1.f1 += t;
    s1.f2 -= t;
    वापस s1;
}

व्योम struct_assign_test(व्योम)
{
    काष्ठा S {
      काष्ठा structa1 lsta1, lsta2;
      पूर्णांक i;
    } s = {{1,2}, {3,4}}, *ps;
    
    ps = &s;
    ps->i = 4;

    struct_assign_test1(ps->lsta2, 3, 4.5);
    म_लिखो("before call: %d %d\n", s.lsta2.f1, s.lsta2.f2);
    ps->lsta2 = struct_assign_test2(ps->lsta2, ps->i);
    म_लिखो("after call: %d %d\n", ps->lsta2.f1, ps->lsta2.f2);

    अटल काष्ठा {
        व्योम (*elem)();
    } t[] = {
        /* XXX: we should allow this even without braces */
        { struct_assign_test }
    };
    म_लिखो("%d\n", struct_assign_test == t[0].elem);

    s.lsta1 = s.lsta2 = struct_assign_test2(s.lsta1, 1);
    म_लिखो("%d %d\n", s.lsta1.f1, s.lsta1.f2);
}

/* casts to short/char */

व्योम cast1(अक्षर a, लघु b, अचिन्हित अक्षर c, अचिन्हित लघु d)
{
    म_लिखो("%d %d %d %d\n", a, b, c, d);
}

अक्षर bcast;
लघु scast;

व्योम cast_test()
{
    पूर्णांक a;
    अक्षर c;
    अक्षर tab[10];
    अचिन्हित b,d;
    लघु s;
    अक्षर *p = शून्य;
    अचिन्हित दीर्घ ul = 0x80000000UL;
    p -= 0x700000000042;

    a = 0xfffff;
    cast1(a, a, a, a);
    a = 0xffffe;
    म_लिखो("%d %d %d %d\n",
           (अक्षर)(a + 1),
           (लघु)(a + 1),
           (अचिन्हित अक्षर)(a + 1),
           (अचिन्हित लघु)(a + 1));
    म_लिखो("%d %d %d %d\n",
           (अक्षर)0xfffff,
           (लघु)0xfffff,
           (अचिन्हित अक्षर)0xfffff,
           (अचिन्हित लघु)0xfffff);

    a = (bcast = 128) + 1;
    म_लिखो("%d\n", a);
    a = (scast = 65536) + 1;
    म_लिखो("%d\n", a);
    
    म_लिखो("sizeof(c) = %d, sizeof((int)c) = %d\n", माप(c), माप((पूर्णांक)c));
    
    /* test cast from unsigned to signed short to int */
    b = 0xf000;
    d = (लघु)b;
    म_लिखो("((unsigned)(short)0x%08x) = 0x%08x\n", b, d);
    b = 0xf0f0;
    d = (अक्षर)b;
    म_लिखो("((unsigned)(char)0x%08x) = 0x%08x\n", b, d);
    
    /* test implicit int casting for array accesses */
    c = 0;
    tab[1] = 2;
    tab[c] = 1;
    म_लिखो("%d %d\n", tab[0], tab[1]);

    /* test implicit casting on some operators */
    म_लिखो("sizeof(+(char)'a') = %d\n", माप(+(अक्षर)'a'));
    म_लिखो("sizeof(-(char)'a') = %d\n", माप(-(अक्षर)'a'));
    म_लिखो("sizeof(~(char)'a') = %d\n", माप(-(अक्षर)'a'));

#अगर CC_NAME != CC_clang /* clang doesn't support non-portable conversions */
    /* from pointer to integer types */
    म_लिखो("%d %d %ld %ld %lld %lld\n",
           (पूर्णांक)p, (अचिन्हित पूर्णांक)p,
           (दीर्घ)p, (अचिन्हित दीर्घ)p,
           (दीर्घ दीर्घ)p, (अचिन्हित दीर्घ दीर्घ)p);
#पूर्ण_अगर

    /* from integers to pointers */
    म_लिखो("%p %p %p %p\n",
           (व्योम *)a, (व्योम *)b, (व्योम *)c, (व्योम *)d);

    /* int to int with sign set */
    म_लिखो("0x%lx\n", (अचिन्हित दीर्घ)(पूर्णांक)ul);
}

/* initializers tests */
काष्ठा structinit1 {
    पूर्णांक f1;
    अक्षर f2;
    लघु f3;
    पूर्णांक farray[3];
};

पूर्णांक sinit1 = 2;
पूर्णांक sinit2 = { 3 };
पूर्णांक sinit3[3] = { 1, 2, {3}, };
पूर्णांक sinit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
पूर्णांक sinit5[3][2] = { 1, 2, 3, 4, 5, 6 };
पूर्णांक sinit6[] = { 1, 2, 3 };
पूर्णांक sinit7[] = { [2] = 3, [0] = 1, 2 };
अक्षर sinit8[] = "hello" "trala";

काष्ठा structinit1 sinit9 = { 1, 2, 3 };
काष्ठा structinit1 sinit10 = { .f2 = 2, 3, .f1 = 1 };
काष्ठा structinit1 sinit11 = { .f2 = 2, 3, .f1 = 1, 
#अगर_घोषित ALL_ISOC99
                               .farray[0] = 10,
                               .farray[1] = 11,
                               .farray[2] = 12,
#पूर्ण_अगर
};

अक्षर *sinit12 = "hello world";
अक्षर *sinit13[] = {
    "test1",
    "test2",
    "test3",
};
अक्षर sinit14[10] = { "abc" };
पूर्णांक sinit15[3] = { माप(sinit15), 1, 2 };

काष्ठा { पूर्णांक a[3], b; } sinit16[] = { { 1 }, 2 };

काष्ठा bar {
        अक्षर *s;
        पूर्णांक len;
} sinit17[] = {
        "a1", 4,
        "a2", 1
};

पूर्णांक sinit18[10] = {
    [2 ... 5] = 20,
    2,
    [8] = 10,
};

काष्ठा complexinit0 {
    पूर्णांक a;
    पूर्णांक b;
};

काष्ठा complexinit {
    पूर्णांक a;
    स्थिर काष्ठा complexinit0 *b;
};

स्थिर अटल काष्ठा complexinit cix[] = {
    [0] = {
	.a = 2000,
	.b = (स्थिर काष्ठा complexinit0[]) {
		{ 2001, 2002 },
		{ 2003, 2003 },
		{}
	}
    }
};

काष्ठा complexinit2 {
	पूर्णांक a;
	पूर्णांक b[];
};

काष्ठा complexinit2 cix20;

काष्ठा complexinit2 cix21 = {
	.a = 3000,
	.b = { 3001, 3002, 3003 }
};

काष्ठा complexinit2 cix22 = {
	.a = 4000,
	.b = { 4001, 4002, 4003, 4004, 4005, 4006 }
};

प्रकार पूर्णांक arrtype1[];
arrtype1 sinit19;
arrtype1 sinit20;
arrtype1 sinit19 = {1};
arrtype1 sinit20 = {2,3};
प्रकार पूर्णांक arrtype2[3];
arrtype2 sinit21;
arrtype2 sinit22;
arrtype2 sinit21 = {4};
arrtype2 sinit22 = {5,6,7};

/* Address comparisons of non-weak symbols with zero can be const-folded */
पूर्णांक sinit23[2] = { "astring" ? माप("astring") : -1,
		   &sinit23 ? 42 : -1 };

पूर्णांक sinit24 = 2 || 1 / 0; /* exception in constant but unevaluated context */

/* bitfield init */
काष्ठा bf_SS {अचिन्हित पूर्णांक bit:1,bits31:31; };
काष्ठा bf_SS bf_init = { .bit = 1 };
काष्ठा bfn_SS {पूर्णांक a,b; काष्ठा bf_SS c; पूर्णांक d,e; };
काष्ठा bfn_SS bfn_init = { .c.bit = 1 };
काष्ठा bfa_SS {पूर्णांक a,b; काष्ठा bf_SS c[3]; पूर्णांक d,e; };
काष्ठा bfa_SS bfa_init = { .c[1].bit = 1 };
काष्ठा bf_SS bfaa_init[3] = { [1].bit = 1 };
काष्ठा bf_SS bfaa_vinit[] = { [2].bit = 1 };
काष्ठा b2_SS {दीर्घ दीर्घ पूर्णांक field : 52; दीर्घ दीर्घ पूर्णांक pad : 12; };
काष्ठा b2_SS bf_init2 = {0xFFF000FFF000FLL, 0x123};

बाह्य पूर्णांक external_inited = 42;

व्योम init_test(व्योम)
{
    पूर्णांक linit1 = 2;
    पूर्णांक linit2 = { 3 };
    पूर्णांक linit4[3][2] = { {1, 2}, {3, 4}, {5, 6} };
    पूर्णांक linit6[] = { 1, 2, 3 };
    पूर्णांक i, j;
    अक्षर linit8[] = "hello" "trala";
    पूर्णांक linit12[10] = { 1, 2 };
    पूर्णांक linit13[10] = { 1, 2, [7] = 3, [3] = 4, };
    अक्षर linit14[10] = "abc";
    पूर्णांक linit15[10] = { linit1, linit1 + 1, [6] = linit1 + 2, };
    काष्ठा linit16 { पूर्णांक a1, a2, a3, a4; } linit16 = { 1, .a3 = 2 };
    पूर्णांक linit17 = माप(linit17);
    पूर्णांक zero = 0;
    /* Addresses on non-weak symbols are non-zero, but not the access itself */
    पूर्णांक linit18[2] = {&zero ? 1 : -1, zero ? -1 : 1 };
    काष्ठा bf_SS bf_finit = { .bit = 1 };
    काष्ठा bfn_SS bfn_finit = { .c.bit = 1 };
    काष्ठा bfa_SS bfa_finit = { .c[1].bit = 1 };
    काष्ठा bf_SS bfaa_finit[3] = { [1].bit = 1 };
    काष्ठा bf_SS bfaa_fvinit[] = { [2].bit = 1 };
    काष्ठा b2_SS bf_finit2 = {0xFFF000FFF000FLL, 0x123};
    
    म_लिखो("sinit1=%d\n", sinit1);
    म_लिखो("sinit2=%d\n", sinit2);
    म_लिखो("sinit3=%d %d %d %d\n", 
           माप(sinit3),
           sinit3[0],
           sinit3[1],
           sinit3[2]
           );
    म_लिखो("sinit6=%d\n", माप(sinit6));
    म_लिखो("sinit7=%d %d %d %d\n", 
           माप(sinit7),
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

    क्रम(i=0;i<3;i++)
        क्रम(j=0;j<2;j++)
            म_लिखो("[%d][%d] = %d %d %d\n", 
                   i, j, sinit4[i][j], sinit5[i][j], linit4[i][j]);
    म_लिखो("linit1=%d\n", linit1);
    म_लिखो("linit2=%d\n", linit2);
    म_लिखो("linit6=%d\n", माप(linit6));
    म_लिखो("linit8=%d %s\n", माप(linit8), linit8);

    म_लिखो("sinit12=%s\n", sinit12);
    म_लिखो("sinit13=%d %s %s %s\n",
           माप(sinit13), 
           sinit13[0],
           sinit13[1],
           sinit13[2]);
    म_लिखो("sinit14=%s\n", sinit14);

    क्रम(i=0;i<10;i++) म_लिखो(" %d", linit12[i]);
    म_लिखो("\n");
    क्रम(i=0;i<10;i++) म_लिखो(" %d", linit13[i]);
    म_लिखो("\n");
    क्रम(i=0;i<10;i++) म_लिखो(" %d", linit14[i]);
    म_लिखो("\n");
    क्रम(i=0;i<10;i++) म_लिखो(" %d", linit15[i]);
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
    क्रम(i=0;i<10;i++)
        म_लिखो("%x ", sinit18[i]);
    म_लिखो("\n");
    /* complex init check */
    म_लिखो("cix: %d %d %d %d %d %d %d\n",
	cix[0].a,
	cix[0].b[0].a, cix[0].b[0].b,
	cix[0].b[1].a, cix[0].b[1].b,
	cix[0].b[2].a, cix[0].b[2].b);
    म_लिखो("cix2: %d %d\n", cix21.b[2], cix22.b[5]);
    म_लिखो("sizeof cix20 %d, cix21 %d, sizeof cix22 %d\n", माप cix20, माप cix21, माप cix22);

    म_लिखो("arrtype1: %d %d %d\n", sinit19[0], sinit20[0], sinit20[1]);
    म_लिखो("arrtype2: %d %d\n", माप(sinit19), माप(sinit20));
    म_लिखो("arrtype3: %d %d %d\n", sinit21[0], sinit21[1], sinit21[2]);
    म_लिखो("arrtype4: %d %d %d\n", sinit22[0], sinit22[1], sinit22[2]);
    म_लिखो("arrtype5: %d %d\n", माप(sinit21), माप(sinit22));
    म_लिखो("arrtype6: %d\n", माप(arrtype2));

    म_लिखो("sinit23= %d %d\n", sinit23[0], sinit23[1]);
    म_लिखो("sinit24=%d\n", sinit24);
    म_लिखो("linit18= %d %d\n", linit18[0], linit18[1]);
    म_लिखो ("bf1: %u %u\n", bf_init.bit, bf_init.bits31);
    म_लिखो ("bf2: %u %u\n", bf_finit.bit, bf_finit.bits31);
    म_लिखो ("bf3: %u %u\n", bfn_init.c.bit, bfn_init.c.bits31);
    म_लिखो ("bf4: %u %u\n", bfn_finit.c.bit, bfn_finit.c.bits31);
    क्रम (i = 0; i < 3; i++)
        म_लिखो ("bf5[%d]: %u %u\n", i, bfa_init.c[i].bit, bfa_init.c[i].bits31);
    क्रम (i = 0; i < 3; i++)
        म_लिखो ("bf6[%d]: %u %u\n", i, bfa_finit.c[i].bit, bfa_finit.c[i].bits31);
    क्रम (i = 0; i < 3; i++)
        म_लिखो ("bf7[%d]: %u %u\n", i, bfaa_init[i].bit, bfaa_init[i].bits31);
    क्रम (i = 0; i < 3; i++)
        म_लिखो ("bf8[%d]: %u %u\n", i, bfaa_finit[i].bit, bfaa_finit[i].bits31);
    क्रम (i = 0; i < 3; i++)
        म_लिखो ("bf9[%d]: %u %u\n", i, bfaa_vinit[i].bit, bfaa_vinit[i].bits31);
    क्रम (i = 0; i < 3; i++)
        म_लिखो ("bf10[%d]: %u %u\n", i, bfaa_fvinit[i].bit, bfaa_fvinit[i].bits31);
}

व्योम switch_uc(अचिन्हित अक्षर uc)
{
	चयन (uc) {
	    हाल 0xfb ... 0xfe:
		म_लिखो("ucsw:1\n");
		अवरोध;
	    हाल 0xff:
		म_लिखो("ucsw:2\n");
		अवरोध;
	    हाल 0 ... 5:
		म_लिखो("ucsw:3\n");
		अवरोध;
	    शेष:
		म_लिखो("ucsw: broken!\n");
	}
}

व्योम switch_sc(चिन्हित अक्षर sc)
{
	चयन (sc) {
	    हाल -5 ... -2:
		म_लिखो("scsw:1\n");
		अवरोध;
	    हाल -1:
		म_लिखो("scsw:2\n");
		अवरोध;
	    हाल 0 ... 5:
		म_लिखो("scsw:3\n");
		अवरोध;
	    शेष:
		म_लिखो("scsw: broken!\n");
	}
}

व्योम switch_test()
{
    पूर्णांक i;
    अचिन्हित दीर्घ दीर्घ ull;
    दीर्घ दीर्घ ll;

    क्रम(i=0;i<15;i++) {
        चयन(i) {
        हाल 0:
        हाल 1:
            म_लिखो("a");
            अवरोध;
        शेष:
            म_लिखो("%d", i);
            अवरोध;
        हाल 8 ... 12:
            म_लिखो("c");
            अवरोध;
        हाल 3:
            म_लिखो("b");
            अवरोध;
        हाल 0xc33c6b9fU:
        हाल 0x7c9eeeb9U:
            अवरोध;
        }
    }
    म_लिखो("\n");

    क्रम (i = 1; i <= 5; i++) {
	ull = (अचिन्हित दीर्घ दीर्घ)i << 61;
	चयन (ull) {
	    हाल 1ULL << 61:
		म_लिखो("ullsw:1\n");
		अवरोध;
	    हाल 2ULL << 61:
		म_लिखो("ullsw:2\n");
		अवरोध;
	    हाल 3ULL << 61:
		म_लिखो("ullsw:3\n");
		अवरोध;
	    हाल 4ULL << 61:
		म_लिखो("ullsw:4\n");
		अवरोध;
	    हाल 5ULL << 61:
		म_लिखो("ullsw:5\n");
		अवरोध;
	    शेष:
		म_लिखो("ullsw: broken!\n");
	}
    }

    क्रम (i = 1; i <= 5; i++) {
	ll = (दीर्घ दीर्घ)i << 61;
	चयन (ll) {
	    हाल 1LL << 61:
		म_लिखो("llsw:1\n");
		अवरोध;
	    हाल 2LL << 61:
		म_लिखो("llsw:2\n");
		अवरोध;
	    हाल 3LL << 61:
		म_लिखो("llsw:3\n");
		अवरोध;
	    हाल 4LL << 61:
		म_लिखो("llsw:4\n");
		अवरोध;
	    हाल 5LL << 61:
		म_लिखो("llsw:5\n");
		अवरोध;
	    शेष:
		म_लिखो("llsw: broken!\n");
	}
    }

    क्रम (i = -5; i <= 5; i++) {
	switch_uc((अचिन्हित अक्षर)i);
    }

    क्रम (i = -5; i <= 5; i++) {
	switch_sc ((चिन्हित अक्षर)i);
    }
}

/* ISOC99 _Bool type */
व्योम c99_bool_test(व्योम)
{
#अगर_घोषित BOOL_ISOC99
    पूर्णांक a;
    _Bool b, b2;

    म_लिखो("sizeof(_Bool) = %d\n", माप(_Bool));
    a = 3;
    म_लिखो("cast: %d %d %d\n", (_Bool)10, (_Bool)0, (_Bool)a);
    b = 3;
    म_लिखो("b = %d\n", b);
    b++;
    म_लिखो("b = %d\n", b);
    b2 = 0;
    म_लिखो("sizeof(x ? _Bool : _Bool) = %d (should be sizeof int)\n",
           माप ((अस्थिर पूर्णांक)a ? b : b2));
#पूर्ण_अगर
}

व्योम bitfield_test(व्योम)
{
    पूर्णांक a;
    लघु sa;
    अचिन्हित अक्षर ca;
    काष्ठा sbf1 {
        पूर्णांक f1 : 3;
        पूर्णांक : 2;
        पूर्णांक f2 : 1;
        पूर्णांक : 0;
        पूर्णांक f3 : 5;
        पूर्णांक f4 : 7;
        अचिन्हित पूर्णांक f5 : 7;
    } st1;
    म_लिखो("sizeof(st1) = %d\n", माप(st1));

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
    अगर (st1.f1 == -1) 
        म_लिखो("st1.f1 == -1\n");
    अन्यथा 
        म_लिखो("st1.f1 != -1\n");
    अगर (st1.f2 == -1) 
        म_लिखो("st1.f2 == -1\n");
    अन्यथा 
        म_लिखो("st1.f2 != -1\n");

    काष्ठा sbf2 {
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

#अगर 0
    Disabled क्रम now until further clarification re GCC compatibility
    काष्ठा sbf3 {
        पूर्णांक f1 : 7;
        पूर्णांक f2 : 1;
        अक्षर f3;
        पूर्णांक f4 : 8;
        पूर्णांक f5 : 1;
        पूर्णांक f6 : 16;
    } st3;
    म_लिखो("sizeof(st3) = %d\n", माप(st3));
#पूर्ण_अगर

    काष्ठा sbf4 {
	पूर्णांक x : 31;
	अक्षर y : 2;
    } st4;
    st4.y = 1;
    म_लिखो("st4.y == %d\n", st4.y);
    काष्ठा sbf5 {
	पूर्णांक a;
	अक्षर b;
	पूर्णांक x : 12, y : 4, : 0, : 4, z : 3;
	अक्षर c;
    } st5 = { 1, 2, 3, 4, -3, 6 };
    म_लिखो("st5 = %d %d %d %d %d %d\n", st5.a, st5.b, st5.x, st5.y, st5.z, st5.c);
    काष्ठा sbf6 {
	लघु x : 12;
	अचिन्हित अक्षर y : 2;
    } st6;
    st6.y = 1;
    म_लिखो("st6.y == %d\n", st6.y);
}

#अगर_घोषित __x86_64__
#घोषणा FLOAT_FMT "%f\n"
#अन्यथा
/* x86's float isn't compatible with GCC */
#घोषणा FLOAT_FMT "%.5f\n"
#पूर्ण_अगर

/* declare strto* functions as they are C99 */
द्विगुन म_से_भग्न(स्थिर अक्षर *nptr, अक्षर **endptr);

#अगर defined(_WIN32)
भग्न strtof(स्थिर अक्षर *nptr, अक्षर **endptr) {वापस (भग्न)म_से_भग्न(nptr, endptr);}
LONG_DOUBLE strtold(स्थिर अक्षर *nptr, अक्षर **endptr) {वापस (LONG_DOUBLE)म_से_भग्न(nptr, endptr);}
#अन्यथा
भग्न strtof(स्थिर अक्षर *nptr, अक्षर **endptr);
LONG_DOUBLE strtold(स्थिर अक्षर *nptr, अक्षर **endptr);
#पूर्ण_अगर

#घोषणा FTEST(prefix, typename, type, fmt)\
व्योम prefix ## cmp(type a, type b)\
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
व्योम prefix ## fcast(type a)\
{\
    भग्न fa;\
    द्विगुन da;\
    LONG_DOUBLE la;\
    पूर्णांक ia;\
    दीर्घ दीर्घ llia;\
    अचिन्हित पूर्णांक ua;\
    अचिन्हित दीर्घ दीर्घ llua;\
    type b;\
    fa = a;\
    da = a;\
    la = a;\
    म_लिखो("ftof: %f %f %Lf\n", fa, da, la);\
    ia = (पूर्णांक)a;\
    llia = (दीर्घ दीर्घ)a;\
    a = (a >= 0) ? a : -a;\
    ua = (अचिन्हित पूर्णांक)a;\
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
    अगर (CC_NAME != CC_clang) म_लिखो("ulltof: " fmt "\n", b);\
}\
\
भग्न prefix ## retf(type a) { वापस a; }\
द्विगुन prefix ## retd(type a) { वापस a; }\
LONG_DOUBLE prefix ## retld(type a) { वापस a; }\
\
व्योम prefix ## call(व्योम)\
{\
    म_लिखो("float: " FLOAT_FMT, prefix ## retf(42.123456789));\
    म_लिखो("double: %f\n", prefix ## retd(42.123456789));\
    म_लिखो("long double: %Lf\n", prefix ## retld(42.123456789));\
    म_लिखो("strto%s: %f\n", #prefix, (द्विगुन)strto ## prefix("1.2", शून्य));\
}\
\
व्योम prefix ## signed_zeros(व्योम) \
{\
  type x = 0.0, y = -0.0, n, p;\
  अगर (x == y)\
    म_लिखो ("Test 1.0 / x != 1.0 / y  returns %d (should be 1).\n",\
            1.0 / x != 1.0 / y);\
  अन्यथा\
    म_लिखो ("x != y; this is wrong!\n");\
\
  n = -x;\
  अगर (x == n)\
    म_लिखो ("Test 1.0 / x != 1.0 / -x returns %d (should be 1).\n",\
            1.0 / x != 1.0 / n);\
  अन्यथा\
    म_लिखो ("x != -x; this is wrong!\n");\
\
  p = +y;\
  अगर (x == p)\
    म_लिखो ("Test 1.0 / x != 1.0 / +y returns %d (should be 1).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    म_लिखो ("x != +y; this is wrong!\n");\
  p = -y;\
  अगर (x == p)\
    म_लिखो ("Test 1.0 / x != 1.0 / -y returns %d (should be 0).\n",\
            1.0 / x != 1.0 / p);\
  अन्यथा\
    म_लिखो ("x != -y; this is wrong!\n");\
}\
व्योम prefix ## nan(व्योम)\
{\
    type nan = 0.0/0.0;\
    type nnan = -nan; \
    म_लिखो("nantest: " fmt " " fmt "\n", nan, nnan);\
}\
व्योम prefix ## test(व्योम)\
{\
    म_लिखो("testing '%s'\n", #typename);\
    prefix ## cmp(1, 2.5);\
    prefix ## cmp(2, 1.5);\
    prefix ## cmp(1, 1);\
    prefix ## fcast(234.6);\
    prefix ## fcast(-2334.6);\
    prefix ## call();\
    prefix ## signed_zeros();\
    अगर (CC_NAME != CC_clang) prefix ## nan();\
}

FTEST(f, भग्न, भग्न, "%f")
FTEST(d, द्विगुन, द्विगुन, "%f")
FTEST(ld, दीर्घ द्विगुन, LONG_DOUBLE, "%Lf")

द्विगुन ftab1[3] = { 1.2, 3.4, -5.6 };


व्योम float_test(व्योम)
{
#अगर !defined(__arm__) || defined(__ARM_PCS_VFP) || defined __ANDROID__
    अस्थिर भग्न fa, fb;
    अस्थिर द्विगुन da, db;
    पूर्णांक a;
    अचिन्हित पूर्णांक b;
    अटल द्विगुन nan2 = 0.0/0.0;
    अटल द्विगुन inf1 = 1.0/0.0;
    अटल द्विगुन inf2 = 1e5000;
    अस्थिर LONG_DOUBLE la;

    म_लिखो("sizeof(float) = %d\n", माप(भग्न));
    म_लिखो("sizeof(double) = %d\n", माप(द्विगुन));
    म_लिखो("sizeof(long double) = %d\n", माप(LONG_DOUBLE));
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
#पूर्ण_अगर
}

पूर्णांक fib(पूर्णांक n)
{
    अगर (n <= 2)
        वापस 1;
    अन्यथा
        वापस fib(n-1) + fib(n-2);
}

#अगर __GNUC__ == 3 || __GNUC__ == 4
# define aligned_function 0
#अन्यथा
व्योम __attribute__((aligned(16))) aligned_function(पूर्णांक i) {}
#पूर्ण_अगर

व्योम funcptr_test()
{
    व्योम (*func)(पूर्णांक);
    पूर्णांक a;
    काष्ठा {
        पूर्णांक dummy;
        व्योम (*func)(पूर्णांक);
    } st1;
    दीर्घ diff;

    func = &अंक;
    (*func)(12345);
    func = अंक;
    a = 1;
    a = 1;
    func(12345);
    /* more complicated pointer computation */
    st1.func = अंक;
    st1.func(12346);
    म_लिखो("sizeof1 = %d\n", माप(funcptr_test));
    म_लिखो("sizeof2 = %d\n", माप funcptr_test);
    म_लिखो("sizeof3 = %d\n", माप(&funcptr_test));
    म_लिखो("sizeof4 = %d\n", माप &funcptr_test);
    a = 0;
    func = अंक + a;
    diff = func - अंक;
    func(42);
    (func + diff)(42);
    (अंक + a)(43);

    /* Check that we can align functions */
    func = aligned_function;
    म_लिखो("aligned_function (should be zero): %d\n", ((पूर्णांक)(uintptr_t)func) & 15);
}

व्योम lloptest(दीर्घ दीर्घ a, दीर्घ दीर्घ b)
{
    अचिन्हित दीर्घ दीर्घ ua, ub;

    ua = a;
    ub = b;
    /* arith */
    म_लिखो("arith: " LONG_LONG_FORMAT " " LONG_LONG_FORMAT " " LONG_LONG_FORMAT "\n",
           a + b,
           a - b,
           a * b);
    
    अगर (b != 0) {
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

व्योम llshift(दीर्घ दीर्घ a, पूर्णांक b)
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

व्योम llfloat(व्योम)
{
    भग्न fa;
    द्विगुन da;
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

दीर्घ दीर्घ llfunc1(पूर्णांक a)
{
    वापस a * 2;
}

काष्ठा S {
    पूर्णांक id; 
    अक्षर item;
};

दीर्घ दीर्घ पूर्णांक मूल्य(काष्ठा S *v)
{
    वापस ((दीर्घ दीर्घ पूर्णांक)v->item);
}

दीर्घ दीर्घ llfunc2(दीर्घ दीर्घ x, दीर्घ दीर्घ y, पूर्णांक z)
{
    वापस x * y * z;
}

व्योम check_opl_save_regs(अक्षर *a, दीर्घ दीर्घ b, पूर्णांक c)
{
    *a = b < 0 && !c;
}

व्योम longlong_test(व्योम)
{
    दीर्घ दीर्घ a, b, c;
    पूर्णांक ia;
    अचिन्हित पूर्णांक ua;
    म_लिखो("sizeof(long long) = %d\n", माप(दीर्घ दीर्घ));
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
#अगर 1
    b = 0x12345678;
    a = -1;
    c = a + b;
    म_लिखो(XLONG_LONG_FORMAT"\n", c);
#पूर्ण_अगर

    /* long long reg spill test */
    {
          काष्ठा S a;

          a.item = 3;
          म_लिखो("%lld\n", मूल्य(&a));
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
    u = (अचिन्हित)(पूर्णांक)(u + 1);
    म_लिखो("long long u=" ULONG_LONG_FORMAT "\n", u);

    /* was a problem with missing save_regs in gen_opl on 32-bit platforms */
    अक्षर cc = 78;
    check_opl_save_regs(&cc, -1, 0);
    म_लिखो("check_opl_save_regs: %d\n", cc);
}

व्योम manyarg_test(व्योम)
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

व्योम*
va_arg_with_struct_ptr(बहु_सूची ap) {
        /*
         * This was a BUG identified with FFTW-3.3.8 on arm64.
         * The test case only checks it compiles on all supported
         * architectures. This function is not currently called.
         */
        काष्ठा X { पूर्णांक _x; };
        काष्ठा X *x = बहु_तर्क(ap, काष्ठा X *);
        वापस x;
}

व्योम vprintf1(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची ap, aq;
    स्थिर अक्षर *p;
    पूर्णांक c, i;
    द्विगुन d;
    दीर्घ दीर्घ ll;
    LONG_DOUBLE ld;

    बहु_शुरू(aq, fmt);
    va_copy(ap, aq);
    
    p = fmt;
    क्रम(;;) {
        c = *p;
        अगर (c == '\0')
            अवरोध;
        p++;
        अगर (c == '%') {
            c = *p;
            चयन(c) {
            हाल '\0':
                जाओ the_end;
            हाल 'd':
                i = बहु_तर्क(ap, पूर्णांक);
                म_लिखो("%d", i);
                अवरोध;
            हाल 'f':
                d = बहु_तर्क(ap, द्विगुन);
                म_लिखो("%f", d);
                अवरोध;
            हाल 'l':
                ll = बहु_तर्क(ap, दीर्घ दीर्घ);
                म_लिखो(LONG_LONG_FORMAT, ll);
                अवरोध;
            हाल 'F':
                ld = बहु_तर्क(ap, LONG_DOUBLE);
                म_लिखो("%Lf", ld);
                अवरोध;
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

काष्ठा myspace {
    लघु पूर्णांक profile;
};
काष्ठा myspace2 {
#अगर CC_NAME == CC_clang /* clang7 doesn't support zero sized structs */
    अक्षर a[1];
#अन्यथा
    अक्षर a[0];
#पूर्ण_अगर
};
काष्ठा myspace3 {
    अक्षर a[1];
};
काष्ठा myspace4 {
    अक्षर a[2];
};
काष्ठा mytest {
    व्योम *foo, *bar, *baz;
};

काष्ठा mytest stdarg_for_struct(काष्ठा myspace bob, ...)
{
    काष्ठा myspace george, bill;
    काष्ठा myspace2 alex1;
    काष्ठा myspace3 alex2;
    काष्ठा myspace4 alex3;
    बहु_सूची ap;
    लघु पूर्णांक validate;

    बहु_शुरू(ap, bob);
    alex1    = बहु_तर्क(ap, काष्ठा myspace2);
    alex2    = बहु_तर्क(ap, काष्ठा myspace3);
    alex3    = बहु_तर्क(ap, काष्ठा myspace4);
    bill     = बहु_तर्क(ap, काष्ठा myspace);
    george   = बहु_तर्क(ap, काष्ठा myspace);
    validate = बहु_तर्क(ap, पूर्णांक);
    म_लिखो("stdarg_for_struct: %d %d %d %d %d %d %d\n",
           alex2.a[0], alex3.a[0], alex3.a[1],
           bob.profile, bill.profile, george.profile, validate);
    बहु_पूर्ण(ap);
    वापस (काष्ठा mytest) {};
}

व्योम stdarg_for_libc(स्थिर अक्षर *fmt, ...)
{
    बहु_सूची args;
    बहु_शुरू(args, fmt);
    भ_लिखो(fmt, args);
    बहु_पूर्ण(args);
}

व्योम stdarg_syntax(पूर्णांक n, ...)
{
    पूर्णांक i;
    बहु_सूची ap;
    अगर (1)
      बहु_शुरू(ap, n);
    अन्यथा
      ;
    i = बहु_तर्क(ap, पूर्णांक);
    म_लिखो("stdarg_void_expr: %d\n", i);
    (बहु_पूर्ण(ap));
}

प्रकार काष्ठा{
    द्विगुन x,y;
} point;
point pts[]={{1.0,2.0},{3.0,4.0},{5.0,6.0},{7.0,8.0},{9.0,10.0},{11.0,12.0}};

अटल व्योम stdarg_double_struct(पूर्णांक nargs, पूर्णांक posd,...)
{
    पूर्णांक i;
    द्विगुन d;
    point pi;
    बहु_सूची args;

    म_लिखो ("stdarg_double_struct: %d\n", posd);
    बहु_शुरू(args,posd);
    क्रम(i = 0; i < nargs; i++) {
        अगर (i == posd) {
            d = बहु_तर्क (args, द्विगुन);
            म_लिखो ("d %d = %g\n", i, d);
        }
        अन्यथा {
            pi = बहु_तर्क (args, point);
            म_लिखो ("pts[%d] = %g %g\n", i, pi.x, pi.y);
        }
    }
    बहु_पूर्ण(args);
}

व्योम stdarg_test(व्योम)
{
    LONG_DOUBLE ld = 1234567891234LL;
    काष्ठा myspace bob;
    काष्ठा myspace2 bob2;
    काष्ठा myspace3 bob3;
    काष्ठा myspace4 bob4;

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
#अगर !(defined _WIN32 && CC_NAME == CC_clang) /* broken clang */
    stdarg_double_struct(6,-1,pts[0],pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,1,pts[0],-1.0,pts[1],pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,2,pts[0],pts[1],-1.0,pts[2],pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,3,pts[0],pts[1],pts[2],-1.0,pts[3],pts[4],pts[5]);
    stdarg_double_struct(7,4,pts[0],pts[1],pts[2],pts[3],-1.0,pts[4],pts[5]);
    stdarg_double_struct(7,5,pts[0],pts[1],pts[2],pts[3],pts[4],-1.0,pts[5]);
#पूर्ण_अगर
}

पूर्णांक reltab[3] = { 1, 2, 3 };

पूर्णांक *rel1 = &reltab[1];
पूर्णांक *rel2 = &reltab[2];

व्योम getmyaddress(व्योम)
{
    म_लिखो("in getmyaddress\n");
}

#अगर_घोषित __LP64__
दीर्घ __pa_symbol(व्योम)
{
    /* This 64bit constant was handled incorrectly, it was used as addend
       (which can hold 64bit just fine) in connection with a symbol,
       and TCC generates wrong code for that (displacements are 32bit only).
       This effectively is "+ 0x80000000", and if addresses of globals
       are below 2GB the result should be a number without high 32 bits set.  */
       वापस ((दीर्घ)(((अचिन्हित दीर्घ)(&rel1))) - (0xffffffff80000000UL));
}
#पूर्ण_अगर

uintptr_t theaddress = (uintptr_t)getmyaddress;
व्योम relocation_test(व्योम)
{
    व्योम (*fptr)(व्योम) = (व्योम (*)(व्योम))theaddress;
    म_लिखो("*rel1=%d\n", *rel1);
    म_लिखो("*rel2=%d\n", *rel2);
    fptr();
#अगर_घोषित __LP64__
    // compare 'addend' displacement versus conventional arithmetics
    म_लिखो("pa_symbol: %d\n", (दीर्घ)&rel1 == __pa_symbol() - 0x80000000);
#पूर्ण_अगर
}

व्योम old_style_f(a,b,c)
     पूर्णांक a, b;
     द्विगुन c;
{
    म_लिखो("a=%d b=%d b=%f\n", a, b, c);
}

व्योम decl_func1(पूर्णांक cmpfn())
{
    म_लिखो("cmpfn=%lx\n", (दीर्घ)cmpfn);
}

व्योम decl_func2(cmpfn)
पूर्णांक cmpfn();
{
    म_लिखो("cmpfn=%lx\n", (दीर्घ)cmpfn);
}

व्योम old_style_function_test(व्योम)
{
#अगर CC_NAME == CC_clang
    /* recent clang versions (at least 15.0) raise an error:
       incompatible pointer to integer conversion passing 'void *'
       For the purpose of this test, pass 1 instead.
     */
    old_style_f(1, 2, 3.0);
#अन्यथा
    old_style_f((व्योम *)1, 2, 3.0);
#पूर्ण_अगर
    decl_func1(शून्य);
    decl_func2(शून्य);
}

व्योम alloca_test()
{
    अक्षर *p = alloca(16);
    म_नकल(p,"123456789012345");
    म_लिखो("alloca: p is %s\n", p);
    अक्षर *demo = "This is only a test.\n";
    /* Test alloca embedded in a larger expression */
    म_लिखो("alloca: %s\n", म_नकल(alloca(म_माप(demo)+1),demo) );
}

व्योम *bounds_checking_is_enabled()
{
    अक्षर ca[10], *cp = ca-1;
    वापस (ca != cp + 1) ? cp : शून्य;
}

प्रकार पूर्णांक constant_negative_array_आकार_as_compile_time_assertion_idiom[(1 ? 2 : 0) - 1];

व्योम c99_vla_test_1(पूर्णांक size1, पूर्णांक size2)
{
    पूर्णांक आकार = size1 * size2;
    पूर्णांक tab1[आकार][2], tab2[10][2];
    व्योम *tab1_ptr, *tab2_ptr, *bad_ptr;

    /* "size" should have been 'captured' at tab1 declaration, 
        so modifying it should have no effect on VLA behaviour. */
    आकार = आकार-1;
    
    म_लिखो("Test C99 VLA 1 (sizeof): ");
    म_लिखो("%s\n", (माप tab1 == size1 * size2 * 2 * माप(पूर्णांक)) ? "PASSED" : "FAILED");
    tab1_ptr = tab1;
    tab2_ptr = tab2;
    म_लिखो("Test C99 VLA 2 (ptrs subtract): ");
    म_लिखो("%s\n", (tab2 - tab1 == (tab2_ptr - tab1_ptr) / (माप(पूर्णांक) * 2)) ? "PASSED" : "FAILED");
    म_लिखो("Test C99 VLA 3 (ptr add): ");
    म_लिखो("%s\n", &tab1[5][1] == (tab1_ptr + (5 * 2 + 1) * माप(पूर्णांक)) ? "PASSED" : "FAILED");
    म_लिखो("Test C99 VLA 4 (ptr access): ");
    tab1[size1][1] = 42;
    म_लिखो("%s\n", (*((पूर्णांक *) (tab1_ptr + (size1 * 2 + 1) * माप(पूर्णांक))) == 42) ? "PASSED" : "FAILED");

    म_लिखो("Test C99 VLA 5 (bounds checking (might be disabled)): ");
    अगर (bad_ptr = bounds_checking_is_enabled()) {
        पूर्णांक *t1 = &tab1[size1 * size2 - 1][3];
        पूर्णांक *t2 = &tab2[9][3];
        म_लिखो("%s ", bad_ptr == t1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == t2 ? "PASSED" : "FAILED");

        अक्षर*c1 = 1 + माप(tab1) + (अक्षर*)tab1;
        अक्षर*c2 = 1 + माप(tab2) + (अक्षर*)tab2;
        म_लिखो("%s ", bad_ptr == c1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == c2 ? "PASSED" : "FAILED");

        पूर्णांक *i1 = tab1[-1];
        पूर्णांक *i2 = tab2[-1];
        म_लिखो("%s ", bad_ptr == i1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == i2 ? "PASSED" : "FAILED");

        पूर्णांक *x1 = tab1[size1 * size2 + 1];
        पूर्णांक *x2 = tab2[10 + 1];
        म_लिखो("%s ", bad_ptr == x1 ? "PASSED" : "FAILED");
        म_लिखो("%s ", bad_ptr == x2 ? "PASSED" : "FAILED");
    } अन्यथा {
        म_लिखो("PASSED PASSED PASSED PASSED PASSED PASSED PASSED PASSED ");
    }
    म_लिखो("\n");
}

व्योम c99_vla_test_2(पूर्णांक d, पूर्णांक h, पूर्णांक w)
{
    पूर्णांक x, y, z;
    पूर्णांक (*arr)[h][w] = दो_स्मृति(माप(पूर्णांक) * d*h*w);
    पूर्णांक c = 1;
    अटल पूर्णांक (*starr)[h][w];

    म_लिखो("Test C99 VLA 6 (pointer)\n");

    क्रम (z=0; z<d; z++) {
        क्रम (y=0; y<h; y++) {
            क्रम (x=0; x<w; x++) {
                arr[z][y][x] = c++;
            }
        }
    }
    क्रम (z=0; z<d; z++) {
        क्रम (y=0; y<h; y++) {
            क्रम (x=0; x<w; x++) {
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
        माप (*arr), माप (*arr)[0], माप (*arr)[0][0],
        arr + 2 - arr, *arr + 3 - *arr,
        0 == माप (*arr + 1) - माप arr,
        0 == माप माप *arr - माप arr,
        starr[0][2][3] == arr[1][2][3]
        );
    मुक्त (arr);
}

व्योम c99_vla_test_3a (पूर्णांक arr[2][3][4])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

व्योम c99_vla_test_3b(पूर्णांक s, पूर्णांक arr[s][3][4])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

व्योम c99_vla_test_3c(पूर्णांक s, पूर्णांक arr[2][s][4])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

व्योम c99_vla_test_3d(पूर्णांक s, पूर्णांक arr[2][3][s])
{
    म_लिखो ("%d\n", arr[1][2][3]);
}

व्योम c99_vla_test_3e(पूर्णांक s, पूर्णांक arr[][3][--s])
{
    म_लिखो ("%d %d %d\n", माप arr, s, arr[1][2][3]);
}

व्योम c99_vla_test_3(व्योम)
{
    पूर्णांक a[2][3][4];

    स_रखो (a, 0, माप(a));
    a[1][2][3] = 123;
    c99_vla_test_3a(a);
    c99_vla_test_3b(2, a);
    c99_vla_test_3c(3, a);
    c99_vla_test_3d(4, a);
    c99_vla_test_3e(5, a);
}

व्योम c99_vla_test(व्योम)
{
    c99_vla_test_1(5, 2);
    c99_vla_test_2(3, 4, 5);
    c99_vla_test_3();
}


व्योम sizeof_test(व्योम)
{
    पूर्णांक a;
    पूर्णांक **ptr;

    म_लिखो("sizeof(int) = %d\n", माप(पूर्णांक));
    म_लिखो("sizeof(unsigned int) = %d\n", माप(अचिन्हित पूर्णांक));
    म_लिखो("sizeof(long) = %d\n", माप(दीर्घ));
    म_लिखो("sizeof(unsigned long) = %d\n", माप(अचिन्हित दीर्घ));
    म_लिखो("sizeof(short) = %d\n", माप(लघु));
    म_लिखो("sizeof(unsigned short) = %d\n", माप(अचिन्हित लघु));
    म_लिखो("sizeof(char) = %d\n", माप(अक्षर));
    म_लिखो("sizeof(unsigned char) = %d\n", माप(अचिन्हित अक्षर));
    म_लिखो("sizeof(func) = %d\n", माप sizeof_test());
    a = 1;
    म_लिखो("sizeof(a++) = %d\n", माप a++);
    म_लिखो("a=%d\n", a);
    ptr = शून्य;
    म_लिखो("sizeof(**ptr) = %d\n", माप (**ptr));

    /* The type of sizeof should be as large as a pointer, actually
       it should be size_t.  */
    म_लिखो("sizeof(sizeof(int) = %d\n", माप(माप(पूर्णांक)));
    uintptr_t t = 1;
    uintptr_t t2;
    /* Effectively <<32, but defined also on 32bit machines.  */
    t <<= 16;
    t <<= 16;
    t++;
    /* This checks that sizeof really can be used to manipulate 
       uintptr_t objects, without truncation.  */
    t2 = t & -माप(uintptr_t);
    म_लिखो ("%lu %lu\n", t, t2);

    /* some alignof tests */
    म_लिखो("__alignof__(int) = %d\n", __alignof__(पूर्णांक));
    म_लिखो("__alignof__(unsigned int) = %d\n", __alignof__(अचिन्हित पूर्णांक));
    म_लिखो("__alignof__(short) = %d\n", __alignof__(लघु));
    म_लिखो("__alignof__(unsigned short) = %d\n", __alignof__(अचिन्हित लघु));
    म_लिखो("__alignof__(char) = %d\n", __alignof__(अक्षर));
    म_लिखो("__alignof__(unsigned char) = %d\n", __alignof__(अचिन्हित अक्षर));
    म_लिखो("__alignof__(func) = %d\n", __alignof__ sizeof_test());

    /* sizes of VLAs need to be evaluated even inside sizeof: */
    a = 2;
    म_लिखो("sizeof(char[1+2*a]) = %d\n", माप(अक्षर[1+2*a]));
    /* And checking if sizeof compound literal works.  Parenthesized: */
    म_लिखो("sizeof( (struct {int i; int j;}){4,5} ) = %d\n",
	   माप( (काष्ठा {पूर्णांक i; पूर्णांक j;}){4,5} ));
    /* And as direct sizeof argument (as unary expression): */
    म_लिखो("sizeof (struct {short i; short j;}){4,5} = %d\n",
	   माप (काष्ठा {लघु i; लघु j;}){4,5} );

    /* sizeof(x && y) should be sizeof(int), even if constant
       evaluating is possible. */
    म_लिखो("sizeof(t && 0) = %d\n", माप(t && 0));
    म_लिखो("sizeof(1 && 1) = %d\n", माप(1 && 1));
    म_लिखो("sizeof(t || 1) = %d\n", माप(t || 1));
    म_लिखो("sizeof(0 || 0) = %d\n", माप(0 || 0));

    पूर्णांक arr[4], fn();
    म_लिखो("sizeof(0, arr) = %d\n", माप(0, arr));
    म_लिखो("sizeof(0, fn) = %d\n", माप(0, fn));
}

व्योम typeof_test(व्योम)
{
    द्विगुन a;
    typeof(a) b;
    typeof(भग्न) c;

    a = 1.5;
    b = 2.5;
    c = 3.5;
    म_लिखो("a=%f b=%f c=%f\n", a, b, c);
}


काष्ठा hlist_गाँठ;
काष्ठा hlist_शीर्ष {
    काष्ठा hlist_गाँठ *first, *last;
};

व्योम consume_ulong (अचिन्हित दीर्घ i)
{
    i = 0;
}

व्योम statement_व्यंजक_test(व्योम)
{
    पूर्णांक a, i;

    /* Basic stmt expr test */
    a = 0;
    क्रम(i=0;i<10;i++) {
        a += 1 + 
            ( { पूर्णांक b, j; 
                b = 0; 
                क्रम(j=0;j<5;j++) 
                    b += j; b; 
            } );
    }
    म_लिखो("a=%d\n", a);
    
    /* Test that symbols aren't freed prematurely.
       With SYM_DEBUG valgrind will show a read from a freed
       symbol, and tcc will show an (invalid) warning on the initialization
       of 'ptr' below, if symbols are popped after the stmt expr.  */
    व्योम *v = (व्योम*)39;
    typeof(({
	    (काष्ठा hlist_गाँठ *)v;
	    })) x;
    typeof (x)
	ptr = (काष्ठा hlist_गाँठ *)v;

    /* This part used to segfault when symbols were popped prematurely.
       The symbols for the static local would be overwritten with
       helper symbols from the pre-processor expansions in between.  */
#घोषणा some_attr     __attribute__((aligned(1)))
#घोषणा tps(str) ({                  \
            अटल स्थिर अक्षर *t some_attr = str; \
            t;                                    \
          })
    म_लिखो ("stmtexpr: %s %s\n",
	    tps("somerandomlongstring"),
	    tps("anotherlongstring"));

    /* Test that the three decls of 't' don't interact.  */
    पूर्णांक t = 40;
    पूर्णांक b = ({ पूर्णांक t = 41; t; });
    पूर्णांक c = ({ पूर्णांक t = 42; t; });

    /* Test that aggregate return values work.  */
    काष्ठा hlist_शीर्ष h
	= ({
	   प्रकार काष्ठा hlist_शीर्ष T;
	   दीर्घ pre = 48;
	   T t = { (व्योम*)43, (व्योम*)44 };
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
       LBL: अगर (i++ == 0) जाओ LBL;
      }
      /* jump to a classical label out of an expr-stmt that had previously
         overshadowed that classical label */
      जाओ LBL;
    });
  LBL:
    म_लिखो("stmtexpr: %d should be 2\n", i);
}

व्योम local_label_test(व्योम)
{
    पूर्णांक a;
    जाओ l1;
 l2:
    a = 1 + ({
        __label__ l1, l2, l3, l4;
        जाओ l1;
    l4:
        म_लिखो("aa1\n");
        जाओ l3;
    l2:
        म_लिखो("aa3\n");
        जाओ l4;
    l1:
        म_लिखो("aa2\n");
        जाओ l2;
    l3:;
        1;
    });
    म_लिखो("a=%d\n", a);
    वापस;
 l4:
    म_लिखो("bb1\n");
    जाओ l2;
 l1:
    म_लिखो("bb2\n");
    जाओ l4;
}

/* inline assembler test */
#अगर (defined(__i386__) || defined(__x86_64__)) && !(defined _WIN32 && CC_NAME == CC_clang)

प्रकार __SIZE_TYPE__ word;

/* from linux kernel */
अटल अक्षर * strncat1(अक्षर * dest,स्थिर अक्षर * src,माप_प्रकार गिनती_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (गिनती_2)
	: "memory");
वापस dest;
}

अटल अक्षर * strncat2(अक्षर * dest,स्थिर अक्षर * src,माप_प्रकार गिनती_2)
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
	: "0" (src),"1" (dest),"2" (0),"3" (0xffffffff), "g" (गिनती_2)
	: "memory");
वापस dest;
}

अटल अंतरभूत व्योम * memcpy1(व्योम * to, स्थिर व्योम * from, माप_प्रकार n)
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
वापस (to);
}

अटल अंतरभूत व्योम * memcpy2(व्योम * to, स्थिर व्योम * from, माप_प्रकार n)
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
वापस (to);
}

अटल __inline__ व्योम sigaddset1(अचिन्हित पूर्णांक *set, पूर्णांक _sig)
{
	__asm__("btsl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc");
}

अटल __inline__ व्योम sigdelset1(अचिन्हित पूर्णांक *set, पूर्णांक _sig)
{
	यंत्र("btrl %1,%0" : "=m"(*set) : "Ir"(_sig - 1) : "cc", "flags");
}

#अगर_घोषित __clang__
/* clang's inline asm is uncapable of 'xchgb %b0,%h0' */
अटल __inline__ __const__ अचिन्हित पूर्णांक swab32(अचिन्हित पूर्णांक x)
{
        वापस ((x >> 24) & 0xff) |
               ((x >> 8) & 0xff00) |
               ((x << 8) & 0xff0000) |
               ((x << 24) & 0xff000000);
}
#अन्यथा
अटल __inline__ __const__ अचिन्हित पूर्णांक swab32(अचिन्हित पूर्णांक x)
{
	__asm__("xchgb %b0,%h0\n\t"	/* swap lower bytes	*/
		"rorl $16,%0\n\t"	/* swap words		*/
		"xchgb %b0,%h0"		/* swap higher bytes	*/
		:"=" "q" (x)
		: "0" (x));
	वापस x;
}
#पूर्ण_अगर

अटल __inline__ अचिन्हित दीर्घ दीर्घ mul64(अचिन्हित पूर्णांक a, अचिन्हित पूर्णांक b)
{
    अचिन्हित दीर्घ दीर्घ res;
#अगर_घोषित __x86_64__
    /* Using the A constraint is wrong (it means rdx:rax, which is too large)
       but still test the 32bit->64bit mull.  */
    अचिन्हित पूर्णांक resh, resl;
    __asm__("mull %2" : "=a" (resl), "=d" (resh) : "a" (a), "r" (b));
    res = ((अचिन्हित दीर्घ दीर्घ)resh << 32) | resl;
#अन्यथा
    __asm__("mull %2" : "=A" (res) : "a" (a), "r" (b));
#पूर्ण_अगर
    वापस res;
}

अटल __inline__ अचिन्हित दीर्घ दीर्घ inc64(अचिन्हित दीर्घ दीर्घ a)
{
    अचिन्हित दीर्घ दीर्घ res;
#अगर_घोषित __x86_64__
    /* Using the A constraint is wrong, and increments are tested
       elsewhere.  */
    res = a + 1;
#अन्यथा
    __asm__("addl $1, %%eax ; adcl $0, %%edx" : "=A" (res) : "A" (a));
#पूर्ण_अगर
    वापस res;
}

काष्ठा struct123 {
    पूर्णांक a;
    पूर्णांक b;
};
काष्ठा struct1231 {
    word addr;
};

word mconstraint_test(काष्ठा struct1231 *r)
{
    word ret;
    अचिन्हित पूर्णांक a[2];
    a[0] = 0;
    __asm__ अस्थिर ("lea %2,%0; movl 4(%0),%k0; addl %2,%k0; movl $51,%2; movl $52,4%2; movl $63,%1"
	             : "=&r" (ret), "=m" (a)
	             : "m" (*(काष्ठा struct123 *)r->addr));
    वापस ret + a[0];
}

#अगर_घोषित __x86_64__
पूर्णांक fls64(अचिन्हित दीर्घ दीर्घ x)
{
  पूर्णांक bitpos = -1;
  यंत्र("bsrq %1,%q0"
      : "+r" (bitpos)
      : "rm" (x));
  वापस bitpos + 1;
}
#पूर्ण_अगर

व्योम other_constraints_test(व्योम)
{
    word ret;
    पूर्णांक var;
#अगर CC_NAME != CC_clang
    __asm__ अस्थिर ("mov %P1,%0" : "=r" (ret) : "p" (&var));
    म_लिखो ("oc1: %d\n", ret == (word)&var);
#पूर्ण_अगर
}

#अगर_अघोषित _WIN32
/* Test global asm blocks playing with aliases.  */
व्योम base_func(व्योम)
{
  म_लिखो ("asmc: base\n");
}

#अगर_अघोषित __APPLE__
बाह्य व्योम override_func1 (व्योम);
बाह्य व्योम override_func2 (व्योम);

यंत्र(".weak override_func1\n.set override_func1, base_func");
यंत्र(".set override_func1, base_func");
यंत्र(".set override_func2, base_func");

व्योम override_func2 (व्योम)
{
  म_लिखो ("asmc: override2\n");
}

/* This checks a construct used by the linux kernel to encode
   references to strings by PC relative references.  */
बाह्य पूर्णांक bug_table[] __attribute__((section("__bug_table")));
अक्षर * get_asm_string (व्योम)
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
#अगर_अघोषित __clang__
  बाह्य पूर्णांक some_प्रतीक;
  यंत्र अस्थिर (".globl some_symbol\n"
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
  अक्षर * str = ((अक्षर*)bug_table) + bug_table[1];
  वापस str;
#अन्यथा
  वापस (अक्षर *) "A string";
#पूर्ण_अगर
}

/* This checks another constructs with local labels.  */
बाह्य अचिन्हित अक्षर alld_stuff[];
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

व्योम asm_local_label_diff (व्योम)
{
  म_लिखो ("asm_local_label_diff: %d %d\n", alld_stuff[0], alld_stuff[1]);
}
#पूर्ण_अगर //!__APPLE__
#पूर्ण_अगर //!_WIN32

/* This checks that static local variables are available from assembler.  */
व्योम asm_local_statics (व्योम)
{
  अटल पूर्णांक localint = 41;
  यंत्र("incl %0" : "+m" (localint));
  म_लिखो ("asm_local_statics: %d\n", localint);
}

अटल
अचिन्हित पूर्णांक set;

व्योम fancy_copy (अचिन्हित *in, अचिन्हित *out)
{
  यंत्र अस्थिर ("" : "=r" (*out) : "0" (*in));
}

व्योम fancy_copy2 (अचिन्हित *in, अचिन्हित *out)
{
  यंत्र अस्थिर ("mov %0,(%1)" : : "r" (*in), "r" (out) : "memory");
}

#अगर defined __x86_64__
व्योम clobber_r12(व्योम)
{
    यंत्र अस्थिर("mov $1, %%r12" ::: "r12");
}
#पूर्ण_अगर

व्योम test_ऊपरी_clobbers_really(व्योम)
{
#अगर defined __x86_64__
    रेजिस्टर word val यंत्र("r12");
    word val2;
    /* This tests if asm clobbers correctly save/restore callee saved
       registers if they are clobbered and if it's the high 8 x86-64
       registers.  This is fragile for GCC as the constraints do not
       correctly capture the data flow, but good enough for us.  */
    यंत्र अस्थिर("mov $0x4542, %%r12" : "=r" (val):: "memory");
    clobber_r12();
    यंत्र अस्थिर("mov %%r12, %0" : "=r" (val2) : "r" (val): "memory");
    म_लिखो("asmhc: 0x%x\n", val2);
#पूर्ण_अगर
}

व्योम test_ऊपरी_clobbers(व्योम)
{
#अगर defined __x86_64__
    word x1, x2;
    यंत्र अस्थिर("mov %%r12,%0" :: "m" (x1)); /* save r12 */
    test_ऊपरी_clobbers_really();
    यंत्र अस्थिर("mov %%r12,%0" :: "m" (x2)); /* new r12 */
    यंत्र अस्थिर("mov %0,%%r12" :: "m" (x1)); /* restore r12 */
    /* should be 0 but tcc doesn't save r12 automatically, which has
       bad effects when gcc helds TCCState *s in r12 in tcc.c:main */
    //printf("r12-clobber-diff: %lx\n", x2 - x1);
#पूर्ण_अगर
}

अटल दीर्घ cpu_संख्या;
व्योम trace_console(दीर्घ len, दीर्घ len2)
{
#अगर_घोषित __x86_64__
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
    अगर (0
        &&
            ({
              दीर्घ pscr_ret__;
              चयन(len) {
                हाल 4:
                    {
                       दीर्घ pfo_ret__;
                       चयन (len2) {
                         हाल 8:	म_लिखो("bla"); pfo_ret__ = 42; अवरोध;
                       }
                       pscr_ret__ = pfo_ret__;
                    }
                  अवरोध;
                हाल 8:
                    {
                       दीर्घ pfo_ret__;
                       चयन (len2) {
                         हाल 1:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	अवरोध;
                         हाल 2:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	अवरोध;
                         हाल 4:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	अवरोध;
                         हाल 8:यंत्र("movq %1,%0": "=r" (pfo_ret__)	: "m" (cpu_संख्या));	अवरोध;
                         शेष: म_लिखो("impossible\n");
                       }
                       pscr_ret__ = pfo_ret__;
                    };
                  अवरोध;
              }
              pscr_ret__;
            }))
      {
        म_लिखो("huh?\n");
      }
#पूर्ण_अगर
}

व्योम test_asm_dead_code(व्योम)
{
  word rdi;
  /* Try to make sure that xdi contains a zero, and hence will
     lead to a segfault if the next asm is evaluated without
     arguments being set up.  */
  यंत्र अस्थिर ("" : "=D" (rdi) : "0" (0));
  (व्योम)माप (({
      पूर्णांक var;
      /* This shouldn't trigger a segfault, either the argument
         registers need to be set up and the asm emitted despite
	 this being in an unevaluated context, or both the argument
	 setup _and_ the asm emission need to be suppressed.  The latter
	 is better.  Disabling asm code gen when suppression is on
	 also fixes the above trace_console bug, but that came earlier
	 than asm suppression.  */
      यंत्र अस्थिर ("movl $0,(%0)" : : "D" (&var) : "memory");
      var;
  }));
}

व्योम test_asm_call(व्योम)
{
#अगर defined __x86_64__ && !defined _WIN64  && !defined(__APPLE__)
  अटल अक्षर str[] = "PATH";
  अक्षर *s;
  /* This tests if a reference to an undefined symbol from an asm
     block, which isn't otherwise referenced in this file, is correctly
     regarded as global symbol, so that it's resolved by other object files
     or libraries.  We chose getenv here, which isn't used anywhere else
     in this file.  (If we used e.g. printf, which is used we already
     would have a global symbol entry, not triggering the bug which is
     tested here).  */
  /* two pushes so stack remains aligned */
  यंत्र अस्थिर ("push %%rdi; push %%rdi; mov %0, %%rdi;"
#अगर 1 && !defined(__TINYC__) && (defined(__PIC__) || defined(__PIE__))
		"call getenv@plt;"
#अन्यथा
		"call getenv;"
#पूर्ण_अगर
		"pop %%rdi; pop %%rdi"
		: "=a" (s) : "r" (str));
  म_लिखो("asmd: %s\n", s);
#पूर्ण_अगर
}

#अगर defined __x86_64__
# define RX "(%rip)"
#अन्यथा
# define RX
#पूर्ण_अगर

व्योम asm_dot_test(व्योम)
{
#अगर_अघोषित __APPLE__
    पूर्णांक x;
    क्रम (x = 1;; ++x) {
        पूर्णांक r = x;
        चयन (x) {
        हाल 1:
            यंत्र(".text; lea S"RX",%eax; lea ."RX",%ecx; sub %ecx,%eax; S=.; jmp p0");
        हाल 2:
#अगर_अघोषित __clang__
            /* clangs internal assembler is broken */
            यंत्र(".text; jmp .+6; .int 123; mov .-4"RX",%eax; jmp p0");
#अन्यथा
            यंत्र(".text; mov $123, %eax; jmp p0");
#पूर्ण_अगर
	हाल 3:
#अगर !defined(_WIN32) && !defined(__clang__)
            यंत्र(".pushsection \".data\"; Y=.; .int 999; X=Y; .int 456; X=.-4; .popsection");
#अन्यथा
            यंत्र(".data; Y=.; .int 999; X=Y; .int 456; X=.-4; .text");
#पूर्ण_अगर
            यंत्र(".text; mov X"RX",%eax; jmp p0");
        हाल 4:
#अगर_घोषित __clang__
            /* Bah!  Clang!  Doesn't want to redefine 'X'  */
            यंत्र(".text; mov $789,%eax; jmp p0");
#अन्यथा
#अगर_अघोषित _WIN32
            यंत्र(".data; X=.; .int 789; Y=.; .int 999; .previous");
#अन्यथा
            यंत्र(".data; X=.; .int 789; Y=.; .int 999; .text");
#पूर्ण_अगर
            यंत्र(".text; mov X"RX",%eax; X=Y; jmp p0");
#पूर्ण_अगर
        हाल 0:
	    यंत्र(".text; p0=.; mov %%eax,%0;" : "=m"(r)); अवरोध;
	}
        अगर (r == x)
            अवरोध;
        म_लिखो("asm_dot_test %d: %d\n", x, r);
    }
#पूर्ण_अगर
}

व्योम asm_pcrel_test(व्योम)
{
    अचिन्हित o1, o2;
    /* subtract text-section label from forward or other-section label */
    यंत्र("1: mov $2f-1b,%%eax; mov %%eax,%0" : "=m"(o1));
    /* verify ... */
    यंत्र("2: lea 2b"RX",%eax; lea 1b"RX",%ecx; sub %ecx,%eax");
    यंत्र("mov %%eax,%0" : "=m"(o2));
    म_लिखो("%s : %x\n", __FUNCTION__, o1 - o2); /* should be zero */
}

व्योम asm_test(व्योम)
{
    अक्षर buf[128];
    अचिन्हित पूर्णांक val, val2;
    काष्ठा struct123 s1;
    काष्ठा struct1231 s2 = { (word)&s1 };
    /* Hide the outer base_func, but check later that the inline
       asm block gets the outer one.  */
    पूर्णांक base_func = 42;
    व्योम override_func3 (व्योम);
    word asmret;
#अगर_घोषित BOOL_ISOC99
    _Bool somebool;
#पूर्ण_अगर
    रेजिस्टर पूर्णांक regvar यंत्र("%esi");

    // parse 0x1E-1 as 3 tokens in asm mode
    यंत्र अस्थिर ("mov $0x1E-1,%eax");

    /* test the no operand case */
    यंत्र अस्थिर ("xorl %eax, %eax");

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
    जाओ label1;
 label2:
    __asm__("btsl %1,%0" : "=m"(set) : "Ir"(20) : "cc");
    म_लिखो("set=0x%x\n", set);
    val = 0x01020304;
    म_लिखो("swab32(0x%08x) = 0x%0x\n", val, swab32(val));
#अगर_अघोषित _WIN32
#अगर_अघोषित __APPLE__
    override_func1();
    override_func2();
    /* The base_func ref from the following inline asm should find
       the global one, not the local decl from this function.  */
    यंत्र अस्थिर(".weak override_func3\n.set override_func3, base_func");
    override_func3();
    म_लिखो("asmstr: %s\n", get_asm_string());
    asm_local_label_diff();
#पूर्ण_अगर
#पूर्ण_अगर
    asm_local_statics();
#अगर_अघोषित __clang__
    /* clang can't deal with the type change */
    /* Check that we can also load structs of appropriate layout
       into registers.  */
    यंत्र अस्थिर("" : "=r" (asmret) : "0"(s2));
    अगर (asmret != s2.addr)
      म_लिखो("asmstr: failed\n");
#पूर्ण_अगर
#अगर_घोषित BOOL_ISOC99
    /* Check that the typesize correctly sets the register size to
       8 bit.  */
    यंत्र अस्थिर("cmp %1,%2; sete %0" : "=a"(somebool) : "r"(1), "r"(2));
    अगर (!somebool)
      म_लिखो("asmbool: failed\n");
#पूर्ण_अगर
    val = 43;
    fancy_copy (&val, &val2);
    म_लिखो ("fancycpy(%d)=%d\n", val, val2);
    val = 44;
    fancy_copy2 (&val, &val2);
    म_लिखो ("fancycpy2(%d)=%d\n", val, val2);
    यंत्र अस्थिर ("mov $0x4243, %%esi" : "=r" (regvar));
    म_लिखो ("regvar=%x\n", regvar);
    test_ऊपरी_clobbers();
    trace_console(8, 8);
    test_asm_dead_code();
    test_asm_call();
    asm_dot_test();
    asm_pcrel_test();
    वापस;
 label1:
    जाओ label2;
}

#अन्यथा

व्योम asm_test(व्योम)
{
}

#पूर्ण_अगर

#घोषणा COMPAT_TYPE(type1, type2) \
{\
    म_लिखो("__builtin_types_compatible_p(%s, %s) = %d\n", #type1, #type2, \
           __builtin_types_compatible_p (type1, type2));\
}

पूर्णांक constant_p_var;

पूर्णांक func(व्योम);


/* __builtin_clz and __builtin_ctz return random values for 0 */
अटल व्योम builtin_test_bits(अचिन्हित दीर्घ दीर्घ x, पूर्णांक cnt[])
{
#अगर GCC_MAJOR >= 4
    cnt[0] += __builtin_ffs(x);
    cnt[1] += __builtin_ffsl(x);
    cnt[2] += __builtin_ffsll(x);

    अगर ((अचिन्हित पूर्णांक) x) cnt[3] += __builtin_clz(x);
    अगर ((अचिन्हित दीर्घ) x) cnt[4] += __builtin_clzl(x);
    अगर ((अचिन्हित दीर्घ दीर्घ) x) cnt[5] += __builtin_clzll(x);

    अगर ((अचिन्हित पूर्णांक) x) cnt[6] += __builtin_ctz(x);
    अगर ((अचिन्हित दीर्घ) x) cnt[7] += __builtin_ctzl(x);
    अगर ((अचिन्हित दीर्घ दीर्घ) x) cnt[8] += __builtin_ctzll(x);

#अगर GCC_MAJOR >= 6 && (CC_NAME != CC_clang || GCC_MAJOR >= 11)
/* Apple clang 10 does not have __builtin_clrsb[l[l]] */
    cnt[9] += __builtin_clrsb(x);
    cnt[10] += __builtin_clrsbl(x);
    cnt[11] += __builtin_clrsbll(x);
#पूर्ण_अगर

    cnt[12] += __builtin_popcount(x);
    cnt[13] += __builtin_popcountl(x);
    cnt[14] += __builtin_popcountll(x);

    cnt[15] += __builtin_parity(x);
    cnt[16] += __builtin_parityl(x);
    cnt[17] += __builtin_parityll(x);
#पूर्ण_अगर
}

व्योम builtin_test(व्योम)
{
    लघु s;
    पूर्णांक i;
    दीर्घ दीर्घ ll;
#अगर GCC_MAJOR >= 3
    COMPAT_TYPE(पूर्णांक, पूर्णांक);
    COMPAT_TYPE(पूर्णांक, अचिन्हित पूर्णांक);
    COMPAT_TYPE(पूर्णांक, अक्षर);
    COMPAT_TYPE(पूर्णांक, स्थिर पूर्णांक);
    COMPAT_TYPE(पूर्णांक, अस्थिर पूर्णांक);
    COMPAT_TYPE(पूर्णांक[2], स्थिर पूर्णांक[2]);
    COMPAT_TYPE(पूर्णांक[2][3], अस्थिर पूर्णांक[][3]);
    COMPAT_TYPE(पूर्णांक (*)[], स्थिर पूर्णांक (*)[]);
#अगर_अघोषित __clang__
    COMPAT_TYPE(__typeof__(1 ? (स्थिर पूर्णांक (*)[2])0 : (पूर्णांक (*)[2])0),
                स्थिर पूर्णांक (*)[2]);
    COMPAT_TYPE(__typeof__(1 ? (स्थिर पूर्णांक (*)[2][3])0 :
                              (अस्थिर पूर्णांक (*)[2][3])0),
                स्थिर अस्थिर पूर्णांक (*)[2][3]);
    COMPAT_TYPE(__typeof__(1 ? (अस्थिर पूर्णांक (*)[2][3])0 :
                              (स्थिर पूर्णांक (*)[2][3])0),
                स्थिर अस्थिर पूर्णांक (*)[2][3]);
#अन्यथा
    /* clang doesn't combine qualifiers through array types */
    म_लिखो("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2])0 : (int (*)[2])0), const int (*)[2]) = 1\n");
    म_लिखो("__builtin_types_compatible_p(__typeof__(1 ? (const int (*)[2][3])0 : (volatile int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
    म_लिखो("__builtin_types_compatible_p(__typeof__(1 ? (volatile int (*)[2][3])0 : (const int (*)[2][3])0), const volatile int (*)[2][3]) = 1\n");
#पूर्ण_अगर
    COMPAT_TYPE(पूर्णांक *, पूर्णांक *);
    COMPAT_TYPE(पूर्णांक *, व्योम *);
    COMPAT_TYPE(पूर्णांक *, स्थिर पूर्णांक *);
    COMPAT_TYPE(अक्षर *, अचिन्हित अक्षर *);
    COMPAT_TYPE(अक्षर *, चिन्हित अक्षर *);
    COMPAT_TYPE(अक्षर *, अक्षर *);
    COMPAT_TYPE(अक्षर **, व्योम *);
#पूर्ण_अगर
    म_लिखो("res1 = %d\n", __builtin_constant_p(1));
    म_लिखो("res2 = %d\n", __builtin_constant_p(1 + 2));
    म_लिखो("res3 = %d\n", __builtin_constant_p(&constant_p_var));
    म_लिखो("res4 = %d\n", __builtin_constant_p(constant_p_var));
    म_लिखो("res5 = %d\n", __builtin_constant_p(100000 / constant_p_var));
    म_लिखो("res6 = %d\n", __builtin_constant_p(i && 1));
    म_लिखो("res7 = %d\n", __builtin_constant_p("hi"));
    म_लिखो("res8 = %d\n", __builtin_constant_p(func()));
#अगर_अघोषित __clang__
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
#पूर्ण_अगर

    s = 1;
    ll = 2;
    i = __builtin_choose_expr (1 != 0, ll, s);
    म_लिखो("bce: %d\n", i);
    i = __builtin_choose_expr (1 != 1, ll, s);
    म_लिखो("bce: %d\n", i);
    i = माप (__builtin_choose_expr (1, ll, s));
    म_लिखो("bce: %d\n", i);
    i = माप (__builtin_choose_expr (0, ll, s));
    म_लिखो("bce: %d\n", i);

    //printf("bera: %p\n", __builtin_extract_return_addr((void*)43));

    {
	पूर्णांक cnt[18];
	अचिन्हित दीर्घ दीर्घ r = 0;

	स_रखो(cnt, 0, माप(cnt));
	builtin_test_bits(0, cnt);
	builtin_test_bits(0xffffffffffffffffull, cnt);
        क्रम (i = 0; i < 64; i++)
	    builtin_test_bits(1ull << i, cnt);
        क्रम (i = 0; i < 1000; i++) {
	    r = 0x5851f42d4c957f2dull * r + 0x14057b7ef767814full;
	    builtin_test_bits(r, cnt);
	}
	क्रम (i = 0; i < 18; i++)
	    म_लिखो ("%d %d\n", i, cnt[i]);
    }
}

#अगर defined _WIN32 || (defined __APPLE__ && GCC_MAJOR >= 15)
व्योम weak_test(व्योम) {}
#अन्यथा
बाह्य पूर्णांक __attribute__((weak)) weak_f1(व्योम);
बाह्य पूर्णांक __attribute__((weak)) weak_f2(व्योम);
बाह्य पूर्णांक                       weak_f3(व्योम);
बाह्य पूर्णांक __attribute__((weak)) weak_v1;
बाह्य पूर्णांक __attribute__((weak)) weak_v2;
बाह्य पूर्णांक                       weak_v3;

बाह्य पूर्णांक                           (*weak_fpa)() __attribute__((weak));
बाह्य पूर्णांक __attribute__((weak))     (*weak_fpb)();
बाह्य     __attribute__((weak)) पूर्णांक (*weak_fpc)();

बाह्य पूर्णांक                     weak_asm_f1(व्योम) यंत्र("weak_asm_f1x") __attribute((weak));
बाह्य पूर्णांक __attribute((weak)) weak_asm_f2(व्योम) यंत्र("weak_asm_f2x")                    ;
बाह्य पूर्णांक __attribute((weak)) weak_asm_f3(व्योम) यंत्र("weak_asm_f3x") __attribute((weak));
बाह्य पूर्णांक                     weak_asm_v1       यंत्र("weak_asm_v1x") __attribute((weak));
बाह्य पूर्णांक __attribute((weak)) weak_asm_v2       यंत्र("weak_asm_v2x")                    ;
बाह्य पूर्णांक __attribute((weak)) weak_asm_v3(व्योम) यंत्र("weak_asm_v3x") __attribute((weak));

#अगर_अघोषित __clang__
अटल स्थिर माप_प्रकार dummy = 0;
बाह्य __typeof(dummy) weak_dummy1 __attribute__((weak, alias("dummy")));
बाह्य __typeof(dummy) __attribute__((weak, alias("dummy"))) weak_dummy2;
बाह्य __attribute__((weak, alias("dummy"))) __typeof(dummy) weak_dummy3;
#पूर्ण_अगर

पूर्णांक some_lib_func(व्योम);
पूर्णांक dummy_impl_of_slf(व्योम) { वापस 444; }
#अगर_अघोषित __clang__
पूर्णांक some_lib_func(व्योम) __attribute__((weak, alias("dummy_impl_of_slf")));
#पूर्ण_अगर

पूर्णांक weak_toolate() __attribute__((weak));
पूर्णांक weak_toolate() { वापस 0; }

व्योम __attribute__((weak)) weak_test(व्योम)
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
	
	म_लिखो("weak_asm_f1=%d\n", weak_asm_f1 != शून्य);
	म_लिखो("weak_asm_f2=%d\n", weak_asm_f2 != शून्य);
	म_लिखो("weak_asm_f3=%d\n", weak_asm_f3 != शून्य);
	म_लिखो("weak_asm_v1=%d\n",&weak_asm_v1 != शून्य);
	म_लिखो("weak_asm_v2=%d\n",&weak_asm_v2 != शून्य);
	म_लिखो("weak_asm_v3=%d\n",&weak_asm_v3 != शून्य);
#अगर_घोषित __clang__
	म_लिखो("some_lib_func=444\n");
#अन्यथा
	म_लिखो("some_lib_func=%d\n", &some_lib_func ? some_lib_func() : 0);
#पूर्ण_अगर
}

पूर्णांक __attribute__((weak)) weak_f2() { वापस 222; }
पूर्णांक __attribute__((weak)) weak_f3() { वापस 333; }
पूर्णांक __attribute__((weak)) weak_v2 = 222;
पूर्णांक __attribute__((weak)) weak_v3 = 333;
#पूर्ण_अगर

व्योम const_func(स्थिर पूर्णांक a)
{
}

व्योम const_warn_test(व्योम)
{
    const_func(1);
}

काष्ठा condstruct {
  पूर्णांक i;
};

पूर्णांक getme (काष्ठा condstruct *s, पूर्णांक i)
{
  पूर्णांक i1 = (i == 0 ? 0 : s)->i;
  पूर्णांक i2 = (i == 0 ? s : 0)->i;
  पूर्णांक i3 = (i == 0 ? (व्योम*)0 : s)->i;
  पूर्णांक i4 = (i == 0 ? s : (व्योम*)0)->i;
  वापस i1 + i2 + i3 + i4;
}

काष्ठा global_तथ्य
{
  पूर्णांक a[40];
  पूर्णांक *b[40];
};

काष्ठा global_तथ्य global_तथ्य;

पूर्णांक global_तथ्य_getstuff (पूर्णांक *, पूर्णांक);

व्योम global_तथ्य_callit (पूर्णांक i)
{
  *global_तथ्य.b[i] = global_तथ्य_getstuff (global_तथ्य.b[i], 1);
}

पूर्णांक global_तथ्य_getstuff (पूर्णांक *p, पूर्णांक i)
{
  वापस *p + i;
}

व्योम global_तथ्य_test (व्योम)
{
  global_तथ्य.a[0] = 42;
  global_तथ्य.b[0] = &global_तथ्य.a[0];
  global_तथ्य_callit (0);
  म_लिखो ("%d\n", global_तथ्य.a[0]);
}

काष्ठा cmpcmpS
{
  अचिन्हित अक्षर fill : 3;
  अचिन्हित अक्षर b1 : 1;
  अचिन्हित अक्षर b2 : 1;
  अचिन्हित अक्षर fill2 : 3;
};

पूर्णांक glob1, glob2, glob3;

व्योम compare_comparisons (काष्ठा cmpcmpS *s)
{
  अगर (s->b1 != (glob1 == glob2)
      || (s->b2 != (glob1 == glob3)))
    म_लिखो ("comparing comparisons broken\n");
}

व्योम cmp_comparison_test(व्योम)
{
  काष्ठा cmpcmpS s;
  s.b1 = 1;
  glob1 = 42; glob2 = 42;
  s.b2 = 0;
  glob3 = 43;
  compare_comparisons (&s);
}

पूर्णांक fcompare (द्विगुन a, द्विगुन b, पूर्णांक code)
{
  चयन (code) {
    हाल 0: वापस a == b;
    हाल 1: वापस a != b;
    हाल 2: वापस a < b;
    हाल 3: वापस a >= b;
    हाल 4: वापस a > b;
    हाल 5: वापस a <= b;
  }
  वापस 0;
}

व्योम math_cmp_test(व्योम)
{
  द्विगुन nan = 0.0/0.0;
  द्विगुन one = 1.0;
  द्विगुन two = 2.0;
  पूर्णांक comp = 0;
  पूर्णांक v;
#घोषणा bug(a,b,op,iop,part) म_लिखो("Test broken: %s %s %s %s %d\n", #a, #b, #op, #iop, part)

  /* This asserts that "a op b" is _not_ true, but "a iop b" is true.
     And it does this in various ways so that all code generation paths
     are checked (generating inverted tests, or non-inverted tests, or
     producing a 0/1 value without jumps (that's done in the fcompare
     function).  */
#घोषणा FCMP(a,b,op,iop,code) \
  अगर (fcompare (a,b,code))    \
    bug (a,b,op,iop,1); \
  अगर (a op b) \
    bug (a,b,op,iop,2); \
  अगर (a iop b) \
    ; \
  अन्यथा \
    bug (a,b,op,iop,3); \
  अगर ((a op b) || comp) \
    bug (a,b,op,iop,4); \
  अगर ((a iop b) || comp) \
    ; \
  अन्यथा \
    bug (a,b,op,iop,5); \
  अगर (v = !(a op b), !v) bug(a,b,op,iop,7);

  /* Equality tests.  */
  FCMP(nan, nan, ==, !=, 0);
  FCMP(one, two, ==, !=, 0);
  FCMP(one, one, !=, ==, 1);
  /* Non-equality is a bit special.  */
  अगर (!fcompare (nan, nan, 1))
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

द्विगुन get100 () { वापस 100.0; }

व्योम callsave_test(व्योम)
{
  पूर्णांक i, s; द्विगुन *d; द्विगुन t;
  s = माप (द्विगुन);
  म_लिखो ("callsavetest: %d\n", s);
  d = alloca (माप(द्विगुन));
  d[0] = 10.0;
  /* x86-64 had a bug were the next call to get100 would evict
     the lvalue &d[0] as VT_LLOCAL, and the reload would be done
     in int type, not pointer type.  When alloca returns a pointer
     with the high 32 bit set (which is likely on x86-64) the access
     generates a segfault.  */
  i = d[0] > get100 ();
  म_लिखो ("%d\n", i);
}


व्योम bfa3(सूचक_भेद_प्रकार str_offset)
{
    म_लिखो("bfa3: %s\n", (अक्षर *)__builtin_frame_address(3) + str_offset);
}
व्योम bfa2(सूचक_भेद_प्रकार str_offset)
{
    म_लिखो("bfa2: %s\n", (अक्षर *)__builtin_frame_address(2) + str_offset);
    bfa3(str_offset);
}
व्योम bfa1(सूचक_भेद_प्रकार str_offset)
{
    म_लिखो("bfa1: %s\n", (अक्षर *)__builtin_frame_address(1) + str_offset);
    bfa2(str_offset);
}

व्योम builtin_frame_address_test(व्योम)
{
/* builtin_frame_address fails on ARM with gcc which make test3 fail */
#अगर_अघोषित __arm__
    अक्षर str[] = "__builtin_frame_address";
    अक्षर *fp0 = __builtin_frame_address(0);

    म_लिखो("str: %s\n", str);
#अगर_अघोषित __riscv // gcc dumps core. tcc, clang work
    bfa1(str-fp0);
#पूर्ण_अगर
#पूर्ण_अगर
}

अक्षर via_volatile (अक्षर i)
{
  अक्षर अस्थिर vi;
  vi = i;
  वापस vi;
}

व्योम volatile_test(व्योम)
{
    अगर (via_volatile (42) != 42)
      म_लिखो (" broken\n");
    अन्यथा
      म_लिखो (" ok\n");
}

काष्ठा __attribute__((__packed__)) Spacked {
    अक्षर a;
    लघु b;
    पूर्णांक c;
};
काष्ठा Spacked spacked;
प्रकार काष्ठा __attribute__((__packed__)) {
    अक्षर a;
    लघु b;
    पूर्णांक c;
} Spacked2;
Spacked2 spacked2;
प्रकार काष्ठा Spacked3_s {
    अक्षर a;
    लघु b;
    पूर्णांक c;
} __attribute__((__packed__)) Spacked3;
Spacked3 spacked3;
काष्ठा gate_struct64 {
    अचिन्हित लघु offset_निचला;
    अचिन्हित लघु segment;
    अचिन्हित ist : 3, zero0 : 5, type : 5, dpl : 2, p : 1;
    अचिन्हित लघु offset_मध्य;
    अचिन्हित offset_ऊपरी;
    अचिन्हित zero1;
} __attribute__((packed));
प्रकार काष्ठा gate_struct64 gate_desc;
gate_desc a_gate_desc;
व्योम attrib_test(व्योम)
{
#अगर_अघोषित _WIN32
  म_लिखो("attr: %d %d %d %d\n", माप(काष्ठा Spacked),
	 माप(spacked), माप(Spacked2), माप(spacked2));
  म_लिखो("attr: %d %d\n", माप(Spacked3), माप(spacked3));
  म_लिखो("attr: %d %d\n", माप(gate_desc), माप(a_gate_desc));
#पूर्ण_अगर
}
बाह्य __attribute__((__unused__)) अक्षर * __attribute__((__unused__)) *
strange_attrib_placement (व्योम);

व्योम * __attribute__((__unused__)) get_void_ptr (व्योम *a)
{
  वापस a;
}

/* This part checks for a bug in TOK_GET (used for inline expansion),
   where the large long long constant left the the high bits set for
   the integer constant token.  */
अटल अंतरभूत
पूर्णांक __get_order(अचिन्हित दीर्घ दीर्घ आकार)
{
  पूर्णांक order;
  आकार -= 0xffff880000000000ULL; // this const left high bits set in the token
    {
      काष्ठा S { पूर्णांक i : 1; } s; // constructed for this '1'
    }
  order = आकार;
  वापस order;
}

/* This just forces the above inline function to be actually emitted.  */
पूर्णांक force_get_order(अचिन्हित दीर्घ s)
{
    वापस __get_order(s);
}

#घोषणा pv(m) म_लिखो(माप (s->m + 0) == 8 ? "%016llx\n" : "%02x\n", s->m)

/* Test failed when using bounds checking */
व्योम bounds_check1_test (व्योम)
{
    काष्ठा s {
        पूर्णांक x;
        दीर्घ दीर्घ y;
    } _s, *s = &_s;
    s->x = 10;
    s->y = 20;
    pv(x);
    pv(y);
}

/* This failed on arm64/riscv64 */
व्योम map_add(पूर्णांक a, पूर्णांक b, पूर्णांक c, पूर्णांक d, पूर्णांक e, पूर्णांक f, पूर्णांक g, पूर्णांक h, पूर्णांक i)
{
  म_लिखो ("%d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i);
}

व्योम func_arg_test(व्योम)
{
    पूर्णांक a = 0;
    पूर्णांक b = 1;
    map_add(0, 1, 2, 3, 4, 5, 6, 7, a && b);
}

/* gcc 2.95.3 does not handle correctly CR in strings or after strays */
#घोषणा CORRECT_CR_HANDLING

/* deprecated and no longer supported in gcc 3.3 */
/* no longer supported by default in TinyCC */
#अगर_घोषित __TINYC__
/* # define ACCEPT_LF_IN_STRINGS */
#पूर्ण_अगर

#घोषणा	tcc_test()

/* keep this as the last test because GCC messes up line-numbers
   with the ^L^K^M characters below */
व्योम whitespace_test(व्योम)
{
    अक्षर *str;
    पूर्णांक tcc_test = 1;

#अगर 1
    pri\
ntf("whitspace:\n");
#पूर्ण_अगर
    pf("N=%d\n", 2);

#अगर_घोषित CORRECT_CR_HANDLING
    pri\
ntf("aaa=%d\n", 3);
#पूर्ण_अगर

    pri\
\
ntf("min=%d\n", 4);

#अगर_घोषित ACCEPT_LF_IN_STRINGS
    म_लिखो("len1=%d\n", म_माप("
"));
#अगर_घोषित CORRECT_CR_HANDLING
    str = "
";
    म_लिखो("len1=%d str[0]=%d\n", म_माप(str), str[0]);
#पूर्ण_अगर
    म_लिखो("len1=%d\n", म_माप("a
"));
#अन्यथा
    म_लिखो("len1=1\nlen1=1 str[0]=10\nlen1=3\n");
#पूर्ण_अगर /* ACCEPT_LF_IN_STRINGS */

#अगर_घोषित __LINE__
    म_लिखो("__LINE__ defined\n");
#पूर्ण_अगर

#अगर 0
    /* wrong with GCC */
    म_लिखो("__LINE__=%d __FILE__=%s\n", __LINE__, __खाता__);
#पंक्ति 1111
    म_लिखो("__LINE__=%d __FILE__=%s\n", __LINE__, __खाता__);
#पंक्ति 2222 "test"
    म_लिखो("__LINE__=%d __FILE__=%s\n", __LINE__, __खाता__);
#पूर्ण_अगर

    म_लिखो("\\
"12\\
063\\
n 456\"\n");

    म_लिखो ("%d\n",
#अगर 1
	    tcc_test
#पूर्ण_अगर
            );

}

#घोषणा RUN(test) माला_दो("---- " #test " ----"), test(), माला_दो("")

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    RUN(whitespace_test);
    RUN(macro_test);
    RUN(recursive_macro_test);
    RUN(string_test);
    RUN(व्यंजक_test);
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
    RUN(व्यंजक_ptr_test);
    RUN(bool_test);
    RUN(optimize_out_test);
    RUN(expr2_test);
    RUN(constant_व्यंजक_test);
    RUN(व्यंजक_cmp_test);
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
    RUN(statement_व्यंजक_test);
    RUN(local_label_test);
    RUN(asm_test);
    RUN(builtin_test);
    RUN(weak_test);
    RUN(global_तथ्य_test);
    RUN(cmp_comparison_test);
    RUN(math_cmp_test);
    RUN(callsave_test);
    RUN(builtin_frame_address_test);
    RUN(volatile_test);
    RUN(attrib_test);
    RUN(bounds_check1_test);
    RUN(func_arg_test);

    वापस 0;
}
