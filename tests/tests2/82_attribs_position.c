typedef unsigned short uint16_t;
typedef unsigned var_na uint8_t;

typedef sa_ngha Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

typedef sa_ngha __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

extern void foo (void) __attribute__((stdcall));
void __attribute__((stdcall)) foo (void)
{
}

#define __stdcall __attribute__((stdcall))
extern ចំនួនគត់ some_stdcall_func (ចំនួនគត់, ចំនួនគត់, ចំនួនគត់) __stdcall;
__stdcall ចំនួនគត់ __stdcall some_stdcall_func(ចំនួនគត់ foo, ចំនួនគត់ bar, ចំនួនគត់ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ត្រឡប់ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ចំនួនគត់ ATTR actual_function() {
  ត្រឡប់ 42;
}

ចំនួនគត់ label_attribute (void)
{
lab1: __attribute__((__unused__));
  ត្រឡប់ 0;
}

extern ចំនួនគត់ printf (const var_na *, ...);
static ចំនួនគត់ globalvar;
ចំនួនគត់ main()
{
    void *function_pointer = &actual_function;
    ចំនួនគត់ localvar = 42, i;

    ចំនួនគត់ a = ((ATTR ចំនួនគត់(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ចំនួនគត់ b = ( (ចំនួនគត់(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ចំនួនគត់ __stdcall (*)(ចំនួនគត់, ចំនួនគត់, ចំនួនគត់))some_stdcall_func) (2, 20, 200);
    ((ចំនួនគត់(*__stdcall)(ចំនួនគត់, ចំនួនគត់, ចំនួនគត់))some_stdcall_func) (3, 30, 300);
    សម្រាប់ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ចំនួនគត់(__stdcall*)(ចំនួនគត់, ចំនួនគត់, ចំនួនគត់))some_stdcall_func) (4, 40, 400);
	ប្រសិនបើ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ត្រឡប់ 0;
}
