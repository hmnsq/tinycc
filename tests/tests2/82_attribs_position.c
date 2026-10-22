প্রকারলেখ unsigned short uint16_t;
প্রকারলেখ unsigned অক্ষর uint8_t;

প্রকারলেখ সংঘ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

প্রকারলেখ সংঘ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

বাহ্যিক শূন্য foo (শূন্য) __attribute__((stdcall));
শূন্য __attribute__((stdcall)) foo (শূন্য)
{
}

#define __stdcall __attribute__((stdcall))
বাহ্যিক পূর্ণসংখ্যা some_stdcall_func (পূর্ণসংখ্যা, পূর্ণসংখ্যা, পূর্ণসংখ্যা) __stdcall;
__stdcall পূর্ণসংখ্যা __stdcall some_stdcall_func(পূর্ণসংখ্যা foo, পূর্ণসংখ্যা bar, পূর্ণসংখ্যা baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ফেরত 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
পূর্ণসংখ্যা ATTR actual_function() {
  ফেরত 42;
}

পূর্ণসংখ্যা label_attribute (শূন্য)
{
lab1: __attribute__((__unused__));
  ফেরত 0;
}

বাহ্যিক পূর্ণসংখ্যা printf (ধ্রুবক অক্ষর *, ...);
স্থির পূর্ণসংখ্যা globalvar;
পূর্ণসংখ্যা প্রধান()
{
    শূন্য *function_pointer = &actual_function;
    পূর্ণসংখ্যা localvar = 42, i;

    পূর্ণসংখ্যা a = ((ATTR পূর্ণসংখ্যা(*) (শূন্য)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    পূর্ণসংখ্যা b = ( (পূর্ণসংখ্যা(ATTR *)(শূন্য))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((পূর্ণসংখ্যা __stdcall (*)(পূর্ণসংখ্যা, পূর্ণসংখ্যা, পূর্ণসংখ্যা))some_stdcall_func) (2, 20, 200);
    ((পূর্ণসংখ্যা(*__stdcall)(পূর্ণসংখ্যা, পূর্ণসংখ্যা, পূর্ণসংখ্যা))some_stdcall_func) (3, 30, 300);
    জন্য (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((পূর্ণসংখ্যা(__stdcall*)(পূর্ণসংখ্যা, পূর্ণসংখ্যা, পূর্ণসংখ্যা))some_stdcall_func) (4, 40, 400);
	যদি (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ফেরত 0;
}
