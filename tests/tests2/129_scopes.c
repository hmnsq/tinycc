පූර්ණ_සංඛ්‍යා printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

පූර්ණ_සංඛ්‍යා main_1(){
    {
        myassert(!in);
        නම්(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        අතරතුර(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}අතරතුර(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        සඳහා(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        සඳහා(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        සඳහා(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    ආපසු 0;
}

/* --------------------------------------------- */
පූර්ණ_සංඛ්‍යා main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ආපසු 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { පූර්ණ_සංඛ්‍යා a; };

/* --------------------------------------------- */
පූර්ණ_සංඛ්‍යා main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ආපසු 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  ආපසු st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    පූර්ණ_සංඛ්‍යා strcmp();
    myassert(!strcmp(a, "test"));
    ආපසු a;
}

පූර්ණ_සංඛ්‍යා main_4()
{
    f4(a4);
    ආපසු 0;
}

/* --------------------------------------------- */
පූර්ණ_සංඛ්‍යා a5[3], b5[];
පූර්ණ_සංඛ්‍යා f5(void);
පූර්ණ_සංඛ්‍යා main_5()
{
    extern පූර්ණ_සංඛ්‍යා a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ආපසු 0;
}
පූර්ණ_සංඛ්‍යා f5(void)
{
    ආපසු a5[2]+b5[2];
}
පූර්ණ_සංඛ්‍යා b5[3];

/* --------------------------------------------- */
static පූර්ණ_සංඛ්‍යා f6(පූර්ණ_සංඛ්‍යා);
පූර්ණ_සංඛ්‍යා i6 = 11;

පූර්ණ_සංඛ්‍යා main_6()
{
    {
        පූර්ණ_සංඛ්‍යා i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            පූර්ණ_සංඛ්‍යා f6(පූර්ණ_සංඛ්‍යා);
            extern පූර්ණ_සංඛ්‍යා i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ආපසු 0;
}

පූර්ණ_සංඛ්‍යා f6(පූර්ණ_සංඛ්‍යා x)
{
    ආපසු x;
}

/* --------------------------------------------- */

#නම් defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#නැතහොත්
# define _ "_"
#endif

sa_nracanaa xx7 { පූර්ණ_සංඛ්‍යා a, b; };

void f7()
{
    sa_nracanaa xx7 { පූර්ණ_සංඛ්‍යා c; } x;
    {
        extern sa_nracanaa xx7 { පූර්ණ_සංඛ්‍යා a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

පූර්ණ_සංඛ්‍යා main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ආපසු 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
පූර්ණ_සංඛ්‍යා main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ආපසු 0;
}
