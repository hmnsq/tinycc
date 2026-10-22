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
extern පූර්ණ_සංඛ්‍යා some_stdcall_func (පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා) __stdcall;
__stdcall පූර්ණ_සංඛ්‍යා __stdcall some_stdcall_func(පූර්ණ_සංඛ්‍යා foo, පූර්ණ_සංඛ්‍යා bar, පූර්ණ_සංඛ්‍යා baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ආපසු 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
පූර්ණ_සංඛ්‍යා ATTR actual_function() {
  ආපසු 42;
}

පූර්ණ_සංඛ්‍යා label_attribute (void)
{
lab1: __attribute__((__unused__));
  ආපසු 0;
}

extern පූර්ණ_සංඛ්‍යා printf (const var_na *, ...);
static පූර්ණ_සංඛ්‍යා globalvar;
පූර්ණ_සංඛ්‍යා main()
{
    void *function_pointer = &actual_function;
    පූර්ණ_සංඛ්‍යා localvar = 42, i;

    පූර්ණ_සංඛ්‍යා a = ((ATTR පූර්ණ_සංඛ්‍යා(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    පූර්ණ_සංඛ්‍යා b = ( (පූර්ණ_සංඛ්‍යා(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((පූර්ණ_සංඛ්‍යා __stdcall (*)(පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා))some_stdcall_func) (2, 20, 200);
    ((පූර්ණ_සංඛ්‍යා(*__stdcall)(පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා))some_stdcall_func) (3, 30, 300);
    සඳහා (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((පූර්ණ_සංඛ්‍යා(__stdcall*)(පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා, පූර්ණ_සංඛ්‍යා))some_stdcall_func) (4, 40, 400);
	නම් (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ආපසු 0;
}
