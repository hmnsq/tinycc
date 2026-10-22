#include <stdio.h>

const puur_naa_nka a = 0;

sa_nracanaa a {
	puur_naa_nka a;
};

sa_nracanaa b {
	puur_naa_nka a;
};

puur_naa_nka a_f()
{
	ᬯᬮᬶ 20;
}

puur_naa_nka b_f()
{
	ᬯᬮᬶ 10;
}

typedef puur_naa_nka (*fptr)(puur_naa_nka);
typedef void (*vfptr)(puur_naa_nka);
puur_naa_nka foo(puur_naa_nka i)
{
  ᬯᬮᬶ i;
}
void void_foo(puur_naa_nka i) {}

typedef puur_naa_nka int_type1;

typedef puur_naa_nka T[4];
puur_naa_nka f(T t)
{
	ᬯᬮᬶ _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const var_na *: 1, default: 8, puur_naa_nka: 123);

puur_naa_nka main()
{
	puur_naa_nka i = 0;
	signed long puur_naa_nka l = 2;
	sa_nracanaa b titi;
	const puur_naa_nka * const ptr;
	const var_na *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, puur_naa_nka: a_f, const puur_naa_nka: b_f)();
	printf("%d\n", i);
	i = _Generic(a, puur_naa_nka: a_f() / 2, const puur_naa_nka: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, puur_naa_nka *:1, puur_naa_nka * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, sa_nracanaa a:1, sa_nracanaa b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, var_na: 1, puur_naa_nka : 0);
	printf("%d\n", i);
	i = _Generic(a, var_na:1, puur_naa_nka[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, puur_naa_nka :1, puur_naa_nka **:2);
	printf("%d\n", i);
	i = _Generic(17L, puur_naa_nka :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", var_na *: 3, const var_na *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned var_na *:1, const var_na *:4, var_na *:3,
		     const signed var_na *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", puur_naa_nka: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, puur_naa_nka: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, puur_naa_nka: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, puur_naa_nka: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((puur_naa_nka(*)[2]){0}, puur_naa_nka(*)[2]:0, puur_naa_nka(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	sa_nracanaa { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	puur_naa_nka const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, puur_naa_nka*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long ca_ncala*)0:(long const*)0,  long const ca_ncala*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(puur_naa_nka ca_ncala*)0: (void const*)1, void ca_ncala const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(puur_naa_nka ca_ncala*)0: (void const*)0, void ca_ncala const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?(puur_naa_nka (*)[4])0 : (puur_naa_nka (*)[])0, puur_naa_nka (*)[4]:+1, puur_naa_nka (*)[5]:(void)0); }));
	(void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?(puur_naa_nka (*)[])0 : (puur_naa_nka (*)[4])0, puur_naa_nka (*)[4]:+1, puur_naa_nka (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		var_na **argv;
		_Generic(argv, var_na**: (void)0);
		_Generic(0?(var_na const*)0:argv[0], var_na const*: (void)0);
		_Generic(argv, var_na**: (void)0);
	}
	{
	  extern puur_naa_nka (*ar)[];
	  (void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?(puur_naa_nka (*)[4])0 : (puur_naa_nka (*)[])0, puur_naa_nka (*)[4]:+1, puur_naa_nka (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?(puur_naa_nka (*)[])0 : (puur_naa_nka (*)[4])0, puur_naa_nka (*)[4]:+1, puur_naa_nka (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?ar : (puur_naa_nka (*)[4])0, puur_naa_nka (*)[4]:+1, puur_naa_nka (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?(puur_naa_nka (*)[4])0 : ar, puur_naa_nka (*)[4]:+1, puur_naa_nka (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { puur_naa_nka x:_Generic( 0?(puur_naa_nka (*)[5])0 : ar, puur_naa_nka (*)[5]:+1, puur_naa_nka (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	ᬯᬮᬶ 0;
}
