बाह्य पूर्णांक म_लिखो(स्थिरांक अक्षर*, ...);
स्थिर पूर्णांक glob_i = 0;

प्रकारव्याख्या संरचना { पूर्णांक a; पूर्णांक b; पूर्णांक c; पूर्णांक d; पूर्णांक e; पूर्णांक f; पूर्णांक g; पूर्णांक h; } tstl;
प्रकारव्याख्या संरचना { पूर्णांक a; पूर्णांक b; पूर्णांक c; पूर्णांक d; } tsti;
प्रकारव्याख्या संरचना { द्विगुण a; द्विगुण b; } tstd;
प्रकारव्याख्या संरचना { दीर्घ द्विगुण a; } tstld;
प्रकारव्याख्या संरचना { पूर्णांक a; द्विगुण b; } tstm;
प्रकारव्याख्या संरचना { दशांश a; दशांश b; दशांश c; दशांश d; } tstf;

शून्य incr_glob_i(पूर्णांक *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    पूर्णांक i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


शून्य check2(अक्षर **hum);

शून्य check(पूर्णांक *j)
{
    अक्षर * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    पूर्णांक chk = 0;

    {
	अक्षर * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    म_लिखो("---- %d\n", chk);
	}
	जर (!chk) {
	    chk = 1;
	    जा non_plopage;
	}
    }

    {
	अक्षर * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	जा out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	अक्षर * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    अक्षर * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		अक्षर * __attribute__ ((cleanup(check2))) cascade3 = "3";

		जा out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    जर (chk != 2)
	जा again;
    {
	{
	    अक्षर * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    जर (chk != 3)
		जा out;
	}
    }
    *j = -1;
    परत;
}

शून्य check_oh_i(अक्षर *oh_i)
{
    म_लिखो("c: %c\n", *oh_i);
    *oh_i = '0';
}

शून्य goto_hell(द्विगुण *f)
{
    म_लिखो("oo: %f\n", *f);
    *f = -1.0;
}

अक्षर *test()
{
    अक्षर *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    परत str;
}

शून्य test_ret_subcall(अक्षर *that)
{
    म_लिखो("should be print before\n");
}

शून्य test_ret()
{
    अक्षर *__attribute__ ((cleanup(check2))) that = "that";
    परत test_ret_subcall(that);
}

शून्य test_ret2()
{
  अक्षर *__attribute__ ((cleanup(check2))) that = "-that";
  {
    अक्षर *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    अक्षर *__attribute__ ((cleanup(check2))) that = "-that2";
    परत;
  }
}

शून्य test2(शून्य) {
    पूर्णांक chk = 0;
again:
    जर (!chk) {
        अक्षर * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        जा again;
    }
}

पूर्णांक test3(शून्य) {
    अक्षर * __attribute__ ((cleanup(check2))) stop_that = "three";
    पूर्णांक chk = 0;

    जर (chk) {
        {
          outside:
	    {
            अक्षर * __attribute__ ((cleanup(check2))) stop_that = "two";
            म_लिखो("---- %d\n", chk);
	    }
        }
    }
    जर (!chk)
    {
        अक्षर * __attribute__ ((cleanup(check2))) stop_that = "one";

        जर (!chk) {
            chk = 1;
            जा outside;
        }
    }
    परत 0;
}

शून्य cl(पूर्णांक *ip)
{
    म_लिखो("%d\n", *ip);
    *ip = -1;
}

शून्य loop_cleanups(शून्य)
{
    __attribute__((cleanup(cl))) पूर्णांक l = 1000;

    म_लिखो("-- loop 0 --\n");
    साठी ( __attribute__((cleanup(cl))) पूर्णांक i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) पूर्णांक j = 100;
    }

    म_लिखो("-- loop 1 --\n");
    साठी (__attribute__((cleanup(cl))) पूर्णांक i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  पूर्णांक j = 200;
        सुरूठेवा;
    }

    म_लिखो("-- loop 2 --\n");
    साठी (__attribute__((cleanup(cl))) पूर्णांक i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) पूर्णांक j = 300;
        थांबा;
    }

    म_लिखो("-- loop 3 --\n");
    साठी (पूर्णांक i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) पूर्णांक j = 400;
	निवड (i) {
	स्थिती 0:
	    सुरूठेवा;
	पूर्वनिर्धारित:
	{
	    __attribute__((cleanup(cl))) पूर्णांक jj = 500;
	    थांबा;
	}
	}
    }
    म_लिखो("after break\n");
}

शून्य my_cleanup1(पूर्णांक *p) {
    म_लिखो("%d\n", *p);
    *p = 0x90;
}

पूर्णांक test_cleanup1(शून्य) {
    पूर्णांक __attribute__((cleanup(my_cleanup1))) n = 42;
    परत n;
}

शून्य my_cleanup2(tstl *p) {
    म_लिखो("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(शून्य) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    परत n;
}

शून्य my_cleanup3(tsti *p) {
    म_लिखो("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(शून्य) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    परत n;
}

शून्य my_cleanup4(tstd *p) {
    म_लिखो("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(शून्य) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    परत n;
}

शून्य my_cleanup5(tstld *p) {
    म_लिखो("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(शून्य) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    परत n;
}

शून्य my_cleanup6(tstm *p) {
    म_लिखो("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(शून्य) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    परत n;
}

शून्य my_cleanup7(tstf *p) {
    म_लिखो("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(शून्य) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    परत n;
}

शून्य my_cleanup8(पूर्णांक **p) {
    **p = 0x90;
}

पूर्णांक test_cleanup8(शून्य) {
    पूर्णांक n = 42;
    पूर्णांक __attribute__((cleanup(my_cleanup8))) *p = &n;
    परत n;
}

स्थिर शून्य my_cleanupe(पूर्णांक *p) {
    *p = 0x90;
}

पूर्णांक main()
{
    पूर्णांक i __attribute__ ((__cleanup__(check))) = 0, not_i;
    पूर्णांक chk = 0;
    (शून्य)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm पंचांग;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) अक्षर oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    म_लिखो("glob_i: %d\n", glob_i);
 naaaaaaaa:
    जर (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) अक्षर oh_i = 'f';
	द्विगुण __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	जा naaaaaaaa;
    }
    i = 105;
    म_लिखो("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    म_लिखो("%d\n", test_cleanup1());
    tl = test_cleanup2();
    म_लिखो("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    म_लिखो("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    म_लिखो("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    म_लिखो("%Lf\n", tld.a);
    पंचांग = test_cleanup6();
    म_लिखो("%d %g\n", पंचांग.a, पंचांग.b);
    tf = test_cleanup7();
    म_लिखो("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    म_लिखो("%d\n", test_cleanup8());
    म_लिखो("%d\n", ({
            पूर्णांक __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    परत i;
}

शून्य check2(अक्षर **hum)
{
    म_लिखो("str: %s\n", *hum);
    *hum = "fail";
}
