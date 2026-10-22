#شامل <stdio.h>

ثابت صحیح a = 0;

ساخت a {
	صحیح a;
};

ساخت b {
	صحیح a;
};

صحیح a_f()
{
	واپس 20;
}

صحیح b_f()
{
	واپس 10;
}

قسمتعریف صحیح (*fptr)(صحیح);
قسمتعریف خالی (*vfptr)(صحیح);
صحیح foo(صحیح i)
{
  واپس i;
}
خالی void_foo(صحیح i) {}

قسمتعریف صحیح int_type1;

قسمتعریف صحیح T[4];
صحیح f(T t)
{
	واپس _Generic(t, __typeof__( ((خالی)0, (T){0}) ) : 1 );
}

#تعریف_کرو gen_sw(a) _Generic(a, ثابت حرف *: 1, طےشدہ: 8, صحیح: 123);

صحیح مین()
{
	صحیح i = 0;
	علامتی طویل صحیح l = 2;
	ساخت b titi;
	ثابت صحیح * ثابت ptr;
	ثابت حرف *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, صحیح: a_f, ثابت صحیح: b_f)();
	لکھو("%d\n", i);
	i = _Generic(a, صحیح: a_f() / 2, ثابت صحیح: b_f() / 2);
	لکھو("%d\n", i);
	i = _Generic(ptr, صحیح *:1, صحیح * ثابت:2, طےشدہ:20);
	لکھو("%d\n", i);
	i = gen_sw(a);
	لکھو("%d\n", i);
	i = _Generic(titi, ساخت a:1, ساخت b:2, طےشدہ:20);
	لکھو("%d\n", i);
	i = _Generic(i2, حرف: 1, صحیح : 0);
	لکھو("%d\n", i);
	i = _Generic(a, حرف:1, صحیح[4]:2, طےشدہ:5);
	لکھو("%d\n", i);
	i = _Generic(17, صحیح :1, صحیح **:2);
	لکھو("%d\n", i);
	i = _Generic(17L, صحیح :1, طویل :2, طویل طویل : 3);
	لکھو("%d\n", i);
	i = _Generic("17, io", حرف *: 3, ثابت حرف *: 1);
	لکھو("%d\n", i);
	i = _Generic(ti, ثابت غیرعلامتی حرف *:1, ثابت حرف *:4, حرف *:3,
		     ثابت علامتی حرف *:2);
	لکھو("%d\n", i);
	لکھو("%s\n", _Generic(i + 2L, طویل: "long", صحیح: "int",
				طویل طویل: "long long"));
	i = _Generic(l, طویل: 1, صحیح: 2);
	لکھو("%d\n", i);
	i = _Generic(foo, fptr: 3, صحیح: 4, vfptr: 5);
	لکھو("%d\n", i);
	i = _Generic(void_foo, fptr: 3, صحیح: 4, vfptr: 5);
	لکھو("%d\n", i);

	(خالی)_Generic((صحیح(*)[2]){0}, صحیح(*)[2]:0, صحیح(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	ساخت { _Bool x_0: _Generic(({0;}),طےشدہ:1); } my_x;

	_Generic((__typeof((اعشاری ثابت)((اعشاری ثابت){42}))*){0}, اعشاری*: 0); //casts lose top-level qualifiers
	صحیح ثابت x = 42; __typeof((__typeof(x))x) *xp = 0; (خالی)_Generic(xp, صحیح*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(طویل*)0:(طویل*)0,  طویل*: (خالی)0);
	//combining of qualifiers
	_Generic( 0?(طویل متلون*)0:(طویل ثابت*)0,  طویل ثابت متلون*: (خالی)0);
	//nul-ptr constant selects other type
	_Generic( 0?(طویل*)0:0,			طویل*: (خالی)0);
	_Generic( 0?(طویل*)0:(خالی*)0, طویل*: (خالی)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(صحیح متلون*)0: (خالی ثابت*)1, خالی متلون ثابت*: (خالی)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(خالی*)(i*0LL):&i, خالی*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(صحیح متلون*)0: (خالی ثابت*)0, خالی متلون ثابت*: (خالی)0);

	//ptrs to incomplete types get completed
	(خالی)(حجم(ساخت { صحیح x:_Generic( 0?(صحیح (*)[4])0 : (صحیح (*)[])0, صحیح (*)[4]:+1, صحیح (*)[5]:(خالی)0); }));
	(خالی)(حجم(ساخت { صحیح x:_Generic( 0?(صحیح (*)[])0 : (صحیح (*)[4])0, صحیح (*)[4]:+1, صحیح (*)[5]:(خالی)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		حرف **argv;
		_Generic(argv, حرف**: (خالی)0);
		_Generic(0?(حرف ثابت*)0:argv[0], حرف ثابت*: (خالی)0);
		_Generic(argv, حرف**: (خالی)0);
	}
	{
	  خارجی صحیح (*ar)[];
	  (خالی)(حجم(ساخت { صحیح x:_Generic( 0?(صحیح (*)[4])0 : (صحیح (*)[])0, صحیح (*)[4]:+1, صحیح (*)[5]:(خالی)0); }));
	  (خالی)(حجم(ساخت { صحیح x:_Generic( 0?(صحیح (*)[])0 : (صحیح (*)[4])0, صحیح (*)[4]:+1, صحیح (*)[5]:(خالی)0); }));
	  (خالی)(حجم(ساخت { صحیح x:_Generic( 0?ar : (صحیح (*)[4])0, صحیح (*)[4]:+1, صحیح (*)[5]:(خالی)0); }));
	  (خالی)(حجم(ساخت { صحیح x:_Generic( 0?(صحیح (*)[4])0 : ar, صحیح (*)[4]:+1, صحیح (*)[5]:(خالی)0); }));
	  (خالی)(حجم(ساخت { صحیح x:_Generic( 0?(صحیح (*)[5])0 : ar, صحیح (*)[5]:+1, صحیح (*)[4]:(خالی)0); }));
	}

	لکھو ("%d\n", f(t));

	واپس 0;
}
