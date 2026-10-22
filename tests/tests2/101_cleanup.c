ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର*, ...);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା glob_i = 0;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a; ପୂର୍ଣ୍ଣସଂଖ୍ୟା b; ପୂର୍ଣ୍ଣସଂଖ୍ୟା c; ପୂର୍ଣ୍ଣସଂଖ୍ୟା d; ପୂର୍ଣ୍ଣସଂଖ୍ୟା e; ପୂର୍ଣ୍ଣସଂଖ୍ୟା f; ପୂର୍ଣ୍ଣସଂଖ୍ୟା g; ପୂର୍ଣ୍ଣସଂଖ୍ୟା h; } tstl;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a; ପୂର୍ଣ୍ଣସଂଖ୍ୟା b; ପୂର୍ଣ୍ଣସଂଖ୍ୟା c; ପୂର୍ଣ୍ଣସଂଖ୍ୟା d; } tsti;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ଦ୍ୱିଗୁଣ a; ଦ୍ୱିଗୁଣ b; } tstd;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { long ଦ୍ୱିଗୁଣ a; } tstld;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ପୂର୍ଣ୍ଣସଂଖ୍ୟା a; ଦ୍ୱିଗୁଣ b; } tstm;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା { ଦଶମିକ a; ଦଶମିକ b; ଦଶମିକ c; ଦଶମିକ d; } tstf;

ଶୂନ୍ୟ incr_glob_i(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


ଶୂନ୍ୟ check2(ଅକ୍ଷର **hum);

ଶୂନ୍ୟ check(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *j)
{
    ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା chk = 0;

    {
	ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	ଯଦି (!chk) {
	    chk = 1;
	    ଯାଅ non_plopage;
	}
    }

    {
	ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	ଯାଅ out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	ଅକ୍ଷର * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    ଅକ୍ଷର * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		ଅକ୍ଷର * __attribute__ ((cleanup(check2))) cascade3 = "3";

		ଯାଅ out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    ଯଦି (chk != 2)
	ଯାଅ again;
    {
	{
	    ଅକ୍ଷର * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    ଯଦି (chk != 3)
		ଯାଅ out;
	}
    }
    *j = -1;
    ଫେରନ୍ତୁ;
}

ଶୂନ୍ୟ check_oh_i(ଅକ୍ଷର *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

ଶୂନ୍ୟ goto_hell(ଦ୍ୱିଗୁଣ *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

ଅକ୍ଷର *test()
{
    ଅକ୍ଷର *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    ଫେରନ୍ତୁ str;
}

ଶୂନ୍ୟ test_ret_subcall(ଅକ୍ଷର *that)
{
    printf("should be print before\n");
}

ଶୂନ୍ୟ test_ret()
{
    ଅକ୍ଷର *__attribute__ ((cleanup(check2))) that = "that";
    ଫେରନ୍ତୁ test_ret_subcall(that);
}

ଶୂନ୍ୟ test_ret2()
{
  ଅକ୍ଷର *__attribute__ ((cleanup(check2))) that = "-that";
  {
    ଅକ୍ଷର *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    ଅକ୍ଷର *__attribute__ ((cleanup(check2))) that = "-that2";
    ଫେରନ୍ତୁ;
  }
}

ଶୂନ୍ୟ test2(ଶୂନ୍ୟ) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା chk = 0;
again:
    ଯଦି (!chk) {
        ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        ଯାଅ again;
    }
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test3(ଶୂନ୍ୟ) {
    ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "three";
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା chk = 0;

    ଯଦି (chk) {
        {
          outside:
	    {
            ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    ଯଦି (!chk)
    {
        ଅକ୍ଷର * __attribute__ ((cleanup(check2))) stop_that = "one";

        ଯଦି (!chk) {
            chk = 1;
            ଯାଅ outside;
        }
    }
    ଫେରନ୍ତୁ 0;
}

ଶୂନ୍ୟ cl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

ଶୂନ୍ୟ loop_cleanups(ଶୂନ୍ୟ)
{
    __attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା l = 1000;

    printf("-- loop 0 --\n");
    ପାଇଁ ( __attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = 100;
    }

    printf("-- loop 1 --\n");
    ପାଇଁ (__attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = 200;
        ଜାରି;
    }

    printf("-- loop 2 --\n");
    ପାଇଁ (__attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = 300;
        ଭାଙ୍ଗ;
    }

    printf("-- loop 3 --\n");
    ପାଇଁ (ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = 400;
	ବାଛ (i) {
	ସ୍ଥିତି 0:
	    ଜାରି;
	ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
	{
	    __attribute__((cleanup(cl))) ପୂର୍ଣ୍ଣସଂଖ୍ୟା jj = 500;
	    ଭାଙ୍ଗ;
	}
	}
    }
    printf("after break\n");
}

ଶୂନ୍ୟ my_cleanup1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test_cleanup1(ଶୂନ୍ୟ) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((cleanup(my_cleanup1))) n = 42;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(ଶୂନ୍ୟ) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(ଶୂନ୍ୟ) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(ଶୂନ୍ୟ) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(ଶୂନ୍ୟ) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(ଶୂନ୍ୟ) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(ଶୂନ୍ୟ) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    ଫେରନ୍ତୁ n;
}

ଶୂନ୍ୟ my_cleanup8(ପୂର୍ଣ୍ଣସଂଖ୍ୟା **p) {
    **p = 0x90;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test_cleanup8(ଶୂନ୍ୟ) {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା n = 42;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__((cleanup(my_cleanup8))) *p = &n;
    ଫେରନ୍ତୁ n;
}

ସ୍ଥିର ଶୂନ୍ୟ my_cleanupe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *p) {
    *p = 0x90;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i __attribute__ ((__cleanup__(check))) = 0, not_i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା chk = 0;
    (ଶୂନ୍ୟ)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) ଅକ୍ଷର oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    ଯଦି (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) ଅକ୍ଷର oh_i = 'f';
	ଦ୍ୱିଗୁଣ __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	ଯାଅ naaaaaaaa;
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
            ପୂର୍ଣ୍ଣସଂଖ୍ୟା __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    ଫେରନ୍ତୁ i;
}

ଶୂନ୍ୟ check2(ଅକ୍ଷର **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
