قسمتعریف غیرعلامتی مختصر uint16_t;
قسمتعریف غیرعلامتی حرف uint8_t;

قسمتعریف اتحاد Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

قسمتعریف اتحاد __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

خارجی خالی foo (خالی) __attribute__((stdcall));
خالی __attribute__((stdcall)) foo (خالی)
{
}

#تعریف_کرو __stdcall __attribute__((stdcall))
خارجی صحیح some_stdcall_func (صحیح, صحیح, صحیح) __stdcall;
__stdcall صحیح __stdcall some_stdcall_func(صحیح foo, صحیح bar, صحیح baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	واپس 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#تعریف_کرو ATTR __attribute__((__noinline__))
صحیح ATTR actual_function() {
  واپس 42;
}

صحیح label_attribute (خالی)
{
lab1: __attribute__((__unused__));
  واپس 0;
}

خارجی صحیح لکھو (ثابت حرف *, ...);
ساکن صحیح globalvar;
صحیح مین()
{
    خالی *function_اشارہ_گر = &actual_function;
    صحیح localvar = 42, i;

    صحیح a = ((ATTR صحیح(*) (خالی)) function_اشارہ_گر)();
    لکھو("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    صحیح b = ( (صحیح(ATTR *)(خالی))  function_اشارہ_گر)();
    لکھو("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((صحیح __stdcall (*)(صحیح, صحیح, صحیح))some_stdcall_func) (2, 20, 200);
    ((صحیح(*__stdcall)(صحیح, صحیح, صحیح))some_stdcall_func) (3, 30, 300);
    برائے (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((صحیح(__stdcall*)(صحیح, صحیح, صحیح))some_stdcall_func) (4, 40, 400);
	اگر (localvar != 42 || globalvar != i)
	  لکھو("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    واپس 0;
}
