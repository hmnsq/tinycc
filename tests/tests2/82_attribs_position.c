రకనిర్వచనం గుర్తులేని పొట్టి uint16_t;
రకనిర్వచనం గుర్తులేని అక్షరం uint8_t;

రకనిర్వచనం సంఘం Unaligned16a {
  uint16_t u;
  uint8_t b[2];
} __attribute__((packed)) Unaligned16a;

రకనిర్వచనం సంఘం __attribute__((packed)) Unaligned16b {
  uint16_t u;
  uint8_t b[2];
} Unaligned16b;

బాహ్య శూన్య foo (శూన్య) __attribute__((stdcall));
శూన్య __attribute__((stdcall)) foo (శూన్య)
{
}

#నిర్వచించు __stdcall __attribute__((stdcall))
బాహ్య పూర్ణాంకం some_stdcall_func (పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం) __stdcall;
__stdcall పూర్ణాంకం __stdcall some_stdcall_func(పూర్ణాంకం foo, పూర్ణాంకం bar, పూర్ణాంకం baz) {
	//printf("Hello from stdcall: %i %i %i\n", foo, bar, baz);
	తిరిగి 43;
}

/* The actual attribute isn't important, must just be
   parsable.  */
#నిర్వచించు ATTR __attribute__((__noinline__))
పూర్ణాంకం ATTR actual_function() {
  తిరిగి 42;
}

పూర్ణాంకం label_attribute (శూన్య)
{
lab1: __attribute__((__unused__));
  తిరిగి 0;
}

బాహ్య పూర్ణాంకం రాయి (స్థిరరాశి అక్షరం *, ...);
స్థిర పూర్ణాంకం globalvar;
పూర్ణాంకం ప్రధాన()
{
    శూన్య *function_సూచిక = &actual_function;
    పూర్ణాంకం localvar = 42, i;

    పూర్ణాంకం a = ((ATTR పూర్ణాంకం(*) (శూన్య)) function_సూచిక)();
    రాయి("%i\n", a);

    /* In the following we once misparsed 'ATTR *' is a btype
       and hence the whole type was garbled.  */
    పూర్ణాంకం b = ( (పూర్ణాంకం(ATTR *)(శూన్య))  function_సూచిక)();
    రాయి("%i\n", b);

    /* All these should work and leave the stack pointer in its original
       position.  */
    some_stdcall_func(1, 10, 100);
    ((పూర్ణాంకం __stdcall (*)(పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం))some_stdcall_func) (2, 20, 200);
    ((పూర్ణాంకం(*__stdcall)(పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం))some_stdcall_func) (3, 30, 300);
    కొరకు (i = 0; i < 1024; i++) {
	globalvar = i;
	/* This was once misparsed at <= gitrev 325241c0, forgetting
	   the stdcall attribute on the function pointer leading to
	   stack increment being done twice (in callee and caller).
	   This will clobber 'i' and 'localvar' which is how we detect
	   this.  */
	((పూర్ణాంకం(__stdcall*)(పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం))some_stdcall_func) (4, 40, 400);
	ఒకవేళ (localvar != 42 || globalvar != i)
	  రాయి("error, localvar=%d i=%d globalvar=%d\n", localvar, i, globalvar);
    }
    తిరిగి 0;
}
