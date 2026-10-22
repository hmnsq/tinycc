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
extern цяло some_stdcall_func (цяло, цяло, цяло) __stdcall;
__stdcall цяло __stdcall some_stdcall_func(цяло foo, цяло bar, цяло baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	върни 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
цяло ATTR actual_function() {
  върни 42;
}

цяло label_attribute (void)
{
lab1: __attribute__((__unused__));
  върни 0;
}

extern цяло printf (const char *, ...);
static цяло globalvar;
цяло main()
{
    void *function_pointer = &actual_function;
    цяло localvar = 42, i;

    цяло a = ((ATTR цяло(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    цяло b = ( (цяло(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((цяло __stdcall (*)(цяло, цяло, цяло))some_stdcall_func) (2, 20, 200);
    ((цяло(*__stdcall)(цяло, цяло, цяло))some_stdcall_func) (3, 30, 300);
    за (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((цяло(__stdcall*)(цяло, цяло, цяло))some_stdcall_func) (4, 40, 400);
	ако (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    върни 0;
}
