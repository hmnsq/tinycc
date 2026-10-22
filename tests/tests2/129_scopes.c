整数 printf(const char*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

enum{ in = 0};

整数 main_1(){
    {
        myassert(!in);
        もし(sizeof(enum{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(sizeof(enum{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        ながら(sizeof(enum{in=1})) { myassert(in); break; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}ながら(0*sizeof(enum{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        ために(sizeof(enum{in=1});;){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        ために(;;sizeof(enum{in=1})){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        ために(;sizeof(enum{in=1});){ myassert(in); break; }
        myassert(!in); //OK
    }
    戻る 0;
}

/* --------------------------------------------- */
整数 main_2()
{
  char c = 'a';
  void func1(char c); /* param 'c' must not shadow local 'c' */
  func1(c);
  戻る 0;
}

void func1(char c)
{
    myassert(c == 'a');
}

struct st { 整数 a; };

/* --------------------------------------------- */
整数 main_3()
{
  struct st func(void);
  struct st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  戻る 0;
}

struct st func(void)
{
  struct st st = { 10 };
  戻る st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(char *(*md)(char *md))
{
   (*md)("test");
}
static char *a4(char *a)
{
    整数 strcmp();
    myassert(!strcmp(a, "test"));
    戻る a;
}

整数 main_4()
{
    f4(a4);
    戻る 0;
}

/* --------------------------------------------- */
整数 a5[3], b5[];
整数 f5(void);
整数 main_5()
{
    extern 整数 a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    戻る 0;
}
整数 f5(void)
{
    戻る a5[2]+b5[2];
}
整数 b5[3];

/* --------------------------------------------- */
static 整数 f6(整数);
整数 i6 = 11;

整数 main_6()
{
    {
        整数 i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            整数 f6(整数);
            extern 整数 i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    戻る 0;
}

整数 f6(整数 x)
{
    戻る x;
}

/* --------------------------------------------- */

#もし defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#否则
# define _ "_"
#endif

struct xx7 { 整数 a, b; };

void f7()
{
    struct xx7 { 整数 c; } x;
    {
        extern struct xx7 { 整数 a, b; } x __asm__(_"z7");
        x.a = 12;
        struct xx7 y = { 0,0 };
    }
    struct xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

整数 main_7()
{
    f7();
    extern struct xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    戻る 0;
}


struct xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
整数 メインページ()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    戻る 0;
}
