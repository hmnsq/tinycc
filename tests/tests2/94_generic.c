#ضمن <stdio.h>

ثابت صحيح a = 0;

بنية a {
	صحيح a;
};

بنية b {
	صحيح a;
};

صحيح a_f()
{
	ܦܢܐ 20;
}

صحيح b_f()
{
	ܦܢܐ 10;
}

تعريفنوع صحيح (*fptr)(صحيح);
تعريفنوع فراغ (*vfptr)(صحيح);
صحيح foo(صحيح i)
{
  ܦܢܐ i;
}
فراغ void_foo(صحيح i) {}

تعريفنوع صحيح int_type1;

تعريفنوع صحيح T[4];
صحيح f(T t)
{
	ܦܢܐ _Generic(t, __typeof__( ((فراغ)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ثابت حرف *: 1, افتراضي: 8, صحيح: 123);

صحيح main()
{
	صحيح i = 0;
	signed long صحيح l = 2;
	بنية b titi;
	ثابت صحيح * ثابت ptr;
	ثابت حرف *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, صحيح: a_f, ثابت صحيح: b_f)();
	printf("%d\n", i);
	i = _Generic(a, صحيح: a_f() / 2, ثابت صحيح: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, صحيح *:1, صحيح * ثابت:2, افتراضي:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, بنية a:1, بنية b:2, افتراضي:20);
	printf("%d\n", i);
	i = _Generic(i2, حرف: 1, صحيح : 0);
	printf("%d\n", i);
	i = _Generic(a, حرف:1, صحيح[4]:2, افتراضي:5);
	printf("%d\n", i);
	i = _Generic(17, صحيح :1, صحيح **:2);
	printf("%d\n", i);
	i = _Generic(17L, صحيح :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", حرف *: 3, ثابت حرف *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ثابت unsigned حرف *:1, ثابت حرف *:4, حرف *:3,
		     ثابت signed حرف *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", صحيح: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, صحيح: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, صحيح: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, صحيح: 4, vfptr: 5);
	printf("%d\n", i);

	(فراغ)_Generic((صحيح(*)[2]){0}, صحيح(*)[2]:0, صحيح(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	بنية { _Bool x_0: _Generic(({0;}),افتراضي:1); } my_x;

	_Generic((__typeof((عائم ثابت)((عائم ثابت){42}))*){0}, عائم*: 0); //casts lose top-level qualifiers
	صحيح ثابت x = 42; __typeof((__typeof(x))x) *xp = 0; (فراغ)_Generic(xp, صحيح*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (فراغ)0);
	//combining of qualifiers
	_Generic( 0?(long متطاير*)0:(long ثابت*)0,  long ثابت متطاير*: (فراغ)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (فراغ)0);
	_Generic( 0?(long*)0:(فراغ*)0, long*: (فراغ)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(صحيح متطاير*)0: (فراغ ثابت*)1, فراغ متطاير ثابت*: (فراغ)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(فراغ*)(i*0LL):&i, فراغ*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(صحيح متطاير*)0: (فراغ ثابت*)0, فراغ متطاير ثابت*: (فراغ)0);

	//ptrs to incomplete types get completed
	(فراغ)(حجم(بنية { صحيح x:_Generic( 0?(صحيح (*)[4])0 : (صحيح (*)[])0, صحيح (*)[4]:+1, صحيح (*)[5]:(فراغ)0); }));
	(فراغ)(حجم(بنية { صحيح x:_Generic( 0?(صحيح (*)[])0 : (صحيح (*)[4])0, صحيح (*)[4]:+1, صحيح (*)[5]:(فراغ)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		حرف **argv;
		_Generic(argv, حرف**: (فراغ)0);
		_Generic(0?(حرف ثابت*)0:argv[0], حرف ثابت*: (فراغ)0);
		_Generic(argv, حرف**: (فراغ)0);
	}
	{
	  خارجي صحيح (*ar)[];
	  (فراغ)(حجم(بنية { صحيح x:_Generic( 0?(صحيح (*)[4])0 : (صحيح (*)[])0, صحيح (*)[4]:+1, صحيح (*)[5]:(فراغ)0); }));
	  (فراغ)(حجم(بنية { صحيح x:_Generic( 0?(صحيح (*)[])0 : (صحيح (*)[4])0, صحيح (*)[4]:+1, صحيح (*)[5]:(فراغ)0); }));
	  (فراغ)(حجم(بنية { صحيح x:_Generic( 0?ar : (صحيح (*)[4])0, صحيح (*)[4]:+1, صحيح (*)[5]:(فراغ)0); }));
	  (فراغ)(حجم(بنية { صحيح x:_Generic( 0?(صحيح (*)[4])0 : ar, صحيح (*)[4]:+1, صحيح (*)[5]:(فراغ)0); }));
	  (فراغ)(حجم(بنية { صحيح x:_Generic( 0?(صحيح (*)[5])0 : ar, صحيح (*)[5]:+1, صحيح (*)[4]:(فراغ)0); }));
	}

	printf ("%d\n", f(t));

	ܦܢܐ 0;
}
