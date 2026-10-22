ཧྲིལ printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

ཧྲིལ main_1(){
    {
        myassert(!in);
        གལ་ཏེ(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        སྐབས(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}སྐབས(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        ཆེད་དུ(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        ཆེད་དུ(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        ཆེད་དུ(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    ཕྱིར 0;
}

/* --------------------------------------------- */
ཧྲིལ main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ཕྱིར 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { ཧྲིལ a; };

/* --------------------------------------------- */
ཧྲིལ main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ཕྱིར 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  ཕྱིར st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    ཧྲིལ strcmp();
    myassert(!strcmp(a, "test"));
    ཕྱིར a;
}

ཧྲིལ main_4()
{
    f4(a4);
    ཕྱིར 0;
}

/* --------------------------------------------- */
ཧྲིལ a5[3], b5[];
ཧྲིལ f5(void);
ཧྲིལ main_5()
{
    extern ཧྲིལ a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ཕྱིར 0;
}
ཧྲིལ f5(void)
{
    ཕྱིར a5[2]+b5[2];
}
ཧྲིལ b5[3];

/* --------------------------------------------- */
static ཧྲིལ f6(ཧྲིལ);
ཧྲིལ i6 = 11;

ཧྲིལ main_6()
{
    {
        ཧྲིལ i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            ཧྲིལ f6(ཧྲིལ);
            extern ཧྲིལ i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ཕྱིར 0;
}

ཧྲིལ f6(ཧྲིལ x)
{
    ཕྱིར x;
}

/* --------------------------------------------- */

#གལ་ཏེ defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#དེ་མིན
# define _ "_"
#endif

sa_nracanaa xx7 { ཧྲིལ a, b; };

void f7()
{
    sa_nracanaa xx7 { ཧྲིལ c; } x;
    {
        extern sa_nracanaa xx7 { ཧྲིལ a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

ཧྲིལ main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ཕྱིར 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
ཧྲིལ གཙོ()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ཕྱིར 0;
}
