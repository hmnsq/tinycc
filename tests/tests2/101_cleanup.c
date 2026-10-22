extern 整数 printf(const char*, ...);
static 整数 glob_i = 0;

typedef struct { 整数 a; 整数 b; 整数 c; 整数 d; 整数 e; 整数 f; 整数 g; 整数 h; } tstl;
typedef struct { 整数 a; 整数 b; 整数 c; 整数 d; } tsti;
typedef struct { double a; double b; } tstd;
typedef struct { long double a; } tstld;
typedef struct { 整数 a; double b; } tstm;
typedef struct { float a; float b; float c; float d; } tstf;

void incr_glob_i(整数 *i)
{
  glob_i += *i;
  *i = -1;
}

#define INCR_GI {						\
    整数 i __attribute__ ((__cleanup__(incr_glob_i))) = 1;	\
  }

#define INCR_GI0 INCR_GI INCR_GI INCR_GI INCR_GI
#define INCR_GI1 INCR_GI0 INCR_GI0 INCR_GI0 INCR_GI0
#define INCR_GI2 INCR_GI1 INCR_GI1 INCR_GI1 INCR_GI1
#define INCR_GI3 INCR_GI2 INCR_GI2 INCR_GI2 INCR_GI2
#define INCR_GI4 INCR_GI3 INCR_GI3 INCR_GI3 INCR_GI3
#define INCR_GI5 INCR_GI4 INCR_GI4 INCR_GI4 INCR_GI4
#define INCR_GI6 INCR_GI5 INCR_GI5 INCR_GI5 INCR_GI5
#define INCR_GI7 INCR_GI6 INCR_GI6 INCR_GI6 INCR_GI6


void check2(char **hum);

void check(整数 *j)
{
    char * __attribute__ ((cleanup(check2))) stop_that = "wololo";
    整数 chk = 0;

    {
	char * __attribute__ ((cleanup(check2))) stop_that = "plop";

	{
	  non_plopage:
	    printf("---- %d\n", chk);
	}
	もし (!chk) {
	    chk = 1;
	    goto non_plopage;
	}
    }

    {
	char * __attribute__ ((cleanup(check2))) stop_that = "tata !";

	goto out;
	stop_that = "titi";
    }
  again:
    chk = 2;
    {
	char * __attribute__ ((cleanup(check2))) cascade1 = "1";
	{
	    char * __attribute__ ((cleanup(check2))) cascade2 = "2";
	    {
		char * __attribute__ ((cleanup(check2))) cascade3 = "3";

		goto out;
		cascade3 = "nope";
	    }
	}
    }
  out:
    もし (chk != 2)
	goto again;
    {
	{
	    char * __attribute__ ((cleanup(check2))) out = "last goto out";
	    ++chk;
	    もし (chk != 3)
		goto out;
	}
    }
    *j = -1;
    戻る;
}

void check_oh_i(char *oh_i)
{
    printf("c: %c\n", *oh_i);
    *oh_i = '0';
}

void goto_hell(double *f)
{
    printf("oo: %f\n", *f);
    *f = -1.0;
}

char *test()
{
    char *__attribute__ ((cleanup(check2))) str = "I don't think this should be print(but gcc got it wrong too)";

    戻る str;
}

void test_ret_subcall(char *that)
{
    printf("should be print before\n");
}

void test_ret()
{
    char *__attribute__ ((cleanup(check2))) that = "that";
    戻る test_ret_subcall(that);
}

void test_ret2()
{
  char *__attribute__ ((cleanup(check2))) that = "-that";
  {
    char *__attribute__ ((cleanup(check2))) that = "this should appear only once";
  }
  {
    char *__attribute__ ((cleanup(check2))) that = "-that2";
    戻る;
  }
}

void test2(void) {
    整数 chk = 0;
again:
    もし (!chk) {
        char * __attribute__ ((cleanup(check2))) stop_that = "test2";
        chk++;
        goto again;
    }
}

