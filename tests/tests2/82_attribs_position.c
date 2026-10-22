প্রকারনির্দেশ unsigned short uint16_t;
প্রকারনির্দেশ unsigned বর্ণ uint8_t;

প্রকারনির্দেশ সঙ্ঘ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

প্রকারনির্দেশ সঙ্ঘ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

বাহ্য শূন্য foo (শূন্য) __attribute__((stdcall));
শূন্য __attribute__((stdcall)) foo (শূন্য)
{
}

#define __stdcall __attribute__((stdcall))
বাহ্য পূর্ণাঙ্ক some_stdcall_func (পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক) __stdcall;
__stdcall পূর্ণাঙ্ক __stdcall some_stdcall_func(পূর্ণাঙ্ক foo, পূর্ণাঙ্ক bar, পূর্ণাঙ্ক baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	প্রত্যাগম 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
পূর্ণাঙ্ক ATTR actual_function() {
  প্রত্যাগম 42;
}

পূর্ণাঙ্ক label_attribute (শূন্য)
{
lab1: __attribute__((__unused__));
  প্রত্যাগম 0;
}

বাহ্য পূর্ণাঙ্ক printf (ধ্রুব বর্ণ *, ...);
স্থির পূর্ণাঙ্ক globalvar;
পূর্ণাঙ্ক main()
{
    শূন্য *function_pointer = &actual_function;
    পূর্ণাঙ্ক localvar = 42, i;

    পূর্ণাঙ্ক a = ((ATTR পূর্ণাঙ্ক(*) (শূন্য)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    পূর্ণাঙ্ক b = ( (পূর্ণাঙ্ক(ATTR *)(শূন্য))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((পূর্ণাঙ্ক __stdcall (*)(পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক))some_stdcall_func) (2, 20, 200);
    ((পূর্ণাঙ্ক(*__stdcall)(পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক))some_stdcall_func) (3, 30, 300);
    প্রতি (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((পূর্ণাঙ্ক(__stdcall*)(পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক))some_stdcall_func) (4, 40, 400);
	যদি (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    প্রত্যাগম 0;
}
