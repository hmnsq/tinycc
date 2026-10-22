ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short uint16_t;
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ uint8_t;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

ಬಾಹ್ಯ ಶೂನ್ಯ foo (ಶೂನ್ಯ) __attribute__((stdcall));
ಶೂನ್ಯ __attribute__((stdcall)) foo (ಶೂನ್ಯ)
{
}

#define __stdcall __attribute__((stdcall))
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ some_stdcall_func (ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ) __stdcall;
__stdcall ಪೂರ್ಣಾಙ್ಕ __stdcall some_stdcall_func(ಪೂರ್ಣಾಙ್ಕ foo, ಪೂರ್ಣಾಙ್ಕ bar, ಪೂರ್ಣಾಙ್ಕ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ಪ್ರತ್ಯಾಗಮ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ಪೂರ್ಣಾಙ್ಕ ATTR actual_function() {
  ಪ್ರತ್ಯಾಗಮ 42;
}

ಪೂರ್ಣಾಙ್ಕ label_attribute (ಶೂನ್ಯ)
{
lab1: __attribute__((__unused__));
  ಪ್ರತ್ಯಾಗಮ 0;
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ globalvar;
ಪೂರ್ಣಾಙ್ಕ main()
{
    ಶೂನ್ಯ *function_pointer = &actual_function;
    ಪೂರ್ಣಾಙ್ಕ localvar = 42, i;

    ಪೂರ್ಣಾಙ್ಕ a = ((ATTR ಪೂರ್ಣಾಙ್ಕ(*) (ಶೂನ್ಯ)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ಪೂರ್ಣಾಙ್ಕ b = ( (ಪೂರ್ಣಾಙ್ಕ(ATTR *)(ಶೂನ್ಯ))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ಪೂರ್ಣಾಙ್ಕ __stdcall (*)(ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ))some_stdcall_func) (2, 20, 200);
    ((ಪೂರ್ಣಾಙ್ಕ(*__stdcall)(ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ))some_stdcall_func) (3, 30, 300);
    ಪ್ರತಿ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ಪೂರ್ಣಾಙ್ಕ(__stdcall*)(ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ, ಪೂರ್ಣಾಙ್ಕ))some_stdcall_func) (4, 40, 400);
	ಯದಿ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}
