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
extern puur_naa_nka some_stdcall_func (puur_naa_nka, puur_naa_nka, puur_naa_nka) __stdcall;
__stdcall puur_naa_nka __stdcall some_stdcall_func(puur_naa_nka foo, puur_naa_nka bar, puur_naa_nka baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	ᤀᤡᤴ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
puur_naa_nka ATTR actual_function() {
  ᤀᤡᤴ 42;
}

puur_naa_nka label_attribute (void)
{
lab1: __attribute__((__unused__));
  ᤀᤡᤴ 0;
}

extern puur_naa_nka printf (const var_na *, ...);
static puur_naa_nka globalvar;
puur_naa_nka main()
{
    void *function_pointer = &actual_function;
    puur_naa_nka localvar = 42, i;

    puur_naa_nka a = ((ATTR puur_naa_nka(*) (void)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    puur_naa_nka b = ( (puur_naa_nka(ATTR *)(void))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((puur_naa_nka __stdcall (*)(puur_naa_nka, puur_naa_nka, puur_naa_nka))some_stdcall_func) (2, 20, 200);
    ((puur_naa_nka(*__stdcall)(puur_naa_nka, puur_naa_nka, puur_naa_nka))some_stdcall_func) (3, 30, 300);
    for (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((puur_naa_nka(__stdcall*)(puur_naa_nka, puur_naa_nka, puur_naa_nka))some_stdcall_func) (4, 40, 400);
	ᤀᤡ᤺ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    ᤀᤡᤴ 0;
}
