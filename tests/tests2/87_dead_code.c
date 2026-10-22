/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
extern 整数 printf (const char *, ...);
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
	整数 i = 1;
	当 (1)
	  当 (i--)
	    some_label:
	      printf("error\n");
	goto some_label;
	})
      );
      timeout--;
  } 当 (timeout);
}

static 整数 global;

static void foo(整数 i)
{
  global+=i;
  printf ("g=%d\n", global);
}

static 整数 check(void)
{
  printf ("check %d\n", global);
  返回 1;
}

static void dowhile(void)
{
  do {
      foo(1);
      如果 (global == 1) {
	  continue;
      } 否则 如果 (global == 2) {
	  continue;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      break;
  } 当 (check());
}

static void nondead_after_dead_return(void)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ 返回; 0;});
  printf ("nondead works\n");
  返回;
}

整数 主要 (void)
{
  整数 i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  如果 (0) {
yeah:
      printf ("yeah\n");
  } 否则 {
      printf ("boo\n");
  }
  如果 (i--)
    goto yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  如果 (0) {
      当 (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  如果 (i >= 0)
    goto enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      整数 j = 1;
      如果 (0) {
	  当 (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      如果 (j >= 0)
	goto enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  如果 (0) {
      为 (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  如果 (i > 0)
    goto enterloop2;

  i = 1;
  如果 (0) {
      do {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } 当 (i--);
  }
  如果 (i > 0)
    goto enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  switch (i) {
      如果 (0) {
	  printf ("error\n");
      case 42:
	  printf ("error2\n");
      case 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  switch (i) {
      如果 (0) {
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

  返回 0;
}
