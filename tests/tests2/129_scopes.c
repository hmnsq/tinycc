صحيح printf(ثابت حرف*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

تعداد{ in = 0};

صحيح main_1(){
    {
        myassert(!in);
        إذا(حجم(تعداد{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        بدل(حجم(تعداد{in=1})) { افتراضي: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        بينما(حجم(تعداد{in=1})) { myassert(in); اكسر; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        افعل{ myassert(!in);}بينما(0*حجم(تعداد{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        لكل(حجم(تعداد{in=1});;){ myassert(in); اكسر; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        لكل(;;حجم(تعداد{in=1})){ myassert(in); اكسر; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        لكل(;حجم(تعداد{in=1});){ myassert(in); اكسر; }
        myassert(!in); //OK
    }
    إرجاع 0;
}

/* --------------------------------------------- */
صحيح main_2()
{
  حرف c = 'a';
  فراغ func1(حرف c); /* param 'c' must not shadow local 'c' */
  func1(c);
  إرجاع 0;
}

فراغ func1(حرف c)
{
    myassert(c == 'a');
}

بنية st { صحيح a; };

/* --------------------------------------------- */
صحيح main_3()
{
  بنية st func(فراغ);
  بنية st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  إرجاع 0;
}

بنية st func(فراغ)
{
  بنية st st = { 10 };
  إرجاع st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
ساكن فراغ f4(حرف *(*md)(حرف *md))
{
   (*md)("test");
}
ساكن حرف *a4(حرف *a)
{
    صحيح strcmp();
    myassert(!strcmp(a, "test"));
    إرجاع a;
}

صحيح main_4()
{
    f4(a4);
    إرجاع 0;
}

/* --------------------------------------------- */
صحيح a5[3], b5[];
صحيح f5(فراغ);
صحيح main_5()
{
    خارجي صحيح a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    إرجاع 0;
}
صحيح f5(فراغ)
{
    إرجاع a5[2]+b5[2];
}
صحيح b5[3];

/* --------------------------------------------- */
ساكن صحيح f6(صحيح);
صحيح i6 = 11;

صحيح main_6()
{
    {
        صحيح i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            صحيح f6(صحيح);
            خارجي صحيح i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    إرجاع 0;
}

صحيح f6(صحيح x)
{
    إرجاع x;
}

/* --------------------------------------------- */

#إذا defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#وإلا
# define _ "_"
#endif

بنية xx7 { صحيح a, b; };

فراغ f7()
{
    بنية xx7 { صحيح c; } x;
    {
        خارجي بنية xx7 { صحيح a, b; } x __asm__(_"z7");
        x.a = 12;
        بنية xx7 y = { 0,0 };
    }
    بنية xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

صحيح main_7()
{
    f7();
    خارجي بنية xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    إرجاع 0;
}


بنية xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
صحيح الرئيسية()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    إرجاع 0;
}
