/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
బాహ్య పూర్ణాంకం రాయి (స్థిరరాశి అక్షరం *, ...);
స్థిర శూన్య kb_wait_1(శూన్య)
{
  గుర్తులేని దీర్ఘ timeout = 2;
  చేయి {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       రాయి("timeout=%ld\n", timeout) :
       ({
	పూర్ణాంకం i = 1;
	అయితే (1)
	  అయితే (i--)
	    some_label:
	      రాయి("error\n");
	వెళ్ళు some_label;
	})
      );
      timeout--;
  } అయితే (timeout);
}

స్థిర పూర్ణాంకం global;

స్థిర శూన్య foo(పూర్ణాంకం i)
{
  global+=i;
  రాయి ("g=%d\n", global);
}

స్థిర పూర్ణాంకం check(శూన్య)
{
  రాయి ("check %d\n", global);
  తిరిగి 1;
}

స్థిర శూన్య dowhile(శూన్య)
{
  చేయి {
      foo(1);
      ఒకవేళ (global == 1) {
	  కొనసాగు;
      } లేకపోతే ఒకవేళ (global == 2) {
	  కొనసాగు;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      ఆపు;
  } అయితే (check());
}

స్థిర శూన్య nondead_after_dead_return(శూన్య)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ తిరిగి; 0;});
  రాయి ("nondead works\n");
  తిరిగి;
}

పూర్ణాంకం ప్రధాన (శూన్య)
{
  పూర్ణాంకం i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ఒకవేళ (0) {
yeah:
      రాయి ("yeah\n");
  } లేకపోతే {
      రాయి ("boo\n");
  }
  ఒకవేళ (i--)
    వెళ్ళు yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ఒకవేళ (0) {
      అయితే (i--) {
	  రాయి ("once\n");
enterloop:
	  రాయి ("twice\n");
      }
  }
  ఒకవేళ (i >= 0)
    వెళ్ళు enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      పూర్ణాంకం j = 1;
      ఒకవేళ (0) {
	  అయితే (j--) {
	      రాయి ("SEonce\n");
    enterexprloop:
	      రాయి ("SEtwice\n");
	  }
      }
      ఒకవేళ (j >= 0)
	వెళ్ళు enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ఒకవేళ (0) {
      కొరకు (i = 1; i--;) {
	  రాయి ("once2\n");
enterloop2:
	  రాయి ("twice2\n");
      }
  }
  ఒకవేళ (i > 0)
    వెళ్ళు enterloop2;

  i = 1;
  ఒకవేళ (0) {
      చేయి {
	  రాయి ("once3\n");
enterloop3:
	  రాయి ("twice3\n");
      } అయితే (i--);
  }
  ఒకవేళ (i > 0)
    వెళ్ళు enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  ఎంపిక (i) {
      ఒకవేళ (0) {
	  రాయి ("error\n");
      స్థితి 42:
	  రాయి ("error2\n");
      స్థితి 41:
	  రాయి ("caseok\n");
      }
  }

  i = 41;
  ఎంపిక (i) {
      ఒకవేళ (0) {
	  రాయి ("error3\n");
      అప్రమేయ:
	  రాయి ("caseok2\n");
	  ఆపు;
      స్థితి 42:
	  రాయి ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  తిరిగి 0;
}
