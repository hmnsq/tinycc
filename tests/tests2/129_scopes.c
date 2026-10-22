পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

গণনা{ in = 0};

পূর্ণাঙ্ক main_1(){
    {
        myassert(!in);
        যদি(পরিমাণ(গণনা{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        ৱিকল্প(পরিমাণ(গণনা{in=1})) { স্ৱভাৱ: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        যেতিয়ালৈ(পরিমাণ(গণনা{in=1})) { myassert(in); ভঙ্গ; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        কৰা{ myassert(!in);}যেতিয়ালৈ(0*পরিমাণ(গণনা{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        বাবে(পরিমাণ(গণনা{in=1});;){ myassert(in); ভঙ্গ; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        বাবে(;;পরিমাণ(গণনা{in=1})){ myassert(in); ভঙ্গ; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        বাবে(;পরিমাণ(গণনা{in=1});){ myassert(in); ভঙ্গ; }
        myassert(!in); //OK
    }
    ঘূৰাই 0;
}

/* --------------------------------------------- */
পূর্ণাঙ্ক main_2()
{
  ৱর্ণ c = 'a';
  শূন্য func1(ৱর্ণ c); /* param 'c' must not shadow local 'c' */
  func1(c);
  ঘূৰাই 0;
}

শূন্য func1(ৱর্ণ c)
{
    myassert(c == 'a');
}

সংরচনা st { পূর্ণাঙ্ক a; };

/* --------------------------------------------- */
পূর্ণাঙ্ক main_3()
{
  সংরচনা st func(শূন্য);
  সংরচনা st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  ঘূৰাই 0;
}

সংরচনা st func(শূন্য)
{
  সংরচনা st st = { 10 };
  ঘূৰাই st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
স্থির শূন্য f4(ৱর্ণ *(*md)(ৱর্ণ *md))
{
   (*md)("test");
}
স্থির ৱর্ণ *a4(ৱর্ণ *a)
{
    পূর্ণাঙ্ক strcmp();
    myassert(!strcmp(a, "test"));
    ঘূৰাই a;
}

পূর্ণাঙ্ক main_4()
{
    f4(a4);
    ঘূৰাই 0;
}

/* --------------------------------------------- */
পূর্ণাঙ্ক a5[3], b5[];
পূর্ণাঙ্ক f5(শূন্য);
পূর্ণাঙ্ক main_5()
{
    বাহ্য পূর্ণাঙ্ক a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    ঘূৰাই 0;
}
পূর্ণাঙ্ক f5(শূন্য)
{
    ঘূৰাই a5[2]+b5[2];
}
পূর্ণাঙ্ক b5[3];

/* --------------------------------------------- */
স্থির পূর্ণাঙ্ক f6(পূর্ণাঙ্ক);
পূর্ণাঙ্ক i6 = 11;

পূর্ণাঙ্ক main_6()
{
    {
        পূর্ণাঙ্ক i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            পূর্ণাঙ্ক f6(পূর্ণাঙ্ক);
            বাহ্য পূর্ণাঙ্ক i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    ঘূৰাই 0;
}

পূর্ণাঙ্ক f6(পূর্ণাঙ্ক x)
{
    ঘূৰাই x;
}

/* --------------------------------------------- */

#যদি defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#অন্যথা
# define _ "_"
#endif

সংরচনা xx7 { পূর্ণাঙ্ক a, b; };

শূন্য f7()
{
    সংরচনা xx7 { পূর্ণাঙ্ক c; } x;
    {
        বাহ্য সংরচনা xx7 { পূর্ণাঙ্ক a, b; } x __asm__(_"z7");
        x.a = 12;
        সংরচনা xx7 y = { 0,0 };
    }
    সংরচনা xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

পূর্ণাঙ্ক main_7()
{
    f7();
    বাহ্য সংরচনা xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    ঘূৰাই 0;
}


সংরচনা xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
পূর্ণাঙ্ক main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    ঘূৰাই 0;
}
