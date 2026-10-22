цео printf(const char*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

enum{ in = 0};

цео main_1(){
    {
        myassert(!in);
        ако(sizeof(enum{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(sizeof(enum{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        док(sizeof(enum{in=1})) { myassert(in); break; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}док(0*sizeof(enum{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        за(sizeof(enum{in=1});;){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        за(;;sizeof(enum{in=1})){ myassert(in); break; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        за(;sizeof(enum{in=1});){ myassert(in); break; }
        myassert(!in); //OK
    }
    врати 0;
}

/* --------------------------------------------- */
цео main_2()
{
  char c = 'a';
  void func1(char c); /* param 'c' must not shadow local 'c' */
  func1(c);
  врати 0;
}

void func1(char c)
{
    myassert(c == 'a');
}

struct st { цео a; };

/* --------------------------------------------- */
цео main_3()
{
  struct st func(void);
  struct st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  врати 0;
}

struct st func(void)
{
  struct st st = { 10 };
  врати st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(char *(*md)(char *md))
{
   (*md)("test");
}
static char *a4(char *a)
{
    цео strcmp();
    myassert(!strcmp(a, "test"));
    врати a;
}

цео main_4()
{
    f4(a4);
    врати 0;
}

/* --------------------------------------------- */
цео a5[3], b5[];
цео f5(void);
цео main_5()
{
    extern цео a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    врати 0;
}
цео f5(void)
{
    врати a5[2]+b5[2];
}
цео b5[3];

/* --------------------------------------------- */
static цео f6(цео);
цео i6 = 11;

цео main_6()
{
    {
        цео i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            цео f6(цео);
            extern цео i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    врати 0;
}

цео f6(цео x)
{
    врати x;
}

/* --------------------------------------------- */

#ако defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#инако
# define _ "_"
#endif

struct xx7 { цео a, b; };

void f7()
{
    struct xx7 { цео c; } x;
    {
        extern struct xx7 { цео a, b; } x __asm__(_"z7");
        x.a = 12;
        struct xx7 y = { 0,0 };
    }
    struct xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

цео main_7()
{
    f7();
    extern struct xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    врати 0;
}


struct xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
цео main()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    врати 0;
}
