#شامل <stdio.h>

ثابت صحیح a = 0;

ساختار a {
	صحیح a;
};

ساختار b {
	صحیح a;
};

صحیح a_f()
{
	بازگشت 20;
}

صحیح b_f()
{
	بازگشت 10;
}

تعریفنوع صحیح (*fptr)(صحیح);
تعریفنوع تهی (*vfptr)(صحیح);
صحیح foo(صحیح i)
{
  بازگشت i;
}
تهی void_foo(صحیح i) {}

تعریفنوع صحیح int_type1;

تعریفنوع صحیح T[4];
صحیح f(T t)
{
	بازگشت _Generic(t, __typeof__( ((تهی)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ثابت نویسه *: 1, پیشفرض: 8, صحیح: 123);

صحیح اصلی()
{
	صحیح i = 0;
	signed long صحیح l = 2;
	ساختار b titi;
	ثابت صحیح * ثابت ptr;
	ثابت نویسه *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, صحیح: a_f, ثابت صحیح: b_f)();
	printf("%d\n", i);
	i = _Generic(a, صحیح: a_f() / 2, ثابت صحیح: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, صحیح *:1, صحیح * ثابت:2, پیشفرض:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, ساختار a:1, ساختار b:2, پیشفرض:20);
	printf("%d\n", i);
	i = _Generic(i2, نویسه: 1, صحیح : 0);
	printf("%d\n", i);
	i = _Generic(a, نویسه:1, صحیح[4]:2, پیشفرض:5);
	printf("%d\n", i);
	i = _Generic(17, صحیح :1, صحیح **:2);
	printf("%d\n", i);
	i = _Generic(17L, صحیح :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", نویسه *: 3, ثابت نویسه *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ثابت unsigned نویسه *:1, ثابت نویسه *:4, نویسه *:3,
		     ثابت signed نویسه *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", صحیح: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, صحیح: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, صحیح: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, صحیح: 4, vfptr: 5);
	printf("%d\n", i);

	(تهی)_Generic((صحیح(*)[2]){0}, صحیح(*)[2]:0, صحیح(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	ساختار { _Bool x_0: _Generic(({0;}),پیشفرض:1); } my_x;

	_Generic((__typeof((اعشاری ثابت)((اعشاری ثابت){42}))*){0}, اعشاری*: 0); //casts lose top-level qualifiers
	صحیح ثابت x = 42; __typeof((__typeof(x))x) *xp = 0; (تهی)_Generic(xp, صحیح*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (تهی)0);
	//combining of qualifiers
	_Generic( 0?(long فرار*)0:(long ثابت*)0,  long ثابت فرار*: (تهی)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (تهی)0);
	_Generic( 0?(long*)0:(تهی*)0, long*: (تهی)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(صحیح فرار*)0: (تهی ثابت*)1, تهی فرار ثابت*: (تهی)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(تهی*)(i*0LL):&i, تهی*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(صحیح فرار*)0: (تهی ثابت*)0, تهی فرار ثابت*: (تهی)0);

	//ptrs to incomplete types get completed
	(تهی)(اندازه(ساختار { صحیح x:_Generic( 0?(صحیح (*)[4])0 : (صحیح (*)[])0, صحیح (*)[4]:+1, صحیح (*)[5]:(تهی)0); }));
	(تهی)(اندازه(ساختار { صحیح x:_Generic( 0?(صحیح (*)[])0 : (صحیح (*)[4])0, صحیح (*)[4]:+1, صحیح (*)[5]:(تهی)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		نویسه **argv;
		_Generic(argv, نویسه**: (تهی)0);
		_Generic(0?(نویسه ثابت*)0:argv[0], نویسه ثابت*: (تهی)0);
		_Generic(argv, نویسه**: (تهی)0);
	}
	{
	  بیرونی صحیح (*ar)[];
	  (تهی)(اندازه(ساختار { صحیح x:_Generic( 0?(صحیح (*)[4])0 : (صحیح (*)[])0, صحیح (*)[4]:+1, صحیح (*)[5]:(تهی)0); }));
	  (تهی)(اندازه(ساختار { صحیح x:_Generic( 0?(صحیح (*)[])0 : (صحیح (*)[4])0, صحیح (*)[4]:+1, صحیح (*)[5]:(تهی)0); }));
	  (تهی)(اندازه(ساختار { صحیح x:_Generic( 0?ar : (صحیح (*)[4])0, صحیح (*)[4]:+1, صحیح (*)[5]:(تهی)0); }));
	  (تهی)(اندازه(ساختار { صحیح x:_Generic( 0?(صحیح (*)[4])0 : ar, صحیح (*)[4]:+1, صحیح (*)[5]:(تهی)0); }));
	  (تهی)(اندازه(ساختار { صحیح x:_Generic( 0?(صحیح (*)[5])0 : ar, صحیح (*)[5]:+1, صحیح (*)[4]:(تهی)0); }));
	}

	printf ("%d\n", f(t));

	بازگشت 0;
}
