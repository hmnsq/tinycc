#include <stdio.h>

const số_nguyên a = 0;

struct a {
	số_nguyên a;
};

struct b {
	số_nguyên a;
};

số_nguyên a_f()
{
	trả_về 20;
}

số_nguyên b_f()
{
	trả_về 10;
}

typedef số_nguyên (*fptr)(số_nguyên);
typedef void (*vfptr)(số_nguyên);
số_nguyên foo(số_nguyên i)
{
  trả_về i;
}
void void_foo(số_nguyên i) {}

typedef số_nguyên int_type1;

typedef số_nguyên T[4];
số_nguyên f(T t)
{
	trả_về _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const char *: 1, default: 8, số_nguyên: 123);

số_nguyên main()
{
	số_nguyên i = 0;
	signed long số_nguyên l = 2;
	struct b titi;
	const số_nguyên * const ptr;
	const char *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, số_nguyên: a_f, const số_nguyên: b_f)();
	printf("%d\n", i);
	i = _Generic(a, số_nguyên: a_f() / 2, const số_nguyên: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, số_nguyên *:1, số_nguyên * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, struct a:1, struct b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, char: 1, số_nguyên : 0);
	printf("%d\n", i);
	i = _Generic(a, char:1, số_nguyên[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, số_nguyên :1, số_nguyên **:2);
	printf("%d\n", i);
	i = _Generic(17L, số_nguyên :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", char *: 3, const char *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned char *:1, const char *:4, char *:3,
		     const signed char *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", số_nguyên: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, số_nguyên: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, số_nguyên: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, số_nguyên: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((số_nguyên(*)[2]){0}, số_nguyên(*)[2]:0, số_nguyên(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	struct { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	số_nguyên const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, số_nguyên*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long volatile*)0:(long const*)0,  long const volatile*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(số_nguyên volatile*)0: (void const*)1, void volatile const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(số_nguyên volatile*)0: (void const*)0, void volatile const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(sizeof(struct { số_nguyên x:_Generic( 0?(số_nguyên (*)[4])0 : (số_nguyên (*)[])0, số_nguyên (*)[4]:+1, số_nguyên (*)[5]:(void)0); }));
	(void)(sizeof(struct { số_nguyên x:_Generic( 0?(số_nguyên (*)[])0 : (số_nguyên (*)[4])0, số_nguyên (*)[4]:+1, số_nguyên (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		char **argv;
		_Generic(argv, char**: (void)0);
		_Generic(0?(char const*)0:argv[0], char const*: (void)0);
		_Generic(argv, char**: (void)0);
	}
	{
	  extern số_nguyên (*ar)[];
	  (void)(sizeof(struct { số_nguyên x:_Generic( 0?(số_nguyên (*)[4])0 : (số_nguyên (*)[])0, số_nguyên (*)[4]:+1, số_nguyên (*)[5]:(void)0); }));
	  (void)(sizeof(struct { số_nguyên x:_Generic( 0?(số_nguyên (*)[])0 : (số_nguyên (*)[4])0, số_nguyên (*)[4]:+1, số_nguyên (*)[5]:(void)0); }));
	  (void)(sizeof(struct { số_nguyên x:_Generic( 0?ar : (số_nguyên (*)[4])0, số_nguyên (*)[4]:+1, số_nguyên (*)[5]:(void)0); }));
	  (void)(sizeof(struct { số_nguyên x:_Generic( 0?(số_nguyên (*)[4])0 : ar, số_nguyên (*)[4]:+1, số_nguyên (*)[5]:(void)0); }));
	  (void)(sizeof(struct { số_nguyên x:_Generic( 0?(số_nguyên (*)[5])0 : ar, số_nguyên (*)[5]:+1, số_nguyên (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	trả_về 0;
}
