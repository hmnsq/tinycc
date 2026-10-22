ចំនួនគត់ printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

ចំនួនគត់ main_1(){
    {
        myassert(!in);
        ប្រសិនបើ(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        ខណៈពេល(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}ខណៈពេល(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        សម្រាប់(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        សម្រាប់(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        សម្រាប់(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    ត្រឡប់ 0;
}

/* --------------------------------------------- */
ចំនួនគត់ main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ត្រឡប់ 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { ចំនួនគត់ a; };

/* --------------------------------------------- */
ចំនួនគត់ main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ត្រឡប់ 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  ត្រឡប់ st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    ចំនួនគត់ strcmp();
    myassert(!strcmp(a, "test"));
    ត្រឡប់ a;
}

ចំនួនគត់ main_4()
{
    f4(a4);
    ត្រឡប់ 0;
}

/* --------------------------------------------- */
ចំនួនគត់ a5[3], b5[];
ចំនួនគត់ f5(void);
ចំនួនគត់ main_5()
{
    extern ចំនួនគត់ a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ត្រឡប់ 0;
}
ចំនួនគត់ f5(void)
{
    ត្រឡប់ a5[2]+b5[2];
}
ចំនួនគត់ b5[3];

/* --------------------------------------------- */
static ចំនួនគត់ f6(ចំនួនគត់);
ចំនួនគត់ i6 = 11;

ចំនួនគត់ main_6()
{
    {
        ចំនួនគត់ i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            ចំនួនគត់ f6(ចំនួនគត់);
            extern ចំនួនគត់ i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ត្រឡប់ 0;
}

ចំនួនគត់ f6(ចំនួនគត់ x)
{
    ត្រឡប់ x;
}

/* --------------------------------------------- */

#ប្រសិនបើ defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#បើមិនដូច្នេះ
# define _ "_"
#endif

sa_nracanaa xx7 { ចំនួនគត់ a, b; };

void f7()
{
    sa_nracanaa xx7 { ចំនួនគត់ c; } x;
    {
        extern sa_nracanaa xx7 { ចំនួនគត់ a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

ចំនួនគត់ main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ត្រឡប់ 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
ចំនួនគត់ main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ត្រឡប់ 0;
}
