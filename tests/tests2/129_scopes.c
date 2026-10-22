puur_naa_nka printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

puur_naa_nka main_1(){
    {
        myassert(!in);
        ᤀᤡ᤺(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        ᤀᤠ᤺(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}ᤀᤠ᤺(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        for(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        for(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        for(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    ᤀᤡᤴ 0;
}

/* --------------------------------------------- */
puur_naa_nka main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ᤀᤡᤴ 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { puur_naa_nka a; };

/* --------------------------------------------- */
puur_naa_nka main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ᤀᤡᤴ 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  ᤀᤡᤴ st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    puur_naa_nka strcmp();
    myassert(!strcmp(a, "test"));
    ᤀᤡᤴ a;
}

puur_naa_nka main_4()
{
    f4(a4);
    ᤀᤡᤴ 0;
}

/* --------------------------------------------- */
puur_naa_nka a5[3], b5[];
puur_naa_nka f5(void);
puur_naa_nka main_5()
{
    extern puur_naa_nka a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ᤀᤡᤴ 0;
}
puur_naa_nka f5(void)
{
    ᤀᤡᤴ a5[2]+b5[2];
}
puur_naa_nka b5[3];

/* --------------------------------------------- */
static puur_naa_nka f6(puur_naa_nka);
puur_naa_nka i6 = 11;

puur_naa_nka main_6()
{
    {
        puur_naa_nka i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            puur_naa_nka f6(puur_naa_nka);
            extern puur_naa_nka i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ᤀᤡᤴ 0;
}

puur_naa_nka f6(puur_naa_nka x)
{
    ᤀᤡᤴ x;
}

/* --------------------------------------------- */

#ᤀᤡ᤺ defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#ᤀᤡ᤺ᤆᤡ
# define _ "_"
#endif

sa_nracanaa xx7 { puur_naa_nka a, b; };

void f7()
{
    sa_nracanaa xx7 { puur_naa_nka c; } x;
    {
        extern sa_nracanaa xx7 { puur_naa_nka a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

puur_naa_nka main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ᤀᤡᤴ 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
puur_naa_nka main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ᤀᤡᤴ 0;
}
