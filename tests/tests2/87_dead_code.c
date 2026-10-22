/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
extern 정수 printf (const char *, ...);
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
	정수 i = 1;
	동안 (1)
	  동안 (i--)
	    some_label:
	      printf("error\n");
	goto some_label;
	})
      );
      timeout--;
  } 동안 (timeout);
}

static 정수 global;

static void foo(정수 i)
{
  global+=i;
  printf ("g=%d\n", global);
}

static 정수 check(void)
{
  printf ("check %d\n", global);
  반환 1;
}

static void dowhile(void)
{
  do {
      foo(1);
      만약 (global == 1) {
	  continue;
      } 아니면 만약 (global == 2) {
	  continue;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      break;
  } 동안 (check());
}

static void nondead_after_dead_return(void)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ 반환; 0;});
  printf ("nondead works\n");
  반환;
}

정수 main (void)
{
  정수 i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  만약 (0) {
yeah:
      printf ("yeah\n");
  } 아니면 {
      printf ("boo\n");
  }
  만약 (i--)
    goto yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  만약 (0) {
      동안 (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  만약 (i >= 0)
    goto enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      정수 j = 1;
      만약 (0) {
	  동안 (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      만약 (j >= 0)
	goto enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  만약 (0) {
      위해 (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  만약 (i > 0)
    goto enterloop2;

  i = 1;
  만약 (0) {
      do {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } 동안 (i--);
  }
  만약 (i > 0)
    goto enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  switch (i) {
      만약 (0) {
	  printf ("error\n");
      case 42:
	  printf ("error2\n");
      case 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  switch (i) {
      만약 (0) {
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

  반환 0;
}
