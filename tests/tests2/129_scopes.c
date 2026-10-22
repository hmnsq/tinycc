ຈຳນວນເຕັມ printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

ຈຳນວນເຕັມ main_1(){
    {
        myassert(!in);
        ຖ້າ(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        ໃນຂະນະທີ່(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}ໃນຂະນະທີ່(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        ສຳລັບ(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        ສຳລັບ(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        ສຳລັບ(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    ສົ່ງຄືນ 0;
}

/* --------------------------------------------- */
ຈຳນວນເຕັມ main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ສົ່ງຄືນ 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { ຈຳນວນເຕັມ a; };

/* --------------------------------------------- */
ຈຳນວນເຕັມ main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ສົ່ງຄືນ 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  ສົ່ງຄືນ st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    ຈຳນວນເຕັມ strcmp();
    myassert(!strcmp(a, "test"));
    ສົ່ງຄືນ a;
}

ຈຳນວນເຕັມ main_4()
{
    f4(a4);
    ສົ່ງຄືນ 0;
}

/* --------------------------------------------- */
ຈຳນວນເຕັມ a5[3], b5[];
ຈຳນວນເຕັມ f5(void);
ຈຳນວນເຕັມ main_5()
{
    extern ຈຳນວນເຕັມ a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ສົ່ງຄືນ 0;
}
ຈຳນວນເຕັມ f5(void)
{
    ສົ່ງຄືນ a5[2]+b5[2];
}
ຈຳນວນເຕັມ b5[3];

/* --------------------------------------------- */
static ຈຳນວນເຕັມ f6(ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ i6 = 11;

ຈຳນວນເຕັມ main_6()
{
    {
        ຈຳນວນເຕັມ i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            ຈຳນວນເຕັມ f6(ຈຳນວນເຕັມ);
            extern ຈຳນວນເຕັມ i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ສົ່ງຄືນ 0;
}

ຈຳນວນເຕັມ f6(ຈຳນວນເຕັມ x)
{
    ສົ່ງຄືນ x;
}

/* --------------------------------------------- */

#ຖ້າ defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#ບໍ່ດັ່ງນັ້ນ
# define _ "_"
#endif

sa_nracanaa xx7 { ຈຳນວນເຕັມ a, b; };

void f7()
{
    sa_nracanaa xx7 { ຈຳນວນເຕັມ c; } x;
    {
        extern sa_nracanaa xx7 { ຈຳນວນເຕັມ a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

ຈຳນວນເຕັມ main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ສົ່ງຄືນ 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
ຈຳນວນເຕັມ main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ສົ່ງຄືນ 0;
}
