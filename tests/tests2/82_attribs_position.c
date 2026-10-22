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
extern ຈຳນວນເຕັມ some_stdcall_func (ຈຳນວນເຕັມ, ຈຳນວນເຕັມ, ຈຳນວນເຕັມ) __stdcall;
__stdcall ຈຳນວນເຕັມ __stdcall some_stdcall_func(ຈຳນວນເຕັມ foo, ຈຳນວນເຕັມ bar, ຈຳນວນເຕັມ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ສົ່ງຄືນ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
ຈຳນວນເຕັມ ATTR actual_function() {
  ສົ່ງຄືນ 42;
}

ຈຳນວນເຕັມ label_attribute (void)
{
lab1: __attribute__((__unused__));
  ສົ່ງຄືນ 0;
}

extern ຈຳນວນເຕັມ printf (const var_na *, ...);
static ຈຳນວນເຕັມ globalvar;
ຈຳນວນເຕັມ main()
{
    void *function_pointer = &actual_function;
    ຈຳນວນເຕັມ localvar = 42, i;

    ຈຳນວນເຕັມ a = ((ATTR ຈຳນວນເຕັມ(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    ຈຳນວນເຕັມ b = ( (ຈຳນວນເຕັມ(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((ຈຳນວນເຕັມ __stdcall (*)(ຈຳນວນເຕັມ, ຈຳນວນເຕັມ, ຈຳນວນເຕັມ))some_stdcall_func) (2, 20, 200);
    ((ຈຳນວນເຕັມ(*__stdcall)(ຈຳນວນເຕັມ, ຈຳນວນເຕັມ, ຈຳນວນເຕັມ))some_stdcall_func) (3, 30, 300);
    ສຳລັບ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((ຈຳນວນເຕັມ(__stdcall*)(ຈຳນວນເຕັມ, ຈຳນວນເຕັມ, ຈຳນວນເຕັມ))some_stdcall_func) (4, 40, 400);
	ຖ້າ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ສົ່ງຄືນ 0;
}
