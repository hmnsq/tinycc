ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ uint16_t;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ uint8_t;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

ಬಾಹ್ಯ ಶೂನ್ಯ foo (ಶೂನ್ಯ) __attribute__((stdcall));
ಶೂನ್ಯ __attribute__((stdcall)) foo (ಶೂನ್ಯ)
{
}

#ವ್ಯಾಖ್ಯಾನಿಸು __stdcall __attribute__((stdcall))
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ some_stdcall_func (ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ) __stdcall;
__stdcall ಪೂರ್ಣಾಂಕ __stdcall some_stdcall_func(ಪೂರ್ಣಾಂಕ foo, ಪೂರ್ಣಾಂಕ bar, ಪೂರ್ಣಾಂಕ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ಹಿಂತಿರುಗಿ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#ವ್ಯಾಖ್ಯಾನಿಸು ATTR __attribute__((__noinline__))
ಪೂರ್ಣಾಂಕ ATTR actual_function() {
  ಹಿಂತಿರುಗಿ 42;
}

ಪೂರ್ಣಾಂಕ label_attribute (ಶೂನ್ಯ)
{
lab1: __attribute__((__unused__));
  ಹಿಂತಿರುಗಿ 0;
}

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ globalvar;
ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
    ಶೂನ್ಯ *function_ಸೂಚಕ = &actual_function;
    ಪೂರ್ಣಾಂಕ localvar = 42, i;

    ಪೂರ್ಣಾಂಕ a = ((ATTR ಪೂರ್ಣಾಂಕ(*) (ಶೂನ್ಯ)) function_ಸೂಚಕ)();
    ಬರೆ("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ಪೂರ್ಣಾಂಕ b = ( (ಪೂರ್ಣಾಂಕ(ATTR *)(ಶೂನ್ಯ))  function_ಸೂಚಕ)();
    ಬರೆ("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ಪೂರ್ಣಾಂಕ __stdcall (*)(ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ))some_stdcall_func) (2, 20, 200);
    ((ಪೂರ್ಣಾಂಕ(*__stdcall)(ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ))some_stdcall_func) (3, 30, 300);
    ಗಾಗಿ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ಪೂರ್ಣಾಂಕ(__stdcall*)(ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ, ಪೂರ್ಣಾಂಕ))some_stdcall_func) (4, 40, 400);
	ಆದರೆ (localvar != 42 || globalvar != i)
	  ಬರೆ("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ಹಿಂತಿರುಗಿ 0;
}
