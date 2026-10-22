#include <stdio.h>

const цео a = 0;

struct a {
	цео a;
};

struct b {
	цео a;
};

цео a_f()
{
	врати 20;
}

цео b_f()
{
	врати 10;
}

typedef цео (*fptr)(цео);
typedef void (*vfptr)(цео);
цео foo(цео i)
{
  врати i;
}
void void_foo(цео i) {}

typedef цео int_type1;

typedef цео T[4];
цео f(T t)
{
	врати _Generic(t, __typeof__( ((void)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, const char *: 1, default: 8, цео: 123);

цео main()
{
	цео i = 0;
	signed long цео l = 2;
	struct b titi;
	const цео * const ptr;
	const char *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, цео: a_f, const цео: b_f)();
	printf("%d\n", i);
	i = _Generic(a, цео: a_f() / 2, const цео: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, цео *:1, цео * const:2, default:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, struct a:1, struct b:2, default:20);
	printf("%d\n", i);
	i = _Generic(i2, char: 1, цео : 0);
	printf("%d\n", i);
	i = _Generic(a, char:1, цео[4]:2, default:5);
	printf("%d\n", i);
	i = _Generic(17, цео :1, цео **:2);
	printf("%d\n", i);
	i = _Generic(17L, цео :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", char *: 3, const char *: 1);
	printf("%d\n", i);
	i = _Generic(ti, const unsigned char *:1, const char *:4, char *:3,
		     const signed char *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", цео: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, цео: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, цео: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, цео: 4, vfptr: 5);
	printf("%d\n", i);

	(void)_Generic((цео(*)[2]){0}, цео(*)[2]:0, цео(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	struct { _Bool x_0: _Generic(({0;}),default:1); } my_x;

	_Generic((__typeof((float const)((float const){42}))*){0}, float*: 0); //casts lose top-level qualifiers
	цео const x = 42; __typeof((__typeof(x))x) *xp = 0; (void)_Generic(xp, цео*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (void)0);
	//combining of qualifiers
	_Generic( 0?(long volatile*)0:(long const*)0,  long const volatile*: (void)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (void)0);
	_Generic( 0?(long*)0:(void*)0, long*: (void)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(цео volatile*)0: (void const*)1, void volatile const*: (void)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(void*)(i*0LL):&i, void*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(цео volatile*)0: (void const*)0, void volatile const*: (void)0);

	//ptrs to incomplete types get completed
	(void)(sizeof(struct { цео x:_Generic( 0?(цео (*)[4])0 : (цео (*)[])0, цео (*)[4]:+1, цео (*)[5]:(void)0); }));
	(void)(sizeof(struct { цео x:_Generic( 0?(цео (*)[])0 : (цео (*)[4])0, цео (*)[4]:+1, цео (*)[5]:(void)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		char **argv;
		_Generic(argv, char**: (void)0);
		_Generic(0?(char const*)0:argv[0], char const*: (void)0);
		_Generic(argv, char**: (void)0);
	}
	{
	  extern цео (*ar)[];
	  (void)(sizeof(struct { цео x:_Generic( 0?(цео (*)[4])0 : (цео (*)[])0, цео (*)[4]:+1, цео (*)[5]:(void)0); }));
	  (void)(sizeof(struct { цео x:_Generic( 0?(цео (*)[])0 : (цео (*)[4])0, цео (*)[4]:+1, цео (*)[5]:(void)0); }));
	  (void)(sizeof(struct { цео x:_Generic( 0?ar : (цео (*)[4])0, цео (*)[4]:+1, цео (*)[5]:(void)0); }));
	  (void)(sizeof(struct { цео x:_Generic( 0?(цео (*)[4])0 : ar, цео (*)[4]:+1, цео (*)[5]:(void)0); }));
	  (void)(sizeof(struct { цео x:_Generic( 0?(цео (*)[5])0 : ar, цео (*)[5]:+1, цео (*)[4]:(void)0); }));
	}

	printf ("%d\n", f(t));

	врати 0;
}
