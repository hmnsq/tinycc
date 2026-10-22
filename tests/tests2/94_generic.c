#অন্তর্ভাৱ <stdio.h>

ধ্রুৱ পূর্ণাঙ্ক a = 0;

সংরচনা a {
	পূর্ণাঙ্ক a;
};

সংরচনা b {
	পূর্ণাঙ্ক a;
};

পূর্ণাঙ্ক a_f()
{
	ঘূৰাই 20;
}

পূর্ণাঙ্ক b_f()
{
	ঘূৰাই 10;
}

প্রকারনির্দেশ পূর্ণাঙ্ক (*fptr)(পূর্ণাঙ্ক);
প্রকারনির্দেশ শূন্য (*vfptr)(পূর্ণাঙ্ক);
পূর্ণাঙ্ক foo(পূর্ণাঙ্ক i)
{
  ঘূৰাই i;
}
শূন্য void_foo(পূর্ণাঙ্ক i) {}

প্রকারনির্দেশ পূর্ণাঙ্ক int_type1;

প্রকারনির্দেশ পূর্ণাঙ্ক T[4];
পূর্ণাঙ্ক f(T t)
{
	ঘূৰাই _Generic(t, __typeof__( ((শূন্য)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ধ্রুৱ ৱর্ণ *: 1, স্ৱভাৱ: 8, পূর্ণাঙ্ক: 123);

পূর্ণাঙ্ক main()
{
	পূর্ণাঙ্ক i = 0;
	signed long পূর্ণাঙ্ক l = 2;
	সংরচনা b titi;
	ধ্রুৱ পূর্ণাঙ্ক * ধ্রুৱ ptr;
	ধ্রুৱ ৱর্ণ *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, পূর্ণাঙ্ক: a_f, ধ্রুৱ পূর্ণাঙ্ক: b_f)();
	printf("%d\n", i);
	i = _Generic(a, পূর্ণাঙ্ক: a_f() / 2, ধ্রুৱ পূর্ণাঙ্ক: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, পূর্ণাঙ্ক *:1, পূর্ণাঙ্ক * ধ্রুৱ:2, স্ৱভাৱ:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, সংরচনা a:1, সংরচনা b:2, স্ৱভাৱ:20);
	printf("%d\n", i);
	i = _Generic(i2, ৱর্ণ: 1, পূর্ণাঙ্ক : 0);
	printf("%d\n", i);
	i = _Generic(a, ৱর্ণ:1, পূর্ণাঙ্ক[4]:2, স্ৱভাৱ:5);
	printf("%d\n", i);
	i = _Generic(17, পূর্ণাঙ্ক :1, পূর্ণাঙ্ক **:2);
	printf("%d\n", i);
	i = _Generic(17L, পূর্ণাঙ্ক :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", ৱর্ণ *: 3, ধ্রুৱ ৱর্ণ *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ধ্রুৱ unsigned ৱর্ণ *:1, ধ্রুৱ ৱর্ণ *:4, ৱর্ণ *:3,
		     ধ্রুৱ signed ৱর্ণ *:2);
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
	সংরচনা { _Bool x_0: _Generic(({0;}),স্ৱভাৱ:1); } my_x;

	_Generic((__typeof((ভিন্ন ধ্রুৱ)((ভিন্ন ধ্রুৱ){42}))*){0}, ভিন্ন*: 0); //casts lose top-level qualifiers
	পূর্ণাঙ্ক ধ্রুৱ x = 42; __typeof((__typeof(x))x) *xp = 0; (শূন্য)_Generic(xp, পূর্ণাঙ্ক*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (শূন্য)0);
	//combining of qualifiers
	_Generic( 0?(long চঞ্চল*)0:(long ধ্রুৱ*)0,  long ধ্রুৱ চঞ্চল*: (শূন্য)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (শূন্য)0);
	_Generic( 0?(long*)0:(শূন্য*)0, long*: (শূন্য)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(পূর্ণাঙ্ক চঞ্চল*)0: (শূন্য ধ্রুৱ*)1, শূন্য চঞ্চল ধ্রুৱ*: (শূন্য)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(শূন্য*)(i*0LL):&i, শূন্য*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(পূর্ণাঙ্ক চঞ্চল*)0: (শূন্য ধ্রুৱ*)0, শূন্য চঞ্চল ধ্রুৱ*: (শূন্য)0);

	//ptrs to incomplete types get completed
	(শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[4])0 : (পূর্ণাঙ্ক (*)[])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));
	(শূন্য)(পরিমাণ(সংরচনা { পূর্ণাঙ্ক x:_Generic( 0?(পূর্ণাঙ্ক (*)[])0 : (পূর্ণাঙ্ক (*)[4])0, পূর্ণাঙ্ক (*)[4]:+1, পূর্ণাঙ্ক (*)[5]:(শূন্য)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		ৱর্ণ **argv;
		_Generic(argv, ৱর্ণ**: (শূন্য)0);
		_Generic(0?(ৱর্ণ ধ্রুৱ*)0:argv[0], ৱর্ণ ধ্রুৱ*: (শূন্য)0);
		_Generic(argv, ৱর্ণ**: (শূন্য)0);
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

	ঘূৰাই 0;
}
