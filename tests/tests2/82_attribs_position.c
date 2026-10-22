வகைவரை unsigned short uint16_t;
வகைவரை unsigned எழுத்து uint8_t;

வகைவரை ஒன்றிப்பு Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

வகைவரை ஒன்றிப்பு __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

வெளி வெறுமை foo (வெறுமை) __attribute__((stdcall));
வெறுமை __attribute__((stdcall)) foo (வெறுமை)
{
}

#define __stdcall __attribute__((stdcall))
வெளி முழு some_stdcall_func (முழு, முழு, முழு) __stdcall;
__stdcall முழு __stdcall some_stdcall_func(முழு foo, முழு bar, முழு baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	திரும்பு 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
முழு ATTR actual_function() {
  திரும்பு 42;
}

முழு label_attribute (வெறுமை)
{
lab1: __attribute__((__unused__));
  திரும்பு 0;
}

வெளி முழு printf (மாறிலி எழுத்து *, ...);
நிலையான முழு globalvar;
முழு முதன்மை()
{
    வெறுமை *function_pointer = &actual_function;
    முழு localvar = 42, i;

    முழு a = ((ATTR முழு(*) (வெறுமை)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    முழு b = ( (முழு(ATTR *)(வெறுமை))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((முழு __stdcall (*)(முழு, முழு, முழு))some_stdcall_func) (2, 20, 200);
    ((முழு(*__stdcall)(முழு, முழு, முழு))some_stdcall_func) (3, 30, 300);
    க்கு (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((முழு(__stdcall*)(முழு, முழு, முழு))some_stdcall_func) (4, 40, 400);
	எனில் (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    திரும்பு 0;
}
