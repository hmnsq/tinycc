typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

typedef union Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

typedef union __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

extern void foo (void) __attribute__((stdcall));
void __attribute__((stdcall)) foo (void)
{
}

#define __stdcall __attribute__((stdcall))
extern целое some_stdcall_func (целое, целое, целое) __stdcall;
__stdcall целое __stdcall some_stdcall_func(целое foo, целое bar, целое baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	вернуть 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
целое ATTR actual_function() {
  вернуть 42;
}

целое label_attribute (void)
{
lab1: __attribute__((__unused__));
  вернуть 0;
}

extern целое printf (const char *, ...);
static целое globalvar;
целое основной()
{
    void *function_pointer = &actual_function;
    целое localvar = 42, i;

    целое a = ((ATTR целое(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    целое b = ( (целое(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((целое __stdcall (*)(целое, целое, целое))some_stdcall_func) (2, 20, 200);
    ((целое(*__stdcall)(целое, целое, целое))some_stdcall_func) (3, 30, 300);
    для (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((целое(__stdcall*)(целое, целое, целое))some_stdcall_func) (4, 40, 400);
	если (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    вернуть 0;
}
