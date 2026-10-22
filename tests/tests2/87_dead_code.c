/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf (ଅଚଳ ଅକ୍ଷର *, ...);
ସ୍ଥିର ଶୂନ୍ୟ kb_wait_1(ଶୂନ୍ୟ)
{
  unsigned long timeout = 2;
  କର {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 1;
	ଯେତେବେଳେ (1)
	  ଯେତେବେଳେ (i--)
	    some_label:
	      printf("error\n");
	ଯାଅ some_label;
	})
      );
      timeout--;
  } ଯେତେବେଳେ (timeout);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା global;

ସ୍ଥିର ଶୂନ୍ୟ foo(ପୂର୍ଣ୍ଣସଂଖ୍ୟା i)
{
  global+=i;
  printf ("g=%d\n", global);
}

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା check(ଶୂନ୍ୟ)
{
  printf ("check %d\n", global);
  ଫେରନ୍ତୁ 1;
}

ସ୍ଥିର ଶୂନ୍ୟ dowhile(ଶୂନ୍ୟ)
{
  କର {
      foo(1);
      ଯଦି (global == 1) {
	  ଜାରି;
      } ଅନ୍ୟଥା ଯଦି (global == 2) {
	  ଜାରି;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      ଭାଙ୍ଗ;
  } ଯେତେବେଳେ (check());
}

ସ୍ଥିର ଶୂନ୍ୟ nondead_after_dead_return(ଶୂନ୍ୟ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ଫେରନ୍ତୁ; 0;});
  printf ("nondead works\n");
  ଫେରନ୍ତୁ;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ଯଦି (0) {
yeah:
      printf ("yeah\n");
  } ଅନ୍ୟଥା {
      printf ("boo\n");
  }
  ଯଦି (i--)
    ଯାଅ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ଯଦି (0) {
      ଯେତେବେଳେ (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  ଯଦି (i >= 0)
    ଯାଅ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      ପୂର୍ଣ୍ଣସଂଖ୍ୟା j = 1;
      ଯଦି (0) {
	  ଯେତେବେଳେ (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      ଯଦି (j >= 0)
	ଯାଅ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ଯଦି (0) {
      ପାଇଁ (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  ଯଦି (i > 0)
    ଯାଅ enterloop2;

  i = 1;
  ଯଦି (0) {
      କର {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } ଯେତେବେଳେ (i--);
  }
  ଯଦି (i > 0)
    ଯାଅ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  ବାଛ (i) {
      ଯଦି (0) {
	  printf ("error\n");
      ସ୍ଥିତି 42:
	  printf ("error2\n");
      ସ୍ଥିତି 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  ବାଛ (i) {
      ଯଦି (0) {
	  printf ("error3\n");
      ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
	  printf ("caseok2\n");
	  ଭାଙ୍ଗ;
      ସ୍ଥିତି 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ଫେରନ୍ତୁ 0;
}
