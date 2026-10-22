#அந்தர்பாவ <stdio.h>

மாறிலி முழு a = 0;

கட்டமைப்பு a {
	முழு a;
};

கட்டமைப்பு b {
	முழு a;
};

முழு a_f()
{
	திரும்பு 20;
}

முழு b_f()
{
	திரும்பு 10;
}

வகைவரை முழு (*fptr)(முழு);
வகைவரை வெறுமை (*vfptr)(முழு);
முழு foo(முழு i)
{
  திரும்பு i;
}
வெறுமை void_foo(முழு i) {}

வகைவரை முழு int_type1;

வகைவரை முழு T[4];
முழு f(T t)
{
	திரும்பு _Generic(t, __typeof__( ((வெறுமை)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, மாறிலி எழுத்து *: 1, இயல்பு: 8, முழு: 123);

முழு முதன்மை()
{
	முழு i = 0;
	signed long முழு l = 2;
	கட்டமைப்பு b titi;
	மாறிலி முழு * மாறிலி ptr;
	மாறிலி எழுத்து *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, முழு: a_f, மாறிலி முழு: b_f)();
	printf("%d\n", i);
	i = _Generic(a, முழு: a_f() / 2, மாறிலி முழு: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, முழு *:1, முழு * மாறிலி:2, இயல்பு:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, கட்டமைப்பு a:1, கட்டமைப்பு b:2, இயல்பு:20);
	printf("%d\n", i);
	i = _Generic(i2, எழுத்து: 1, முழு : 0);
	printf("%d\n", i);
	i = _Generic(a, எழுத்து:1, முழு[4]:2, இயல்பு:5);
	printf("%d\n", i);
	i = _Generic(17, முழு :1, முழு **:2);
	printf("%d\n", i);
	i = _Generic(17L, முழு :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", எழுத்து *: 3, மாறிலி எழுத்து *: 1);
	printf("%d\n", i);
	i = _Generic(ti, மாறிலி unsigned எழுத்து *:1, மாறிலி எழுத்து *:4, எழுத்து *:3,
		     மாறிலி signed எழுத்து *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", முழு: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, முழு: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, முழு: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, முழு: 4, vfptr: 5);
	printf("%d\n", i);

	(வெறுமை)_Generic((முழு(*)[2]){0}, முழு(*)[2]:0, முழு(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	கட்டமைப்பு { _Bool x_0: _Generic(({0;}),இயல்பு:1); } my_x;

	_Generic((__typeof((தசம மாறிலி)((தசம மாறிலி){42}))*){0}, தசம*: 0); //casts lose top-level qualifiers
	முழு மாறிலி x = 42; __typeof((__typeof(x))x) *xp = 0; (வெறுமை)_Generic(xp, முழு*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (வெறுமை)0);
	//combining of qualifiers
	_Generic( 0?(long நிலையற்ற*)0:(long மாறிலி*)0,  long மாறிலி நிலையற்ற*: (வெறுமை)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (வெறுமை)0);
	_Generic( 0?(long*)0:(வெறுமை*)0, long*: (வெறுமை)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(முழு நிலையற்ற*)0: (வெறுமை மாறிலி*)1, வெறுமை நிலையற்ற மாறிலி*: (வெறுமை)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(வெறுமை*)(i*0LL):&i, வெறுமை*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(முழு நிலையற்ற*)0: (வெறுமை மாறிலி*)0, வெறுமை நிலையற்ற மாறிலி*: (வெறுமை)0);

	//ptrs to incomplete types get completed
	(வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?(முழு (*)[4])0 : (முழு (*)[])0, முழு (*)[4]:+1, முழு (*)[5]:(வெறுமை)0); }));
	(வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?(முழு (*)[])0 : (முழு (*)[4])0, முழு (*)[4]:+1, முழு (*)[5]:(வெறுமை)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		எழுத்து **argv;
		_Generic(argv, எழுத்து**: (வெறுமை)0);
		_Generic(0?(எழுத்து மாறிலி*)0:argv[0], எழுத்து மாறிலி*: (வெறுமை)0);
		_Generic(argv, எழுத்து**: (வெறுமை)0);
	}
	{
	  வெளி முழு (*ar)[];
	  (வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?(முழு (*)[4])0 : (முழு (*)[])0, முழு (*)[4]:+1, முழு (*)[5]:(வெறுமை)0); }));
	  (வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?(முழு (*)[])0 : (முழு (*)[4])0, முழு (*)[4]:+1, முழு (*)[5]:(வெறுமை)0); }));
	  (வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?ar : (முழு (*)[4])0, முழு (*)[4]:+1, முழு (*)[5]:(வெறுமை)0); }));
	  (வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?(முழு (*)[4])0 : ar, முழு (*)[4]:+1, முழு (*)[5]:(வெறுமை)0); }));
	  (வெறுமை)(அளவு(கட்டமைப்பு { முழு x:_Generic( 0?(முழு (*)[5])0 : ar, முழு (*)[5]:+1, முழு (*)[4]:(வெறுமை)0); }));
	}

	printf ("%d\n", f(t));

	திரும்பு 0;
}
