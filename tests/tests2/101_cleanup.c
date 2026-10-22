बाह्य पूर्णांक म_लिखो(स्थिर अक्षर*, ...);
अटल पूर्णांक glob_i = 0;

प्रकार काष्ठा { पूर्णांक a; पूर्णांक b; पूर्णांक c; पूर्णांक d; पूर्णांक e; पूर्णांक f; पूर्णांक g; पूर्णांक h; } tstl;
प्रकार काष्ठा { पूर्णांक a; पूर्णांक b; पूर्णांक c; पूर्णांक d; } tsti;
प्रकार काष्ठा { द्विगुन a; द्विगुन b; } tstd;
प्रकार काष्ठा { दीर्घ द्विगुन a; } tstld;
प्रकार काष्ठा { पूर्णांक a; द्विगुन b; } tstm;
प्रकार काष्ठा { भग्न a; भग्न b; भग्न c; भग्न d; } tstf;

व्योम incr_glob_i(पूर्णांक *i)
{
  glob_i += *i;
  *i = -1;
}

#घोषणा INCR_GI {						\
    पूर्णांक i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#घोषणा INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#घोषणा INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#घोषणा INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#घोषणा INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#घोषणा INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#घोषणा INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#घोषणा INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#घोषणा INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


व्योम check2(अक्षर **hum);

व्योम check(पूर्णांक *j)
{
    अक्षर * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    पूर्णांक chk = 0;

    {
	अक्षर * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    म_लिखो("---- %d\n", chk);
	}
	अगर (!chk) {
	    chk = 1;
	    जाओ non_plopage;
	}
    }

    {
	अक्षर * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	जाओ out;
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

		जाओ out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    अगर (chk != 2)
	जाओ again;
    {
	{
	    अक्षर * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    अगर (chk != 3)
		जाओ out;
	}
    }
    *j = -1;
    वापस;
}

व्योम check_oh_i(अक्षर *oh_i)
{
    म_लिखो("c: %c\n", *oh_i);
    *oh_i = '0';
}

व्योम goto_hell(द्विगुन *f)
{
    म_लिखो("oo: %f\n", *f);
    *f = -1.0;
}

अक्षर *test()
{
    अक्षर *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    वापस str;
}

व्योम test_ret_subcall(अक्षर *that)
{
    म_लिखो("should be print before\n");
}

व्योम test_ret()
{
    अक्षर *__attribute__ ((cleanup(check2))) that = "that";
    वापस test_ret_subcall(that);
}

व्योम test_ret2()
{
  अक्षर *__attribute__ ((cleanup(check2))) that = "-that";
  {
    अक्षर *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    अक्षर *__attribute__ ((cleanup(check2))) that = "-that2";
    वापस;
  }
}

व्योम test2(व्योम) {
    पूर्णांक chk = 0;
again:
    अगर (!chk) {
        अक्षर * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        जाओ again;
    }
}

पूर्णांक test3(व्योम) {
    अक्षर * __attribute__ ((cleanup(check2))) stop_that = "three";
    पूर्णांक chk = 0;

    अगर (chk) {
        {
          outside:
	    {
            अक्षर * __attribute__ ((cleanup(check2))) stop_that = "two";
            म_लिखो("---- %d\n", chk);
	    }
        }
    }
    अगर (!chk)
    {
        अक्षर * __attribute__ ((cleanup(check2))) stop_that = "one";

        अगर (!chk) {
            chk = 1;
            जाओ outside;
        }
    }
    वापस 0;
}

व्योम cl(पूर्णांक *ip)
{
    म_लिखो("%d\n", *ip);
    *ip = -1;
}

व्योम loop_cleanups(व्योम)
{
    __attribute__((cleanup(cl))) पूर्णांक l = 1000;

    म_लिखो("-- loop 0 --\n");
    क्रम ( __attribute__((cleanup(cl))) पूर्णांक i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) पूर्णांक j = 100;
    }

    म_लिखो("-- loop 1 --\n");
    क्रम (__attribute__((cleanup(cl))) पूर्णांक i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  पूर्णांक j = 200;
        जारी;
    }

    म_लिखो("-- loop 2 --\n");
    क्रम (__attribute__((cleanup(cl))) पूर्णांक i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) पूर्णांक j = 300;
        अवरोध;
    }

    म_लिखो("-- loop 3 --\n");
    क्रम (पूर्णांक i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) पूर्णांक j = 400;
	चयन (i) {
	हाल 0:
	    जारी;
	शेष:
	{
	    __attribute__((cleanup(cl))) पूर्णांक jj = 500;
	    अवरोध;
	}
	}
    }
    म_लिखो("after break\n");
}

व्योम my_cleanup1(पूर्णांक *p) {
    म_लिखो("%d\n", *p);
    *p = 0x90;
}

पूर्णांक test_cleanup1(व्योम) {
    पूर्णांक __attribute__((cleanup(my_cleanup1))) n = 42;
    वापस n;
}

व्योम my_cleanup2(tstl *p) {
    म_लिखो("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(व्योम) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    वापस n;
}

व्योम my_cleanup3(tsti *p) {
    म_लिखो("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(व्योम) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    वापस n;
}

व्योम my_cleanup4(tstd *p) {
    म_लिखो("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(व्योम) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    वापस n;
}

व्योम my_cleanup5(tstld *p) {
    म_लिखो("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(व्योम) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    वापस n;
}

व्योम my_cleanup6(tstm *p) {
    म_लिखो("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(व्योम) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    वापस n;
}

व्योम my_cleanup7(tstf *p) {
    म_लिखो("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(व्योम) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    वापस n;
}

व्योम my_cleanup8(पूर्णांक **p) {
    **p = 0x90;
}

पूर्णांक test_cleanup8(व्योम) {
    पूर्णांक n = 42;
    पूर्णांक __attribute__((cleanup(my_cleanup8))) *p = &n;
    वापस n;
}

अटल व्योम my_cleanupe(पूर्णांक *p) {
    *p = 0x90;
}

पूर्णांक मुख्य()
{
    पूर्णांक i __attribute__ ((__cleanup__(check))) = 0, not_i;
    पूर्णांक chk = 0;
    (व्योम)not_i;
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
    अगर (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) अक्षर oh_i = 'f';
	द्विगुन __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	जाओ naaaaaaaa;
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
    वापस i;
}

व्योम check2(अक्षर **hum)
{
    म_लिखो("str: %s\n", *hum);
    *hum = "fail";
}
