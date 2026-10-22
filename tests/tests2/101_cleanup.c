ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ*, ...);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ glob_i = 0;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ a; ಪೂರ್ಣಾಙ್ಕ b; ಪೂರ್ಣಾಙ್ಕ c; ಪೂರ್ಣಾಙ್ಕ d; ಪೂರ್ಣಾಙ್ಕ e; ಪೂರ್ಣಾಙ್ಕ f; ಪೂರ್ಣಾಙ್ಕ g; ಪೂರ್ಣಾಙ್ಕ h; } tstl;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ a; ಪೂರ್ಣಾಙ್ಕ b; ಪೂರ್ಣಾಙ್ಕ c; ಪೂರ್ಣಾಙ್ಕ d; } tsti;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ದ್ವಿಗುಣ a; ದ್ವಿಗುಣ b; } tstd;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { long ದ್ವಿಗುಣ a; } tstld;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ a; ದ್ವಿಗುಣ b; } tstm;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ { ಭಿನ್ನ a; ಭಿನ್ನ b; ಭಿನ್ನ c; ಭಿನ್ನ d; } tstf;

ಶೂನ್ಯ incr_glob_i(ಪೂರ್ಣಾಙ್ಕ *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    ಪೂರ್ಣಾಙ್ಕ i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


ಶೂನ್ಯ check2(ವರ್ಣ **hum);

ಶೂನ್ಯ check(ಪೂರ್ಣಾಙ್ಕ *j)
{
    ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    ಪೂರ್ಣಾಙ್ಕ chk = 0;

    {
	ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	ಯದಿ (!chk) {
	    chk = 1;
	    ಗಚ್ಛ non_plopage;
	}
    }

    {
	ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	ಗಚ್ಛ out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	ವರ್ಣ * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    ವರ್ಣ * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		ವರ್ಣ * __attribute__ ((cleanup(check2))) cascade3 = "3";

		ಗಚ್ಛ out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    ಯದಿ (chk != 2)
	ಗಚ್ಛ again;
    {
	{
	    ವರ್ಣ * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    ಯದಿ (chk != 3)
		ಗಚ್ಛ out;
	}
    }
    *j = -1;
    ಪ್ರತ್ಯಾಗಮ;
}

ಶೂನ್ಯ check_oh_i(ವರ್ಣ *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

ಶೂನ್ಯ goto_hell(ದ್ವಿಗುಣ *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

ವರ್ಣ *test()
{
    ವರ್ಣ *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ಪ್ರತ್ಯಾಗಮ str;
}

ಶೂನ್ಯ test_ret_subcall(ವರ್ಣ *that)
{
    printf("should be print before\n");
}

ಶೂನ್ಯ test_ret()
{
    ವರ್ಣ *__attribute__ ((cleanup(check2))) that = "that";
    ಪ್ರತ್ಯಾಗಮ test_ret_subcall(that);
}

ಶೂನ್ಯ test_ret2()
{
  ವರ್ಣ *__attribute__ ((cleanup(check2))) that = "-that";
  {
    ವರ್ಣ *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    ವರ್ಣ *__attribute__ ((cleanup(check2))) that = "-that2";
    ಪ್ರತ್ಯಾಗಮ;
  }
}

ಶೂನ್ಯ test2(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಙ್ಕ chk = 0;
again:
    ಯದಿ (!chk) {
        ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        ಗಚ್ಛ again;
    }
}

ಪೂರ್ಣಾಙ್ಕ test3(ಶೂನ್ಯ) {
    ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "three";
    ಪೂರ್ಣಾಙ್ಕ chk = 0;

    ಯದಿ (chk) {
        {
          outside:
	    {
            ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    ಯದಿ (!chk)
    {
        ವರ್ಣ * __attribute__ ((cleanup(check2))) stop_that = "one";

        ಯದಿ (!chk) {
            chk = 1;
            ಗಚ್ಛ outside;
        }
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಶೂನ್ಯ cl(ಪೂರ್ಣಾಙ್ಕ *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

ಶೂನ್ಯ loop_cleanups(ಶೂನ್ಯ)
{
    __attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ l = 1000;

    printf("-- loop 0 --\n");
    ಪ್ರತಿ ( __attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ j = 100;
    }

    printf("-- loop 1 --\n");
    ಪ್ರತಿ (__attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  ಪೂರ್ಣಾಙ್ಕ j = 200;
        ಅನುವರ್ತ;
    }

    printf("-- loop 2 --\n");
    ಪ್ರತಿ (__attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ j = 300;
        ಭಙ್ಗ;
    }

    printf("-- loop 3 --\n");
    ಪ್ರತಿ (ಪೂರ್ಣಾಙ್ಕ i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ j = 400;
	ವಿಕಲ್ಪ (i) {
	ಪಕ್ಷ 0:
	    ಅನುವರ್ತ;
	ಸ್ವಭಾವ:
	{
	    __attribute__((cleanup(cl))) ಪೂರ್ಣಾಙ್ಕ jj = 500;
	    ಭಙ್ಗ;
	}
	}
    }
    printf("after break\n");
}

ಶೂನ್ಯ my_cleanup1(ಪೂರ್ಣಾಙ್ಕ *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

ಪೂರ್ಣಾಙ್ಕ test_cleanup1(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಙ್ಕ __attribute__((cleanup(my_cleanup1))) n = 42;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(ಶೂನ್ಯ) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(ಶೂನ್ಯ) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(ಶೂನ್ಯ) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(ಶೂನ್ಯ) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(ಶೂನ್ಯ) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(ಶೂನ್ಯ) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಶೂನ್ಯ my_cleanup8(ಪೂರ್ಣಾಙ್ಕ **p) {
    **p = 0x90;
}

ಪೂರ್ಣಾಙ್ಕ test_cleanup8(ಶೂನ್ಯ) {
    ಪೂರ್ಣಾಙ್ಕ n = 42;
    ಪೂರ್ಣಾಙ್ಕ __attribute__((cleanup(my_cleanup8))) *p = &n;
    ಪ್ರತ್ಯಾಗಮ n;
}

ಸ್ಥಿರ ಶೂನ್ಯ my_cleanupe(ಪೂರ್ಣಾಙ್ಕ *p) {
    *p = 0x90;
}

ಪೂರ್ಣಾಙ್ಕ main()
{
    ಪೂರ್ಣಾಙ್ಕ i __attribute__ ((__cleanup__(check))) = 0, not_i;
    ಪೂರ್ಣಾಙ್ಕ chk = 0;
    (ಶೂನ್ಯ)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) ವರ್ಣ oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    ಯದಿ (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) ವರ್ಣ oh_i = 'f';
	ದ್ವಿಗುಣ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	ಗಚ್ಛ naaaaaaaa;
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
            ಪೂರ್ಣಾಙ್ಕ __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ಪ್ರತ್ಯಾಗಮ i;
}

ಶೂನ್ಯ check2(ವರ್ಣ **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
