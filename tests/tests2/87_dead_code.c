/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
बाह्य पूर्णाङ्क printf (ध्रुव वर्ण *, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
  unsigned long timeout = 2;
  करोहि {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	पूर्णाङ्क i = 1;
	याव (1)
	  याव (i--)
	    some_label:
	      printf("error\n");
	गच्छ some_label;
	})
      );
      timeout--;
  } याव (timeout);
}

स्थिर पूर्णाङ्क global;

स्थिर शून्य foo(पूर्णाङ्क i)
{
  global+=i;
  printf ("g=%d\n", global);
}

स्थिर पूर्णाङ्क check(शून्य)
{
  printf ("check %d\n", global);
  पटिनिवत्त 1;
}

स्थिर शून्य dowhile(शून्य)
{
  करोहि {
      foo(1);
      सचे (global == 1) {
	  अनुवर्त;
      } अञ्ञथा सचे (global == 2) {
	  अनुवर्त;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      भङ्ग;
  } याव (check());
}

स्थिर शून्य nondead_after_dead_return(शून्य)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ पटिनिवत्त; 0;});
  printf ("nondead works\n");
  पटिनिवत्त;
}

पूर्णाङ्क main (शून्य)
{
  पूर्णाङ्क i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  सचे (0) {
yeah:
      printf ("yeah\n");
  } अञ्ञथा {
      printf ("boo\n");
  }
  सचे (i--)
    गच्छ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  सचे (0) {
      याव (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  सचे (i >= 0)
    गच्छ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      पूर्णाङ्क j = 1;
      सचे (0) {
	  याव (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      सचे (j >= 0)
	गच्छ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  सचे (0) {
      अत्थाय (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  सचे (i > 0)
    गच्छ enterloop2;

  i = 1;
  सचे (0) {
      करोहि {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } याव (i--);
  }
  सचे (i > 0)
    गच्छ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  विकल्प (i) {
      सचे (0) {
	  printf ("error\n");
      पक्ष 42:
	  printf ("error2\n");
      पक्ष 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  विकल्प (i) {
      सचे (0) {
	  printf ("error3\n");
      स्वभाव:
	  printf ("caseok2\n");
	  भङ्ग;
      पक्ष 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  पटिनिवत्त 0;
}
