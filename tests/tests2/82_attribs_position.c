પ્રકારવ્યાખ્યા unsigned short uint16_t;
પ્રકારવ્યાખ્યા unsigned અક્ષર uint8_t;

પ્રકારવ્યાખ્યા સંઘ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

પ્રકારવ્યાખ્યા સંઘ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

બાહ્ય શૂન્ય foo (શૂન્ય) __attribute__((stdcall));
શૂન્ય __attribute__((stdcall)) foo (શૂન્ય)
{
}

#define __stdcall __attribute__((stdcall))
બાહ્ય પૂર્ણાંક some_stdcall_func (પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક) __stdcall;
__stdcall પૂર્ણાંક __stdcall some_stdcall_func(પૂર્ણાંક foo, પૂર્ણાંક bar, પૂર્ણાંક baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	પાછા 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
પૂર્ણાંક ATTR actual_function() {
  પાછા 42;
}

પૂર્ણાંક label_attribute (શૂન્ય)
{
lab1: __attribute__((__unused__));
  પાછા 0;
}

બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
સ્થિર પૂર્ણાંક globalvar;
પૂર્ણાંક મુખ્ય()
{
    શૂન્ય *function_pointer = &actual_function;
    પૂર્ણાંક localvar = 42, i;

    પૂર્ણાંક a = ((ATTR પૂર્ણાંક(*) (શૂન્ય)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    પૂર્ણાંક b = ( (પૂર્ણાંક(ATTR *)(શૂન્ય))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((પૂર્ણાંક __stdcall (*)(પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક))some_stdcall_func) (2, 20, 200);
    ((પૂર્ણાંક(*__stdcall)(પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક))some_stdcall_func) (3, 30, 300);
    માટે (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((પૂર્ણાંક(__stdcall*)(પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક))some_stdcall_func) (4, 40, 400);
	જો (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    પાછા 0;
}
