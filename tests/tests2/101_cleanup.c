બાહ્ય પૂર્ણાંક printf(અચલ અક્ષર*, ...);
સ્થિર પૂર્ણાંક glob_i = 0;

પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક a; પૂર્ણાંક b; પૂર્ણાંક c; પૂર્ણાંક d; પૂર્ણાંક e; પૂર્ણાંક f; પૂર્ણાંક g; પૂર્ણાંક h; } tstl;
પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક a; પૂર્ણાંક b; પૂર્ણાંક c; પૂર્ણાંક d; } tsti;
પ્રકારવ્યાખ્યા સંરચના { દ્વિગુણ a; દ્વિગુણ b; } tstd;
પ્રકારવ્યાખ્યા સંરચના { long દ્વિગુણ a; } tstld;
પ્રકારવ્યાખ્યા સંરચના { પૂર્ણાંક a; દ્વિગુણ b; } tstm;
પ્રકારવ્યાખ્યા સંરચના { દશાંશ a; દશાંશ b; દશાંશ c; દશાંશ d; } tstf;

શૂન્ય incr_glob_i(પૂર્ણાંક *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    પૂર્ણાંક i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


શૂન્ય check2(અક્ષર **hum);

શૂન્ય check(પૂર્ણાંક *j)
{
    અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    પૂર્ણાંક chk = 0;

    {
	અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	જો (!chk) {
	    chk = 1;
	    જાઓ non_plopage;
	}
    }

    {
	અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	જાઓ out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	અક્ષર * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    અક્ષર * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		અક્ષર * __attribute__ ((cleanup(check2))) cascade3 = "3";

		જાઓ out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    જો (chk != 2)
	જાઓ again;
    {
	{
	    અક્ષર * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    જો (chk != 3)
		જાઓ out;
	}
    }
    *j = -1;
    પાછા;
}

શૂન્ય check_oh_i(અક્ષર *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

શૂન્ય goto_hell(દ્વિગુણ *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

અક્ષર *test()
{
    અક્ષર *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    પાછા str;
}

શૂન્ય test_ret_subcall(અક્ષર *that)
{
    printf("should be print before\n");
}

શૂન્ય test_ret()
{
    અક્ષર *__attribute__ ((cleanup(check2))) that = "that";
    પાછા test_ret_subcall(that);
}

શૂન્ય test_ret2()
{
  અક્ષર *__attribute__ ((cleanup(check2))) that = "-that";
  {
    અક્ષર *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    અક્ષર *__attribute__ ((cleanup(check2))) that = "-that2";
    પાછા;
  }
}

શૂન્ય test2(શૂન્ય) {
    પૂર્ણાંક chk = 0;
again:
    જો (!chk) {
        અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        જાઓ again;
    }
}

પૂર્ણાંક test3(શૂન્ય) {
    અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "three";
    પૂર્ણાંક chk = 0;

    જો (chk) {
        {
          outside:
	    {
            અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    જો (!chk)
    {
        અક્ષર * __attribute__ ((cleanup(check2))) stop_that = "one";

        જો (!chk) {
            chk = 1;
            જાઓ outside;
        }
    }
    પાછા 0;
}

શૂન્ય cl(પૂર્ણાંક *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

શૂન્ય loop_cleanups(શૂન્ય)
{
    __attribute__((cleanup(cl))) પૂર્ણાંક l = 1000;

    printf("-- loop 0 --\n");
    માટે ( __attribute__((cleanup(cl))) પૂર્ણાંક i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) પૂર્ણાંક j = 100;
    }

    printf("-- loop 1 --\n");
    માટે (__attribute__((cleanup(cl))) પૂર્ણાંક i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  પૂર્ણાંક j = 200;
        ચાલુ;
    }

    printf("-- loop 2 --\n");
    માટે (__attribute__((cleanup(cl))) પૂર્ણાંક i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) પૂર્ણાંક j = 300;
        તોડો;
    }

    printf("-- loop 3 --\n");
    માટે (પૂર્ણાંક i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) પૂર્ણાંક j = 400;
	પસંદગી (i) {
	સ્થિતિ 0:
	    ચાલુ;
	મૂળભૂત:
	{
	    __attribute__((cleanup(cl))) પૂર્ણાંક jj = 500;
	    તોડો;
	}
	}
    }
    printf("after break\n");
}

શૂન્ય my_cleanup1(પૂર્ણાંક *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

પૂર્ણાંક test_cleanup1(શૂન્ય) {
    પૂર્ણાંક __attribute__((cleanup(my_cleanup1))) n = 42;
    પાછા n;
}

શૂન્ય my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(શૂન્ય) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    પાછા n;
}

શૂન્ય my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(શૂન્ય) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    પાછા n;
}

શૂન્ય my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(શૂન્ય) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    પાછા n;
}

શૂન્ય my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(શૂન્ય) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    પાછા n;
}

શૂન્ય my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(શૂન્ય) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    પાછા n;
}

શૂન્ય my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(શૂન્ય) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    પાછા n;
}

શૂન્ય my_cleanup8(પૂર્ણાંક **p) {
    **p = 0x90;
}

પૂર્ણાંક test_cleanup8(શૂન્ય) {
    પૂર્ણાંક n = 42;
    પૂર્ણાંક __attribute__((cleanup(my_cleanup8))) *p = &n;
    પાછા n;
}

સ્થિર શૂન્ય my_cleanupe(પૂર્ણાંક *p) {
    *p = 0x90;
}

પૂર્ણાંક મુખ્ય()
{
    પૂર્ણાંક i __attribute__ ((__cleanup__(check))) = 0, not_i;
    પૂર્ણાંક chk = 0;
    (શૂન્ય)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) અક્ષર oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    જો (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) અક્ષર oh_i = 'f';
	દ્વિગુણ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	જાઓ naaaaaaaa;
    }
    i = 105;
    printf("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    printf("%d\n", test_cleanup1());
    tl = test_cleanup2();
    printf("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    printf("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    printf("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    printf("%Lf\n", tld.a);
    tm = test_cleanup6();
    printf("%d %g\n", tm.a, tm.b);
    tf = test_cleanup7();
    printf("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    printf("%d\n", test_cleanup8());
    printf("%d\n", ({
            પૂર્ણાંક __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    પાછા i;
}

શૂન્ય check2(અક્ષર **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
