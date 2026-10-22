صحیح printf(ثابت نویسه*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

شمارش{ in = 0};

صحیح main_1(){
    {
        myassert(!in);
        اگر(اندازه(شمارش{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        انتخاب(اندازه(شمارش{in=1})) { پیشفرض: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        وقتی(اندازه(شمارش{in=1})) { myassert(in); بشکن; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        انجامبده{ myassert(!in);}وقتی(0*اندازه(شمارش{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        برای(اندازه(شمارش{in=1});;){ myassert(in); بشکن; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        برای(;;اندازه(شمارش{in=1})){ myassert(in); بشکن; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        برای(;اندازه(شمارش{in=1});){ myassert(in); بشکن; }
        myassert(!in); //OK
    }
    بازگشت 0;
}

/* --------------------------------------------- */
صحیح main_2()
{
  نویسه c = 'a';
  تهی func1(نویسه c); /* param 'c' must not shadow local 'c' */
  func1(c);
  بازگشت 0;
}

تهی func1(نویسه c)
{
    myassert(c == 'a');
}

ساختار st { صحیح a; };

/* --------------------------------------------- */
صحیح main_3()
{
  ساختار st func(تهی);
  ساختار st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  بازگشت 0;
}

ساختار st func(تهی)
{
  ساختار st st = { 10 };
  بازگشت st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
ایستا تهی f4(نویسه *(*md)(نویسه *md))
{
   (*md)("test");
}
ایستا نویسه *a4(نویسه *a)
{
    صحیح strcmp();
    myassert(!strcmp(a, "test"));
    بازگشت a;
}

صحیح main_4()
{
    f4(a4);
    بازگشت 0;
}

/* --------------------------------------------- */
صحیح a5[3], b5[];
صحیح f5(تهی);
صحیح main_5()
{
    بیرونی صحیح a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    بازگشت 0;
}
صحیح f5(تهی)
{
    بازگشت a5[2]+b5[2];
}
صحیح b5[3];

/* --------------------------------------------- */
ایستا صحیح f6(صحیح);
صحیح i6 = 11;

صحیح main_6()
{
    {
        صحیح i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            صحیح f6(صحیح);
            بیرونی صحیح i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    بازگشت 0;
}

صحیح f6(صحیح x)
{
    بازگشت x;
}

/* --------------------------------------------- */

#اگر defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#وگرنه
# define _ "_"
#endif

ساختار xx7 { صحیح a, b; };

تهی f7()
{
    ساختار xx7 { صحیح c; } x;
    {
        بیرونی ساختار xx7 { صحیح a, b; } x __asm__(_"z7");
        x.a = 12;
        ساختار xx7 y = { 0,0 };
    }
    ساختار xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

صحیح main_7()
{
    f7();
    بیرونی ساختار xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    بازگشت 0;
}


ساختار xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
صحیح اصلی()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    بازگشت 0;
}
