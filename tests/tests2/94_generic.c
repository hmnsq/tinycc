#अन्तर्भाव <stdio.h>

ध्रुव पूर्णाङ्क a = 0;

संरचना a {
	पूर्णाङ्क a;
};

संरचना b {
	पूर्णाङ्क a;
};

पूर्णाङ्क a_f()
{
	प्रत्यागम 20;
}

पूर्णाङ्क b_f()
{
	प्रत्यागम 10;
}

प्रकारनिर्देश पूर्णाङ्क (*fptr)(पूर्णाङ्क);
प्रकारनिर्देश शून्य (*vfptr)(पूर्णाङ्क);
पूर्णाङ्क foo(पूर्णाङ्क i)
{
  प्रत्यागम i;
}
शून्य void_foo(पूर्णाङ्क i) {}

प्रकारनिर्देश पूर्णाङ्क int_type1;

प्रकारनिर्देश पूर्णाङ्क T[4];
पूर्णाङ्क f(T t)
{
	प्रत्यागम _Generic(t, __typeof__( ((शून्य)0, (T){0}) ) : 1 );
}

#define gen_sw(a) _Generic(a, ध्रुव वर्ण *: 1, स्वभाव: 8, पूर्णाङ्क: 123);

पूर्णाङ्क main()
{
	पूर्णाङ्क i = 0;
	signed long पूर्णाङ्क l = 2;
	संरचना b titi;
	ध्रुव पूर्णाङ्क * ध्रुव ptr;
	ध्रुव वर्ण *ti;
	int_type1 i2;
	T t;

	i = _Generic(a, पूर्णाङ्क: a_f, ध्रुव पूर्णाङ्क: b_f)();
	printf("%d\n", i);
	i = _Generic(a, पूर्णाङ्क: a_f() / 2, ध्रुव पूर्णाङ्क: b_f() / 2);
	printf("%d\n", i);
	i = _Generic(ptr, पूर्णाङ्क *:1, पूर्णाङ्क * ध्रुव:2, स्वभाव:20);
	printf("%d\n", i);
	i = gen_sw(a);
	printf("%d\n", i);
	i = _Generic(titi, संरचना a:1, संरचना b:2, स्वभाव:20);
	printf("%d\n", i);
	i = _Generic(i2, वर्ण: 1, पूर्णाङ्क : 0);
	printf("%d\n", i);
	i = _Generic(a, वर्ण:1, पूर्णाङ्क[4]:2, स्वभाव:5);
	printf("%d\n", i);
	i = _Generic(17, पूर्णाङ्क :1, पूर्णाङ्क **:2);
	printf("%d\n", i);
	i = _Generic(17L, पूर्णाङ्क :1, long :2, long long : 3);
	printf("%d\n", i);
	i = _Generic("17, io", वर्ण *: 3, ध्रुव वर्ण *: 1);
	printf("%d\n", i);
	i = _Generic(ti, ध्रुव unsigned वर्ण *:1, ध्रुव वर्ण *:4, वर्ण *:3,
		     ध्रुव signed वर्ण *:2);
	printf("%d\n", i);
	printf("%s\n", _Generic(i + 2L, long: "long", पूर्णाङ्क: "int",
				long long: "long long"));
	i = _Generic(l, long: 1, पूर्णाङ्क: 2);
	printf("%d\n", i);
	i = _Generic(foo, fptr: 3, पूर्णाङ्क: 4, vfptr: 5);
	printf("%d\n", i);
	i = _Generic(void_foo, fptr: 3, पूर्णाङ्क: 4, vfptr: 5);
	printf("%d\n", i);

	(शून्य)_Generic((पूर्णाङ्क(*)[2]){0}, पूर्णाङ्क(*)[2]:0, पूर्णाङ्क(*)[4]:0); //shouldn't match twice

	//should accept ({ }) in the controlling expr of _Generic even in const_wanted contexts
	संरचना { _Bool x_0: _Generic(({0;}),स्वभाव:1); } my_x;

	_Generic((__typeof((भिन्न ध्रुव)((भिन्न ध्रुव){42}))*){0}, भिन्न*: 0); //casts lose top-level qualifiers
	पूर्णाङ्क ध्रुव x = 42; __typeof((__typeof(x))x) *xp = 0; (शून्य)_Generic(xp, पूर्णाङ्क*: 0); //casts lose top-level qualifiers

	//TEST TERNARY:
	//Same type
	_Generic( 0?(long*)0:(long*)0,  long*: (शून्य)0);
	//combining of qualifiers
	_Generic( 0?(long चञ्चल*)0:(long ध्रुव*)0,  long ध्रुव चञ्चल*: (शून्य)0);
	//nul-ptr constant selects other type
	_Generic( 0?(long*)0:0,			long*: (शून्य)0);
	_Generic( 0?(long*)0:(शून्य*)0, long*: (शून्य)0);

	//void ptrs get chosen preferentially; qualifs still combine
	_Generic( 0?(पूर्णाङ्क चञ्चल*)0: (शून्य ध्रुव*)1, शून्य चञ्चल ध्रुव*: (शून्य)0);
        //but this is no null-ptr constant, so fallback to void-choice
        i = 0;
        _Generic( 1?(शून्य*)(i*0LL):&i, शून्य*:0);
	//like gcc but not clang, don't treat (void* const as the null-ptr constant)
	_Generic( 0?(पूर्णाङ्क चञ्चल*)0: (शून्य ध्रुव*)0, शून्य चञ्चल ध्रुव*: (शून्य)0);

	//ptrs to incomplete types get completed
	(शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?(पूर्णाङ्क (*)[4])0 : (पूर्णाङ्क (*)[])0, पूर्णाङ्क (*)[4]:+1, पूर्णाङ्क (*)[5]:(शून्य)0); }));
	(शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?(पूर्णाङ्क (*)[])0 : (पूर्णाङ्क (*)[4])0, पूर्णाङ्क (*)[4]:+1, पूर्णाङ्क (*)[5]:(शून्य)0); }));

	{
	  /* completion shouldn't affect the type of decl */
		वर्ण **argv;
		_Generic(argv, वर्ण**: (शून्य)0);
		_Generic(0?(वर्ण ध्रुव*)0:argv[0], वर्ण ध्रुव*: (शून्य)0);
		_Generic(argv, वर्ण**: (शून्य)0);
	}
	{
	  बाह्य पूर्णाङ्क (*ar)[];
	  (शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?(पूर्णाङ्क (*)[4])0 : (पूर्णाङ्क (*)[])0, पूर्णाङ्क (*)[4]:+1, पूर्णाङ्क (*)[5]:(शून्य)0); }));
	  (शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?(पूर्णाङ्क (*)[])0 : (पूर्णाङ्क (*)[4])0, पूर्णाङ्क (*)[4]:+1, पूर्णाङ्क (*)[5]:(शून्य)0); }));
	  (शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?ar : (पूर्णाङ्क (*)[4])0, पूर्णाङ्क (*)[4]:+1, पूर्णाङ्क (*)[5]:(शून्य)0); }));
	  (शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?(पूर्णाङ्क (*)[4])0 : ar, पूर्णाङ्क (*)[4]:+1, पूर्णाङ्क (*)[5]:(शून्य)0); }));
	  (शून्य)(परिमाण(संरचना { पूर्णाङ्क x:_Generic( 0?(पूर्णाङ्क (*)[5])0 : ar, पूर्णाङ्क (*)[5]:+1, पूर्णाङ्क (*)[4]:(शून्य)0); }));
	}

	printf ("%d\n", f(t));

	प्रत्यागम 0;
}
