/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಬರೆ (ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *, ...);
ಸ್ಥಿರ ಶೂನ್ಯ kb_wait_1(ಶೂನ್ಯ)
{
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ timeout = 2;
  ಮಾಡು {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       ಬರೆ("timeout=%ld\n", timeout) :
       ({
	ಪೂರ್ಣಾಂಕ i = 1;
	ಆಗ (1)
	  ಆಗ (i--)
	    some_label:
	      ಬರೆ("error\n");
	ಹೋಗು some_label;
	})
      );
      timeout--;
  } ಆಗ (timeout);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ global;

ಸ್ಥಿರ ಶೂನ್ಯ foo(ಪೂರ್ಣಾಂಕ i)
{
  global+=i;
  ಬರೆ ("g=%d\n", global);
}

ಸ್ಥಿರ ಪೂರ್ಣಾಂಕ check(ಶೂನ್ಯ)
{
  ಬರೆ ("check %d\n", global);
  ಹಿಂತಿರುಗಿ 1;
}

ಸ್ಥಿರ ಶೂನ್ಯ dowhile(ಶೂನ್ಯ)
{
  ಮಾಡು {
      foo(1);
      ಆದರೆ (global == 1) {
	  ಮುಂದುವರಿ;
      } ಇಲ್ಲದಿದ್ದರೆ ಆದರೆ (global == 2) {
	  ಮುಂದುವರಿ;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      ನಿಲ್ಲಿಸು;
  } ಆಗ (check());
}

ಸ್ಥಿರ ಶೂನ್ಯ nondead_after_dead_return(ಶೂನ್ಯ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ಹಿಂತಿರುಗಿ; 0;});
  ಬರೆ ("nondead works\n");
  ಹಿಂತಿರುಗಿ;
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ (ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಂಕ i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ಆದರೆ (0) {
yeah:
      ಬರೆ ("yeah\n");
  } ಇಲ್ಲದಿದ್ದರೆ {
      ಬರೆ ("boo\n");
  }
  ಆದರೆ (i--)
    ಹೋಗು yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ಆದರೆ (0) {
      ಆಗ (i--) {
	  ಬರೆ ("once\n");
enterloop:
	  ಬರೆ ("twice\n");
      }
  }
  ಆದರೆ (i >= 0)
    ಹೋಗು enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      ಪೂರ್ಣಾಂಕ j = 1;
      ಆದರೆ (0) {
	  ಆಗ (j--) {
	      ಬರೆ ("SEonce\n");
    enterexprloop:
	      ಬರೆ ("SEtwice\n");
	  }
      }
      ಆದರೆ (j >= 0)
	ಹೋಗು enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ಆದರೆ (0) {
      ಗಾಗಿ (i = 1; i--;) {
	  ಬರೆ ("once2\n");
enterloop2:
	  ಬರೆ ("twice2\n");
      }
  }
  ಆದರೆ (i > 0)
    ಹೋಗು enterloop2;

  i = 1;
  ಆದರೆ (0) {
      ಮಾಡು {
	  ಬರೆ ("once3\n");
enterloop3:
	  ಬರೆ ("twice3\n");
      } ಆಗ (i--);
  }
  ಆದರೆ (i > 0)
    ಹೋಗು enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  ಆಯ್ಕೆ (i) {
      ಆದರೆ (0) {
	  ಬರೆ ("error\n");
      ಸ್ಥಿತಿ 42:
	  ಬರೆ ("error2\n");
      ಸ್ಥಿತಿ 41:
	  ಬರೆ ("caseok\n");
      }
  }

  i = 41;
  ಆಯ್ಕೆ (i) {
      ಆದರೆ (0) {
	  ಬರೆ ("error3\n");
      ಪೂರ್ವನಿಯೋಜಿತ:
	  ಬರೆ ("caseok2\n");
	  ನಿಲ್ಲಿಸು;
      ಸ್ಥಿತಿ 42:
	  ಬರೆ ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ಹಿಂತಿರುಗಿ 0;
}
