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
extern ཧྲིལ some_stdcall_func (ཧྲིལ, ཧྲིལ, ཧྲིལ) __stdcall;
__stdcall ཧྲིལ __stdcall some_stdcall_func(ཧྲིལ foo, ཧྲིལ bar, ཧྲིལ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ཕྱིར 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ཧྲིལ ATTR actual_function() {
  ཕྱིར 42;
}

ཧྲིལ label_attribute (void)
{
lab1: __attribute__((__unused__));
  ཕྱིར 0;
}

extern ཧྲིལ printf (const var_na *, ...);
static ཧྲིལ globalvar;
ཧྲིལ གཙོ()
{
    void *function_pointer = &actual_function;
    ཧྲིལ localvar = 42, i;

    ཧྲིལ a = ((ATTR ཧྲིལ(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ཧྲིལ b = ( (ཧྲིལ(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ཧྲིལ __stdcall (*)(ཧྲིལ, ཧྲིལ, ཧྲིལ))some_stdcall_func) (2, 20, 200);
    ((ཧྲིལ(*__stdcall)(ཧྲིལ, ཧྲིལ, ཧྲིལ))some_stdcall_func) (3, 30, 300);
    ཆེད་དུ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ཧྲིལ(__stdcall*)(ཧྲིལ, ཧྲིལ, ཧྲིལ))some_stdcall_func) (4, 40, 400);
	གལ་ཏེ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ཕྱིར 0;
}
