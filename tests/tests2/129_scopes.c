целое printf(const char*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

enum{ in = 0};

целое main_1(){
    {
        myassert(!in);
        если(sizeof(enum{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        switch(sizeof(enum{in=1})) { default: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        пока(sizeof(enum{in=1})) { myassert(in); break; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        do{ myassert(!in);}пока(0*sizeof(enum{in=1}));
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
    вернуть 0;
}

/* --------------------------------------------- */
целое main_2()
{
  char c = 'a';
  void func1(char c); /* param 'c' must not shadow local 'c' */
  func1(c);
  вернуть 0;
}

void func1(char c)
{
    myassert(c == 'a');
}

struct st { целое a; };

/* --------------------------------------------- */
целое main_3()
{
  struct st func(void);
  struct st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  вернуть 0;
}

struct st func(void)
{
  struct st st = { 10 };
  вернуть st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
static void f4(char *(*md)(char *md))
{
   (*md)("test");
}
static char *a4(char *a)
{
    целое strcmp();
    myassert(!strcmp(a, "test"));
    вернуть a;
}

целое main_4()
{
    f4(a4);
    вернуть 0;
}

/* --------------------------------------------- */
целое a5[3], b5[];
целое f5(void);
целое main_5()
{
    extern целое a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    вернуть 0;
}
целое f5(void)
{
    вернуть a5[2]+b5[2];
}
целое b5[3];

/* --------------------------------------------- */
static целое f6(целое);
целое i6 = 11;

целое main_6()
{
    {
        целое i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            целое f6(целое);
            extern целое i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    вернуть 0;
}

целое f6(целое x)
{
    вернуть x;
}

/* --------------------------------------------- */

#если defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#иначе
# define _ "_"
#endif

struct xx7 { целое a, b; };

void f7()
{
    struct xx7 { целое c; } x;
    {
        extern struct xx7 { целое a, b; } x __asm__(_"z7");
        x.a = 12;
        struct xx7 y = { 0,0 };
    }
    struct xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

целое main_7()
{
    f7();
    extern struct xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    вернуть 0;
}


struct xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
целое основной()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    вернуть 0;
}
