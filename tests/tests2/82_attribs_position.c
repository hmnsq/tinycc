تعريفنوع unsigned short uint16_t;
تعريفنوع unsigned حرف uint8_t;

تعريفنوع اتحاد Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

تعريفنوع اتحاد __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

خارجي فراغ foo (فراغ) __attribute__((stdcall));
فراغ __attribute__((stdcall)) foo (فراغ)
{
}

#define __stdcall __attribute__((stdcall))
خارجي صحيح some_stdcall_func (صحيح, صحيح, صحيح) __stdcall;
__stdcall صحيح __stdcall some_stdcall_func(صحيح foo, صحيح bar, صحيح baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	أرجع 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
صحيح ATTR actual_function() {
  أرجع 42;
}

صحيح label_attribute (فراغ)
{
lab1: __attribute__((__unused__));
  أرجع 0;
}

خارجي صحيح printf (ثابت حرف *, ...);
ساكن صحيح globalvar;
صحيح main()
{
    فراغ *function_pointer = &actual_function;
    صحيح localvar = 42, i;

    صحيح a = ((ATTR صحيح(*) (فراغ)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    صحيح b = ( (صحيح(ATTR *)(فراغ))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((صحيح __stdcall (*)(صحيح, صحيح, صحيح))some_stdcall_func) (2, 20, 200);
    ((صحيح(*__stdcall)(صحيح, صحيح, صحيح))some_stdcall_func) (3, 30, 300);
    لكل (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((صحيح(__stdcall*)(صحيح, صحيح, صحيح))some_stdcall_func) (4, 40, 400);
	𐤀𐤌 (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    أرجع 0;
}
