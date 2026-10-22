வெளி முழு printf(மாறிலி எழுத்து*, ...);
நிலையான முழு glob_i = 0;

வகைவரை கட்டமைப்பு { முழு a; முழு b; முழு c; முழு d; முழு e; முழு f; முழு g; முழு h; } tstl;
வகைவரை கட்டமைப்பு { முழு a; முழு b; முழு c; முழு d; } tsti;
வகைவரை கட்டமைப்பு { இரட்டை a; இரட்டை b; } tstd;
வகைவரை கட்டமைப்பு { long இரட்டை a; } tstld;
வகைவரை கட்டமைப்பு { முழு a; இரட்டை b; } tstm;
வகைவரை கட்டமைப்பு { தசம a; தசம b; தசம c; தசம d; } tstf;

வெறுமை incr_glob_i(முழு *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    முழு i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


வெறுமை check2(எழுத்து **hum);

வெறுமை check(முழு *j)
{
    எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    முழு chk = 0;

    {
	எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	எனில் (!chk) {
	    chk = 1;
	    செல் non_plopage;
	}
    }

    {
	எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	செல் out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	எழுத்து * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    எழுத்து * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		எழுத்து * __attribute__ ((cleanup(check2))) cascade3 = "3";

		செல் out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    எனில் (chk != 2)
	செல் again;
    {
	{
	    எழுத்து * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    எனில் (chk != 3)
		செல் out;
	}
    }
    *j = -1;
    திரும்பு;
}

வெறுமை check_oh_i(எழுத்து *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

வெறுமை goto_hell(இரட்டை *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

எழுத்து *test()
{
    எழுத்து *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    திரும்பு str;
}

வெறுமை test_ret_subcall(எழுத்து *that)
{
    printf("should be print before\n");
}

வெறுமை test_ret()
{
    எழுத்து *__attribute__ ((cleanup(check2))) that = "that";
    திரும்பு test_ret_subcall(that);
}

வெறுமை test_ret2()
{
  எழுத்து *__attribute__ ((cleanup(check2))) that = "-that";
  {
    எழுத்து *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    எழுத்து *__attribute__ ((cleanup(check2))) that = "-that2";
    திரும்பு;
  }
}

வெறுமை test2(வெறுமை) {
    முழு chk = 0;
again:
    எனில் (!chk) {
        எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        செல் again;
    }
}

முழு test3(வெறுமை) {
    எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "three";
    முழு chk = 0;

    எனில் (chk) {
        {
          outside:
	    {
            எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    எனில் (!chk)
    {
        எழுத்து * __attribute__ ((cleanup(check2))) stop_that = "one";

        எனில் (!chk) {
            chk = 1;
            செல் outside;
        }
    }
    திரும்பு 0;
}

வெறுமை cl(முழு *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

வெறுமை loop_cleanups(வெறுமை)
{
    __attribute__((cleanup(cl))) முழு l = 1000;

    printf("-- loop 0 --\n");
    க்கு ( __attribute__((cleanup(cl))) முழு i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) முழு j = 100;
    }

    printf("-- loop 1 --\n");
    க்கு (__attribute__((cleanup(cl))) முழு i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  முழு j = 200;
        தொடர்;
    }

    printf("-- loop 2 --\n");
    க்கு (__attribute__((cleanup(cl))) முழு i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) முழு j = 300;
        நிறுத்து;
    }

    printf("-- loop 3 --\n");
    க்கு (முழு i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) முழு j = 400;
	தேர்வு (i) {
	நிலை 0:
	    தொடர்;
	இயல்பு:
	{
	    __attribute__((cleanup(cl))) முழு jj = 500;
	    நிறுத்து;
	}
	}
    }
    printf("after break\n");
}

வெறுமை my_cleanup1(முழு *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

முழு test_cleanup1(வெறுமை) {
    முழு __attribute__((cleanup(my_cleanup1))) n = 42;
    திரும்பு n;
}

வெறுமை my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(வெறுமை) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    திரும்பு n;
}

வெறுமை my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(வெறுமை) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    திரும்பு n;
}

வெறுமை my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(வெறுமை) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    திரும்பு n;
}

வெறுமை my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(வெறுமை) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    திரும்பு n;
}

வெறுமை my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(வெறுமை) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    திரும்பு n;
}

வெறுமை my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(வெறுமை) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    திரும்பு n;
}

வெறுமை my_cleanup8(முழு **p) {
    **p = 0x90;
}

முழு test_cleanup8(வெறுமை) {
    முழு n = 42;
    முழு __attribute__((cleanup(my_cleanup8))) *p = &n;
    திரும்பு n;
}

நிலையான வெறுமை my_cleanupe(முழு *p) {
    *p = 0x90;
}

முழு முதன்மை()
{
    முழு i __attribute__ ((__cleanup__(check))) = 0, not_i;
    முழு chk = 0;
    (வெறுமை)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) எழுத்து oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    எனில் (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) எழுத்து oh_i = 'f';
	இரட்டை __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	செல் naaaaaaaa;
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
            முழு __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    திரும்பு i;
}

வெறுமை check2(எழுத்து **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
