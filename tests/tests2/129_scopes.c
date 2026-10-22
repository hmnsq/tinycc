ціле printf(const char*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

enum{ in = 0};

ціле main_1(){
    {
        myassert(!in);
        якщо(sizeof(enum{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(sizeof(enum{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        поки(sizeof(enum{in=1})) { myassert(in); break; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}поки(0*sizeof(enum{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        для(sizeof(enum{in=1});;){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        для(;;sizeof(enum{in=1})){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        для(;sizeof(enum{in=1});){ myassert(in); break; }
        myassert(!in); //OK
    }
    повернути 0;
}

/* --------------------------------------------- */
ціле main_2()
{
  char c = 'a';
  void func1(char c); /* param 'c' must not shadow local 'c' */
  func1(c);
  повернути 0;
}

void func1(char c)
{
    myassert(c == 'a');
}

struct st { ціле a; };

/* --------------------------------------------- */
ціле main_3()
{
  struct st func(void);
  struct st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  повернути 0;
}

struct st func(void)
{
  struct st st = { 10 };
  повернути st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(char *(*md)(char *md))
{
   (*md)("test");
}
static char *a4(char *a)
{
    ціле strcmp();
    myassert(!strcmp(a, "test"));
    повернути a;
}

ціле main_4()
{
    f4(a4);
    повернути 0;
}

/* --------------------------------------------- */
ціле a5[3], b5[];
ціле f5(void);
ціле main_5()
{
    extern ціле a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    повернути 0;
}
ціле f5(void)
{
    повернути a5[2]+b5[2];
}
ціле b5[3];

/* --------------------------------------------- */
static ціле f6(ціле);
ціле i6 = 11;

ціле main_6()
{
    {
        ціле i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            ціле f6(ціле);
            extern ціле i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    повернути 0;
}

ціле f6(ціле x)
{
    повернути x;
}

/* --------------------------------------------- */

#якщо defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#інакше
# define _ "_"
#endif

struct xx7 { ціле a, b; };

void f7()
{
    struct xx7 { ціле c; } x;
    {
        extern struct xx7 { ціле a, b; } x __asm__(_"z7");
        x.a = 12;
        struct xx7 y = { 0,0 };
    }
    struct xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

ціле main_7()
{
    f7();
    extern struct xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    повернути 0;
}


struct xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
ціле main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    повернути 0;
}
