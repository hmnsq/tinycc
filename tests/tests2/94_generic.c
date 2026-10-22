#include <stdio.h>

const จำนวนเต็ม a = 0;

sa_nracanaa a {
	จำนวนเต็ม a;
};

sa_nracanaa b {
	จำนวนเต็ม a;
};

จำนวนเต็ม a_f()
{
	คืน 20;
}

จำนวนเต็ม b_f()
{
	คืน 10;
}

typedef จำนวนเต็ม (*fptr)(จำนวนเต็ม);
typedef void (*vfptr)(จำนวนเต็ม);
จำนวนเต็ม foo(จำนวนเต็ม i)
{
  คืน i;
}
void void_foo(จำนวนเต็ม i) {}

typedef จำนวนเต็ม int_type1;

typedef จำนวนเต็ม T[4];
จำนวนเต็ม f(T t)
{
	คืน _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const var_na *: 1, default: 8, จำนวนเต็ม: 123);

จำนวนเต็ม หลัก()
{
	จำนวนเต็ม i = 0;
	signed long จำนวนเต็ม l = 2;
	sa_nracanaa b titi;
	const จำนวนเต็ม * const ptr;
	const var_na *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, จำนวนเต็ม: a_f, const จำนวนเต็ม: b_f)();
	printf("%d\n", i);
	i = _Generic(a, จำนวนเต็ม: a_f() / 2, const จำนวนเต็ม: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, จำนวนเต็ม *:1, จำนวนเต็ม * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, sa_nracanaa a:1, sa_nracanaa b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, var_na: 1, จำนวนเต็ม : 0);
	printf("%d\n", i);
	i = _Generic(a, var_na:1, จำนวนเต็ม[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, จำนวนเต็ม :1, จำนวนเต็ม **:2);
	printf("%d\n", i);
	i = _Generic(17L, จำนวนเต็ม :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", var_na *: 3, const var_na *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned var_na *:1, const var_na *:4, var_na *:3,
		     const signed var_na *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", จำนวนเต็ม: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, จำนวนเต็ม: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, จำนวนเต็ม: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, จำนวนเต็ม: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((จำนวนเต็ม(*)[2]){0}, จำนวนเต็ม(*)[2]:0, จำนวนเต็ม(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	sa_nracanaa { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	จำนวนเต็ม const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, จำนวนเต็ม*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long ca_ncala*)0:(long const*)0,  long const ca_ncala*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(จำนวนเต็ม ca_ncala*)0: (void const*)1, void ca_ncala const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(จำนวนเต็ม ca_ncala*)0: (void const*)0, void ca_ncala const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?(จำนวนเต็ม (*)[4])0 : (จำนวนเต็ม (*)[])0, จำนวนเต็ม (*)[4]:+1, จำนวนเต็ม (*)[5]:(void)0); }));
	(void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?(จำนวนเต็ม (*)[])0 : (จำนวนเต็ม (*)[4])0, จำนวนเต็ม (*)[4]:+1, จำนวนเต็ม (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		var_na **argv;
		_Generic(argv, var_na**: (void)0);
		_Generic(0?(var_na const*)0:argv[0], var_na const*: (void)0);
		_Generic(argv, var_na**: (void)0);
	}
	{
	  extern จำนวนเต็ม (*ar)[];
	  (void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?(จำนวนเต็ม (*)[4])0 : (จำนวนเต็ม (*)[])0, จำนวนเต็ม (*)[4]:+1, จำนวนเต็ม (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?(จำนวนเต็ม (*)[])0 : (จำนวนเต็ม (*)[4])0, จำนวนเต็ม (*)[4]:+1, จำนวนเต็ม (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?ar : (จำนวนเต็ม (*)[4])0, จำนวนเต็ม (*)[4]:+1, จำนวนเต็ม (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?(จำนวนเต็ม (*)[4])0 : ar, จำนวนเต็ม (*)[4]:+1, จำนวนเต็ม (*)[5]:(void)0); }));
	  (void)(parimaa_na(sa_nracanaa { จำนวนเต็ม x:_Generic( 0?(จำนวนเต็ม (*)[5])0 : ar, จำนวนเต็ม (*)[5]:+1, จำนวนเต็ม (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	คืน 0;
}
