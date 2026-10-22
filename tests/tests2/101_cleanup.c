خارجی صحیح لکھو(ثابت حرف*, ...);
ساکن صحیح glob_i = 0;

قسمتعریف ساخت { صحیح a; صحیح b; صحیح c; صحیح d; صحیح e; صحیح f; صحیح g; صحیح h; } tstl;
قسمتعریف ساخت { صحیح a; صحیح b; صحیح c; صحیح d; } tsti;
قسمتعریف ساخت { دوہرا a; دوہرا b; } tstd;
قسمتعریف ساخت { طویل دوہرا a; } tstld;
قسمتعریف ساخت { صحیح a; دوہرا b; } tstm;
قسمتعریف ساخت { اعشاری a; اعشاری b; اعشاری c; اعشاری d; } tstf;

خالی incr_glob_i(صحیح *i)
{
  glob_i += *i;
  *i = -1;
}

#تعریف_کرو INCR_GI {						\
    صحیح i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#تعریف_کرو INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#تعریف_کرو INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#تعریف_کرو INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#تعریف_کرو INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#تعریف_کرو INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#تعریف_کرو INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#تعریف_کرو INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#تعریف_کرو INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


خالی check2(حرف **hum);

خالی check(صحیح *j)
{
    حرف * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    صحیح chk = 0;

    {
	حرف * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    لکھو("---- %d\n", chk);
	}
	اگر (!chk) {
	    chk = 1;
	    جاؤ non_plopage;
	}
    }

    {
	حرف * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	جاؤ برآمد;
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

		جاؤ برآمد;
		cascade3 = "nope";
	    }
	}
    }
  برآمد:
    اگر (chk != 2)
	جاؤ again;
    {
	{
	    حرف * __attribute__ ((cleanup(check2))) برآمد = "last goto out";
	    ++chk;
	    اگر (chk != 3)
		جاؤ برآمد;
	}
    }
    *j = -1;
    واپس;
}

خالی check_oh_i(حرف *oh_i)
{
    لکھو("c: %c\n", *oh_i);
    *oh_i = '0';
}

خالی goto_hell(دوہرا *f)
{
    لکھو("oo: %f\n", *f);
    *f = -1.0;
}

حرف *test()
{
    حرف *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    واپس str;
}

خالی test_ret_subcall(حرف *that)
{
    لکھو("should be print before\n");
}

خالی test_ret()
{
    حرف *__attribute__ ((cleanup(check2))) that = "that";
    واپس test_ret_subcall(that);
}

خالی test_ret2()
{
  حرف *__attribute__ ((cleanup(check2))) that = "-that";
  {
    حرف *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    حرف *__attribute__ ((cleanup(check2))) that = "-that2";
    واپس;
  }
}

خالی test2(خالی) {
    صحیح chk = 0;
again:
    اگر (!chk) {
        حرف * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        جاؤ again;
    }
}

صحیح test3(خالی) {
    حرف * __attribute__ ((cleanup(check2))) stop_that = "three";
    صحیح chk = 0;

    اگر (chk) {
        {
          outside:
	    {
            حرف * __attribute__ ((cleanup(check2))) stop_that = "two";
            لکھو("---- %d\n", chk);
	    }
        }
    }
    اگر (!chk)
    {
        حرف * __attribute__ ((cleanup(check2))) stop_that = "one";

        اگر (!chk) {
            chk = 1;
            جاؤ outside;
        }
    }
    واپس 0;
}

خالی cl(صحیح *ip)
{
    لکھو("%d\n", *ip);
    *ip = -1;
}

