#অন্তর্ভাব <stdio.h>

ধ্রুব পূর্ণাঙ্ক a = 0;

সংরচনা a {
	পূর্ণাঙ্ক a;
};

সংরচনা b {
	পূর্ণাঙ্ক a;
};

পূর্ণাঙ্ক a_f()
{
	প্রত্যাগম 20;
}

পূর্ণাঙ্ক b_f()
{
	প্রত্যাগম 10;
}

প্রকারনির্দেশ পূর্ণাঙ্ক (*fptr)(পূর্ণাঙ্ক);
প্রকারনির্দেশ শূন্য (*vfptr)(পূর্ণাঙ্ক);
পূর্ণাঙ্ক foo(পূর্ণাঙ্ক i)
{
  প্রত্যাগম i;
}
শূন্য void_foo(পূর্ণাঙ্ক i) {}

প্রকারনির্দেশ পূর্ণাঙ্ক int_type1;

প্রকারনির্দেশ পূর্ণাঙ্ক T[4];
পূর্ণাঙ্ক f(T t)
{
	প্রত্যাগম _Generic(t, __typeof__( ((শূন্য)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ধ্রুব বর্ণ *: 1, স্বভাব: 8, পূর্ণাঙ্ক: 123);

পূর্ণাঙ্ক main()
{
	পূর্ণাঙ্ক i = 0;
	signed long পূর্ণাঙ্ক l = 2;
	সংরচনা b titi;
	ধ্রুব পূর্ণাঙ্ক * ধ্রুব ptr;
	ধ্রুব বর্ণ *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, পূর্ণাঙ্ক: a_f, ধ্রুব পূর্ণাঙ্ক: b_f)();
	printf("%d\n", i);
	i = _Generic(a, পূর্ণাঙ্ক: a_f() / 2, ধ্রুব পূর্ণাঙ্ক: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, পূর্ণাঙ্ক *:1, পূর্ণাঙ্ক * ধ্রুব:2, স্বভাব:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, সংরচনা a:1, সংরচনা b:2, স্বভাব:20);
	printf("%d\n", i);
	i = _Generic(i2, বর্ণ: 1, পূর্ণাঙ্ক : 0);
	printf("%d\n", i);
	i = _Generic(a, বর্ণ:1, পূর্ণাঙ্ক[4]:2, স্বভাব:5);
	printf("%d\n", i);
	i = _Generic(17, পূর্ণাঙ্ক :1, পূর্ণাঙ্ক **:2);
	printf("%d\n", i);
	i = _Generic(17L, পূর্ণাঙ্ক :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", বর্ণ *: 3, ধ্রুব বর্ণ *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ধ্রুব unsigned বর্ণ *:1, ধ্রুব বর্ণ *:4, বর্ণ *:3,
		     ধ্রুব signed বর্ণ *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", পূর্ণাঙ্ক: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, পূর্ণাঙ্ক: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, পূর্ণাঙ্ক: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, পূর্ণাঙ্ক: 4, vfptr: 5);
	printf("%d\n", i);

	(শূন্য)_Generic((পূর্ণাঙ্ক(*)[2]){0}, পূর্ণাঙ্ক(*)[2]:0, পূর্ণাঙ্ক(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	সংরচনা { _Bool x_0: _Generic(({0;}),স্বভাব:1); } my_x;

	_Generic((__typeof((ভিন্ন ধ্রুব)((ভিন্ন ধ্রুব){42}))*){0}, ভিন্ন*: 0); //casts lose top-level qualifiers
	পূর্ণাঙ্ক ধ্রুব x = 42; __typeof((__typeof(x))x) *xp = 0; (শূন্য)_Generic(xp, পূর্ণাঙ্ক*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (শূন্য)0);
	//combining of qualifiers
	_Generic( 0?(long চঞ্চল*)0:(long ধ্রুব*)0,  long ধ্রুব চঞ্চল*: (শূন্য)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (শূন্য)0);
	_Generic( 0?(long*)0:(শূন্য*)0, long*: (শূন্য)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(পূর্ণাঙ্ক চঞ্চল*)0: (শূন্য ধ্রুব*)1, শূন্য চঞ্চল ধ্রুব*: (শূন্য)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(শূন্য*)(i*0LL):&i, শূন্য*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(পূর্ণাঙ্ক চঞ্চল*)0: (শূন্য ধ্রুব*)0, শূন্য চঞ্চল ধ্রুব*: (শূন্য)0);

	//ptrs to incomplete types get completed
	(শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[4])0 : (পূর্ণাঙ্ক (*)[])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));
	(শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[])0 : (পূর্ণাঙ্ক (*)[4])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		বর্ণ **argv;
		_Generic(argv, বর্ণ**: (শূন্য)0);
		_Generic(0?(বর্ণ ধ্রুব*)0:argv[0], বর্ণ ধ্রুব*: (শূন্য)0);
		_Generic(argv, বর্ণ**: (শূন্য)0);
	}
	{
	  বাহ্য পূর্ণাঙ্ক (*ar)[];
	  (শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[4])0 : (পূর্ণাঙ্ক (*)[])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));
	  (শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[])0 : (পূর্ণাঙ্ক (*)[4])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));
	  (শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?ar : (পূর্ণাঙ্ক (*)[4])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));
	  (শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[4])0 : ar, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));
	  (শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[5])0 : ar, পূর্ণাঙ্ক (*)[5]:+1, পূর্ণাঙ্ক (*)[4]:(শূন্য)0); }));
	}

	printf ("%d\n", f(t));

	প্রত্যাগম 0;
}
