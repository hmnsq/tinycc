#include <stdio.h>

const целое a = 0;

struct a {
	целое a;
};

struct b {
	целое a;
};

целое a_f()
{
	вернуть 20;
}

целое b_f()
{
	вернуть 10;
}

typedef целое (*fptr)(целое);
typedef void (*vfptr)(целое);
целое foo(целое i)
{
  вернуть i;
}
void void_foo(целое i) {}

typedef целое int_type1;

typedef целое T[4];
целое f(T t)
{
	вернуть _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const char *: 1, default: 8, целое: 123);

целое основной()
{
	целое i = 0;
	signed long целое l = 2;
	struct b titi;
	const целое * const ptr;
	const char *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, целое: a_f, const целое: b_f)();
	printf("%d\n", i);
	i = _Generic(a, целое: a_f() / 2, const целое: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, целое *:1, целое * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, struct a:1, struct b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, char: 1, целое : 0);
	printf("%d\n", i);
	i = _Generic(a, char:1, целое[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, целое :1, целое **:2);
	printf("%d\n", i);
	i = _Generic(17L, целое :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", char *: 3, const char *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned char *:1, const char *:4, char *:3,
		     const signed char *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", целое: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, целое: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, целое: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, целое: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((целое(*)[2]){0}, целое(*)[2]:0, целое(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	struct { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	целое const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, целое*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long volatile*)0:(long const*)0,  long const volatile*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(целое volatile*)0: (void const*)1, void volatile const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(целое volatile*)0: (void const*)0, void volatile const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(sizeof(struct { целое x:_Generic( 0?(целое (*)[4])0 : (целое (*)[])0, целое (*)[4]:+1, целое (*)[5]:(void)0); }));
	(void)(sizeof(struct { целое x:_Generic( 0?(целое (*)[])0 : (целое (*)[4])0, целое (*)[4]:+1, целое (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		char **argv;
		_Generic(argv, char**: (void)0);
		_Generic(0?(char const*)0:argv[0], char const*: (void)0);
		_Generic(argv, char**: (void)0);
	}
	{
	  extern целое (*ar)[];
	  (void)(sizeof(struct { целое x:_Generic( 0?(целое (*)[4])0 : (целое (*)[])0, целое (*)[4]:+1, целое (*)[5]:(void)0); }));
	  (void)(sizeof(struct { целое x:_Generic( 0?(целое (*)[])0 : (целое (*)[4])0, целое (*)[4]:+1, целое (*)[5]:(void)0); }));
	  (void)(sizeof(struct { целое x:_Generic( 0?ar : (целое (*)[4])0, целое (*)[4]:+1, целое (*)[5]:(void)0); }));
	  (void)(sizeof(struct { целое x:_Generic( 0?(целое (*)[4])0 : ar, целое (*)[4]:+1, целое (*)[5]:(void)0); }));
	  (void)(sizeof(struct { целое x:_Generic( 0?(целое (*)[5])0 : ar, целое (*)[5]:+1, целое (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	вернуть 0;
}
