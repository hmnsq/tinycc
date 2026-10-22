#ಅನ್ತರ್ಭಾವ <stdio.h>

ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ a = 0;

ಸಂರಚನಾ a {
	ಪೂರ್ಣಾಙ್ಕ a;
};

ಸಂರಚನಾ b {
	ಪೂರ್ಣಾಙ್ಕ a;
};

ಪೂರ್ಣಾಙ್ಕ a_f()
{
	ಪ್ರತ್ಯಾಗಮ 20;
}

ಪೂರ್ಣಾಙ್ಕ b_f()
{
	ಪ್ರತ್ಯಾಗಮ 10;
}

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (*fptr)(ಪೂರ್ಣಾಙ್ಕ);
ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (*vfptr)(ಪೂರ್ಣಾಙ್ಕ);
ಪೂರ್ಣಾಙ್ಕ foo(ಪೂರ್ಣಾಙ್ಕ i)
{
  ಪ್ರತ್ಯಾಗಮ i;
}
ಶೂನ್ಯ void_foo(ಪೂರ್ಣಾಙ್ಕ i) {}

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ int_type1;

ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ T[4];
ಪೂರ್ಣಾಙ್ಕ f(T t)
{
	ಪ್ರತ್ಯಾಗಮ _Generic(t, __typeof__( ((ಶೂನ್ಯ)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ಧ್ರುವ ವರ್ಣ *: 1, ಸ್ವಭಾವ: 8, ಪೂರ್ಣಾಙ್ಕ: 123);

ಪೂರ್ಣಾಙ್ಕ main()
{
	ಪೂರ್ಣಾಙ್ಕ i = 0;
	signed long ಪೂರ್ಣಾಙ್ಕ l = 2;
	ಸಂರಚನಾ b titi;
	ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ * ಧ್ರುವ ptr;
	ಧ್ರುವ ವರ್ಣ *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, ಪೂರ್ಣಾಙ್ಕ: a_f, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ: b_f)();
	printf("%d\n", i);
	i = _Generic(a, ಪೂರ್ಣಾಙ್ಕ: a_f() / 2, ಧ್ರುವ ಪೂರ್ಣಾಙ್ಕ: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, ಪೂರ್ಣಾಙ್ಕ *:1, ಪೂರ್ಣಾಙ್ಕ * ಧ್ರುವ:2, ಸ್ವಭಾವ:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, ಸಂರಚನಾ a:1, ಸಂರಚನಾ b:2, ಸ್ವಭಾವ:20);
	printf("%d\n", i);
	i = _Generic(i2, ವರ್ಣ: 1, ಪೂರ್ಣಾಙ್ಕ : 0);
	printf("%d\n", i);
	i = _Generic(a, ವರ್ಣ:1, ಪೂರ್ಣಾಙ್ಕ[4]:2, ಸ್ವಭಾವ:5);
	printf("%d\n", i);
	i = _Generic(17, ಪೂರ್ಣಾಙ್ಕ :1, ಪೂರ್ಣಾಙ್ಕ **:2);
	printf("%d\n", i);
	i = _Generic(17L, ಪೂರ್ಣಾಙ್ಕ :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", ವರ್ಣ *: 3, ಧ್ರುವ ವರ್ಣ *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ಧ್ರುವ unsigned ವರ್ಣ *:1, ಧ್ರುವ ವರ್ಣ *:4, ವರ್ಣ *:3,
		     ಧ್ರುವ signed ವರ್ಣ *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", ಪೂರ್ಣಾಙ್ಕ: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, ಪೂರ್ಣಾಙ್ಕ: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, ಪೂರ್ಣಾಙ್ಕ: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, ಪೂರ್ಣಾಙ್ಕ: 4, vfptr: 5);
	printf("%d\n", i);

	(ಶೂನ್ಯ)_Generic((ಪೂರ್ಣಾಙ್ಕ(*)[2]){0}, ಪೂರ್ಣಾಙ್ಕ(*)[2]:0, ಪೂರ್ಣಾಙ್ಕ(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	ಸಂರಚನಾ { _Bool x_0: _Generic(({0;}),ಸ್ವಭಾವ:1); } my_x;

	_Generic((__typeof((ಭಿನ್ನ ಧ್ರುವ)((ಭಿನ್ನ ಧ್ರುವ){42}))*){0}, ಭಿನ್ನ*: 0); //casts lose top-level qualifiers
	ಪೂರ್ಣಾಙ್ಕ ಧ್ರುವ x = 42; __typeof((__typeof(x))x) *xp = 0; (ಶೂನ್ಯ)_Generic(xp, ಪೂರ್ಣಾಙ್ಕ*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (ಶೂನ್ಯ)0);
	//combining of qualifiers
	_Generic( 0?(long ಚಞ್ಚಲ*)0:(long ಧ್ರುವ*)0,  long ಧ್ರುವ ಚಞ್ಚಲ*: (ಶೂನ್ಯ)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (ಶೂನ್ಯ)0);
	_Generic( 0?(long*)0:(ಶೂನ್ಯ*)0, long*: (ಶೂನ್ಯ)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ ಚಞ್ಚಲ*)0: (ಶೂನ್ಯ ಧ್ರುವ*)1, ಶೂನ್ಯ ಚಞ್ಚಲ ಧ್ರುವ*: (ಶೂನ್ಯ)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(ಶೂನ್ಯ*)(i*0LL):&i, ಶೂನ್ಯ*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ ಚಞ್ಚಲ*)0: (ಶೂನ್ಯ ಧ್ರುವ*)0, ಶೂನ್ಯ ಚಞ್ಚಲ ಧ್ರುವ*: (ಶೂನ್ಯ)0);

	//ptrs to incomplete types get completed
	(ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ (*)[4])0 : (ಪೂರ್ಣಾಙ್ಕ (*)[])0, ಪೂರ್ಣಾಙ್ಕ (*)[4]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[5]:(ಶೂನ್ಯ)0); }));
	(ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ (*)[])0 : (ಪೂರ್ಣಾಙ್ಕ (*)[4])0, ಪೂರ್ಣಾಙ್ಕ (*)[4]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[5]:(ಶೂನ್ಯ)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		ವರ್ಣ **argv;
		_Generic(argv, ವರ್ಣ**: (ಶೂನ್ಯ)0);
		_Generic(0?(ವರ್ಣ ಧ್ರುವ*)0:argv[0], ವರ್ಣ ಧ್ರುವ*: (ಶೂನ್ಯ)0);
		_Generic(argv, ವರ್ಣ**: (ಶೂನ್ಯ)0);
	}
	{
	  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ (*ar)[];
	  (ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ (*)[4])0 : (ಪೂರ್ಣಾಙ್ಕ (*)[])0, ಪೂರ್ಣಾಙ್ಕ (*)[4]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[5]:(ಶೂನ್ಯ)0); }));
	  (ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ (*)[])0 : (ಪೂರ್ಣಾಙ್ಕ (*)[4])0, ಪೂರ್ಣಾಙ್ಕ (*)[4]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[5]:(ಶೂನ್ಯ)0); }));
	  (ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?ar : (ಪೂರ್ಣಾಙ್ಕ (*)[4])0, ಪೂರ್ಣಾಙ್ಕ (*)[4]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[5]:(ಶೂನ್ಯ)0); }));
	  (ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ (*)[4])0 : ar, ಪೂರ್ಣಾಙ್ಕ (*)[4]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[5]:(ಶೂನ್ಯ)0); }));
	  (ಶೂನ್ಯ)(ಪರಿಮಾಣ(ಸಂರಚನಾ { ಪೂರ್ಣಾಙ್ಕ x:_Generic( 0?(ಪೂರ್ಣಾಙ್ಕ (*)[5])0 : ar, ಪೂರ್ಣಾಙ್ಕ (*)[5]:+1, ಪೂರ್ಣಾಙ್ಕ (*)[4]:(ಶೂನ್ಯ)0); }));
	}

	printf ("%d\n", f(t));

	ಪ್ರತ್ಯಾಗಮ 0;
}
