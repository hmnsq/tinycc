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
extern ціле some_stdcall_func (ціле, ціле, ціле) __stdcall;
__stdcall ціле __stdcall some_stdcall_func(ціле foo, ціле bar, ціле baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	повернути 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ціле ATTR actual_function() {
  повернути 42;
}

ціле label_attribute (void)
{
lab1: __attribute__((__unused__));
  повернути 0;
}

extern ціле printf (const char *, ...);
static ціле globalvar;
ціле main()
{
    void *function_pointer = &actual_function;
    ціле localvar = 42, i;

    ціле a = ((ATTR ціле(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ціле b = ( (ціле(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ціле __stdcall (*)(ціле, ціле, ціле))some_stdcall_func) (2, 20, 200);
    ((ціле(*__stdcall)(ціле, ціле, ціле))some_stdcall_func) (3, 30, 300);
    для (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ціле(__stdcall*)(ціле, ціле, ціле))some_stdcall_func) (4, 40, 400);
	якщо (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    повернути 0;
}
