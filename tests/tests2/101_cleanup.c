బాహ్య పూర్ణాంకం రాయి(స్థిరరాశి అక్షరం*, ...);
స్థిర పూర్ణాంకం glob_i = 0;

రకనిర్వచనం నిర్మాణం { పూర్ణాంకం a; పూర్ణాంకం b; పూర్ణాంకం c; పూర్ణాంకం d; పూర్ణాంకం e; పూర్ణాంకం f; పూర్ణాంకం g; పూర్ణాంకం h; } tstl;
రకనిర్వచనం నిర్మాణం { పూర్ణాంకం a; పూర్ణాంకం b; పూర్ణాంకం c; పూర్ణాంకం d; } tsti;
రకనిర్వచనం నిర్మాణం { ద్విగుణ a; ద్విగుణ b; } tstd;
రకనిర్వచనం నిర్మాణం { దీర్ఘ ద్విగుణ a; } tstld;
రకనిర్వచనం నిర్మాణం { పూర్ణాంకం a; ద్విగుణ b; } tstm;
రకనిర్వచనం నిర్మాణం { దశాంశం a; దశాంశం b; దశాంశం c; దశాంశం d; } tstf;

శూన్య incr_glob_i(పూర్ణాంకం *i)
{
  glob_i += *i;
  *i = -1;
}

#నిర్వచించు INCR_GI {						\
    పూర్ణాంకం i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#నిర్వచించు INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#నిర్వచించు INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#నిర్వచించు INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#నిర్వచించు INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#నిర్వచించు INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#నిర్వచించు INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#నిర్వచించు INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#నిర్వచించు INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


శూన్య check2(అక్షరం **hum);

శూన్య check(పూర్ణాంకం *j)
{
    అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    పూర్ణాంకం chk = 0;

    {
	అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    రాయి("---- %d\n", chk);
	}
	ఒకవేళ (!chk) {
	    chk = 1;
	    వెళ్ళు non_plopage;
	}
    }

    {
	అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	వెళ్ళు బహిర్గతం;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	అక్షరం * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    అక్షరం * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		అక్షరం * __attribute__ ((cleanup(check2))) cascade3 = "3";

		వెళ్ళు బహిర్గతం;
		cascade3 = "nope";
	    }
	}
    }
  బహిర్గతం:
    ఒకవేళ (chk != 2)
	వెళ్ళు again;
    {
	{
	    అక్షరం * __attribute__ ((cleanup(check2))) బహిర్గతం = "last goto out";
	    ++chk;
	    ఒకవేళ (chk != 3)
		వెళ్ళు బహిర్గతం;
	}
    }
    *j = -1;
    తిరిగి;
}

శూన్య check_oh_i(అక్షరం *oh_i)
{
    రాయి("c: %c\n", *oh_i);
    *oh_i = '0';
}

శూన్య goto_hell(ద్విగుణ *f)
{
    రాయి("oo: %f\n", *f);
    *f = -1.0;
}

అక్షరం *test()
{
    అక్షరం *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    తిరిగి str;
}

శూన్య test_ret_subcall(అక్షరం *that)
{
    రాయి("should be print before\n");
}

శూన్య test_ret()
{
    అక్షరం *__attribute__ ((cleanup(check2))) that = "that";
    తిరిగి test_ret_subcall(that);
}

శూన్య test_ret2()
{
  అక్షరం *__attribute__ ((cleanup(check2))) that = "-that";
  {
    అక్షరం *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    అక్షరం *__attribute__ ((cleanup(check2))) that = "-that2";
    తిరిగి;
  }
}

శూన్య test2(శూన్య) {
    పూర్ణాంకం chk = 0;
again:
    ఒకవేళ (!chk) {
        అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        వెళ్ళు again;
    }
}

పూర్ణాంకం test3(శూన్య) {
    అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "three";
    పూర్ణాంకం chk = 0;

    ఒకవేళ (chk) {
        {
          outside:
	    {
            అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "two";
            రాయి("---- %d\n", chk);
	    }
        }
    }
    ఒకవేళ (!chk)
    {
        అక్షరం * __attribute__ ((cleanup(check2))) stop_that = "one";

        ఒకవేళ (!chk) {
            chk = 1;
            వెళ్ళు outside;
        }
    }
    తిరిగి 0;
}