整数 test3(void) {
    char * __attribute__ ((cleanup(check2))) stop_that = "three";
    整数 chk = 0;

    もし (chk) {
        {
          outside:
	    {
            char * __attribute__ ((cleanup(check2))) stop_that = "two";
            printf("---- %d\n", chk);
	    }
        }
    }
    もし (!chk)
    {
        char * __attribute__ ((cleanup(check2))) stop_that = "one";

        もし (!chk) {
            chk = 1;
            goto outside;
        }
    }
    戻る 0;
}

void cl(整数 *ip)
{
    printf("%d\n", *ip);
    *ip = -1;
}

void loop_cleanups(void)
{
    __attribute__((cleanup(cl))) 整数 l = 1000;

    printf("-- loop 0 --\n");
    ために ( __attribute__((cleanup(cl))) 整数 i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) 整数 j = 100;
    }

    printf("-- loop 1 --\n");
    ために (__attribute__((cleanup(cl))) 整数 i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl)))  整数 j = 200;
        continue;
    }

    printf("-- loop 2 --\n");
    ために (__attribute__((cleanup(cl))) 整数 i = 0; i < 10; ++i) {
        __attribute__((cleanup(cl))) 整数 j = 300;
        break;
    }

    printf("-- loop 3 --\n");
    ために (整数 i = 0; i < 2; ++i) {
	__attribute__((cleanup(cl))) 整数 j = 400;
	switch (i) {
	case 0:
	    continue;
	default:
	{
	    __attribute__((cleanup(cl))) 整数 jj = 500;
	    break;
	}
	}
    }
    printf("after break\n");
}

void my_cleanup1(整数 *p) {
    printf("%d\n", *p);
    *p = 0x90;
}

整数 test_cleanup1(void) {
    整数 __attribute__((cleanup(my_cleanup1))) n = 42;
    戻る n;
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
    戻る n;
}

void my_cleanup3(tsti *p) {
    printf("%d %d %d %d\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tsti test_cleanup3(void) {
    tsti __attribute__((cleanup(my_cleanup3))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    戻る n;
}

void my_cleanup4(tstd *p) {
    printf("%g %g\n", p->a, p->b);
    p->a = 90.0; p->b = 91.0;
}

tstd test_cleanup4(void) {
    tstd __attribute__((cleanup(my_cleanup4))) n;
    n.a = 42.0; n.b = 43.0;
    戻る n;
}

void my_cleanup5(tstld *p) {
    printf("%Lf\n", p->a);
    p->a = 90.0;
}

tstld test_cleanup5(void) {
    tstld __attribute__((cleanup(my_cleanup5))) n;
    n.a = 42.0;
    戻る n;
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
    戻る n;
}

void my_cleanup7(tstf *p) {
    printf("%f %f %f %f\n", p->a, p->b, p->c, p->d);
    p->a = 0x90; p->b = 0x91; p->c = 0x92; p->d = 0x93;
}

tstf test_cleanup7(void) {
    tstf __attribute__((cleanup(my_cleanup7))) n;
    n.a = 42; n.b = 43; n.c = 44; n.d = 45;
    戻る n;
}

void my_cleanup8(整数 **p) {
    **p = 0x90;
}

整数 test_cleanup8(void) {
    整数 n = 42;
    整数 __attribute__((cleanup(my_cleanup8))) *p = &n;
    戻る n;
}

static void my_cleanupe(整数 *p) {
    *p = 0x90;
}

整数 メインページ()
{
    整数 i __attribute__ ((__cleanup__(check))) = 0, not_i;
    整数 chk = 0;
    (void)not_i;
    tstl tl;
    tsti ti;
    tstd td;
    tstld tld;
    tstm tm;
    tstf tf;

    {
	__attribute__ ((__cleanup__(check_oh_i))) char oh_i = 'o', o = 'a';
    }

    INCR_GI7;
    printf("glob_i: %d\n", glob_i);
 naaaaaaaa:
    もし (!chk) {
	__attribute__ ((__cleanup__(check_oh_i))) char oh_i = 'f';
	double __attribute__ ((__cleanup__(goto_hell))) f = 2.6;

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
            整数 __attribute__ ((cleanup(my_cleanupe))) n = 42;
            n; }));
    戻る i;
}

void check2(char **hum)
{
    printf("str: %s\n", *hum);
    *hum = "fail";
}
