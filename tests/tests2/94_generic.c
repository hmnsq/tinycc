#include <stdio.h>

const පූර්ණ_සංඛ්‍යා a = 0;

sa_nracanaa a {
	පූර්ණ_සංඛ්‍යා a;
};

sa_nracanaa b {
	පූර්ණ_සංඛ්‍යා a;
};

පූර්ණ_සංඛ්‍යා a_f()
{
	ආපසු 20;
}

පූර්ණ_සංඛ්‍යා b_f()
{
	ආපසු 10;
}

typedef පූර්ණ_සංඛ්‍යා (*fptr)(පූර්ණ_සංඛ්‍යා);
typedef void (*vfptr)(පූර්ණ_සංඛ්‍යා);
පූර්ණ_සංඛ්‍යා foo(පූර්ණ_සංඛ්‍යා i)
{
  ආපසු i;
}
void void_foo(පූර්ණ_සංඛ්‍යා i) {}

typedef පූර්ණ_සංඛ්‍යා int_type1;

typedef පූර්ණ_සංඛ්‍යා T[4];
පූර්ණ_සංඛ්‍යා f(T t)
{
	ආපසු _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const var_na *: 1, default: 8, පූර්ණ_සංඛ්‍යා: 123);

පූර්ණ_සංඛ්‍යා main()
{
	පූර්ණ_සංඛ්‍යා i = 0;
	signed long පූර්ණ_සංඛ්‍යා l = 2;
	sa_nracanaa b titi;
	const පූර්ණ_සංඛ්‍යා * const ptr;
	const var_na *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, පූර්ණ_සංඛ්‍යා: a_f, const පූර්ණ_සංඛ්‍යා: b_f)();
	printf("%d\n", i);
	i = _Generic(a, පූර්ණ_සංඛ්‍යා: a_f() / 2, const පූර්ණ_සංඛ්‍යා: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, පූර්ණ_සංඛ්‍යා *:1, පූර්ණ_සංඛ්‍යා * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, sa_nracanaa a:1, sa_nracanaa b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, var_na: 1, පූර්ණ_සංඛ්‍යා : 0);
	printf("%d\n", i);
	i = _Generic(a, var_na:1, පූර්ණ_සංඛ්‍යා[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, පූර්ණ_සංඛ්‍යා :1, පූර්ණ_සංඛ්‍යා **:2);
	printf("%d\n", i);
	i = _Generic(17L, පූර්ණ_සංඛ්‍යා :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", var_na *: 3, const var_na *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned var_na *:1, const var_na *:4, var_na *:3,
		     const signed var_na *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", පූර්ණ_සංඛ්‍යා: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, පූර්ණ_සංඛ්‍යා: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, පූර්ණ_සංඛ්‍යා: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, පූර්ණ_සංඛ්‍යා: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((පූර්ණ_සංඛ්‍යා(*)[2]){0}, පූර්ණ_සංඛ්‍යා(*)[2]:0, පූර්ණ_සංඛ්‍යා(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	sa_nracanaa { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	පූර්ණ_සංඛ්‍යා const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, පූර්ණ_සංඛ්‍යා*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long ca_ncala*)0:(long const*)0,  long const ca_ncala*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(පූර්ණ_සංඛ්‍යා ca_ncala*)0: (void const*)1, void ca_ncala const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(පූර්ණ_සංඛ්‍යා ca_ncala*)0: (void const*)0, void ca_ncala const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?(පූර්ණ_සංඛ්‍යා (*)[4])0 : (පූර්ණ_සංඛ්‍යා (*)[])0, පූර්ණ_සංඛ්‍යා (*)[4]:+1, පූර්ණ_සංඛ්‍යා (*)[5]:(void)0); }));
	(void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?(පූර්ණ_සංඛ්‍යා (*)[])0 : (පූර්ණ_සංඛ්‍යා (*)[4])0, පූර්ණ_සංඛ්‍යා (*)[4]:+1, පූර්ණ_සංඛ්‍යා (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		var_na **argv;
		_Generic(argv, var_na**: (void)0);
		_Generic(0?(var_na const*)0:argv[0], var_na const*: (void)0);
		_Generic(argv, var_na**: (void)0);
	}
	{
	  extern පූර්ණ_සංඛ්‍යා (*ar)[];
	  (void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?(පූර්ණ_සංඛ්‍යා (*)[4])0 : (පූර්ණ_සංඛ්‍යා (*)[])0, පූර්ණ_සංඛ්‍යා (*)[4]:+1, පූර්ණ_සංඛ්‍යා (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?(පූර්ණ_සංඛ්‍යා (*)[])0 : (පූර්ණ_සංඛ්‍යා (*)[4])0, පූර්ණ_සංඛ්‍යා (*)[4]:+1, පූර්ණ_සංඛ්‍යා (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?ar : (පූර්ණ_සංඛ්‍යා (*)[4])0, පූර්ණ_සංඛ්‍යා (*)[4]:+1, පූර්ණ_සංඛ්‍යා (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?(පූර්ණ_සංඛ්‍යා (*)[4])0 : ar, පූර්ණ_සංඛ්‍යා (*)[4]:+1, පූර්ණ_සංඛ්‍යා (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { පූර්ණ_සංඛ්‍යා x:_Generic( 0?(පූර්ණ_සංඛ්‍යා (*)[5])0 : ar, පූර්ණ_සංඛ්‍යා (*)[5]:+1, පූර්ණ_සංඛ්‍යා (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	ආපසු 0;
}
