বাহ্যিক পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর*, ...);
স্থির পূর্ণসংখ্যা glob_i = 0;

প্রকারলেখ কাঠামো { পূর্ণসংখ্যা a; পূর্ণসংখ্যা b; পূর্ণসংখ্যা c; পূর্ণসংখ্যা d; পূর্ণসংখ্যা e; পূর্ণসংখ্যা f; পূর্ণসংখ্যা g; পূর্ণসংখ্যা h; } tstl;
প্রকারলেখ কাঠামো { পূর্ণসংখ্যা a; পূর্ণসংখ্যা b; পূর্ণসংখ্যা c; পূর্ণসংখ্যা d; } tsti;
প্রকারলেখ কাঠামো { দ্বিগুণ a; দ্বিগুণ b; } tstd;
প্রকারলেখ কাঠামো { long দ্বিগুণ a; } tstld;
প্রকারলেখ কাঠামো { পূর্ণসংখ্যা a; দ্বিগুণ b; } tstm;
প্রকারলেখ কাঠামো { দশমিক a; দশমিক b; দশমিক c; দশমিক d; } tstf;

শূন্য incr_glob_i(পূর্ণসংখ্যা *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    পূর্ণসংখ্যা i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


শূন্য check2(অক্ষর **hum);

শূন্য check(পূর্ণসংখ্যা *j)
{
    অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    পূর্ণসংখ্যা chk = 0;

    {
	অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	যদি (!chk) {
	    chk = 1;
	    যাও non_plopage;
	}
    }

    {
	অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	যাও out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	অক্ষর * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    অক্ষর * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		অক্ষর * __attribute__ ((cleanup(check2))) cascade3 = "3";

		যাও out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    যদি (chk != 2)
	যাও again;
    {
	{
	    অক্ষর * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    যদি (chk != 3)
		যাও out;
	}
    }
    *j = -1;
    ফেরত;
}

শূন্য check_oh_i(অক্ষর *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

শূন্য goto_hell(দ্বিগুণ *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

অক্ষর *test()
{
    অক্ষর *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ফেরত str;
}

শূন্য test_ret_subcall(অক্ষর *that)
{
    printf("should be print before\n");
}

শূন্য test_ret()
{
    অক্ষর *__attribute__ ((cleanup(check2))) that = "that";
    ফেরত test_ret_subcall(that);
}

শূন্য test_ret2()
{
  অক্ষর *__attribute__ ((cleanup(check2))) that = "-that";
  {
    অক্ষর *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    অক্ষর *__attribute__ ((cleanup(check2))) that = "-that2";
    ফেরত;
  }
}

শূন্য test2(শূন্য) {
    পূর্ণসংখ্যা chk = 0;
again:
    যদি (!chk) {
        অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        যাও again;
    }
}

পূর্ণসংখ্যা test3(শূন্য) {
    অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "three";
    পূর্ণসংখ্যা chk = 0;

    যদি (chk) {
        {
          outside:
	    {
            অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    যদি (!chk)
    {
        অক্ষর * __attribute__ ((cleanup(check2))) stop_that = "one";

        যদি (!chk) {
            chk = 1;
            যাও outside;
        }
    }
    ফেরত 0;
}

শূন্য cl(পূর্ণসংখ্যা *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

শূন্য loop_cleanups(শূন্য)
{
    __attribute__((cleanup(cl))) পূর্ণসংখ্যা l = 1000;

    printf("-- loop 0 --\n");
    জন্য ( __attribute__((cleanup(cl))) পূর্ণসংখ্যা i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) পূর্ণসংখ্যা j = 100;
    }

    printf("-- loop 1 --\n");
    জন্য (__attribute__((cleanup(cl))) পূর্ণসংখ্যা i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  পূর্ণসংখ্যা j = 200;
        চালু;
    }

    printf("-- loop 2 --\n");
    জন্য (__attribute__((cleanup(cl))) পূর্ণসংখ্যা i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) পূর্ণসংখ্যা j = 300;
        বিরতি;
    }

    printf("-- loop 3 --\n");
    জন্য (পূর্ণসংখ্যা i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) পূর্ণসংখ্যা j = 400;
	নির্বাচন (i) {
	ক্ষেত্র 0:
	    চালু;
	পূর্বনির্ধারিত:
	{
	    __attribute__((cleanup(cl))) পূর্ণসংখ্যা jj = 500;
	    বিরতি;
	}
	}
    }
    printf("after break\n");
}

শূন্য my_cleanup1(পূর্ণসংখ্যা *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

পূর্ণসংখ্যা test_cleanup1(শূন্য) {
    পূর্ণসংখ্যা __attribute__((cleanup(my_cleanup1))) n = 42;
    ফেরত n;
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
    ফেরত n;
}

শূন্য my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(শূন্য) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ফেরত n;
}

শূন্য my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(শূন্য) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ফেরত n;
}

শূন্য my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(শূন্য) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ফেরত n;
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
    ফেরত n;
}

শূন্য my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(শূন্য) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ফেরত n;
}

শূন্য my_cleanup8(পূর্ণসংখ্যা **p) {
    **p = 0x90;
}

পূর্ণসংখ্যা test_cleanup8(শূন্য) {
    পূর্ণসংখ্যা n = 42;
    পূর্ণসংখ্যা __attribute__((cleanup(my_cleanup8))) *p = &n;
    ফেরত n;
}

স্থির শূন্য my_cleanupe(পূর্ণসংখ্যা *p) {
    *p = 0x90;
}

পূর্ণসংখ্যা প্রধান()
{
    পূর্ণসংখ্যা i __attribute__ ((__cleanup__(check))) = 0, not_i;
    পূর্ণসংখ্যা chk = 0;
    (শূন্য)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) অক্ষর oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    যদি (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) অক্ষর oh_i = 'f';
	দ্বিগুণ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	যাও naaaaaaaa;
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
            পূর্ণসংখ্যা __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ফেরত i;
}

শূন্য check2(অক্ষর **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
