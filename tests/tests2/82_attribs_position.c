प्रकारनिर्देश अचिन्हित लघु uint16_t;
प्रकारनिर्देश अचिन्हित वर्ण uint8_t;

प्रकारनिर्देश सङ्घ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

प्रकारनिर्देश सङ्घ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

बाह्य शून्य foo (शून्य) __attribute__((stdcall));
शून्य __attribute__((stdcall)) foo (शून्य)
{
}

#define __stdcall __attribute__((stdcall))
बाह्य पूर्णाङ्क some_stdcall_func (पूर्णाङ्क, पूर्णाङ्क, पूर्णाङ्क) __stdcall;
__stdcall पूर्णाङ्क __stdcall some_stdcall_func(पूर्णाङ्क foo, पूर्णाङ्क bar, पूर्णाङ्क baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	प्रत्यागम 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
पूर्णाङ्क ATTR actual_function() {
  प्रत्यागम 42;
}

पूर्णाङ्क label_attribute (शून्य)
{
lab1: __attribute__((__unused__));
  प्रत्यागम 0;
}

बाह्य पूर्णाङ्क म_लिखो (ध्रुव वर्ण *, ...);
स्थिर पूर्णाङ्क globalvar;
पूर्णाङ्क main()
{
    शून्य *function_pointer = &actual_function;
    पूर्णाङ्क localvar = 42, i;

    पूर्णाङ्क a = ((ATTR पूर्णाङ्क(*) (शून्य)) function_pointer)();
    म_लिखो("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    पूर्णाङ्क b = ( (पूर्णाङ्क(ATTR *)(शून्य))  function_pointer)();
    म_लिखो("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((पूर्णाङ्क __stdcall (*)(पूर्णाङ्क, पूर्णाङ्क, पूर्णाङ्क))some_stdcall_func) (2, 20, 200);
    ((पूर्णाङ्क(*__stdcall)(पूर्णाङ्क, पूर्णाङ्क, पूर्णाङ्क))some_stdcall_func) (3, 30, 300);
    प्रति (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((पूर्णाङ्क(__stdcall*)(पूर्णाङ्क, पूर्णाङ्क, पूर्णाङ्क))some_stdcall_func) (4, 40, 400);
	यदि (localvar != 42 || globalvar != i)
	  म_लिखो("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    प्रत्यागम 0;
}
