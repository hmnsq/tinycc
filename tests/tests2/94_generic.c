#অন্তর্ভাব <stdio.h>

ধ্রুবক পূর্ণসংখ্যা a = 0;

কাঠামো a {
	পূর্ণসংখ্যা a;
};

কাঠামো b {
	পূর্ণসংখ্যা a;
};

পূর্ণসংখ্যা a_f()
{
	ফেরত 20;
}

পূর্ণসংখ্যা b_f()
{
	ফেরত 10;
}

প্রকারলেখ পূর্ণসংখ্যা (*fptr)(পূর্ণসংখ্যা);
প্রকারলেখ শূন্য (*vfptr)(পূর্ণসংখ্যা);
পূর্ণসংখ্যা foo(পূর্ণসংখ্যা i)
{
  ফেরত i;
}
শূন্য void_foo(পূর্ণসংখ্যা i) {}

প্রকারলেখ পূর্ণসংখ্যা int_type1;

প্রকারলেখ পূর্ণসংখ্যা T[4];
পূর্ণসংখ্যা f(T t)
{
	ফেরত _Generic(t, __typeof__( ((শূন্য)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ধ্রুবক অক্ষর *: 1, পূর্বনির্ধারিত: 8, পূর্ণসংখ্যা: 123);

পূর্ণসংখ্যা প্রধান()
{
	পূর্ণসংখ্যা i = 0;
	signed long পূর্ণসংখ্যা l = 2;
	কাঠামো b titi;
	ধ্রুবক পূর্ণসংখ্যা * ধ্রুবক ptr;
	ধ্রুবক অক্ষর *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, পূর্ণসংখ্যা: a_f, ধ্রুবক পূর্ণসংখ্যা: b_f)();
	printf("%d\n", i);
	i = _Generic(a, পূর্ণসংখ্যা: a_f() / 2, ধ্রুবক পূর্ণসংখ্যা: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, পূর্ণসংখ্যা *:1, পূর্ণসংখ্যা * ধ্রুবক:2, পূর্বনির্ধারিত:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, কাঠামো a:1, কাঠামো b:2, পূর্বনির্ধারিত:20);
	printf("%d\n", i);
	i = _Generic(i2, অক্ষর: 1, পূর্ণসংখ্যা : 0);
	printf("%d\n", i);
	i = _Generic(a, অক্ষর:1, পূর্ণসংখ্যা[4]:2, পূর্বনির্ধারিত:5);
	printf("%d\n", i);
	i = _Generic(17, পূর্ণসংখ্যা :1, পূর্ণসংখ্যা **:2);
	printf("%d\n", i);
	i = _Generic(17L, পূর্ণসংখ্যা :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", অক্ষর *: 3, ধ্রুবক অক্ষর *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ধ্রুবক unsigned অক্ষর *:1, ধ্রুবক অক্ষর *:4, অক্ষর *:3,
		     ধ্রুবক signed অক্ষর *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", পূর্ণসংখ্যা: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, পূর্ণসংখ্যা: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, পূর্ণসংখ্যা: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, পূর্ণসংখ্যা: 4, vfptr: 5);
	printf("%d\n", i);

	(শূন্য)_Generic((পূর্ণসংখ্যা(*)[2]){0}, পূর্ণসংখ্যা(*)[2]:0, পূর্ণসংখ্যা(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	কাঠামো { _Bool x_0: _Generic(({0;}),পূর্বনির্ধারিত:1); } my_x;

	_Generic((__typeof((দশমিক ধ্রুবক)((দশমিক ধ্রুবক){42}))*){0}, দশমিক*: 0); //casts lose top-level qualifiers
	পূর্ণসংখ্যা ধ্রুবক x = 42; __typeof((__typeof(x))x) *xp = 0; (শূন্য)_Generic(xp, পূর্ণসংখ্যা*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (শূন্য)0);
	//combining of qualifiers
	_Generic( 0?(long অস্থির*)0:(long ধ্রুবক*)0,  long ধ্রুবক অস্থির*: (শূন্য)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (শূন্য)0);
	_Generic( 0?(long*)0:(শূন্য*)0, long*: (শূন্য)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(পূর্ণসংখ্যা অস্থির*)0: (শূন্য ধ্রুবক*)1, শূন্য অস্থির ধ্রুবক*: (শূন্য)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(শূন্য*)(i*0LL):&i, শূন্য*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(পূর্ণসংখ্যা অস্থির*)0: (শূন্য ধ্রুবক*)0, শূন্য অস্থির ধ্রুবক*: (শূন্য)0);

	//ptrs to incomplete types get completed
	(শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?(পূর্ণসংখ্যা (*)[4])0 : (পূর্ণসংখ্যা (*)[])0, পূর্ণসংখ্যা (*)[4]:+1, পূর্ণসংখ্যা (*)[5]:(শূন্য)0); }));
	(শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?(পূর্ণসংখ্যা (*)[])0 : (পূর্ণসংখ্যা (*)[4])0, পূর্ণসংখ্যা (*)[4]:+1, পূর্ণসংখ্যা (*)[5]:(শূন্য)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		অক্ষর **argv;
		_Generic(argv, অক্ষর**: (শূন্য)0);
		_Generic(0?(অক্ষর ধ্রুবক*)0:argv[0], অক্ষর ধ্রুবক*: (শূন্য)0);
		_Generic(argv, অক্ষর**: (শূন্য)0);
	}
	{
	  বাহ্যিক পূর্ণসংখ্যা (*ar)[];
	  (শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?(পূর্ণসংখ্যা (*)[4])0 : (পূর্ণসংখ্যা (*)[])0, পূর্ণসংখ্যা (*)[4]:+1, পূর্ণসংখ্যা (*)[5]:(শূন্য)0); }));
	  (শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?(পূর্ণসংখ্যা (*)[])0 : (পূর্ণসংখ্যা (*)[4])0, পূর্ণসংখ্যা (*)[4]:+1, পূর্ণসংখ্যা (*)[5]:(শূন্য)0); }));
	  (শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?ar : (পূর্ণসংখ্যা (*)[4])0, পূর্ণসংখ্যা (*)[4]:+1, পূর্ণসংখ্যা (*)[5]:(শূন্য)0); }));
	  (শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?(পূর্ণসংখ্যা (*)[4])0 : ar, পূর্ণসংখ্যা (*)[4]:+1, পূর্ণসংখ্যা (*)[5]:(শূন্য)0); }));
	  (শূন্য)(আকার(কাঠামো { পূর্ণসংখ্যা x:_Generic( 0?(পূর্ণসংখ্যা (*)[5])0 : ar, পূর্ণসংখ্যা (*)[5]:+1, পূর্ণসংখ্যা (*)[4]:(শূন্য)0); }));
	}

	printf ("%d\n", f(t));

	ফেরত 0;
}
