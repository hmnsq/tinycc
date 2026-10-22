प्रकार अचिन्हित लघु uint16_t;
प्रकार अचिन्हित अक्षर uint8_t;

प्रकार जोड़ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

प्रकार जोड़ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

बाह्य व्योम foo (व्योम) __attribute__((stdcall));
व्योम __attribute__((stdcall)) foo (व्योम)
{
}

#घोषणा __stdcall __attribute__((stdcall))
बाह्य पूर्णांक some_stdcall_func (पूर्णांक, पूर्णांक, पूर्णांक) __stdcall;
__stdcall पूर्णांक __stdcall some_stdcall_func(पूर्णांक foo, पूर्णांक bar, पूर्णांक baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	वापस 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#घोषणा ATTR __attribute__((__noinline__))
पूर्णांक ATTR actual_function() {
  वापस 42;
}

पूर्णांक label_attribute (व्योम)
{
lab1: __attribute__((__unused__));
  वापस 0;
}

बाह्य पूर्णांक म_लिखो (स्थिर अक्षर *, ...);
अटल पूर्णांक globalvar;
पूर्णांक मुख्य()
{
    व्योम *function_pointer = &actual_function;
    पूर्णांक localvar = 42, i;

    पूर्णांक a = ((ATTR पूर्णांक(*) (व्योम)) function_pointer)();
    म_लिखो("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    पूर्णांक b = ( (पूर्णांक(ATTR *)(व्योम))  function_pointer)();
    म_लिखो("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((पूर्णांक __stdcall (*)(पूर्णांक, पूर्णांक, पूर्णांक))some_stdcall_func) (2, 20, 200);
    ((पूर्णांक(*__stdcall)(पूर्णांक, पूर्णांक, पूर्णांक))some_stdcall_func) (3, 30, 300);
    क्रम (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((पूर्णांक(__stdcall*)(पूर्णांक, पूर्णांक, पूर्णांक))some_stdcall_func) (4, 40, 400);
	अगर (localvar != 42 || globalvar != i)
	  म_लिखो("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    वापस 0;
}
