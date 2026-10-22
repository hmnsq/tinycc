પૂર્ણાંક printf(અચલ અક્ષર*, ...);

#define myassert(x) \
    printf("%s:%d: %s : \"%s\"\n", __FILE__,__LINE__,(x)?"ok":"error",#x)

ગણના{ in = 0};

પૂર્ણાંક main_1(){
    {
        myassert(!in);
        જો(કદ(ગણના{in=1})) myassert(in);
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        પસંદગી(કદ(ગણના{in=1})) { મૂળભૂત: myassert(in); }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        જ્યારે(કદ(ગણના{in=1})) { myassert(in); તોડો; }
        myassert(!in); //OOPS
    }
    {
        myassert(!in);
        કરો{ myassert(!in);}જ્યારે(0*કદ(ગણના{in=1}));
        myassert(!in); //OOPS
    }

    {
        myassert(!in);
        માટે(કદ(ગણના{in=1});;){ myassert(in); તોડો; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        માટે(;;કદ(ગણના{in=1})){ myassert(in); તોડો; }
        myassert(!in); //OK
    }
    {
        myassert(!in);
        માટે(;કદ(ગણના{in=1});){ myassert(in); તોડો; }
        myassert(!in); //OK
    }
    પાછા 0;
}

/* --------------------------------------------- */
પૂર્ણાંક main_2()
{
  અક્ષર c = 'a';
  શૂન્ય func1(અક્ષર c); /* param 'c' must not shadow local 'c' */
  func1(c);
  પાછા 0;
}

શૂન્ય func1(અક્ષર c)
{
    myassert(c == 'a');
}

સંરચના st { પૂર્ણાંક a; };

/* --------------------------------------------- */
પૂર્ણાંક main_3()
{
  સંરચના st func(શૂન્ય);
  સંરચના st st = func(); /* not an 'incompatible redefinition' */
  myassert(st.a == 10);
  પાછા 0;
}

સંરચના st func(શૂન્ય)
{
  સંરચના st st = { 10 };
  પાછા st;
}

/* --------------------------------------------- */
/* func* 'md' must not be shadowed by param 'md' */
સ્થિર શૂન્ય f4(અક્ષર *(*md)(અક્ષર *md))
{
   (*md)("test");
}
સ્થિર અક્ષર *a4(અક્ષર *a)
{
    પૂર્ણાંક strcmp();
    myassert(!strcmp(a, "test"));
    પાછા a;
}

પૂર્ણાંક main_4()
{
    f4(a4);
    પાછા 0;
}

/* --------------------------------------------- */
પૂર્ણાંક a5[3], b5[];
પૂર્ણાંક f5(શૂન્ય);
પૂર્ણાંક main_5()
{
    બાહ્ય પૂર્ણાંક a5[3], b5[3];
    a5[2]=10, b5[2]=4;
    myassert(f5() == 10 + 4);
    પાછા 0;
}
પૂર્ણાંક f5(શૂન્ય)
{
    પાછા a5[2]+b5[2];
}
પૂર્ણાંક b5[3];

/* --------------------------------------------- */
સ્થિર પૂર્ણાંક f6(પૂર્ણાંક);
પૂર્ણાંક i6 = 11;

પૂર્ણાંક main_6()
{
    {
        પૂર્ણાંક i6 = 33, f6 = 44;
        myassert(i6 == 33 && f6 == 44);
        {
            પૂર્ણાંક f6(પૂર્ણાંક);
            બાહ્ય પૂર્ણાંક i6;
            myassert(i6 == 11 && f6(22) == 22);
        }
        myassert(i6 == 33 && f6 == 44);
    }
    myassert(i6 == 11 && f6(22) == 22);
    પાછા 0;
}

પૂર્ણાંક f6(પૂર્ણાંક x)
{
    પાછા x;
}

/* --------------------------------------------- */

#જો defined __TINYC__ \
    ? !defined __leading_underscore \
    : !(defined __APPLE__ || defined _WIN32)
# define _
#નહીંતર
# define _ "_"
#endif

સંરચના xx7 { પૂર્ણાંક a, b; };

શૂન્ય f7()
{
    સંરચના xx7 { પૂર્ણાંક c; } x;
    {
        બાહ્ય સંરચના xx7 { પૂર્ણાંક a, b; } x __asm__(_"z7");
        x.a = 12;
        સંરચના xx7 y = { 0,0 };
    }
    સંરચના xx7 y = { 90 };
    x.c = 78;
    printf("xx7 (1) : %d %d\n", x.c, y.c);
}

પૂર્ણાંક main_7()
{
    f7();
    બાહ્ય સંરચના xx7 y __asm__(_"z7");
    printf("xx7 (2) : %d %d\n", y.a, y.b);
    પાછા 0;
}


સંરચના xx7 z7 = { 0, 34 };

/* --------------------------------------------- */
પૂર્ણાંક મુખ્ય()
{
    main_1();
    main_2();
    main_3();
    main_4();
    main_5();
    main_6();
    main_7();
    પાછા 0;
}
