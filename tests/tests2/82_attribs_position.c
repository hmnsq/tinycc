ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ uint16_t;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ uint8_t;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

ਬਾਹਰੀ ਖਾਲੀ foo (ਖਾਲੀ) __attribute__((stdcall));
ਖਾਲੀ __attribute__((stdcall)) foo (ਖਾਲੀ)
{
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __stdcall __attribute__((stdcall))
ਬਾਹਰੀ ਪੂਰਨ some_stdcall_func (ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ) __stdcall;
__stdcall ਪੂਰਨ __stdcall some_stdcall_func(ਪੂਰਨ foo, ਪੂਰਨ bar, ਪੂਰਨ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ਵਾਪਸ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATTR __attribute__((__noinline__))
ਪੂਰਨ ATTR actual_function() {
  ਵਾਪਸ 42;
}

ਪੂਰਨ label_attribute (ਖਾਲੀ)
{
lab1: __attribute__((__unused__));
  ਵਾਪਸ 0;
}

ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ (ਅਚਲ ਅੱਖਰ *, ...);
ਸਥਿਰ ਪੂਰਨ globalvar;
ਪੂਰਨ ਮੁੱਖ()
{
    ਖਾਲੀ *function_ਸੂਚਕ = &actual_function;
    ਪੂਰਨ localvar = 42, i;

    ਪੂਰਨ a = ((ATTR ਪੂਰਨ(*) (ਖਾਲੀ)) function_ਸੂਚਕ)();
    ਲਿਖੋ("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ਪੂਰਨ b = ( (ਪੂਰਨ(ATTR *)(ਖਾਲੀ))  function_ਸੂਚਕ)();
    ਲਿਖੋ("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ਪੂਰਨ __stdcall (*)(ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ))some_stdcall_func) (2, 20, 200);
    ((ਪੂਰਨ(*__stdcall)(ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ))some_stdcall_func) (3, 30, 300);
    ਲਈ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ਪੂਰਨ(__stdcall*)(ਪੂਰਨ, ਪੂਰਨ, ਪੂਰਨ))some_stdcall_func) (4, 40, 400);
	ਜੇ (localvar != 42 || globalvar != i)
	  ਲਿਖੋ("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ਵਾਪਸ 0;
}
