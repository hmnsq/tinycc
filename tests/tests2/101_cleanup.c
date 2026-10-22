خارجي صحيح لکو(ثابت حرف*, ...);
ساكن صحيح glob_i = 0;

تعريفنوع بنية { صحيح a; صحيح b; صحيح c; صحيح d; صحيح e; صحيح f; صحيح g; صحيح h; } tstl;
تعريفنوع بنية { صحيح a; صحيح b; صحيح c; صحيح d; } tsti;
تعريفنوع بنية { مزدوج a; مزدوج b; } tstd;
تعريفنوع بنية { ڊگهو مزدوج a; } tstld;
تعريفنوع بنية { صحيح a; مزدوج b; } tstm;
تعريفنوع بنية { عائم a; عائم b; عائم c; عائم d; } tstf;

فراغ incr_glob_i(صحيح *i)
{
  glob_i += *i;
  *i = -1;
}

#وصف_ڪريو INCR_GI {						\
    صحيح i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#وصف_ڪريو INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#وصف_ڪريو INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#وصف_ڪريو INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#وصف_ڪريو INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#وصف_ڪريو INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#وصف_ڪريو INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#وصف_ڪريو INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#وصف_ڪريو INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


فراغ check2(حرف **hum);

فراغ check(صحيح *j)
{
    حرف * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    صحيح chk = 0;

    {
	حرف * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    لکو("---- %d\n", chk);
	}
	إذا (!chk) {
	    chk = 1;
	    اذهب non_plopage;
	}
    }

    {
	حرف * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	اذهب ٻاهريون;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	حرف * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    حرف * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		حرف * __attribute__ ((cleanup(check2))) cascade3 = "3";

		اذهب ٻاهريون;
		cascade3 = "nope";
	    }
	}
    }
  ٻاهريون:
    إذا (chk != 2)
	اذهب again;
    {
	{
	    حرف * __attribute__ ((cleanup(check2))) ٻاهريون = "last goto out";
	    ++chk;
	    إذا (chk != 3)
		اذهب ٻاهريون;
	}
    }
    *j = -1;
    أرجع;
}

فراغ check_oh_i(حرف *oh_i)
{
    لکو("c: %c\n", *oh_i);
    *oh_i = '0';
}

فراغ goto_hell(مزدوج *f)
{
    لکو("oo: %f\n", *f);
    *f = -1.0;
}

حرف *test()
{
    حرف *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    أرجع str;
}

فراغ test_ret_subcall(حرف *that)
{
    لکو("should be print before\n");
}

فراغ test_ret()
{
    حرف *__attribute__ ((cleanup(check2))) that = "that";
    أرجع test_ret_subcall(that);
}

فراغ test_ret2()
{
  حرف *__attribute__ ((cleanup(check2))) that = "-that";
  {
    حرف *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    حرف *__attribute__ ((cleanup(check2))) that = "-that2";
    أرجع;
  }
}

فراغ test2(فراغ) {
    صحيح chk = 0;
again:
    إذا (!chk) {
        حرف * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        اذهب again;
    }
}

صحيح test3(فراغ) {
    حرف * __attribute__ ((cleanup(check2))) stop_that = "three";
    صحيح chk = 0;

    إذا (chk) {
        {
          outside:
	    {
            حرف * __attribute__ ((cleanup(check2))) stop_that = "two";
            لکو("---- %d\n", chk);
	    }
        }
    }
    إذا (!chk)
    {
        حرف * __attribute__ ((cleanup(check2))) stop_that = "one";

        إذا (!chk) {
            chk = 1;
            اذهب outside;
        }
    }
    أرجع 0;
}

فراغ cl(صحيح *ip)
{
    لکو("%d\n", *ip);
    *ip = -1;
}

فراغ loop_cleanups(فراغ)
{
    __attribute__((cleanup(cl))) صحيح l = 1000;

    لکو("-- loop 0 --\n");
    لكل ( __attribute__((cleanup(cl))) صحيح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) صحيح j = 100;
    }

    لکو("-- loop 1 --\n");
    لكل (__attribute__((cleanup(cl))) صحيح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  صحيح j = 200;
        استمر;
    }

    لکو("-- loop 2 --\n");
    لكل (__attribute__((cleanup(cl))) صحيح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) صحيح j = 300;
        اكسر;
    }

    لکو("-- loop 3 --\n");
    لكل (صحيح i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) صحيح j = 400;
	بدل (i) {
	حالة 0:
	    استمر;
	افتراضي:
	{
	    __attribute__((cleanup(cl))) صحيح jj = 500;
	    اكسر;
	}
	}
    }
    لکو("after break\n");
}

فراغ my_cleanup1(صحيح *p) {
    لکو("%d\n", *p);
    *p = 0x90;
}

صحيح test_cleanup1(فراغ) {
    صحيح __attribute__((cleanup(my_cleanup1))) n = 42;
    أرجع n;
}

فراغ my_cleanup2(tstl *p) {
    لکو("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(فراغ) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    أرجع n;
}

فراغ my_cleanup3(tsti *p) {
    لکو("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(فراغ) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    أرجع n;
}

فراغ my_cleanup4(tstd *p) {
    لکو("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(فراغ) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    أرجع n;
}

فراغ my_cleanup5(tstld *p) {
    لکو("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(فراغ) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    أرجع n;
}

فراغ my_cleanup6(tstm *p) {
    لکو("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(فراغ) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    أرجع n;
}

فراغ my_cleanup7(tstf *p) {
    لکو("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(فراغ) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    أرجع n;
}

فراغ my_cleanup8(صحيح **p) {
    **p = 0x90;
}

صحيح test_cleanup8(فراغ) {
    صحيح n = 42;
    صحيح __attribute__((cleanup(my_cleanup8))) *p = &n;
    أرجع n;
}

ساكن فراغ my_cleanupe(صحيح *p) {
    *p = 0x90;
}

صحيح مکيه()
{
    صحيح i __attribute__ ((__cleanup__(check))) = 0, not_i;
    صحيح chk = 0;
    (فراغ)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) حرف oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    لکو("glob_i: %d\n", glob_i);
 naaaaaaaa:
    إذا (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) حرف oh_i = 'f';
	مزدوج __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	اذهب naaaaaaaa;
    }
    i = 105;
    لکو("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    لکو("%d\n", test_cleanup1());
    tl = test_cleanup2();
    لکو("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    لکو("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    لکو("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    لکو("%Lf\n", tld.a);
    tm = test_cleanup6();
    لکو("%d %g\n", tm.a, tm.b);
    tf = test_cleanup7();
    لکو("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    لکو("%d\n", test_cleanup8());
    لکو("%d\n", ({
            صحيح __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    أرجع i;
}

فراغ check2(حرف **hum)
{
    لکو("str: %s\n", *hum);
    *hum = "fail";
}
