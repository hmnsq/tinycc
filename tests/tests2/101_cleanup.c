ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ(ਅਚਲ ਅੱਖਰ*, ...);
ਸਥਿਰ ਪੂਰਨ glob_i = 0;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ a; ਪੂਰਨ b; ਪੂਰਨ c; ਪੂਰਨ d; ਪੂਰਨ e; ਪੂਰਨ f; ਪੂਰਨ g; ਪੂਰਨ h; } tstl;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ a; ਪੂਰਨ b; ਪੂਰਨ c; ਪੂਰਨ d; } tsti;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਦੁੱਗਣਾ a; ਦੁੱਗਣਾ b; } tstd;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਲੰਮਾ ਦੁੱਗਣਾ a; } tstld;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਪੂਰਨ a; ਦੁੱਗਣਾ b; } tstm;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ { ਦਸ਼ਮਲਵ a; ਦਸ਼ਮਲਵ b; ਦਸ਼ਮਲਵ c; ਦਸ਼ਮਲਵ d; } tstf;

ਖਾਲੀ incr_glob_i(ਪੂਰਨ *i)
{
  glob_i += *i;
  *i = -1;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI {						\
    ਪੂਰਨ i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


ਖਾਲੀ check2(ਅੱਖਰ **hum);

ਖਾਲੀ check(ਪੂਰਨ *j)
{
    ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    ਪੂਰਨ chk = 0;

    {
	ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    ਲਿਖੋ("---- %d\n", chk);
	}
	ਜੇ (!chk) {
	    chk = 1;
	    ਜਾਓ non_plopage;
	}
    }

    {
	ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	ਜਾਓ ਬਾਹਰਲਾ;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	ਅੱਖਰ * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    ਅੱਖਰ * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		ਅੱਖਰ * __attribute__ ((cleanup(check2))) cascade3 = "3";

		ਜਾਓ ਬਾਹਰਲਾ;
		cascade3 = "nope";
	    }
	}
    }
  ਬਾਹਰਲਾ:
    ਜੇ (chk != 2)
	ਜਾਓ again;
    {
	{
	    ਅੱਖਰ * __attribute__ ((cleanup(check2))) ਬਾਹਰਲਾ = "last goto out";
	    ++chk;
	    ਜੇ (chk != 3)
		ਜਾਓ ਬਾਹਰਲਾ;
	}
    }
    *j = -1;
    ਵਾਪਸ;
}

ਖਾਲੀ check_oh_i(ਅੱਖਰ *oh_i)
{
    ਲਿਖੋ("c: %c\n", *oh_i);
    *oh_i = '0';
}

ਖਾਲੀ goto_hell(ਦੁੱਗਣਾ *f)
{
    ਲਿਖੋ("oo: %f\n", *f);
    *f = -1.0;
}

ਅੱਖਰ *test()
{
    ਅੱਖਰ *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ਵਾਪਸ str;
}

ਖਾਲੀ test_ret_subcall(ਅੱਖਰ *that)
{
    ਲਿਖੋ("should be print before\n");
}

ਖਾਲੀ test_ret()
{
    ਅੱਖਰ *__attribute__ ((cleanup(check2))) that = "that";
    ਵਾਪਸ test_ret_subcall(that);
}

ਖਾਲੀ test_ret2()
{
  ਅੱਖਰ *__attribute__ ((cleanup(check2))) that = "-that";
  {
    ਅੱਖਰ *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    ਅੱਖਰ *__attribute__ ((cleanup(check2))) that = "-that2";
    ਵਾਪਸ;
  }
}

ਖਾਲੀ test2(ਖਾਲੀ) {
    ਪੂਰਨ chk = 0;
again:
    ਜੇ (!chk) {
        ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        ਜਾਓ again;
    }
}

ਪੂਰਨ test3(ਖਾਲੀ) {
    ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "three";
    ਪੂਰਨ chk = 0;

    ਜੇ (chk) {
        {
          outside:
	    {
            ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "two";
            ਲਿਖੋ("---- %d\n", chk);
	    }
        }
    }
    ਜੇ (!chk)
    {
        ਅੱਖਰ * __attribute__ ((cleanup(check2))) stop_that = "one";

        ਜੇ (!chk) {
            chk = 1;
            ਜਾਓ outside;
        }
    }
    ਵਾਪਸ 0;
}

