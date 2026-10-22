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
extern จำนวนเต็ม some_stdcall_func (จำนวนเต็ม, จำนวนเต็ม, จำนวนเต็ม) __stdcall;
__stdcall จำนวนเต็ม __stdcall some_stdcall_func(จำนวนเต็ม foo, จำนวนเต็ม bar, จำนวนเต็ม baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	คืน 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
จำนวนเต็ม ATTR actual_function() {
  คืน 42;
}

จำนวนเต็ม label_attribute (void)
{
lab1: __attribute__((__unused__));
  คืน 0;
}

extern จำนวนเต็ม printf (const var_na *, ...);
static จำนวนเต็ม globalvar;
จำนวนเต็ม หลัก()
{
    void *function_pointer = &actual_function;
    จำนวนเต็ม localvar = 42, i;

    จำนวนเต็ม a = ((ATTR จำนวนเต็ม(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    จำนวนเต็ม b = ( (จำนวนเต็ม(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((จำนวนเต็ม __stdcall (*)(จำนวนเต็ม, จำนวนเต็ม, จำนวนเต็ม))some_stdcall_func) (2, 20, 200);
    ((จำนวนเต็ม(*__stdcall)(จำนวนเต็ม, จำนวนเต็ม, จำนวนเต็ม))some_stdcall_func) (3, 30, 300);
    สำหรับ (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((จำนวนเต็ม(__stdcall*)(จำนวนเต็ม, จำนวนเต็ม, จำนวนเต็ม))some_stdcall_func) (4, 40, 400);
	ถ้า (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    คืน 0;
}
