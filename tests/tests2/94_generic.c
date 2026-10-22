#include <stdio.h>

const 정수 a = 0;

struct a {
	정수 a;
};

struct b {
	정수 a;
};

정수 a_f()
{
	반환 20;
}

정수 b_f()
{
	반환 10;
}

typedef 정수 (*fptr)(정수);
typedef void (*vfptr)(정수);
정수 foo(정수 i)
{
  반환 i;
}
void void_foo(정수 i) {}

typedef 정수 int_type1;

typedef 정수 T[4];
정수 f(T t)
{
	반환 _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const char *: 1, default: 8, 정수: 123);

정수 main()
{
	정수 i = 0;
	signed long 정수 l = 2;
	struct b titi;
	const 정수 * const ptr;
	const char *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, 정수: a_f, const 정수: b_f)();
	printf("%d\n", i);
	i = _Generic(a, 정수: a_f() / 2, const 정수: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, 정수 *:1, 정수 * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, struct a:1, struct b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, char: 1, 정수 : 0);
	printf("%d\n", i);
	i = _Generic(a, char:1, 정수[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, 정수 :1, 정수 **:2);
	printf("%d\n", i);
	i = _Generic(17L, 정수 :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", char *: 3, const char *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned char *:1, const char *:4, char *:3,
		     const signed char *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", 정수: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, 정수: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, 정수: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, 정수: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((정수(*)[2]){0}, 정수(*)[2]:0, 정수(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	struct { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	정수 const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, 정수*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long volatile*)0:(long const*)0,  long const volatile*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(정수 volatile*)0: (void const*)1, void volatile const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(정수 volatile*)0: (void const*)0, void volatile const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(sizeof(struct { 정수 x:_Generic( 0?(정수 (*)[4])0 : (정수 (*)[])0, 정수 (*)[4]:+1, 정수 (*)[5]:(void)0); }));
	(void)(sizeof(struct { 정수 x:_Generic( 0?(정수 (*)[])0 : (정수 (*)[4])0, 정수 (*)[4]:+1, 정수 (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		char **argv;
		_Generic(argv, char**: (void)0);
		_Generic(0?(char const*)0:argv[0], char const*: (void)0);
		_Generic(argv, char**: (void)0);
	}
	{
	  extern 정수 (*ar)[];
	  (void)(sizeof(struct { 정수 x:_Generic( 0?(정수 (*)[4])0 : (정수 (*)[])0, 정수 (*)[4]:+1, 정수 (*)[5]:(void)0); }));
	  (void)(sizeof(struct { 정수 x:_Generic( 0?(정수 (*)[])0 : (정수 (*)[4])0, 정수 (*)[4]:+1, 정수 (*)[5]:(void)0); }));
	  (void)(sizeof(struct { 정수 x:_Generic( 0?ar : (정수 (*)[4])0, 정수 (*)[4]:+1, 정수 (*)[5]:(void)0); }));
	  (void)(sizeof(struct { 정수 x:_Generic( 0?(정수 (*)[4])0 : ar, 정수 (*)[4]:+1, 정수 (*)[5]:(void)0); }));
	  (void)(sizeof(struct { 정수 x:_Generic( 0?(정수 (*)[5])0 : ar, 정수 (*)[5]:+1, 정수 (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	반환 0;
}
