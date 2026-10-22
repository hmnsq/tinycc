จำนวนเต็ม printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

จำนวนเต็ม main_1(){
    {
        myassert(!in);
        ถ้า(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        ขณะ(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}ขณะ(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        สำหรับ(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        สำหรับ(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        สำหรับ(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    คืน 0;
}

/* --------------------------------------------- */
จำนวนเต็ม main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  คืน 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { จำนวนเต็ม a; };

/* --------------------------------------------- */
จำนวนเต็ม main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  คืน 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  คืน st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    จำนวนเต็ม strcmp();
    myassert(!strcmp(a, "test"));
    คืน a;
}

จำนวนเต็ม main_4()
{
    f4(a4);
    คืน 0;
}

/* --------------------------------------------- */
จำนวนเต็ม a5[3], b5[];
จำนวนเต็ม f5(void);
จำนวนเต็ม main_5()
{
    extern จำนวนเต็ม a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    คืน 0;
}
จำนวนเต็ม f5(void)
{
    คืน a5[2]+b5[2];
}
จำนวนเต็ม b5[3];

/* --------------------------------------------- */
static จำนวนเต็ม f6(จำนวนเต็ม);
จำนวนเต็ม i6 = 11;

จำนวนเต็ม main_6()
{
    {
        จำนวนเต็ม i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            จำนวนเต็ม f6(จำนวนเต็ม);
            extern จำนวนเต็ม i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    คืน 0;
}

จำนวนเต็ม f6(จำนวนเต็ม x)
{
    คืน x;
}

/* --------------------------------------------- */

#ถ้า defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#มิฉะนั้น
# define _ "_"
#endif

sa_nracanaa xx7 { จำนวนเต็ม a, b; };

void f7()
{
    sa_nracanaa xx7 { จำนวนเต็ม c; } x;
    {
        extern sa_nracanaa xx7 { จำนวนเต็ม a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

จำนวนเต็ม main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    คืน 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
จำนวนเต็ม หลัก()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    คืน 0;
}
