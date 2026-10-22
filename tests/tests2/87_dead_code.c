/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
வெளி முழு printf (மாறிலி எழுத்து *, ...);
நிலையான வெறுமை kb_wait_1(வெறுமை)
{
  unsigned long timeout = 2;
  செய் {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	முழு i = 1;
	போது (1)
	  போது (i--)
	    some_label:
	      printf("error\n");
	செல் some_label;
	})
      );
      timeout--;
  } போது (timeout);
}

நிலையான முழு global;

நிலையான வெறுமை foo(முழு i)
{
  global+=i;
  printf ("g=%d\n", global);
}

நிலையான முழு check(வெறுமை)
{
  printf ("check %d\n", global);
  திரும்பு 1;
}

நிலையான வெறுமை dowhile(வெறுமை)
{
  செய் {
      foo(1);
      எனில் (global == 1) {
	  தொடர்;
      } இல்லையெனில் எனில் (global == 2) {
	  தொடர்;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      நிறுத்து;
  } போது (check());
}

நிலையான வெறுமை nondead_after_dead_return(வெறுமை)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ திரும்பு; 0;});
  printf ("nondead works\n");
  திரும்பு;
}

முழு முதன்மை (வெறுமை)
{
  முழு i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  எனில் (0) {
yeah:
      printf ("yeah\n");
  } இல்லையெனில் {
      printf ("boo\n");
  }
  எனில் (i--)
    செல் yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  எனில் (0) {
      போது (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  எனில் (i >= 0)
    செல் enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      முழு j = 1;
      எனில் (0) {
	  போது (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      எனில் (j >= 0)
	செல் enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  எனில் (0) {
      க்கு (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  எனில் (i > 0)
    செல் enterloop2;

  i = 1;
  எனில் (0) {
      செய் {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } போது (i--);
  }
  எனில் (i > 0)
    செல் enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  தேர்வு (i) {
      எனில் (0) {
	  printf ("error\n");
      நிலை 42:
	  printf ("error2\n");
      நிலை 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  தேர்வு (i) {
      எனில் (0) {
	  printf ("error3\n");
      இயல்பு:
	  printf ("caseok2\n");
	  நிறுத்து;
      நிலை 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  திரும்பு 0;
}
