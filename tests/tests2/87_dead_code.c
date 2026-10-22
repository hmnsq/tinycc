/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
extern puur_naa_nka printf (const var_na *, ...);
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
	puur_naa_nka i = 1;
	ᤀᤠ᤺ (1)
	  ᤀᤠ᤺ (i--)
	    some_label:
	      printf("error\n");
	goto some_label;
	})
      );
      timeout--;
  } ᤀᤠ᤺ (timeout);
}

static puur_naa_nka global;

static void foo(puur_naa_nka i)
{
  global+=i;
  printf ("g=%d\n", global);
}

static puur_naa_nka check(void)
{
  printf ("check %d\n", global);
  ᤀᤡᤴ 1;
}

static void dowhile(void)
{
  do {
      foo(1);
      ᤀᤡ᤺ (global == 1) {
	  continue;
      } ᤀᤡ᤺ᤆᤡ ᤀᤡ᤺ (global == 2) {
	  continue;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      bha_nga;
  } ᤀᤠ᤺ (check());
}

static void nondead_after_dead_return(void)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ᤀᤡᤴ; 0;});
  printf ("nondead works\n");
  ᤀᤡᤴ;
}

puur_naa_nka main (void)
{
  puur_naa_nka i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ᤀᤡ᤺ (0) {
yeah:
      printf ("yeah\n");
  } ᤀᤡ᤺ᤆᤡ {
      printf ("boo\n");
  }
  ᤀᤡ᤺ (i--)
    goto yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ᤀᤡ᤺ (0) {
      ᤀᤠ᤺ (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  ᤀᤡ᤺ (i >= 0)
    goto enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      puur_naa_nka j = 1;
      ᤀᤡ᤺ (0) {
	  ᤀᤠ᤺ (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      ᤀᤡ᤺ (j >= 0)
	goto enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ᤀᤡ᤺ (0) {
      for (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  ᤀᤡ᤺ (i > 0)
    goto enterloop2;

  i = 1;
  ᤀᤡ᤺ (0) {
      do {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } ᤀᤠ᤺ (i--);
  }
  ᤀᤡ᤺ (i > 0)
    goto enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  switch (i) {
      ᤀᤡ᤺ (0) {
	  printf ("error\n");
      pak_sa 42:
	  printf ("error2\n");
      pak_sa 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  switch (i) {
      ᤀᤡ᤺ (0) {
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

  ᤀᤡᤴ 0;
}