ਖਾਲੀ cl(ਪੂਰਨ *ip)
{
    ਲਿਖੋ("%d\n", *ip);
    *ip = -1;
}

ਖਾਲੀ loop_cleanups(ਖਾਲੀ)
{
    __attribute__((cleanup(cl))) ਪੂਰਨ l = 1000;

    ਲਿਖੋ("-- loop 0 --\n");
    ਲਈ ( __attribute__((cleanup(cl))) ਪੂਰਨ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ਪੂਰਨ j = 100;
    }

    ਲਿਖੋ("-- loop 1 --\n");
    ਲਈ (__attribute__((cleanup(cl))) ਪੂਰਨ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  ਪੂਰਨ j = 200;
        ਜਾਰੀ;
    }

    ਲਿਖੋ("-- loop 2 --\n");
    ਲਈ (__attribute__((cleanup(cl))) ਪੂਰਨ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ਪੂਰਨ j = 300;
        ਰੋਕੋ;
    }

    ਲਿਖੋ("-- loop 3 --\n");
    ਲਈ (ਪੂਰਨ i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) ਪੂਰਨ j = 400;
	ਚੋਣ (i) {
	ਹਾਲਤ 0:
	    ਜਾਰੀ;
	ਮੂਲ:
	{
	    __attribute__((cleanup(cl))) ਪੂਰਨ jj = 500;
	    ਰੋਕੋ;
	}
	}
    }
    ਲਿਖੋ("after break\n");
}

ਖਾਲੀ my_cleanup1(ਪੂਰਨ *p) {
    ਲਿਖੋ("%d\n", *p);
    *p = 0x90;
}

ਪੂਰਨ test_cleanup1(ਖਾਲੀ) {
    ਪੂਰਨ __attribute__((cleanup(my_cleanup1))) n = 42;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup2(tstl *p) {
    ਲਿਖੋ("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(ਖਾਲੀ) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup3(tsti *p) {
    ਲਿਖੋ("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(ਖਾਲੀ) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup4(tstd *p) {
    ਲਿਖੋ("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(ਖਾਲੀ) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup5(tstld *p) {
    ਲਿਖੋ("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(ਖਾਲੀ) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup6(tstm *p) {
    ਲਿਖੋ("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(ਖਾਲੀ) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup7(tstf *p) {
    ਲਿਖੋ("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(ਖਾਲੀ) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ਵਾਪਸ n;
}

ਖਾਲੀ my_cleanup8(ਪੂਰਨ **p) {
    **p = 0x90;
}

ਪੂਰਨ test_cleanup8(ਖਾਲੀ) {
    ਪੂਰਨ n = 42;
    ਪੂਰਨ __attribute__((cleanup(my_cleanup8))) *p = &n;
    ਵਾਪਸ n;
}

ਸਥਿਰ ਖਾਲੀ my_cleanupe(ਪੂਰਨ *p) {
    *p = 0x90;
}

ਪੂਰਨ ਮੁੱਖ()
{
    ਪੂਰਨ i __attribute__ ((__cleanup__(check))) = 0, not_i;
    ਪੂਰਨ chk = 0;
    (ਖਾਲੀ)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) ਅੱਖਰ oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    ਲਿਖੋ("glob_i: %d\n", glob_i);
 naaaaaaaa:
    ਜੇ (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) ਅੱਖਰ oh_i = 'f';
	ਦੁੱਗਣਾ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	ਜਾਓ naaaaaaaa;
    }
    i = 105;
    ਲਿਖੋ("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    ਲਿਖੋ("%d\n", test_cleanup1());
    tl = test_cleanup2();
    ਲਿਖੋ("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    ਲਿਖੋ("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    ਲਿਖੋ("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    ਲਿਖੋ("%Lf\n", tld.a);
    tm = test_cleanup6();
    ਲਿਖੋ("%d %g\n", tm.a, tm.b);
    tf = test_cleanup7();
    ਲਿਖੋ("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    ਲਿਖੋ("%d\n", test_cleanup8());
    ਲਿਖੋ("%d\n", ({
            ਪੂਰਨ __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ਵਾਪਸ i;
}

ਖਾਲੀ check2(ਅੱਖਰ **hum)
{
    ਲਿਖੋ("str: %s\n", *hum);
    *hum = "fail";
}
