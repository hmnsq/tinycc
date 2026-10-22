ကိန်းပြည့် printf(const var_na*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ga_nanaa{ in = 0};

ကိန်းပြည့် main_1(){
    {
        myassert(!in);
        အကယ်၍(parimaa_na(ga_nanaa{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(parimaa_na(ga_nanaa{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        နေစဉ်(parimaa_na(ga_nanaa{in=1})) { myassert(in); bha_nga; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}နေစဉ်(0*parimaa_na(ga_nanaa{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        အတွက်(parimaa_na(ga_nanaa{in=1});;){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        အတွက်(;;parimaa_na(ga_nanaa{in=1})){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        အတွက်(;parimaa_na(ga_nanaa{in=1});){ myassert(in); bha_nga; }
        myassert(!in); //OK
    }
    ပြန်ပေး 0;
}

/* --------------------------------------------- */
ကိန်းပြည့် main_2()
{
  var_na c = 'a';
  void func1(var_na c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ပြန်ပေး 0;
}

void func1(var_na c)
{
    myassert(c == 'a');
}

sa_nracanaa st { ကိန်းပြည့် a; };

/* --------------------------------------------- */
ကိန်းပြည့် main_3()
{
  sa_nracanaa st func(void);
  sa_nracanaa st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ပြန်ပေး 0;
}

sa_nracanaa st func(void)
{
  sa_nracanaa st st = { 10 };
  ပြန်ပေး st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(var_na *(*md)(var_na *md))
{
   (*md)("test");
}
static var_na *a4(var_na *a)
{
    ကိန်းပြည့် strcmp();
    myassert(!strcmp(a, "test"));
    ပြန်ပေး a;
}

ကိန်းပြည့် main_4()
{
    f4(a4);
    ပြန်ပေး 0;
}

/* --------------------------------------------- */
ကိန်းပြည့် a5[3], b5[];
ကိန်းပြည့် f5(void);
ကိန်းပြည့် main_5()
{
    extern ကိန်းပြည့် a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ပြန်ပေး 0;
}
ကိန်းပြည့် f5(void)
{
    ပြန်ပေး a5[2]+b5[2];
}
ကိန်းပြည့် b5[3];

/* --------------------------------------------- */
static ကိန်းပြည့် f6(ကိန်းပြည့်);
ကိန်းပြည့် i6 = 11;

ကိန်းပြည့် main_6()
{
    {
        ကိန်းပြည့် i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            ကိန်းပြည့် f6(ကိန်းပြည့်);
            extern ကိန်းပြည့် i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ပြန်ပေး 0;
}

ကိန်းပြည့် f6(ကိန်းပြည့် x)
{
    ပြန်ပေး x;
}

/* --------------------------------------------- */

#အကယ်၍ defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#မဟုတ်ပါက
# define _ "_"
#endif

sa_nracanaa xx7 { ကိန်းပြည့် a, b; };

void f7()
{
    sa_nracanaa xx7 { ကိန်းပြည့် c; } x;
    {
        extern sa_nracanaa xx7 { ကိန်းပြည့် a, b; } x __asm__(_"z7");
        x.a = 12;
        sa_nracanaa xx7 y = { 0,0 };
    }
    sa_nracanaa xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

ကိန်းပြည့် main_7()
{
    f7();
    extern sa_nracanaa xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ပြန်ပေး 0;
}


sa_nracanaa xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
ကိန်းပြည့် main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ပြန်ပေး 0;
}
