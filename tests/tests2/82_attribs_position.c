ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short uint16_t;
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ଅକ୍ଷର uint8_t;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

ବାହ୍ୟ ଶୂନ୍ୟ foo (ଶୂନ୍ୟ) __attribute__((stdcall));
ଶୂନ୍ୟ __attribute__((stdcall)) foo (ଶୂନ୍ୟ)
{
}

#define __stdcall __attribute__((stdcall))
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା some_stdcall_func (ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା) __stdcall;
__stdcall ପୂର୍ଣ୍ଣସଂଖ୍ୟା __stdcall some_stdcall_func(ପୂର୍ଣ୍ଣସଂଖ୍ୟା foo, ପୂର୍ଣ୍ଣସଂଖ୍ୟା bar, ପୂର୍ଣ୍ଣସଂଖ୍ୟା baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ଫେରନ୍ତୁ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ATTR actual_function() {
  ଫେରନ୍ତୁ 42;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା label_attribute (ଶୂନ୍ୟ)
{
lab1: __attribute__((__unused__));
  ଫେରନ୍ତୁ 0;
}

ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା globalvar;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ଶୂନ୍ୟ *function_pointer = &actual_function;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା localvar = 42, i;

    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = ((ATTR ପୂର୍ଣ୍ଣସଂଖ୍ୟା(*) (ଶୂନ୍ୟ)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା b = ( (ପୂର୍ଣ୍ଣସଂଖ୍ୟା(ATTR *)(ଶୂନ୍ୟ))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା __stdcall (*)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା))some_stdcall_func) (2, 20, 200);
    ((ପୂର୍ଣ୍ଣସଂଖ୍ୟା(*__stdcall)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା))some_stdcall_func) (3, 30, 300);
    ପାଇଁ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ପୂର୍ଣ୍ଣସଂଖ୍ୟା(__stdcall*)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା, ପୂର୍ଣ୍ଣସଂଖ୍ୟା))some_stdcall_func) (4, 40, 400);
	ଯଦି (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ଫେରନ୍ତୁ 0;
}
