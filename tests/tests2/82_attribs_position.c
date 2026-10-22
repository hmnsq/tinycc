തരനിർവചനം unsigned short uint16_t;
തരനിർവചനം unsigned അക്ഷരം uint8_t;

തരനിർവചനം സംഘം Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

തരനിർവചനം സംഘം __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

ബാഹ്യ ശൂന്യം foo (ശൂന്യം) __attribute__((stdcall));
ശൂന്യം __attribute__((stdcall)) foo (ശൂന്യം)
{
}

#define __stdcall __attribute__((stdcall))
ബാഹ്യ പൂർണ്ണസംഖ്യ some_stdcall_func (പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ) __stdcall;
__stdcall പൂർണ്ണസംഖ്യ __stdcall some_stdcall_func(പൂർണ്ണസംഖ്യ foo, പൂർണ്ണസംഖ്യ bar, പൂർണ്ണസംഖ്യ baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	തിരികെ 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#define ATTR __attribute__((__noinline__))
പൂർണ്ണസംഖ്യ ATTR actual_function() {
  തിരികെ 42;
}

പൂർണ്ണസംഖ്യ label_attribute (ശൂന്യം)
{
lab1: __attribute__((__unused__));
  തിരികെ 0;
}

ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
സ്ഥിതം പൂർണ്ണസംഖ്യ globalvar;
പൂർണ്ണസംഖ്യ പ്രധാന()
{
    ശൂന്യം *function_pointer = &actual_function;
    പൂർണ്ണസംഖ്യ localvar = 42, i;

    പൂർണ്ണസംഖ്യ a = ((ATTR പൂർണ്ണസംഖ്യ(*) (ശൂന്യം)) function_pointer)();
    printf("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    പൂർണ്ണസംഖ്യ b = ( (പൂർണ്ണസംഖ്യ(ATTR *)(ശൂന്യം))  function_pointer)();
    printf("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((പൂർണ്ണസംഖ്യ __stdcall (*)(പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ))some_stdcall_func) (2, 20, 200);
    ((പൂർണ്ണസംഖ്യ(*__stdcall)(പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ))some_stdcall_func) (3, 30, 300);
    വേണ്ടി (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((പൂർണ്ണസംഖ്യ(__stdcall*)(പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ))some_stdcall_func) (4, 40, 400);
	എങ്കിൽ (localvar != 42 || globalvar != i)
	  printf("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    തിരികെ 0;
}
