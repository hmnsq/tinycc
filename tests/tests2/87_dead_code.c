/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
बाह्य पूर्णाङ्क printf (ध्रुव वर्ण *, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
  unsigned long timeout = 2;
  करेहि {
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
	जाव (1)
	  जाव (i--)
	    some_label:
	      printf("error\n");
	गच्छ some_label;
	})
      );
      timeout--;
  } जाव (timeout);
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
  प्रत्यागम 1;
}

स्थिर शून्य dowhile(शून्य)
{
  करेहि {
      foo(1);
      जइ (global == 1) {
	  अनुवर्त;
      } अण्णहा जइ (global == 2) {
	  अनुवर्त;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      भङ्ग;
  } जाव (check());
}

स्थिर शून्य nondead_after_dead_return(शून्य)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ प्रत्यागम; 0;});
  printf ("nondead works\n");
  प्रत्यागम;
}

पूर्णाङ्क main (शून्य)
{
  पूर्णाङ्क i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  जइ (0) {
yeah:
      printf ("yeah\n");
  } अण्णहा {
      printf ("boo\n");
  }
  जइ (i--)
    गच्छ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  जइ (0) {
      जाव (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  जइ (i >= 0)
    गच्छ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      पूर्णाङ्क j = 1;
      जइ (0) {
	  जाव (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      जइ (j >= 0)
	गच्छ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  जइ (0) {
      प्रति (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  जइ (i > 0)
    गच्छ enterloop2;

  i = 1;
  जइ (0) {
      करेहि {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } जाव (i--);
  }
  जइ (i > 0)
    गच्छ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  विकल्प (i) {
      जइ (0) {
	  printf ("error\n");
      पक्ष 42:
	  printf ("error2\n");
      पक्ष 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  विकल्प (i) {
      जइ (0) {
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

  प्रत्यागम 0;
}
