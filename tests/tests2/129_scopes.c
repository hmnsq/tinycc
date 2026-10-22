정수 printf(const char*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

enum{ in = 0};

정수 main_1(){
    {
        myassert(!in);
        만약(sizeof(enum{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(sizeof(enum{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        동안(sizeof(enum{in=1})) { myassert(in); break; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}동안(0*sizeof(enum{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        위해(sizeof(enum{in=1});;){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        위해(;;sizeof(enum{in=1})){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        위해(;sizeof(enum{in=1});){ myassert(in); break; }
        myassert(!in); //OK
    }
    반환 0;
}

/* --------------------------------------------- */
정수 main_2()
{
  char c = 'a';
  void func1(char c); /* param 'c' must not shadow local 'c' */
  func1(c);
  반환 0;
}

void func1(char c)
{
    myassert(c == 'a');
}

struct st { 정수 a; };

/* --------------------------------------------- */
정수 main_3()
{
  struct st func(void);
  struct st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  반환 0;
}

struct st func(void)
{
  struct st st = { 10 };
  반환 st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(char *(*md)(char *md))
{
   (*md)("test");
}
static char *a4(char *a)
{
    정수 strcmp();
    myassert(!strcmp(a, "test"));
    반환 a;
}

정수 main_4()
{
    f4(a4);
    반환 0;
}

/* --------------------------------------------- */
정수 a5[3], b5[];
정수 f5(void);
정수 main_5()
{
    extern 정수 a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    반환 0;
}
정수 f5(void)
{
    반환 a5[2]+b5[2];
}
정수 b5[3];

/* --------------------------------------------- */
static 정수 f6(정수);
정수 i6 = 11;

정수 main_6()
{
    {
        정수 i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            정수 f6(정수);
            extern 정수 i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    반환 0;
}

정수 f6(정수 x)
{
    반환 x;
}

/* --------------------------------------------- */

#만약 defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#아니면
# define _ "_"
#endif

struct xx7 { 정수 a, b; };

void f7()
{
    struct xx7 { 정수 c; } x;
    {
        extern struct xx7 { 정수 a, b; } x __asm__(_"z7");
        x.a = 12;
        struct xx7 y = { 0,0 };
    }
    struct xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

정수 main_7()
{
    f7();
    extern struct xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    반환 0;
}


struct xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
정수 main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    반환 0;
}
