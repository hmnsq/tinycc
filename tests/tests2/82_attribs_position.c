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
extern 整数 some_stdcall_func (整数, 整数, 整数) __stdcall;
__stdcall 整数 __stdcall some_stdcall_func(整数 foo, 整数 bar, 整数 baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	戻る 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
整数 ATTR actual_function() {
  戻る 42;
}

整数 label_attribute (void)
{
lab1: __attribute__((__unused__));
  戻る 0;
}

extern 整数 printf (const char *, ...);
static 整数 globalvar;
整数 メインページ()
{
    void *function_pointer = &actual_function;
    整数 localvar = 42, i;

    整数 a = ((ATTR 整数(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    整数 b = ( (整数(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((整数 __stdcall (*)(整数, 整数, 整数))some_stdcall_func) (2, 20, 200);
    ((整数(*__stdcall)(整数, 整数, 整数))some_stdcall_func) (3, 30, 300);
    ために (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((整数(__stdcall*)(整数, 整数, 整数))some_stdcall_func) (4, 40, 400);
	もし (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    戻る 0;
}
