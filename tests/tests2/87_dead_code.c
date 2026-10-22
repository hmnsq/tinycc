/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
extern පූර්ණ_සංඛ්‍යා printf (const var_na *, ...);
static void kb_wait_1(void)
{
  unsigned long timeout = 2;
  do {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	පූර්ණ_සංඛ්‍යා i = 1;
	අතරතුර (1)
	  අතරතුර (i--)
	    some_label:
	      printf("error\n");
	goto some_label;
	})
      );
      timeout--;
  } අතරතුර (timeout);
}

static පූර්ණ_සංඛ්‍යා global;

static void foo(පූර්ණ_සංඛ්‍යා i)
{
  global+=i;
  printf ("g=%d\n", global);
}

static පූර්ණ_සංඛ්‍යා check(void)
{
  printf ("check %d\n", global);
  ආපසු 1;
}

static void dowhile(void)
{
  do {
      foo(1);
      නම් (global == 1) {
	  continue;
      } නැතහොත් නම් (global == 2) {
	  continue;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      bha_nga;
  } අතරතුර (check());
}

static void nondead_after_dead_return(void)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ආපසු; 0;});
  printf ("nondead works\n");
  ආපසු;
}

පූර්ණ_සංඛ්‍යා main (void)
{
  පූර්ණ_සංඛ්‍යා i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  නම් (0) {
yeah:
      printf ("yeah\n");
  } නැතහොත් {
      printf ("boo\n");
  }
  නම් (i--)
    goto yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  නම් (0) {
      අතරතුර (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  නම් (i >= 0)
    goto enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      පූර්ණ_සංඛ්‍යා j = 1;
      නම් (0) {
	  අතරතුර (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      නම් (j >= 0)
	goto enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  නම් (0) {
      සඳහා (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  නම් (i > 0)
    goto enterloop2;

  i = 1;
  නම් (0) {
      do {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } අතරතුර (i--);
  }
  නම් (i > 0)
    goto enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  switch (i) {
      නම් (0) {
	  printf ("error\n");
      pak_sa 42:
	  printf ("error2\n");
      pak_sa 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  switch (i) {
      නම් (0) {
	  printf ("error3\n");
      default:
	  printf ("caseok2\n");
	  bha_nga;
      pak_sa 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ආපසු 0;
}
