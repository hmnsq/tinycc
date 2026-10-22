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
extern ကိန်းပြည့် some_stdcall_func (ကိန်းပြည့်, ကိန်းပြည့်, ကိန်းပြည့်) __stdcall;
__stdcall ကိန်းပြည့် __stdcall some_stdcall_func(ကိန်းပြည့် foo, ကိန်းပြည့် bar, ကိန်းပြည့် baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ပြန်ပေး 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ကိန်းပြည့် ATTR actual_function() {
  ပြန်ပေး 42;
}

ကိန်းပြည့် label_attribute (void)
{
lab1: __attribute__((__unused__));
  ပြန်ပေး 0;
}

extern ကိန်းပြည့် printf (const var_na *, ...);
static ကိန်းပြည့် globalvar;
ကိန်းပြည့် main()
{
    void *function_pointer = &actual_function;
    ကိန်းပြည့် localvar = 42, i;

    ကိန်းပြည့် a = ((ATTR ကိန်းပြည့်(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ကိန်းပြည့် b = ( (ကိန်းပြည့်(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ကိန်းပြည့် __stdcall (*)(ကိန်းပြည့်, ကိန်းပြည့်, ကိန်းပြည့်))some_stdcall_func) (2, 20, 200);
    ((ကိန်းပြည့်(*__stdcall)(ကိန်းပြည့်, ကိန်းပြည့်, ကိန်းပြည့်))some_stdcall_func) (3, 30, 300);
    အတွက် (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ကိန်းပြည့်(__stdcall*)(ကိန်းပြည့်, ကိန်းပြည့်, ကိန်းပြည့်))some_stdcall_func) (4, 40, 400);
	အကယ်၍ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ပြန်ပေး 0;
}
