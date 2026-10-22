số_nguyên printf(const char*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

enum{ in = 0};

số_nguyên main_1(){
    {
        myassert(!in);
        nếu(sizeof(enum{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(sizeof(enum{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        trong_khi(sizeof(enum{in=1})) { myassert(in); break; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}trong_khi(0*sizeof(enum{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        cho(sizeof(enum{in=1});;){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        cho(;;sizeof(enum{in=1})){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        cho(;sizeof(enum{in=1});){ myassert(in); break; }
        myassert(!in); //OK
    }
    trả_về 0;
}

/* --------------------------------------------- */
số_nguyên main_2()
{
  char c = 'a';
  void func1(char c); /* param 'c' must not shadow local 'c' */
  func1(c);
  trả_về 0;
}

void func1(char c)
{
    myassert(c == 'a');
}

struct st { số_nguyên a; };

/* --------------------------------------------- */
số_nguyên main_3()
{
  struct st func(void);
  struct st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  trả_về 0;
}

struct st func(void)
{
  struct st st = { 10 };
  trả_về st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(char *(*md)(char *md))
{
   (*md)("test");
}
static char *a4(char *a)
{
    số_nguyên strcmp();
    myassert(!strcmp(a, "test"));
    trả_về a;
}

số_nguyên main_4()
{
    f4(a4);
    trả_về 0;
}

/* --------------------------------------------- */
số_nguyên a5[3], b5[];
số_nguyên f5(void);
số_nguyên main_5()
{
    extern số_nguyên a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    trả_về 0;
}
số_nguyên f5(void)
{
    trả_về a5[2]+b5[2];
}
số_nguyên b5[3];

/* --------------------------------------------- */
static số_nguyên f6(số_nguyên);
số_nguyên i6 = 11;

số_nguyên main_6()
{
    {
        số_nguyên i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            số_nguyên f6(số_nguyên);
            extern số_nguyên i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    trả_về 0;
}

số_nguyên f6(số_nguyên x)
{
    trả_về x;
}

/* --------------------------------------------- */

#nếu defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#không_thì
# define _ "_"
#endif

struct xx7 { số_nguyên a, b; };

void f7()
{
    struct xx7 { số_nguyên c; } x;
    {
        extern struct xx7 { số_nguyên a, b; } x __asm__(_"z7");
        x.a = 12;
        struct xx7 y = { 0,0 };
    }
    struct xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

số_nguyên main_7()
{
    f7();
    extern struct xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    trả_về 0;
}


struct xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
số_nguyên main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    trả_về 0;
}
