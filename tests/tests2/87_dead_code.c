/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ printf (ಧ್ರುವ ವರ್ಣ *, ...);
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_1(ಶೂನ್ಯ)
{
  unsigned long timeout = 2;
  ಕುರು {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	ಪೂರ್ಣಾಙ್ಕ i = 1;
	ಯಾವತ್ (1)
	  ಯಾವತ್ (i--)
	    some_label:
	      printf("error\n");
	ಗಚ್ಛ some_label;
	})
      );
      timeout--;
  } ಯಾವತ್ (timeout);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ global;

ಸ್ಥಿರ ಶೂನ್ಯ foo(ಪೂರ್ಣಾಙ್ಕ i)
{
  global+=i;
  printf ("g=%d\n", global);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ check(ಶೂನ್ಯ)
{
  printf ("check %d\n", global);
  ಪ್ರತ್ಯಾಗಮ 1;
}

ಸ್ಥಿರ ಶೂನ್ಯ dowhile(ಶೂನ್ಯ)
{
  ಕುರು {
      foo(1);
      ಯದಿ (global == 1) {
	  ಅನುವರ್ತ;
      } ಅನ್ಯಥಾ ಯದಿ (global == 2) {
	  ಅನುವರ್ತ;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      ಭಙ್ಗ;
  } ಯಾವತ್ (check());
}

ಸ್ಥಿರ ಶೂನ್ಯ nondead_after_dead_return(ಶೂನ್ಯ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ಪ್ರತ್ಯಾಗಮ; 0;});
  printf ("nondead works\n");
  ಪ್ರತ್ಯಾಗಮ;
}

ಪೂರ್ಣಾಙ್ಕ main (ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ಯದಿ (0) {
yeah:
      printf ("yeah\n");
  } ಅನ್ಯಥಾ {
      printf ("boo\n");
  }
  ಯದಿ (i--)
    ಗಚ್ಛ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ಯದಿ (0) {
      ಯಾವತ್ (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  ಯದಿ (i >= 0)
    ಗಚ್ಛ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      ಪೂರ್ಣಾಙ್ಕ j = 1;
      ಯದಿ (0) {
	  ಯಾವತ್ (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      ಯದಿ (j >= 0)
	ಗಚ್ಛ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ಯದಿ (0) {
      ಪ್ರತಿ (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  ಯದಿ (i > 0)
    ಗಚ್ಛ enterloop2;

  i = 1;
  ಯದಿ (0) {
      ಕುರು {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } ಯಾವತ್ (i--);
  }
  ಯದಿ (i > 0)
    ಗಚ್ಛ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  ವಿಕಲ್ಪ (i) {
      ಯದಿ (0) {
	  printf ("error\n");
      ಪಕ್ಷ 42:
	  printf ("error2\n");
      ಪಕ್ಷ 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  ವಿಕಲ್ಪ (i) {
      ಯದಿ (0) {
	  printf ("error3\n");
      ಸ್ವಭಾವ:
	  printf ("caseok2\n");
	  ಭಙ್ಗ;
      ಪಕ್ಷ 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ಪ್ರತ್ಯಾಗಮ 0;
}