శూన్య cl(పూర్ణాంకం *ip)
{
    రాయి("%d\n", *ip);
    *ip = -1;
}

శూన్య loop_cleanups(శూన్య)
{
    __attribute__((cleanup(cl))) పూర్ణాంకం l = 1000;

    రాయి("-- loop 0 --\n");
    కొరకు ( __attribute__((cleanup(cl))) పూర్ణాంకం i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) పూర్ణాంకం j = 100;
    }

    రాయి("-- loop 1 --\n");
    కొరకు (__attribute__((cleanup(cl))) పూర్ణాంకం i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  పూర్ణాంకం j = 200;
        కొనసాగు;
    }

    రాయి("-- loop 2 --\n");
    కొరకు (__attribute__((cleanup(cl))) పూర్ణాంకం i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) పూర్ణాంకం j = 300;
        ఆపు;
    }

    రాయి("-- loop 3 --\n");
    కొరకు (పూర్ణాంకం i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) పూర్ణాంకం j = 400;
	ఎంపిక (i) {
	స్థితి 0:
	    కొనసాగు;
	అప్రమేయ:
	{
	    __attribute__((cleanup(cl))) పూర్ణాంకం jj = 500;
	    ఆపు;
	}
	}
    }
    రాయి("after break\n");
}

శూన్య my_cleanup1(పూర్ణాంకం *p) {
    రాయి("%d\n", *p);
    *p = 0x90;
}

పూర్ణాంకం test_cleanup1(శూన్య) {
    పూర్ణాంకం __attribute__((cleanup(my_cleanup1))) n = 42;
    తిరిగి n;
}

శూన్య my_cleanup2(tstl *p) {
    రాయి("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(శూన్య) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    తిరిగి n;
}

శూన్య my_cleanup3(tsti *p) {
    రాయి("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(శూన్య) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    తిరిగి n;
}

శూన్య my_cleanup4(tstd *p) {
    రాయి("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(శూన్య) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    తిరిగి n;
}

శూన్య my_cleanup5(tstld *p) {
    రాయి("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(శూన్య) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    తిరిగి n;
}

శూన్య my_cleanup6(tstm *p) {
    రాయి("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(శూన్య) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    తిరిగి n;
}

శూన్య my_cleanup7(tstf *p) {
    రాయి("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(శూన్య) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    తిరిగి n;
}

శూన్య my_cleanup8(పూర్ణాంకం **p) {
    **p = 0x90;
}

పూర్ణాంకం test_cleanup8(శూన్య) {
    పూర్ణాంకం n = 42;
    పూర్ణాంకం __attribute__((cleanup(my_cleanup8))) *p = &n;
    తిరిగి n;
}

స్థిర శూన్య my_cleanupe(పూర్ణాంకం *p) {
    *p = 0x90;
}

పూర్ణాంకం ప్రధాన()
{
    పూర్ణాంకం i __attribute__ ((__cleanup__(check))) = 0, not_i;
    పూర్ణాంకం chk = 0;
    (శూన్య)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) అక్షరం oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    రాయి("glob_i: %d\n", glob_i);
 naaaaaaaa:
    ఒకవేళ (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) అక్షరం oh_i = 'f';
	ద్విగుణ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	వెళ్ళు naaaaaaaa;
    }
    i = 105;
    రాయి("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    రాయి("%d\n", test_cleanup1());
    tl = test_cleanup2();
    రాయి("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    రాయి("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    రాయి("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    రాయి("%Lf\n", tld.a);
    tm = test_cleanup6();
    రాయి("%d %g\n", tm.a, tm.b);
    tf = test_cleanup7();
    రాయి("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    రాయి("%d\n", test_cleanup8());
    రాయి("%d\n", ({
            పూర్ణాంకం __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    తిరిగి i;
}

శూన్య check2(అక్షరం **hum)
{
    రాయి("str: %s\n", *hum);
    *hum = "fail";
}
