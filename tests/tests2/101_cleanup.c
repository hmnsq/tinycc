extern ຈຳນວນເຕັມ printf(const var_na*, ...);
static ຈຳນວນເຕັມ glob_i = 0;

typedef sa_nracanaa { ຈຳນວນເຕັມ a; ຈຳນວນເຕັມ b; ຈຳນວນເຕັມ c; ຈຳນວນເຕັມ d; ຈຳນວນເຕັມ e; ຈຳນວນເຕັມ f; ຈຳນວນເຕັມ g; ຈຳນວນເຕັມ h; } tstl;
typedef sa_nracanaa { ຈຳນວນເຕັມ a; ຈຳນວນເຕັມ b; ຈຳນວນເຕັມ c; ຈຳນວນເຕັມ d; } tsti;
typedef sa_nracanaa { dviguu_na a; dviguu_na b; } tstd;
typedef sa_nracanaa { long dviguu_na a; } tstld;
typedef sa_nracanaa { ຈຳນວນເຕັມ a; dviguu_na b; } tstm;
typedef sa_nracanaa { float a; float b; float c; float d; } tstf;

void incr_glob_i(ຈຳນວນເຕັມ *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    ຈຳນວນເຕັມ i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
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

void check(ຈຳນວນເຕັມ *j)
{
    var_na * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    ຈຳນວນເຕັມ chk = 0;

    {
	var_na * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	ຖ້າ (!chk) {
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
    ຖ້າ (chk != 2)
	goto again;
    {
	{
	    var_na * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    ຖ້າ (chk != 3)
		goto out;
	}
    }
    *j = -1;
    ສົ່ງຄືນ;
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

    ສົ່ງຄືນ str;
}

void test_ret_subcall(var_na *that)
{
    printf("should be print before\n");
}

void test_ret()
{
    var_na *__attribute__ ((cleanup(check2))) that = "that";
    ສົ່ງຄືນ test_ret_subcall(that);
}

void test_ret2()
{
  var_na *__attribute__ ((cleanup(check2))) that = "-that";
  {
    var_na *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    var_na *__attribute__ ((cleanup(check2))) that = "-that2";
    ສົ່ງຄືນ;
  }
}

void test2(void) {
    ຈຳນວນເຕັມ chk = 0;
again:
    ຖ້າ (!chk) {
        var_na * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        goto again;
    }
}

ຈຳນວນເຕັມ test3(void) {
    var_na * __attribute__ ((cleanup(check2))) stop_that = "three";
    ຈຳນວນເຕັມ chk = 0;

    ຖ້າ (chk) {
        {
          outside:
	    {
            var_na * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    ຖ້າ (!chk)
    {
        var_na * __attribute__ ((cleanup(check2))) stop_that = "one";

        ຖ້າ (!chk) {
            chk = 1;
            goto outside;
        }
    }
    ສົ່ງຄືນ 0;
}

void cl(ຈຳນວນເຕັມ *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

void loop_cleanups(void)
{
    __attribute__((cleanup(cl))) ຈຳນວນເຕັມ l = 1000;

    printf("-- loop 0 --\n");
    ສຳລັບ ( __attribute__((cleanup(cl))) ຈຳນວນເຕັມ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ຈຳນວນເຕັມ j = 100;
    }

    printf("-- loop 1 --\n");
    ສຳລັບ (__attribute__((cleanup(cl))) ຈຳນວນເຕັມ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  ຈຳນວນເຕັມ j = 200;
        continue;
    }

    printf("-- loop 2 --\n");
    ສຳລັບ (__attribute__((cleanup(cl))) ຈຳນວນເຕັມ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ຈຳນວນເຕັມ j = 300;
        bha_nga;
    }

    printf("-- loop 3 --\n");
    ສຳລັບ (ຈຳນວນເຕັມ i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) ຈຳນວນເຕັມ j = 400;
	switch (i) {
	pak_sa 0:
	    continue;
	default:
	{
	    __attribute__((cleanup(cl))) ຈຳນວນເຕັມ jj = 500;
	    bha_nga;
	}
	}
    }
    printf("after break\n");
}

void my_cleanup1(ຈຳນວນເຕັມ *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

ຈຳນວນເຕັມ test_cleanup1(void) {
    ຈຳນວນເຕັມ __attribute__((cleanup(my_cleanup1))) n = 42;
    ສົ່ງຄືນ n;
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
    ສົ່ງຄືນ n;
}

void my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(void) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ສົ່ງຄືນ n;
}

void my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(void) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ສົ່ງຄືນ n;
}

void my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(void) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ສົ່ງຄືນ n;
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
    ສົ່ງຄືນ n;
}

void my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(void) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ສົ່ງຄືນ n;
}

void my_cleanup8(ຈຳນວນເຕັມ **p) {
    **p = 0x90;
}

ຈຳນວນເຕັມ test_cleanup8(void) {
    ຈຳນວນເຕັມ n = 42;
    ຈຳນວນເຕັມ __attribute__((cleanup(my_cleanup8))) *p = &n;
    ສົ່ງຄືນ n;
}

static void my_cleanupe(ຈຳນວນເຕັມ *p) {
    *p = 0x90;
}

ຈຳນວນເຕັມ main()
{
    ຈຳນວນເຕັມ i __attribute__ ((__cleanup__(check))) = 0, not_i;
    ຈຳນວນເຕັມ chk = 0;
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
    ຖ້າ (!chk) {
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
            ຈຳນວນເຕັມ __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ສົ່ງຄືນ i;
}

void check2(var_na **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
