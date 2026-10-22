ബാഹ്യ പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം*, ...);
സ്ഥിതം പൂർണ്ണസംഖ്യ glob_i = 0;

തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ a; പൂർണ്ണസംഖ്യ b; പൂർണ്ണസംഖ്യ c; പൂർണ്ണസംഖ്യ d; പൂർണ്ണസംഖ്യ e; പൂർണ്ണസംഖ്യ f; പൂർണ്ണസംഖ്യ g; പൂർണ്ണസംഖ്യ h; } tstl;
തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ a; പൂർണ്ണസംഖ്യ b; പൂർണ്ണസംഖ്യ c; പൂർണ്ണസംഖ്യ d; } tsti;
തരനിർവചനം ഘടന { ഇരട്ട a; ഇരട്ട b; } tstd;
തരനിർവചനം ഘടന { long ഇരട്ട a; } tstld;
തരനിർവചനം ഘടന { പൂർണ്ണസംഖ്യ a; ഇരട്ട b; } tstm;
തരനിർവചനം ഘടന { ദശാംശം a; ദശാംശം b; ദശാംശം c; ദശാംശം d; } tstf;

ശൂന്യം incr_glob_i(പൂർണ്ണസംഖ്യ *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    പൂർണ്ണസംഖ്യ i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


ശൂന്യം check2(അക്ഷരം **hum);

ശൂന്യം check(പൂർണ്ണസംഖ്യ *j)
{
    അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    പൂർണ്ണസംഖ്യ chk = 0;

    {
	അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	എങ്കിൽ (!chk) {
	    chk = 1;
	    പോകുക non_plopage;
	}
    }

    {
	അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	പോകുക out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	അക്ഷരം * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    അക്ഷരം * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		അക്ഷരം * __attribute__ ((cleanup(check2))) cascade3 = "3";

		പോകുക out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    എങ്കിൽ (chk != 2)
	പോകുക again;
    {
	{
	    അക്ഷരം * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    എങ്കിൽ (chk != 3)
		പോകുക out;
	}
    }
    *j = -1;
    തിരികെ;
}

ശൂന്യം check_oh_i(അക്ഷരം *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

ശൂന്യം goto_hell(ഇരട്ട *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

അക്ഷരം *test()
{
    അക്ഷരം *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    തിരികെ str;
}

ശൂന്യം test_ret_subcall(അക്ഷരം *that)
{
    printf("should be print before\n");
}

ശൂന്യം test_ret()
{
    അക്ഷരം *__attribute__ ((cleanup(check2))) that = "that";
    തിരികെ test_ret_subcall(that);
}

ശൂന്യം test_ret2()
{
  അക്ഷരം *__attribute__ ((cleanup(check2))) that = "-that";
  {
    അക്ഷരം *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    അക്ഷരം *__attribute__ ((cleanup(check2))) that = "-that2";
    തിരികെ;
  }
}

ശൂന്യം test2(ശൂന്യം) {
    പൂർണ്ണസംഖ്യ chk = 0;
again:
    എങ്കിൽ (!chk) {
        അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        പോകുക again;
    }
}

പൂർണ്ണസംഖ്യ test3(ശൂന്യം) {
    അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "three";
    പൂർണ്ണസംഖ്യ chk = 0;

    എങ്കിൽ (chk) {
        {
          outside:
	    {
            അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    എങ്കിൽ (!chk)
    {
        അക്ഷരം * __attribute__ ((cleanup(check2))) stop_that = "one";

        എങ്കിൽ (!chk) {
            chk = 1;
            പോകുക outside;
        }
    }
    തിരികെ 0;
}

ശൂന്യം cl(പൂർണ്ണസംഖ്യ *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

ശൂന്യം loop_cleanups(ശൂന്യം)
{
    __attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ l = 1000;

    printf("-- loop 0 --\n");
    വേണ്ടി ( __attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ j = 100;
    }

    printf("-- loop 1 --\n");
    വേണ്ടി (__attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  പൂർണ്ണസംഖ്യ j = 200;
        തുടരുക;
    }

    printf("-- loop 2 --\n");
    വേണ്ടി (__attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ j = 300;
        നിർത്തുക;
    }

    printf("-- loop 3 --\n");
    വേണ്ടി (പൂർണ്ണസംഖ്യ i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ j = 400;
	തിരഞ്ഞെടുപ്പ് (i) {
	അവസ്ഥ 0:
	    തുടരുക;
	സ്ഥിരസ്ഥിതി:
	{
	    __attribute__((cleanup(cl))) പൂർണ്ണസംഖ്യ jj = 500;
	    നിർത്തുക;
	}
	}
    }
    printf("after break\n");
}

ശൂന്യം my_cleanup1(പൂർണ്ണസംഖ്യ *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

പൂർണ്ണസംഖ്യ test_cleanup1(ശൂന്യം) {
    പൂർണ്ണസംഖ്യ __attribute__((cleanup(my_cleanup1))) n = 42;
    തിരികെ n;
}

ശൂന്യം my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(ശൂന്യം) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    തിരികെ n;
}

ശൂന്യം my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(ശൂന്യം) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    തിരികെ n;
}

ശൂന്യം my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(ശൂന്യം) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    തിരികെ n;
}

ശൂന്യം my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(ശൂന്യം) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    തിരികെ n;
}

ശൂന്യം my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(ശൂന്യം) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    തിരികെ n;
}

ശൂന്യം my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(ശൂന്യം) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    തിരികെ n;
}

ശൂന്യം my_cleanup8(പൂർണ്ണസംഖ്യ **p) {
    **p = 0x90;
}

പൂർണ്ണസംഖ്യ test_cleanup8(ശൂന്യം) {
    പൂർണ്ണസംഖ്യ n = 42;
    പൂർണ്ണസംഖ്യ __attribute__((cleanup(my_cleanup8))) *p = &n;
    തിരികെ n;
}

സ്ഥിതം ശൂന്യം my_cleanupe(പൂർണ്ണസംഖ്യ *p) {
    *p = 0x90;
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
    പൂർണ്ണസംഖ്യ i __attribute__ ((__cleanup__(check))) = 0, not_i;
    പൂർണ്ണസംഖ്യ chk = 0;
    (ശൂന്യം)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) അക്ഷരം oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    എങ്കിൽ (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) അക്ഷരം oh_i = 'f';
	ഇരട്ട __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	പോകുക naaaaaaaa;
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
            പൂർണ്ണസംഖ്യ __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    തിരികെ i;
}

ശൂന്യം check2(അക്ഷരം **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
