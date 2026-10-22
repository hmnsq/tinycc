extern පූර්ණ_සංඛ්‍යා printf(const var_na*, ...);
static පූර්ණ_සංඛ්‍යා glob_i = 0;

typedef sa_nracanaa { පූර්ණ_සංඛ්‍යා a; පූර්ණ_සංඛ්‍යා b; පූර්ණ_සංඛ්‍යා c; පූර්ණ_සංඛ්‍යා d; පූර්ණ_සංඛ්‍යා e; පූර්ණ_සංඛ්‍යා f; පූර්ණ_සංඛ්‍යා g; පූර්ණ_සංඛ්‍යා h; } tstl;
typedef sa_nracanaa { පූර්ණ_සංඛ්‍යා a; පූර්ණ_සංඛ්‍යා b; පූර්ණ_සංඛ්‍යා c; පූර්ණ_සංඛ්‍යා d; } tsti;
typedef sa_nracanaa { dviguu_na a; dviguu_na b; } tstd;
typedef sa_nracanaa { long dviguu_na a; } tstld;
typedef sa_nracanaa { පූර්ණ_සංඛ්‍යා a; dviguu_na b; } tstm;
typedef sa_nracanaa { float a; float b; float c; float d; } tstf;

void incr_glob_i(පූර්ණ_සංඛ්‍යා *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    පූර්ණ_සංඛ්‍යා i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


void check2(var_na **hum);

void check(පූර්ණ_සංඛ්‍යා *j)
{
    var_na * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    පූර්ණ_සංඛ්‍යා chk = 0;

    {
	var_na * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	නම් (!chk) {
	    chk = 1;
	    goto non_plopage;
	}
    }

    {
	var_na * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	goto out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	var_na * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    var_na * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		var_na * __attribute__ ((cleanup(check2))) cascade3 = "3";

		goto out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    නම් (chk != 2)
	goto again;
    {
	{
	    var_na * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    නම් (chk != 3)
		goto out;
	}
    }
    *j = -1;
    ආපසු;
}

void check_oh_i(var_na *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

void goto_hell(dviguu_na *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

var_na *test()
{
    var_na *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ආපසු str;
}

void test_ret_subcall(var_na *that)
{
    printf("should be print before\n");
}

void test_ret()
{
    var_na *__attribute__ ((cleanup(check2))) that = "that";
    ආපසු test_ret_subcall(that);
}

void test_ret2()
{
  var_na *__attribute__ ((cleanup(check2))) that = "-that";
  {
    var_na *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    var_na *__attribute__ ((cleanup(check2))) that = "-that2";
    ආපසු;
  }
}

void test2(void) {
    පූර්ණ_සංඛ්‍යා chk = 0;
again:
    නම් (!chk) {
        var_na * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        goto again;
    }
}

පූර්ණ_සංඛ්‍යා test3(void) {
    var_na * __attribute__ ((cleanup(check2))) stop_that = "three";
    පූර්ණ_සංඛ්‍යා chk = 0;

    නම් (chk) {
        {
          outside:
	    {
            var_na * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    නම් (!chk)
    {
        var_na * __attribute__ ((cleanup(check2))) stop_that = "one";

        නම් (!chk) {
            chk = 1;
            goto outside;
        }
    }
    ආපසු 0;
}

void cl(පූර්ණ_සංඛ්‍යා *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

void loop_cleanups(void)
{
    __attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා l = 1000;

    printf("-- loop 0 --\n");
    සඳහා ( __attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා j = 100;
    }

    printf("-- loop 1 --\n");
    සඳහා (__attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  පූර්ණ_සංඛ්‍යා j = 200;
        continue;
    }

    printf("-- loop 2 --\n");
    සඳහා (__attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා j = 300;
        bha_nga;
    }

    printf("-- loop 3 --\n");
    සඳහා (පූර්ණ_සංඛ්‍යා i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා j = 400;
	switch (i) {
	pak_sa 0:
	    continue;
	default:
	{
	    __attribute__((cleanup(cl))) පූර්ණ_සංඛ්‍යා jj = 500;
	    bha_nga;
	}
	}
    }
    printf("after break\n");
}

void my_cleanup1(පූර්ණ_සංඛ්‍යා *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

පූර්ණ_සංඛ්‍යා test_cleanup1(void) {
    පූර්ණ_සංඛ්‍යා __attribute__((cleanup(my_cleanup1))) n = 42;
    ආපසු n;
}

void my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(void) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    ආපසු n;
}

void my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(void) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ආපසු n;
}

void my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(void) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ආපසු n;
}

void my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(void) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ආපසු n;
}

void my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(void) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    ආපසු n;
}

void my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(void) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ආපසු n;
}

void my_cleanup8(පූර්ණ_සංඛ්‍යා **p) {
    **p = 0x90;
}

පූර්ණ_සංඛ්‍යා test_cleanup8(void) {
    පූර්ණ_සංඛ්‍යා n = 42;
    පූර්ණ_සංඛ්‍යා __attribute__((cleanup(my_cleanup8))) *p = &n;
    ආපසු n;
}

static void my_cleanupe(පූර්ණ_සංඛ්‍යා *p) {
    *p = 0x90;
}

පූර්ණ_සංඛ්‍යා main()
{
    පූර්ණ_සංඛ්‍යා i __attribute__ ((__cleanup__(check))) = 0, not_i;
    පූර්ණ_සංඛ්‍යා chk = 0;
    (void)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) var_na oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    නම් (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) var_na oh_i = 'f';
	dviguu_na __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	goto naaaaaaaa;
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
            පූර්ණ_සංඛ්‍යා __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ආපසු i;
}

void check2(var_na **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
