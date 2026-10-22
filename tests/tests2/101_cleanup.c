বাহ্য পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ*, ...);
স্থির পূর্ণাঙ্ক glob_i = 0;

প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক a; পূর্ণাঙ্ক b; পূর্ণাঙ্ক c; পূর্ণাঙ্ক d; পূর্ণাঙ্ক e; পূর্ণাঙ্ক f; পূর্ণাঙ্ক g; পূর্ণাঙ্ক h; } tstl;
প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক a; পূর্ণাঙ্ক b; পূর্ণাঙ্ক c; পূর্ণাঙ্ক d; } tsti;
প্রকারনির্দেশ সংরচনা { দ্ৱিগুণ a; দ্ৱিগুণ b; } tstd;
প্রকারনির্দেশ সংরচনা { long দ্ৱিগুণ a; } tstld;
প্রকারনির্দেশ সংরচনা { পূর্ণাঙ্ক a; দ্ৱিগুণ b; } tstm;
প্রকারনির্দেশ সংরচনা { ভিন্ন a; ভিন্ন b; ভিন্ন c; ভিন্ন d; } tstf;

শূন্য incr_glob_i(পূর্ণাঙ্ক *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    পূর্ণাঙ্ক i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


শূন্য check2(ৱর্ণ **hum);

শূন্য check(পূর্ণাঙ্ক *j)
{
    ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    পূর্ণাঙ্ক chk = 0;

    {
	ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	যদি (!chk) {
	    chk = 1;
	    গচ্ছ non_plopage;
	}
    }

    {
	ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	গচ্ছ out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	ৱর্ণ * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    ৱর্ণ * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		ৱর্ণ * __attribute__ ((cleanup(check2))) cascade3 = "3";

		গচ্ছ out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    যদি (chk != 2)
	গচ্ছ again;
    {
	{
	    ৱর্ণ * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    যদি (chk != 3)
		গচ্ছ out;
	}
    }
    *j = -1;
    ঘূৰাই;
}

শূন্য check_oh_i(ৱর্ণ *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

শূন্য goto_hell(দ্ৱিগুণ *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

ৱর্ণ *test()
{
    ৱর্ণ *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ঘূৰাই str;
}

শূন্য test_ret_subcall(ৱর্ণ *that)
{
    printf("should be print before\n");
}

শূন্য test_ret()
{
    ৱর্ণ *__attribute__ ((cleanup(check2))) that = "that";
    ঘূৰাই test_ret_subcall(that);
}

শূন্য test_ret2()
{
  ৱর্ণ *__attribute__ ((cleanup(check2))) that = "-that";
  {
    ৱর্ণ *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    ৱর্ণ *__attribute__ ((cleanup(check2))) that = "-that2";
    ঘূৰাই;
  }
}

শূন্য test2(শূন্য) {
    পূর্ণাঙ্ক chk = 0;
again:
    যদি (!chk) {
        ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        গচ্ছ again;
    }
}

পূর্ণাঙ্ক test3(শূন্য) {
    ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "three";
    পূর্ণাঙ্ক chk = 0;

    যদি (chk) {
        {
          outside:
	    {
            ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    যদি (!chk)
    {
        ৱর্ণ * __attribute__ ((cleanup(check2))) stop_that = "one";

        যদি (!chk) {
            chk = 1;
            গচ্ছ outside;
        }
    }
    ঘূৰাই 0;
}

শূন্য cl(পূর্ণাঙ্ক *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

শূন্য loop_cleanups(শূন্য)
{
    __attribute__((cleanup(cl))) পূর্ণাঙ্ক l = 1000;

    printf("-- loop 0 --\n");
    বাবে ( __attribute__((cleanup(cl))) পূর্ণাঙ্ক i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) পূর্ণাঙ্ক j = 100;
    }

    printf("-- loop 1 --\n");
    বাবে (__attribute__((cleanup(cl))) পূর্ণাঙ্ক i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  পূর্ণাঙ্ক j = 200;
        অনুৱর্ত;
    }

    printf("-- loop 2 --\n");
    বাবে (__attribute__((cleanup(cl))) পূর্ণাঙ্ক i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) পূর্ণাঙ্ক j = 300;
        ভঙ্গ;
    }

    printf("-- loop 3 --\n");
    বাবে (পূর্ণাঙ্ক i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) পূর্ণাঙ্ক j = 400;
	ৱিকল্প (i) {
	পক্ষ 0:
	    অনুৱর্ত;
	স্ৱভাৱ:
	{
	    __attribute__((cleanup(cl))) পূর্ণাঙ্ক jj = 500;
	    ভঙ্গ;
	}
	}
    }
    printf("after break\n");
}

শূন্য my_cleanup1(পূর্ণাঙ্ক *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

পূর্ণাঙ্ক test_cleanup1(শূন্য) {
    পূর্ণাঙ্ক __attribute__((cleanup(my_cleanup1))) n = 42;
    ঘূৰাই n;
}

শূন্য my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(শূন্য) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    ঘূৰাই n;
}

শূন্য my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(শূন্য) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ঘূৰাই n;
}

শূন্য my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(শূন্য) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ঘূৰাই n;
}

শূন্য my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(শূন্য) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ঘূৰাই n;
}

শূন্য my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(শূন্য) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    ঘূৰাই n;
}

শূন্য my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(শূন্য) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ঘূৰাই n;
}

শূন্য my_cleanup8(পূর্ণাঙ্ক **p) {
    **p = 0x90;
}

পূর্ণাঙ্ক test_cleanup8(শূন্য) {
    পূর্ণাঙ্ক n = 42;
    পূর্ণাঙ্ক __attribute__((cleanup(my_cleanup8))) *p = &n;
    ঘূৰাই n;
}

স্থির শূন্য my_cleanupe(পূর্ণাঙ্ক *p) {
    *p = 0x90;
}

পূর্ণাঙ্ক main()
{
    পূর্ণাঙ্ক i __attribute__ ((__cleanup__(check))) = 0, not_i;
    পূর্ণাঙ্ক chk = 0;
    (শূন্য)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) ৱর্ণ oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    যদি (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) ৱর্ণ oh_i = 'f';
	দ্ৱিগুণ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	গচ্ছ naaaaaaaa;
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
            পূর্ণাঙ্ক __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ঘূৰাই i;
}

শূন্য check2(ৱর্ণ **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
