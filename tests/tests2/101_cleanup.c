बाह्य पूर्णाङ्क printf(ध्रुव वर्ण*, ...);
स्थिर पूर्णाङ्क glob_i = 0;

प्रकारनिर्देश संरचना { पूर्णाङ्क a; पूर्णाङ्क b; पूर्णाङ्क c; पूर्णाङ्क d; पूर्णाङ्क e; पूर्णाङ्क f; पूर्णाङ्क g; पूर्णाङ्क h; } tstl;
प्रकारनिर्देश संरचना { पूर्णाङ्क a; पूर्णाङ्क b; पूर्णाङ्क c; पूर्णाङ्क d; } tsti;
प्रकारनिर्देश संरचना { द्विगुण a; द्विगुण b; } tstd;
प्रकारनिर्देश संरचना { long द्विगुण a; } tstld;
प्रकारनिर्देश संरचना { पूर्णाङ्क a; द्विगुण b; } tstm;
प्रकारनिर्देश संरचना { भिन्न a; भिन्न b; भिन्न c; भिन्न d; } tstf;

शून्य incr_glob_i(पूर्णाङ्क *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    पूर्णाङ्क i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


शून्य check2(वर्ण **hum);

शून्य check(पूर्णाङ्क *j)
{
    वर्ण * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    पूर्णाङ्क chk = 0;

    {
	वर्ण * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	यदि (!chk) {
	    chk = 1;
	    गच्छ non_plopage;
	}
    }

    {
	वर्ण * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	गच्छ out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	वर्ण * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    वर्ण * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		वर्ण * __attribute__ ((cleanup(check2))) cascade3 = "3";

		गच्छ out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    यदि (chk != 2)
	गच्छ again;
    {
	{
	    वर्ण * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    यदि (chk != 3)
		गच्छ out;
	}
    }
    *j = -1;
    प्रत्यागम;
}

शून्य check_oh_i(वर्ण *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

शून्य goto_hell(द्विगुण *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

वर्ण *test()
{
    वर्ण *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    प्रत्यागम str;
}

शून्य test_ret_subcall(वर्ण *that)
{
    printf("should be print before\n");
}

शून्य test_ret()
{
    वर्ण *__attribute__ ((cleanup(check2))) that = "that";
    प्रत्यागम test_ret_subcall(that);
}

शून्य test_ret2()
{
  वर्ण *__attribute__ ((cleanup(check2))) that = "-that";
  {
    वर्ण *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    वर्ण *__attribute__ ((cleanup(check2))) that = "-that2";
    प्रत्यागम;
  }
}

शून्य test2(शून्य) {
    पूर्णाङ्क chk = 0;
again:
    यदि (!chk) {
        वर्ण * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        गच्छ again;
    }
}

पूर्णाङ्क test3(शून्य) {
    वर्ण * __attribute__ ((cleanup(check2))) stop_that = "three";
    पूर्णाङ्क chk = 0;

    यदि (chk) {
        {
          outside:
	    {
            वर्ण * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    यदि (!chk)
    {
        वर्ण * __attribute__ ((cleanup(check2))) stop_that = "one";

        यदि (!chk) {
            chk = 1;
            गच्छ outside;
        }
    }
    प्रत्यागम 0;
}

शून्य cl(पूर्णाङ्क *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

शून्य loop_cleanups(शून्य)
{
    __attribute__((cleanup(cl))) पूर्णाङ्क l = 1000;

    printf("-- loop 0 --\n");
    प्रति ( __attribute__((cleanup(cl))) पूर्णाङ्क i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) पूर्णाङ्क j = 100;
    }

    printf("-- loop 1 --\n");
    प्रति (__attribute__((cleanup(cl))) पूर्णाङ्क i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  पूर्णाङ्क j = 200;
        अनुवर्त;
    }

    printf("-- loop 2 --\n");
    प्रति (__attribute__((cleanup(cl))) पूर्णाङ्क i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) पूर्णाङ्क j = 300;
        भङ्ग;
    }

    printf("-- loop 3 --\n");
    प्रति (पूर्णाङ्क i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) पूर्णाङ्क j = 400;
	विकल्प (i) {
	पक्ष 0:
	    अनुवर्त;
	स्वभाव:
	{
	    __attribute__((cleanup(cl))) पूर्णाङ्क jj = 500;
	    भङ्ग;
	}
	}
    }
    printf("after break\n");
}

शून्य my_cleanup1(पूर्णाङ्क *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

पूर्णाङ्क test_cleanup1(शून्य) {
    पूर्णाङ्क __attribute__((cleanup(my_cleanup1))) n = 42;
    प्रत्यागम n;
}

शून्य my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(शून्य) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    प्रत्यागम n;
}

शून्य my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(शून्य) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    प्रत्यागम n;
}

शून्य my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(शून्य) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    प्रत्यागम n;
}

शून्य my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(शून्य) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    प्रत्यागम n;
}

शून्य my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(शून्य) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    प्रत्यागम n;
}

शून्य my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(शून्य) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    प्रत्यागम n;
}

शून्य my_cleanup8(पूर्णाङ्क **p) {
    **p = 0x90;
}

पूर्णाङ्क test_cleanup8(शून्य) {
    पूर्णाङ्क n = 42;
    पूर्णाङ्क __attribute__((cleanup(my_cleanup8))) *p = &n;
    प्रत्यागम n;
}

स्थिर शून्य my_cleanupe(पूर्णाङ्क *p) {
    *p = 0x90;
}

पूर्णाङ्क main()
{
    पूर्णाङ्क i __attribute__ ((__cleanup__(check))) = 0, not_i;
    पूर्णाङ्क chk = 0;
    (शून्य)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) वर्ण oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    यदि (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) वर्ण oh_i = 'f';
	द्विगुण __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	गच्छ naaaaaaaa;
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
            पूर्णाङ्क __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    प्रत्यागम i;
}

शून्य check2(वर्ण **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
