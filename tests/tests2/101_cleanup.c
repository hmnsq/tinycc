ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ*, ...);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ glob_i = 0;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ a; ಪೂರ್ಣಾಂಕ b; ಪೂರ್ಣಾಂಕ c; ಪೂರ್ಣಾಂಕ d; ಪೂರ್ಣಾಂಕ e; ಪೂರ್ಣಾಂಕ f; ಪೂರ್ಣಾಂಕ g; ಪೂರ್ಣಾಂಕ h; } tstl;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ a; ಪೂರ್ಣಾಂಕ b; ಪೂರ್ಣಾಂಕ c; ಪೂರ್ಣಾಂಕ d; } tsti;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ದ್ವಿಗುಣ a; ದ್ವಿಗುಣ b; } tstd;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ದೀರ್ಘ ದ್ವಿಗುಣ a; } tstld;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ಪೂರ್ಣಾಂಕ a; ದ್ವಿಗುಣ b; } tstm;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ { ದಶಮಾಂಶ a; ದಶಮಾಂಶ b; ದಶಮಾಂಶ c; ದಶಮಾಂಶ d; } tstf;

ಶೂನ್ಯ incr_glob_i(ಪೂರ್ಣಾಂಕ *i)
{
  glob_i += *i;
  *i = -1;
}

#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI {						\
    ಪೂರ್ಣಾಂಕ i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#ವ್ಯಾಖ್ಯಾನಿಸು INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


ಶೂನ್ಯ check2(ಅಕ್ಷರ **hum);

ಶೂನ್ಯ check(ಪೂರ್ಣಾಂಕ *j)
{
    ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    ಪೂರ್ಣಾಂಕ chk = 0;

    {
	ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    ಬರೆ("---- %d\n", chk);
	}
	ಆದರೆ (!chk) {
	    chk = 1;
	    ಹೋಗು non_plopage;
	}
    }

    {
	ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	ಹೋಗು ಹೊರಹೋಗು;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) cascade3 = "3";

		ಹೋಗು ಹೊರಹೋಗು;
		cascade3 = "nope";
	    }
	}
    }
  ಹೊರಹೋಗು:
    ಆದರೆ (chk != 2)
	ಹೋಗು again;
    {
	{
	    ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) ಹೊರಹೋಗು = "last goto out";
	    ++chk;
	    ಆದರೆ (chk != 3)
		ಹೋಗು ಹೊರಹೋಗು;
	}
    }
    *j = -1;
    ಹಿಂತಿರುಗಿ;
}

ಶೂನ್ಯ check_oh_i(ಅಕ್ಷರ *oh_i)
{
    ಬರೆ("c: %c\n", *oh_i);
    *oh_i = '0';
}

ಶೂನ್ಯ goto_hell(ದ್ವಿಗುಣ *f)
{
    ಬರೆ("oo: %f\n", *f);
    *f = -1.0;
}

ಅಕ್ಷರ *test()
{
    ಅಕ್ಷರ *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ಹಿಂತಿರುಗಿ str;
}

ಶೂನ್ಯ test_ret_subcall(ಅಕ್ಷರ *that)
{
    ಬರೆ("should be print before\n");
}

ಶೂನ್ಯ test_ret()
{
    ಅಕ್ಷರ *__attribute__ ((cleanup(check2))) that = "that";
    ಹಿಂತಿರುಗಿ test_ret_subcall(that);
}

ಶೂನ್ಯ test_ret2()
{
  ಅಕ್ಷರ *__attribute__ ((cleanup(check2))) that = "-that";
  {
    ಅಕ್ಷರ *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    ಅಕ್ಷರ *__attribute__ ((cleanup(check2))) that = "-that2";
    ಹಿಂತಿರುಗಿ;
  }
}

ಶೂನ್ಯ test2(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಂಕ chk = 0;
again:
    ಆದರೆ (!chk) {
        ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        ಹೋಗು again;
    }
}

ಪೂರ್ಣಾಂಕ test3(ಶೂನ್ಯ) {
    ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "three";
    ಪೂರ್ಣಾಂಕ chk = 0;

    ಆದರೆ (chk) {
        {
          outside:
	    {
            ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "two";
            ಬರೆ("---- %d\n", chk);
	    }
        }
    }
    ಆದರೆ (!chk)
    {
        ಅಕ್ಷರ * __attribute__ ((cleanup(check2))) stop_that = "one";

        ಆದರೆ (!chk) {
            chk = 1;
            ಹೋಗು outside;
        }
    }
    ಹಿಂತಿರುಗಿ 0;
}

