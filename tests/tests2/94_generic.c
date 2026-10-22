#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਅਚਲ ਪੂਰਨ a = 0;

ਬਣਤਰ a {
	ਪੂਰਨ a;
};

ਬਣਤਰ b {
	ਪੂਰਨ a;
};

ਪੂਰਨ a_f()
{
	ਵਾਪਸ 20;
}

ਪੂਰਨ b_f()
{
	ਵਾਪਸ 10;
}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (*fptr)(ਪੂਰਨ);
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (*vfptr)(ਪੂਰਨ);
ਪੂਰਨ foo(ਪੂਰਨ i)
{
  ਵਾਪਸ i;
}
ਖਾਲੀ void_foo(ਪੂਰਨ i) {}

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ int_type1;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ T[4];
ਪੂਰਨ f(T t)
{
	ਵਾਪਸ _Generic(t, __typeof__( ((ਖਾਲੀ)0, (T){0}) ) : 1 );
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gen_sw(a) _Generic(a, ਅਚਲ ਅੱਖਰ *: 1, ਮੂਲ: 8, ਪੂਰਨ: 123);

ਪੂਰਨ ਮੁੱਖ()
{
	ਪੂਰਨ i = 0;
	ਨਿਸ਼ਾਨੀਵਾਲਾ ਲੰਮਾ ਪੂਰਨ l = 2;
	ਬਣਤਰ b titi;
	ਅਚਲ ਪੂਰਨ * ਅਚਲ ptr;
	ਅਚਲ ਅੱਖਰ *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, ਪੂਰਨ: a_f, ਅਚਲ ਪੂਰਨ: b_f)();
	ਲਿਖੋ("%d\n", i);
	i = _Generic(a, ਪੂਰਨ: a_f() / 2, ਅਚਲ ਪੂਰਨ: b_f() / 2);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(ptr, ਪੂਰਨ *:1, ਪੂਰਨ * ਅਚਲ:2, ਮੂਲ:20);
	ਲਿਖੋ("%d\n", i);
	i = gen_sw(a);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(titi, ਬਣਤਰ a:1, ਬਣਤਰ b:2, ਮੂਲ:20);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(i2, ਅੱਖਰ: 1, ਪੂਰਨ : 0);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(a, ਅੱਖਰ:1, ਪੂਰਨ[4]:2, ਮੂਲ:5);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(17, ਪੂਰਨ :1, ਪੂਰਨ **:2);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(17L, ਪੂਰਨ :1, ਲੰਮਾ :2, ਲੰਮਾ ਲੰਮਾ : 3);
	ਲਿਖੋ("%d\n", i);
	i = _Generic("17, io", ਅੱਖਰ *: 3, ਅਚਲ ਅੱਖਰ *: 1);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(ti, ਅਚਲ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *:1, ਅਚਲ ਅੱਖਰ *:4, ਅੱਖਰ *:3,
		     ਅਚਲ ਨਿਸ਼ਾਨੀਵਾਲਾ ਅੱਖਰ *:2);
	ਲਿਖੋ("%d\n", i);
	ਲਿਖੋ("%s\n", _Generic(i + 2L, ਲੰਮਾ: "long", ਪੂਰਨ: "int",
				ਲੰਮਾ ਲੰਮਾ: "long long"));
	i = _Generic(l, ਲੰਮਾ: 1, ਪੂਰਨ: 2);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(foo, fptr: 3, ਪੂਰਨ: 4, vfptr: 5);
	ਲਿਖੋ("%d\n", i);
	i = _Generic(void_foo, fptr: 3, ਪੂਰਨ: 4, vfptr: 5);
	ਲਿਖੋ("%d\n", i);

	(ਖਾਲੀ)_Generic((ਪੂਰਨ(*)[2]){0}, ਪੂਰਨ(*)[2]:0, ਪੂਰਨ(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	ਬਣਤਰ { _Bool x_0: _Generic(({0;}),ਮੂਲ:1); } my_x;

	_Generic((__typeof((ਦਸ਼ਮਲਵ ਅਚਲ)((ਦਸ਼ਮਲਵ ਅਚਲ){42}))*){0}, ਦਸ਼ਮਲਵ*: 0); //casts lose top-level qualifiers
	ਪੂਰਨ ਅਚਲ x = 42; __typeof((__typeof(x))x) *xp = 0; (ਖਾਲੀ)_Generic(xp, ਪੂਰਨ*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(ਲੰਮਾ*)0:(ਲੰਮਾ*)0,  ਲੰਮਾ*: (ਖਾਲੀ)0);
	//combining of qualifiers
	_Generic( 0?(ਲੰਮਾ ਅਸਥਿਰ*)0:(ਲੰਮਾ ਅਚਲ*)0,  ਲੰਮਾ ਅਚਲ ਅਸਥਿਰ*: (ਖਾਲੀ)0);
	//nul-ptr constant selects other type
	_Generic( 0?(ਲੰਮਾ*)0:0,			ਲੰਮਾ*: (ਖਾਲੀ)0);
	_Generic( 0?(ਲੰਮਾ*)0:(ਖਾਲੀ*)0, ਲੰਮਾ*: (ਖਾਲੀ)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(ਪੂਰਨ ਅਸਥਿਰ*)0: (ਖਾਲੀ ਅਚਲ*)1, ਖਾਲੀ ਅਸਥਿਰ ਅਚਲ*: (ਖਾਲੀ)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(ਖਾਲੀ*)(i*0LL):&i, ਖਾਲੀ*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(ਪੂਰਨ ਅਸਥਿਰ*)0: (ਖਾਲੀ ਅਚਲ*)0, ਖਾਲੀ ਅਸਥਿਰ ਅਚਲ*: (ਖਾਲੀ)0);

	//ptrs to incomplete types get completed
	(ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?(ਪੂਰਨ (*)[4])0 : (ਪੂਰਨ (*)[])0, ਪੂਰਨ (*)[4]:+1, ਪੂਰਨ (*)[5]:(ਖਾਲੀ)0); }));
	(ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?(ਪੂਰਨ (*)[])0 : (ਪੂਰਨ (*)[4])0, ਪੂਰਨ (*)[4]:+1, ਪੂਰਨ (*)[5]:(ਖਾਲੀ)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		ਅੱਖਰ **argv;
		_Generic(argv, ਅੱਖਰ**: (ਖਾਲੀ)0);
		_Generic(0?(ਅੱਖਰ ਅਚਲ*)0:argv[0], ਅੱਖਰ ਅਚਲ*: (ਖਾਲੀ)0);
		_Generic(argv, ਅੱਖਰ**: (ਖਾਲੀ)0);
	}
	{
	  ਬਾਹਰੀ ਪੂਰਨ (*ar)[];
	  (ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?(ਪੂਰਨ (*)[4])0 : (ਪੂਰਨ (*)[])0, ਪੂਰਨ (*)[4]:+1, ਪੂਰਨ (*)[5]:(ਖਾਲੀ)0); }));
	  (ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?(ਪੂਰਨ (*)[])0 : (ਪੂਰਨ (*)[4])0, ਪੂਰਨ (*)[4]:+1, ਪੂਰਨ (*)[5]:(ਖਾਲੀ)0); }));
	  (ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?ar : (ਪੂਰਨ (*)[4])0, ਪੂਰਨ (*)[4]:+1, ਪੂਰਨ (*)[5]:(ਖਾਲੀ)0); }));
	  (ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?(ਪੂਰਨ (*)[4])0 : ar, ਪੂਰਨ (*)[4]:+1, ਪੂਰਨ (*)[5]:(ਖਾਲੀ)0); }));
	  (ਖਾਲੀ)(ਆਕਾਰ(ਬਣਤਰ { ਪੂਰਨ x:_Generic( 0?(ਪੂਰਨ (*)[5])0 : ar, ਪੂਰਨ (*)[5]:+1, ਪੂਰਨ (*)[4]:(ਖਾਲੀ)0); }));
	}

	ਲਿਖੋ ("%d\n", f(t));

	ਵਾਪਸ 0;
}
