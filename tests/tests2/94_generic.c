#અન્તર્ભાવ <stdio.h>

અચલ પૂર્ણાંક a = 0;

સંરચના a {
	પૂર્ણાંક a;
};

સંરચના b {
	પૂર્ણાંક a;
};

પૂર્ણાંક a_f()
{
	પાછા 20;
}

પૂર્ણાંક b_f()
{
	પાછા 10;
}

પ્રકારવ્યાખ્યા પૂર્ણાંક (*fptr)(પૂર્ણાંક);
પ્રકારવ્યાખ્યા શૂન્ય (*vfptr)(પૂર્ણાંક);
પૂર્ણાંક foo(પૂર્ણાંક i)
{
  પાછા i;
}
શૂન્ય void_foo(પૂર્ણાંક i) {}

પ્રકારવ્યાખ્યા પૂર્ણાંક int_type1;

પ્રકારવ્યાખ્યા પૂર્ણાંક T[4];
પૂર્ણાંક f(T t)
{
	પાછા _Generic(t, __typeof__( ((શૂન્ય)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, અચલ અક્ષર *: 1, મૂળભૂત: 8, પૂર્ણાંક: 123);

પૂર્ણાંક મુખ્ય()
{
	પૂર્ણાંક i = 0;
	signed long પૂર્ણાંક l = 2;
	સંરચના b titi;
	અચલ પૂર્ણાંક * અચલ ptr;
	અચલ અક્ષર *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, પૂર્ણાંક: a_f, અચલ પૂર્ણાંક: b_f)();
	printf("%d\n", i);
	i = _Generic(a, પૂર્ણાંક: a_f() / 2, અચલ પૂર્ણાંક: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, પૂર્ણાંક *:1, પૂર્ણાંક * અચલ:2, મૂળભૂત:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, સંરચના a:1, સંરચના b:2, મૂળભૂત:20);
	printf("%d\n", i);
	i = _Generic(i2, અક્ષર: 1, પૂર્ણાંક : 0);
	printf("%d\n", i);
	i = _Generic(a, અક્ષર:1, પૂર્ણાંક[4]:2, મૂળભૂત:5);
	printf("%d\n", i);
	i = _Generic(17, પૂર્ણાંક :1, પૂર્ણાંક **:2);
	printf("%d\n", i);
	i = _Generic(17L, પૂર્ણાંક :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", અક્ષર *: 3, અચલ અક્ષર *: 1);
	printf("%d\n", i);
	i = _Generic(ti, અચલ unsigned અક્ષર *:1, અચલ અક્ષર *:4, અક્ષર *:3,
		     અચલ signed અક્ષર *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", પૂર્ણાંક: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, પૂર્ણાંક: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, પૂર્ણાંક: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, પૂર્ણાંક: 4, vfptr: 5);
	printf("%d\n", i);

	(શૂન્ય)_Generic((પૂર્ણાંક(*)[2]){0}, પૂર્ણાંક(*)[2]:0, પૂર્ણાંક(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	સંરચના { _Bool x_0: _Generic(({0;}),મૂળભૂત:1); } my_x;

	_Generic((__typeof((દશાંશ અચલ)((દશાંશ અચલ){42}))*){0}, દશાંશ*: 0); //casts lose top-level qualifiers
	પૂર્ણાંક અચલ x = 42; __typeof((__typeof(x))x) *xp = 0; (શૂન્ય)_Generic(xp, પૂર્ણાંક*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (શૂન્ય)0);
	//combining of qualifiers
	_Generic( 0?(long અસ્થિર*)0:(long અચલ*)0,  long અચલ અસ્થિર*: (શૂન્ય)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (શૂન્ય)0);
	_Generic( 0?(long*)0:(શૂન્ય*)0, long*: (શૂન્ય)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(પૂર્ણાંક અસ્થિર*)0: (શૂન્ય અચલ*)1, શૂન્ય અસ્થિર અચલ*: (શૂન્ય)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(શૂન્ય*)(i*0LL):&i, શૂન્ય*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(પૂર્ણાંક અસ્થિર*)0: (શૂન્ય અચલ*)0, શૂન્ય અસ્થિર અચલ*: (શૂન્ય)0);

	//ptrs to incomplete types get completed
	(શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?(પૂર્ણાંક (*)[4])0 : (પૂર્ણાંક (*)[])0, પૂર્ણાંક (*)[4]:+1, પૂર્ણાંક (*)[5]:(શૂન્ય)0); }));
	(શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?(પૂર્ણાંક (*)[])0 : (પૂર્ણાંક (*)[4])0, પૂર્ણાંક (*)[4]:+1, પૂર્ણાંક (*)[5]:(શૂન્ય)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		અક્ષર **argv;
		_Generic(argv, અક્ષર**: (શૂન્ય)0);
		_Generic(0?(અક્ષર અચલ*)0:argv[0], અક્ષર અચલ*: (શૂન્ય)0);
		_Generic(argv, અક્ષર**: (શૂન્ય)0);
	}
	{
	  બાહ્ય પૂર્ણાંક (*ar)[];
	  (શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?(પૂર્ણાંક (*)[4])0 : (પૂર્ણાંક (*)[])0, પૂર્ણાંક (*)[4]:+1, પૂર્ણાંક (*)[5]:(શૂન્ય)0); }));
	  (શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?(પૂર્ણાંક (*)[])0 : (પૂર્ણાંક (*)[4])0, પૂર્ણાંક (*)[4]:+1, પૂર્ણાંક (*)[5]:(શૂન્ય)0); }));
	  (શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?ar : (પૂર્ણાંક (*)[4])0, પૂર્ણાંક (*)[4]:+1, પૂર્ણાંક (*)[5]:(શૂન્ય)0); }));
	  (શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?(પૂર્ણાંક (*)[4])0 : ar, પૂર્ણાંક (*)[4]:+1, પૂર્ણાંક (*)[5]:(શૂન્ય)0); }));
	  (શૂન્ય)(કદ(સંરચના { પૂર્ણાંક x:_Generic( 0?(પૂર્ણાંક (*)[5])0 : ar, પૂર્ણાંક (*)[5]:+1, પૂર્ણાંક (*)[4]:(શૂન્ય)0); }));
	}

	printf ("%d\n", f(t));

	પાછા 0;
}
