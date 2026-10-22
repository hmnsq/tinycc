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
extern 정수 some_stdcall_func (정수, 정수, 정수) __stdcall;
__stdcall 정수 __stdcall some_stdcall_func(정수 foo, 정수 bar, 정수 baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	반환 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
정수 ATTR actual_function() {
  반환 42;
}

정수 label_attribute (void)
{
lab1: __attribute__((__unused__));
  반환 0;
}

extern 정수 printf (const char *, ...);
static 정수 globalvar;
정수 main()
{
    void *function_pointer = &actual_function;
    정수 localvar = 42, i;

    정수 a = ((ATTR 정수(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    정수 b = ( (정수(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((정수 __stdcall (*)(정수, 정수, 정수))some_stdcall_func) (2, 20, 200);
    ((정수(*__stdcall)(정수, 정수, 정수))some_stdcall_func) (3, 30, 300);
    위해 (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((정수(__stdcall*)(정수, 정수, 정수))some_stdcall_func) (4, 40, 400);
	만약 (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    반환 0;
}
