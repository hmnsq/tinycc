بیرونی صحیح printf(ثابت نویسه*, ...);
ایستا صحیح glob_i = 0;

تعریفنوع ساختار { صحیح a; صحیح b; صحیح c; صحیح d; صحیح e; صحیح f; صحیح g; صحیح h; } tstl;
تعریفنوع ساختار { صحیح a; صحیح b; صحیح c; صحیح d; } tsti;
تعریفنوع ساختار { دوگانه a; دوگانه b; } tstd;
تعریفنوع ساختار { long دوگانه a; } tstld;
تعریفنوع ساختار { صحیح a; دوگانه b; } tstm;
تعریفنوع ساختار { اعشاری a; اعشاری b; اعشاری c; اعشاری d; } tstf;

تهی incr_glob_i(صحیح *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    صحیح i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


تهی check2(نویسه **hum);

تهی check(صحیح *j)
{
    نویسه * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    صحیح chk = 0;

    {
	نویسه * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	اگر (!chk) {
	    chk = 1;
	    برو non_plopage;
	}
    }

    {
	نویسه * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	برو out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	نویسه * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    نویسه * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		نویسه * __attribute__ ((cleanup(check2))) cascade3 = "3";

		برو out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    اگر (chk != 2)
	برو again;
    {
	{
	    نویسه * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    اگر (chk != 3)
		برو out;
	}
    }
    *j = -1;
    بازگشت;
}

تهی check_oh_i(نویسه *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

تهی goto_hell(دوگانه *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

نویسه *test()
{
    نویسه *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    بازگشت str;
}

تهی test_ret_subcall(نویسه *that)
{
    printf("should be print before\n");
}

تهی test_ret()
{
    نویسه *__attribute__ ((cleanup(check2))) that = "that";
    بازگشت test_ret_subcall(that);
}

تهی test_ret2()
{
  نویسه *__attribute__ ((cleanup(check2))) that = "-that";
  {
    نویسه *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    نویسه *__attribute__ ((cleanup(check2))) that = "-that2";
    بازگشت;
  }
}

تهی test2(تهی) {
    صحیح chk = 0;
again:
    اگر (!chk) {
        نویسه * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        برو again;
    }
}

صحیح test3(تهی) {
    نویسه * __attribute__ ((cleanup(check2))) stop_that = "three";
    صحیح chk = 0;

    اگر (chk) {
        {
          outside:
	    {
            نویسه * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    اگر (!chk)
    {
        نویسه * __attribute__ ((cleanup(check2))) stop_that = "one";

        اگر (!chk) {
            chk = 1;
            برو outside;
        }
    }
    بازگشت 0;
}

تهی cl(صحیح *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

تهی loop_cleanups(تهی)
{
    __attribute__((cleanup(cl))) صحیح l = 1000;

    printf("-- loop 0 --\n");
    برای ( __attribute__((cleanup(cl))) صحیح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) صحیح j = 100;
    }

    printf("-- loop 1 --\n");
    برای (__attribute__((cleanup(cl))) صحیح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  صحیح j = 200;
        ادامه;
    }

    printf("-- loop 2 --\n");
    برای (__attribute__((cleanup(cl))) صحیح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) صحیح j = 300;
        بشکن;
    }

    printf("-- loop 3 --\n");
    برای (صحیح i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) صحیح j = 400;
	انتخاب (i) {
	حالت 0:
	    ادامه;
	پیشفرض:
	{
	    __attribute__((cleanup(cl))) صحیح jj = 500;
	    بشکن;
	}
	}
    }
    printf("after break\n");
}

تهی my_cleanup1(صحیح *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

صحیح test_cleanup1(تهی) {
    صحیح __attribute__((cleanup(my_cleanup1))) n = 42;
    بازگشت n;
}

تهی my_cleanup2(tstl *p) {
    printf("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(تهی) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    بازگشت n;
}

تهی my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(تهی) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    بازگشت n;
}

تهی my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(تهی) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    بازگشت n;
}

تهی my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(تهی) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    بازگشت n;
}

تهی my_cleanup6(tstm *p) {
    printf("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(تهی) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    بازگشت n;
}

تهی my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(تهی) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    بازگشت n;
}

تهی my_cleanup8(صحیح **p) {
    **p = 0x90;
}

صحیح test_cleanup8(تهی) {
    صحیح n = 42;
    صحیح __attribute__((cleanup(my_cleanup8))) *p = &n;
    بازگشت n;
}

ایستا تهی my_cleanupe(صحیح *p) {
    *p = 0x90;
}

صحیح اصلی()
{
    صحیح i __attribute__ ((__cleanup__(check))) = 0, not_i;
    صحیح chk = 0;
    (تهی)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) نویسه oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    اگر (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) نویسه oh_i = 'f';
	دوگانه __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	برو naaaaaaaa;
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
            صحیح __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    بازگشت i;
}

تهی check2(نویسه **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
