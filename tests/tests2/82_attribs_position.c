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
extern số_nguyên some_stdcall_func (số_nguyên, số_nguyên, số_nguyên) __stdcall;
__stdcall số_nguyên __stdcall some_stdcall_func(số_nguyên foo, số_nguyên bar, số_nguyên baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	trả_về 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
số_nguyên ATTR actual_function() {
  trả_về 42;
}

số_nguyên label_attribute (void)
{
lab1: __attribute__((__unused__));
  trả_về 0;
}

extern số_nguyên printf (const char *, ...);
static số_nguyên globalvar;
số_nguyên main()
{
    void *function_pointer = &actual_function;
    số_nguyên localvar = 42, i;

    số_nguyên a = ((ATTR số_nguyên(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    số_nguyên b = ( (số_nguyên(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((số_nguyên __stdcall (*)(số_nguyên, số_nguyên, số_nguyên))some_stdcall_func) (2, 20, 200);
    ((số_nguyên(*__stdcall)(số_nguyên, số_nguyên, số_nguyên))some_stdcall_func) (3, 30, 300);
    cho (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((số_nguyên(__stdcall*)(số_nguyên, số_nguyên, số_nguyên))some_stdcall_func) (4, 40, 400);
	nếu (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    trả_về 0;
}
