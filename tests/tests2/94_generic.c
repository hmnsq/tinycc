#include <stdio.h>

const ཧྲིལ a = 0;

sa_nracanaa a {
	ཧྲིལ a;
};

sa_nracanaa b {
	ཧྲིལ a;
};

ཧྲིལ a_f()
{
	ལོག 20;
}

ཧྲིལ b_f()
{
	ལོག 10;
}

typedef ཧྲིལ (*fptr)(ཧྲིལ);
typedef void (*vfptr)(ཧྲིལ);
ཧྲིལ foo(ཧྲིལ i)
{
  ལོག i;
}
void void_foo(ཧྲིལ i) {}

typedef ཧྲིལ int_type1;

typedef ཧྲིལ T[4];
ཧྲིལ f(T t)
{
	ལོག _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const var_na *: 1, default: 8, ཧྲིལ: 123);

ཧྲིལ main()
{
	ཧྲིལ i = 0;
	signed long ཧྲིལ l = 2;
	sa_nracanaa b titi;
	const ཧྲིལ * const ptr;
	const var_na *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, ཧྲིལ: a_f, const ཧྲིལ: b_f)();
	printf("%d\n", i);
	i = _Generic(a, ཧྲིལ: a_f() / 2, const ཧྲིལ: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, ཧྲིལ *:1, ཧྲིལ * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, sa_nracanaa a:1, sa_nracanaa b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, var_na: 1, ཧྲིལ : 0);
	printf("%d\n", i);
	i = _Generic(a, var_na:1, ཧྲིལ[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, ཧྲིལ :1, ཧྲིལ **:2);
	printf("%d\n", i);
	i = _Generic(17L, ཧྲིལ :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", var_na *: 3, const var_na *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned var_na *:1, const var_na *:4, var_na *:3,
		     const signed var_na *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", ཧྲིལ: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, ཧྲིལ: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, ཧྲིལ: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, ཧྲིལ: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((ཧྲིལ(*)[2]){0}, ཧྲིལ(*)[2]:0, ཧྲིལ(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	sa_nracanaa { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	ཧྲིལ const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, ཧྲིལ*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long ca_ncala*)0:(long const*)0,  long const ca_ncala*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(ཧྲིལ ca_ncala*)0: (void const*)1, void ca_ncala const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(ཧྲིལ ca_ncala*)0: (void const*)0, void ca_ncala const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?(ཧྲིལ (*)[4])0 : (ཧྲིལ (*)[])0, ཧྲིལ (*)[4]:+1, ཧྲིལ (*)[5]:(void)0); }));
	(void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?(ཧྲིལ (*)[])0 : (ཧྲིལ (*)[4])0, ཧྲིལ (*)[4]:+1, ཧྲིལ (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		var_na **argv;
		_Generic(argv, var_na**: (void)0);
		_Generic(0?(var_na const*)0:argv[0], var_na const*: (void)0);
		_Generic(argv, var_na**: (void)0);
	}
	{
	  extern ཧྲིལ (*ar)[];
	  (void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?(ཧྲིལ (*)[4])0 : (ཧྲིལ (*)[])0, ཧྲིལ (*)[4]:+1, ཧྲིལ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?(ཧྲིལ (*)[])0 : (ཧྲིལ (*)[4])0, ཧྲིལ (*)[4]:+1, ཧྲིལ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?ar : (ཧྲིལ (*)[4])0, ཧྲིལ (*)[4]:+1, ཧྲིལ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?(ཧྲིལ (*)[4])0 : ar, ཧྲིལ (*)[4]:+1, ཧྲིལ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ཧྲིལ x:_Generic( 0?(ཧྲིལ (*)[5])0 : ar, ཧྲིལ (*)[5]:+1, ཧྲིལ (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	ལོག 0;
}