ಶೂನ್ಯ cl(ಪೂರ್ಣಾಂಕ *ip)
{
    ಬರೆ("%d\n", *ip);
    *ip = -1;
}

ಶೂನ್ಯ loop_cleanups(ಶೂನ್ಯ)
{
    __attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ l = 1000;

    ಬರೆ("-- loop 0 --\n");
    ಗಾಗಿ ( __attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ j = 100;
    }

    ಬರೆ("-- loop 1 --\n");
    ಗಾಗಿ (__attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  ಪೂರ್ಣಾಂಕ j = 200;
        ಮುಂದುವರಿ;
    }

    ಬರೆ("-- loop 2 --\n");
    ಗಾಗಿ (__attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ j = 300;
        ನಿಲ್ಲಿಸು;
    }

    ಬರೆ("-- loop 3 --\n");
    ಗಾಗಿ (ಪೂರ್ಣಾಂಕ i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ j = 400;
	ಆಯ್ಕೆ (i) {
	ಸ್ಥಿತಿ 0:
	    ಮುಂದುವರಿ;
	ಪೂರ್ವನಿಯೋಜಿತ:
	{
	    __attribute__((cleanup(cl))) ಪೂರ್ಣಾಂಕ jj = 500;
	    ನಿಲ್ಲಿಸು;
	}
	}
    }
    ಬರೆ("after break\n");
}

ಶೂನ್ಯ my_cleanup1(ಪೂರ್ಣಾಂಕ *p) {
    ಬರೆ("%d\n", *p);
    *p = 0x90;
}

ಪೂರ್ಣಾಂಕ test_cleanup1(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಂಕ __attribute__((cleanup(my_cleanup1))) n = 42;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup2(tstl *p) {
    ಬರೆ("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(ಶೂನ್ಯ) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup3(tsti *p) {
    ಬರೆ("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(ಶೂನ್ಯ) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup4(tstd *p) {
    ಬರೆ("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(ಶೂನ್ಯ) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup5(tstld *p) {
    ಬರೆ("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(ಶೂನ್ಯ) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup6(tstm *p) {
    ಬರೆ("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(ಶೂನ್ಯ) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup7(tstf *p) {
    ಬರೆ("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(ಶೂನ್ಯ) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ಹಿಂತಿರುಗಿ n;
}

ಶೂನ್ಯ my_cleanup8(ಪೂರ್ಣಾಂಕ **p) {
    **p = 0x90;
}

ಪೂರ್ಣಾಂಕ test_cleanup8(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಂಕ n = 42;
    ಪೂರ್ಣಾಂಕ __attribute__((cleanup(my_cleanup8))) *p = &n;
    ಹಿಂತಿರುಗಿ n;
}

ಸ್ಥಿರ ಶೂನ್ಯ my_cleanupe(ಪೂರ್ಣಾಂಕ *p) {
    *p = 0x90;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಪೂರ್ಣಾಂಕ i __attribute__ ((__cleanup__(check))) = 0, not_i;
    ಪೂರ್ಣಾಂಕ chk = 0;
    (ಶೂನ್ಯ)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) ಅಕ್ಷರ oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    ಬರೆ("glob_i: %d\n", glob_i);
 naaaaaaaa:
    ಆದರೆ (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) ಅಕ್ಷರ oh_i = 'f';
	ದ್ವಿಗುಣ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	ಹೋಗು naaaaaaaa;
    }
    i = 105;
    ಬರೆ("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    ಬರೆ("%d\n", test_cleanup1());
    tl = test_cleanup2();
    ಬರೆ("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    ಬರೆ("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    ಬರೆ("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    ಬರೆ("%Lf\n", tld.a);
    tm = test_cleanup6();
    ಬರೆ("%d %g\n", tm.a, tm.b);
    tf = test_cleanup7();
    ಬರೆ("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    ಬರೆ("%d\n", test_cleanup8());
    ಬರೆ("%d\n", ({
            ಪೂರ್ಣಾಂಕ __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ಹಿಂತಿರುಗಿ i;
}

ಶೂನ್ಯ check2(ಅಕ್ಷರ **hum)
{
    ಬರೆ("str: %s\n", *hum);
    *hum = "fail";
}