خالی loop_cleanups(خالی)
{
    __attribute__((cleanup(cl))) صحیح l = 1000;

    لکھو("-- loop 0 --\n");
    برائے ( __attribute__((cleanup(cl))) صحیح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) صحیح j = 100;
    }

    لکھو("-- loop 1 --\n");
    برائے (__attribute__((cleanup(cl))) صحیح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  صحیح j = 200;
        جاری;
    }

    لکھو("-- loop 2 --\n");
    برائے (__attribute__((cleanup(cl))) صحیح i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) صحیح j = 300;
        توڑو;
    }

    لکھو("-- loop 3 --\n");
    برائے (صحیح i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) صحیح j = 400;
	انتخاب (i) {
	حالت 0:
	    جاری;
	طےشدہ:
	{
	    __attribute__((cleanup(cl))) صحیح jj = 500;
	    توڑو;
	}
	}
    }
    لکھو("after break\n");
}

خالی my_cleanup1(صحیح *p) {
    لکھو("%d\n", *p);
    *p = 0x90;
}

صحیح test_cleanup1(خالی) {
    صحیح __attribute__((cleanup(my_cleanup1))) n = 42;
    واپس n;
}

خالی my_cleanup2(tstl *p) {
    لکھو("%d %d %d %d %d %d %d %d\n", p->a, p->b, p->c, p->d,
			                p->e, p->f, p->g, p->h);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
    p->e = 0x94; p->f = 0x95; p->g = 0x96; p->h = 0x97;
}

tstl test_cleanup2(خالی) {
    tstl __attribute__((cleanup(my_cleanup2))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    n.e = 46; n.f = 47; n.g = 48; n.h = 49;
    واپس n;
}

خالی my_cleanup3(tsti *p) {
    لکھو("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(خالی) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    واپس n;
}

خالی my_cleanup4(tstd *p) {
    لکھو("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(خالی) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    واپس n;
}

خالی my_cleanup5(tstld *p) {
    لکھو("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(خالی) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    واپس n;
}

خالی my_cleanup6(tstm *p) {
    لکھو("%d %g\n", p->a, p->b);
    p->a = 90;
    p->b = 91.0;
}

tstm test_cleanup6(خالی) {
    tstm __attribute__((cleanup(my_cleanup6))) n;
    n.a = 42;
    n.b = 43.0;
    واپس n;
}

خالی my_cleanup7(tstf *p) {
    لکھو("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(خالی) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    واپس n;
}

خالی my_cleanup8(صحیح **p) {
    **p = 0x90;
}

صحیح test_cleanup8(خالی) {
    صحیح n = 42;
    صحیح __attribute__((cleanup(my_cleanup8))) *p = &n;
    واپس n;
}

ساکن خالی my_cleanupe(صحیح *p) {
    *p = 0x90;
}

صحیح مین()
{
    صحیح i __attribute__ ((__cleanup__(check))) = 0, not_i;
    صحیح chk = 0;
    (خالی)not_i;
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
    لکھو("glob_i: %d\n", glob_i);
 naaaaaaaa:
    اگر (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) حرف oh_i = 'f';
	دوہرا __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

	chk = 1;
	جاؤ naaaaaaaa;
    }
    i = 105;
    لکھو("because what if free was call inside cleanup function %s\n", test());
    test_ret();
    test_ret2();
    test2();
    test3();
    loop_cleanups();
    لکھو("%d\n", test_cleanup1());
    tl = test_cleanup2();
    لکھو("%d %d %d %d %d %d %d %d\n", tl.a, tl.b, tl.c, tl.d,
					tl.e, tl.f, tl.g, tl.h);
    ti = test_cleanup3();
    لکھو("%d %d %d %d\n", ti.a, ti.b, ti.c, ti.d);
    td = test_cleanup4();
    لکھو("%g %g\n", td.a, td.b);
    tld = test_cleanup5();
    لکھو("%Lf\n", tld.a);
    tm = test_cleanup6();
    لکھو("%d %g\n", tm.a, tm.b);
    tf = test_cleanup7();
    لکھو("%f %f %f %f\n", tf.a, tf.b, tf.c, tf.d);
    لکھو("%d\n", test_cleanup8());
    لکھو("%d\n", ({
            صحیح __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    واپس i;
}

خالی check2(حرف **hum)
{
    لکھو("str: %s\n", *hum);
    *hum = "fail";
}
