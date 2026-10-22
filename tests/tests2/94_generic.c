#include <stdio.h>

const ຈຳນວນເຕັມ a = 0;

sa_nracanaa a {
	ຈຳນວນເຕັມ a;
};

sa_nracanaa b {
	ຈຳນວນເຕັມ a;
};

ຈຳນວນເຕັມ a_f()
{
	ສົ່ງຄືນ 20;
}

ຈຳນວນເຕັມ b_f()
{
	ສົ່ງຄືນ 10;
}

typedef ຈຳນວນເຕັມ (*fptr)(ຈຳນວນເຕັມ);
typedef void (*vfptr)(ຈຳນວນເຕັມ);
ຈຳນວນເຕັມ foo(ຈຳນວນເຕັມ i)
{
  ສົ່ງຄືນ i;
}
void void_foo(ຈຳນວນເຕັມ i) {}

typedef ຈຳນວນເຕັມ int_type1;

typedef ຈຳນວນເຕັມ T[4];
ຈຳນວນເຕັມ f(T t)
{
	ສົ່ງຄືນ _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const var_na *: 1, default: 8, ຈຳນວນເຕັມ: 123);

ຈຳນວນເຕັມ main()
{
	ຈຳນວນເຕັມ i = 0;
	signed long ຈຳນວນເຕັມ l = 2;
	sa_nracanaa b titi;
	const ຈຳນວນເຕັມ * const ptr;
	const var_na *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, ຈຳນວນເຕັມ: a_f, const ຈຳນວນເຕັມ: b_f)();
	printf("%d\n", i);
	i = _Generic(a, ຈຳນວນເຕັມ: a_f() / 2, const ຈຳນວນເຕັມ: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, ຈຳນວນເຕັມ *:1, ຈຳນວນເຕັມ * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, sa_nracanaa a:1, sa_nracanaa b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, var_na: 1, ຈຳນວນເຕັມ : 0);
	printf("%d\n", i);
	i = _Generic(a, var_na:1, ຈຳນວນເຕັມ[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, ຈຳນວນເຕັມ :1, ຈຳນວນເຕັມ **:2);
	printf("%d\n", i);
	i = _Generic(17L, ຈຳນວນເຕັມ :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", var_na *: 3, const var_na *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned var_na *:1, const var_na *:4, var_na *:3,
		     const signed var_na *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", ຈຳນວນເຕັມ: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, ຈຳນວນເຕັມ: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, ຈຳນວນເຕັມ: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, ຈຳນວນເຕັມ: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((ຈຳນວນເຕັມ(*)[2]){0}, ຈຳນວນເຕັມ(*)[2]:0, ຈຳນວນເຕັມ(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	sa_nracanaa { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	ຈຳນວນເຕັມ const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, ຈຳນວນເຕັມ*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long ca_ncala*)0:(long const*)0,  long const ca_ncala*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(ຈຳນວນເຕັມ ca_ncala*)0: (void const*)1, void ca_ncala const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(ຈຳນວນເຕັມ ca_ncala*)0: (void const*)0, void ca_ncala const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?(ຈຳນວນເຕັມ (*)[4])0 : (ຈຳນວນເຕັມ (*)[])0, ຈຳນວນເຕັມ (*)[4]:+1, ຈຳນວນເຕັມ (*)[5]:(void)0); }));
	(void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?(ຈຳນວນເຕັມ (*)[])0 : (ຈຳນວນເຕັມ (*)[4])0, ຈຳນວນເຕັມ (*)[4]:+1, ຈຳນວນເຕັມ (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		var_na **argv;
		_Generic(argv, var_na**: (void)0);
		_Generic(0?(var_na const*)0:argv[0], var_na const*: (void)0);
		_Generic(argv, var_na**: (void)0);
	}
	{
	  extern ຈຳນວນເຕັມ (*ar)[];
	  (void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?(ຈຳນວນເຕັມ (*)[4])0 : (ຈຳນວນເຕັມ (*)[])0, ຈຳນວນເຕັມ (*)[4]:+1, ຈຳນວນເຕັມ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?(ຈຳນວນເຕັມ (*)[])0 : (ຈຳນວນເຕັມ (*)[4])0, ຈຳນວນເຕັມ (*)[4]:+1, ຈຳນວນເຕັມ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?ar : (ຈຳນວນເຕັມ (*)[4])0, ຈຳນວນເຕັມ (*)[4]:+1, ຈຳນວນເຕັມ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?(ຈຳນວນເຕັມ (*)[4])0 : ar, ຈຳນວນເຕັມ (*)[4]:+1, ຈຳນວນເຕັມ (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { ຈຳນວນເຕັມ x:_Generic( 0?(ຈຳນວນເຕັມ (*)[5])0 : ar, ຈຳນວນເຕັມ (*)[5]:+1, ຈຳນວນເຕັມ (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	ສົ່ງຄືນ 0;
}
