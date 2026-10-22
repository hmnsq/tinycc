/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
ਬਾਹਰੀ ਪੂਰਨ ਲਿਖੋ (ਅਚਲ ਅੱਖਰ *, ...);
ਸਥਿਰ ਖਾਲੀ kb_wait_1(ਖਾਲੀ)
{
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ timeout = 2;
  ਕਰੋ {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       ਲਿਖੋ("timeout=%ld\n", timeout) :
       ({
	ਪੂਰਨ i = 1;
	ਜਦੋਂ (1)
	  ਜਦੋਂ (i--)
	    some_label:
	      ਲਿਖੋ("error\n");
	ਜਾਓ some_label;
	})
      );
      timeout--;
  } ਜਦੋਂ (timeout);
}

ਸਥਿਰ ਪੂਰਨ global;

ਸਥਿਰ ਖਾਲੀ foo(ਪੂਰਨ i)
{
  global+=i;
  ਲਿਖੋ ("g=%d\n", global);
}

ਸਥਿਰ ਪੂਰਨ check(ਖਾਲੀ)
{
  ਲਿਖੋ ("check %d\n", global);
  ਵਾਪਸ 1;
}

ਸਥਿਰ ਖਾਲੀ dowhile(ਖਾਲੀ)
{
  ਕਰੋ {
      foo(1);
      ਜੇ (global == 1) {
	  ਜਾਰੀ;
      } ਨਹੀਂਤਾਂ ਜੇ (global == 2) {
	  ਜਾਰੀ;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      ਰੋਕੋ;
  } ਜਦੋਂ (check());
}

ਸਥਿਰ ਖਾਲੀ nondead_after_dead_return(ਖਾਲੀ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ਵਾਪਸ; 0;});
  ਲਿਖੋ ("nondead works\n");
  ਵਾਪਸ;
}

ਪੂਰਨ ਮੁੱਖ (ਖਾਲੀ)
{
  ਪੂਰਨ i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ਜੇ (0) {
yeah:
      ਲਿਖੋ ("yeah\n");
  } ਨਹੀਂਤਾਂ {
      ਲਿਖੋ ("boo\n");
  }
  ਜੇ (i--)
    ਜਾਓ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ਜੇ (0) {
      ਜਦੋਂ (i--) {
	  ਲਿਖੋ ("once\n");
enterloop:
	  ਲਿਖੋ ("twice\n");
      }
  }
  ਜੇ (i >= 0)
    ਜਾਓ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      ਪੂਰਨ j = 1;
      ਜੇ (0) {
	  ਜਦੋਂ (j--) {
	      ਲਿਖੋ ("SEonce\n");
    enterexprloop:
	      ਲਿਖੋ ("SEtwice\n");
	  }
      }
      ਜੇ (j >= 0)
	ਜਾਓ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ਜੇ (0) {
      ਲਈ (i = 1; i--;) {
	  ਲਿਖੋ ("once2\n");
enterloop2:
	  ਲਿਖੋ ("twice2\n");
      }
  }
  ਜੇ (i > 0)
    ਜਾਓ enterloop2;

  i = 1;
  ਜੇ (0) {
      ਕਰੋ {
	  ਲਿਖੋ ("once3\n");
enterloop3:
	  ਲਿਖੋ ("twice3\n");
      } ਜਦੋਂ (i--);
  }
  ਜੇ (i > 0)
    ਜਾਓ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  ਚੋਣ (i) {
      ਜੇ (0) {
	  ਲਿਖੋ ("error\n");
      ਹਾਲਤ 42:
	  ਲਿਖੋ ("error2\n");
      ਹਾਲਤ 41:
	  ਲਿਖੋ ("caseok\n");
      }
  }

  i = 41;
  ਚੋਣ (i) {
      ਜੇ (0) {
	  ਲਿਖੋ ("error3\n");
      ਮੂਲ:
	  ਲਿਖੋ ("caseok2\n");
	  ਰੋਕੋ;
      ਹਾਲਤ 42:
	  ਲਿਖੋ ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ਵਾਪਸ 0;
}
