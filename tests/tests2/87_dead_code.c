/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
extern цяло printf (const char *, ...);
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
	цяло i = 1;
	докато (1)
	  докато (i--)
	    some_label:
	      printf("error\n");
	goto some_label;
	})
      );
      timeout--;
  } докато (timeout);
}

static цяло global;

static void foo(цяло i)
{
  global+=i;
  printf ("g=%d\n", global);
}

static цяло check(void)
{
  printf ("check %d\n", global);
  върни 1;
}

static void dowhile(void)
{
  do {
      foo(1);
      ако (global == 1) {
	  continue;
      } иначе ако (global == 2) {
	  continue;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      break;
  } докато (check());
}

static void nondead_after_dead_return(void)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ върни; 0;});
  printf ("nondead works\n");
  върни;
}

цяло main (void)
{
  цяло i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ако (0) {
yeah:
      printf ("yeah\n");
  } иначе {
      printf ("boo\n");
  }
  ако (i--)
    goto yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ако (0) {
      докато (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  ако (i >= 0)
    goto enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      цяло j = 1;
      ако (0) {
	  докато (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      ако (j >= 0)
	goto enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ако (0) {
      за (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  ако (i > 0)
    goto enterloop2;

  i = 1;
  ако (0) {
      do {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } докато (i--);
  }
  ако (i > 0)
    goto enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  switch (i) {
      ако (0) {
	  printf ("error\n");
      case 42:
	  printf ("error2\n");
      case 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  switch (i) {
      ако (0) {
	  printf ("error3\n");
      default:
	  printf ("caseok2\n");
	  break;
      case 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  върни 0;
}
