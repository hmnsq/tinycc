#അന്തര്ഭാവ <stdio.h>

സ്ഥിരം പൂർണ്ണസംഖ്യ a = 0;

ഘടന a {
	പൂർണ്ണസംഖ്യ a;
};

ഘടന b {
	പൂർണ്ണസംഖ്യ a;
};

പൂർണ്ണസംഖ്യ a_f()
{
	തിരികെ 20;
}

പൂർണ്ണസംഖ്യ b_f()
{
	തിരികെ 10;
}

തരനിർവചനം പൂർണ്ണസംഖ്യ (*fptr)(പൂർണ്ണസംഖ്യ);
തരനിർവചനം ശൂന്യം (*vfptr)(പൂർണ്ണസംഖ്യ);
പൂർണ്ണസംഖ്യ foo(പൂർണ്ണസംഖ്യ i)
{
  തിരികെ i;
}
ശൂന്യം void_foo(പൂർണ്ണസംഖ്യ i) {}

തരനിർവചനം പൂർണ്ണസംഖ്യ int_type1;

തരനിർവചനം പൂർണ്ണസംഖ്യ T[4];
പൂർണ്ണസംഖ്യ f(T t)
{
	തിരികെ _Generic(t, __typeof__( ((ശൂന്യം)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, സ്ഥിരം അക്ഷരം *: 1, സ്ഥിരസ്ഥിതി: 8, പൂർണ്ണസംഖ്യ: 123);

പൂർണ്ണസംഖ്യ പ്രധാന()
{
	പൂർണ്ണസംഖ്യ i = 0;
	signed long പൂർണ്ണസംഖ്യ l = 2;
	ഘടന b titi;
	സ്ഥിരം പൂർണ്ണസംഖ്യ * സ്ഥിരം ptr;
	സ്ഥിരം അക്ഷരം *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, പൂർണ്ണസംഖ്യ: a_f, സ്ഥിരം പൂർണ്ണസംഖ്യ: b_f)();
	printf("%d\n", i);
	i = _Generic(a, പൂർണ്ണസംഖ്യ: a_f() / 2, സ്ഥിരം പൂർണ്ണസംഖ്യ: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, പൂർണ്ണസംഖ്യ *:1, പൂർണ്ണസംഖ്യ * സ്ഥിരം:2, സ്ഥിരസ്ഥിതി:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, ഘടന a:1, ഘടന b:2, സ്ഥിരസ്ഥിതി:20);
	printf("%d\n", i);
	i = _Generic(i2, അക്ഷരം: 1, പൂർണ്ണസംഖ്യ : 0);
	printf("%d\n", i);
	i = _Generic(a, അക്ഷരം:1, പൂർണ്ണസംഖ്യ[4]:2, സ്ഥിരസ്ഥിതി:5);
	printf("%d\n", i);
	i = _Generic(17, പൂർണ്ണസംഖ്യ :1, പൂർണ്ണസംഖ്യ **:2);
	printf("%d\n", i);
	i = _Generic(17L, പൂർണ്ണസംഖ്യ :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", അക്ഷരം *: 3, സ്ഥിരം അക്ഷരം *: 1);
	printf("%d\n", i);
	i = _Generic(ti, സ്ഥിരം unsigned അക്ഷരം *:1, സ്ഥിരം അക്ഷരം *:4, അക്ഷരം *:3,
		     സ്ഥിരം signed അക്ഷരം *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", പൂർണ്ണസംഖ്യ: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, പൂർണ്ണസംഖ്യ: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, പൂർണ്ണസംഖ്യ: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, പൂർണ്ണസംഖ്യ: 4, vfptr: 5);
	printf("%d\n", i);

	(ശൂന്യം)_Generic((പൂർണ്ണസംഖ്യ(*)[2]){0}, പൂർണ്ണസംഖ്യ(*)[2]:0, പൂർണ്ണസംഖ്യ(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	ഘടന { _Bool x_0: _Generic(({0;}),സ്ഥിരസ്ഥിതി:1); } my_x;

	_Generic((__typeof((ദശാംശം സ്ഥിരം)((ദശാംശം സ്ഥിരം){42}))*){0}, ദശാംശം*: 0); //casts lose top-level qualifiers
	പൂർണ്ണസംഖ്യ സ്ഥിരം x = 42; __typeof((__typeof(x))x) *xp = 0; (ശൂന്യം)_Generic(xp, പൂർണ്ണസംഖ്യ*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (ശൂന്യം)0);
	//combining of qualifiers
	_Generic( 0?(long അസ്ഥിര*)0:(long സ്ഥിരം*)0,  long സ്ഥിരം അസ്ഥിര*: (ശൂന്യം)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (ശൂന്യം)0);
	_Generic( 0?(long*)0:(ശൂന്യം*)0, long*: (ശൂന്യം)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(പൂർണ്ണസംഖ്യ അസ്ഥിര*)0: (ശൂന്യം സ്ഥിരം*)1, ശൂന്യം അസ്ഥിര സ്ഥിരം*: (ശൂന്യം)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(ശൂന്യം*)(i*0LL):&i, ശൂന്യം*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(പൂർണ്ണസംഖ്യ അസ്ഥിര*)0: (ശൂന്യം സ്ഥിരം*)0, ശൂന്യം അസ്ഥിര സ്ഥിരം*: (ശൂന്യം)0);

	//ptrs to incomplete types get completed
	(ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?(പൂർണ്ണസംഖ്യ (*)[4])0 : (പൂർണ്ണസംഖ്യ (*)[])0, പൂർണ്ണസംഖ്യ (*)[4]:+1, പൂർണ്ണസംഖ്യ (*)[5]:(ശൂന്യം)0); }));
	(ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?(പൂർണ്ണസംഖ്യ (*)[])0 : (പൂർണ്ണസംഖ്യ (*)[4])0, പൂർണ്ണസംഖ്യ (*)[4]:+1, പൂർണ്ണസംഖ്യ (*)[5]:(ശൂന്യം)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		അക്ഷരം **argv;
		_Generic(argv, അക്ഷരം**: (ശൂന്യം)0);
		_Generic(0?(അക്ഷരം സ്ഥിരം*)0:argv[0], അക്ഷരം സ്ഥിരം*: (ശൂന്യം)0);
		_Generic(argv, അക്ഷരം**: (ശൂന്യം)0);
	}
	{
	  ബാഹ്യ പൂർണ്ണസംഖ്യ (*ar)[];
	  (ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?(പൂർണ്ണസംഖ്യ (*)[4])0 : (പൂർണ്ണസംഖ്യ (*)[])0, പൂർണ്ണസംഖ്യ (*)[4]:+1, പൂർണ്ണസംഖ്യ (*)[5]:(ശൂന്യം)0); }));
	  (ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?(പൂർണ്ണസംഖ്യ (*)[])0 : (പൂർണ്ണസംഖ്യ (*)[4])0, പൂർണ്ണസംഖ്യ (*)[4]:+1, പൂർണ്ണസംഖ്യ (*)[5]:(ശൂന്യം)0); }));
	  (ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?ar : (പൂർണ്ണസംഖ്യ (*)[4])0, പൂർണ്ണസംഖ്യ (*)[4]:+1, പൂർണ്ണസംഖ്യ (*)[5]:(ശൂന്യം)0); }));
	  (ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?(പൂർണ്ണസംഖ്യ (*)[4])0 : ar, പൂർണ്ണസംഖ്യ (*)[4]:+1, പൂർണ്ണസംഖ്യ (*)[5]:(ശൂന്യം)0); }));
	  (ശൂന്യം)(വലുപ്പം(ഘടന { പൂർണ്ണസംഖ്യ x:_Generic( 0?(പൂർണ്ണസംഖ്യ (*)[5])0 : ar, പൂർണ്ണസംഖ്യ (*)[5]:+1, പൂർണ്ണസംഖ്യ (*)[4]:(ശൂന്യം)0); }));
	}

	printf ("%d\n", f(t));

	തിരികെ 0;
}
