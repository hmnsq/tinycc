/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
ബാഹ്യ പൂർണ്ണസംഖ്യ printf (സ്ഥിരം അക്ഷരം *, ...);
സ്ഥിതം ശൂന്യം kb_wait_1(ശൂന്യം)
{
  unsigned long timeout = 2;
  ചെയ്യുക {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	പൂർണ്ണസംഖ്യ i = 1;
	ആകുമ്പോൾ (1)
	  ആകുമ്പോൾ (i--)
	    some_label:
	      printf("error\n");
	പോകുക some_label;
	})
      );
      timeout--;
  } ആകുമ്പോൾ (timeout);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ global;

സ്ഥിതം ശൂന്യം foo(പൂർണ്ണസംഖ്യ i)
{
  global+=i;
  printf ("g=%d\n", global);
}

സ്ഥിതം പൂർണ്ണസംഖ്യ check(ശൂന്യം)
{
  printf ("check %d\n", global);
  തിരികെ 1;
}

സ്ഥിതം ശൂന്യം dowhile(ശൂന്യം)
{
  ചെയ്യുക {
      foo(1);
      എങ്കിൽ (global == 1) {
	  തുടരുക;
      } അല്ലെങ്കിൽ എങ്കിൽ (global == 2) {
	  തുടരുക;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      നിർത്തുക;
  } ആകുമ്പോൾ (check());
}

സ്ഥിതം ശൂന്യം nondead_after_dead_return(ശൂന്യം)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ തിരികെ; 0;});
  printf ("nondead works\n");
  തിരികെ;
}

പൂർണ്ണസംഖ്യ പ്രധാന (ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  എങ്കിൽ (0) {
yeah:
      printf ("yeah\n");
  } അല്ലെങ്കിൽ {
      printf ("boo\n");
  }
  എങ്കിൽ (i--)
    പോകുക yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  എങ്കിൽ (0) {
      ആകുമ്പോൾ (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  എങ്കിൽ (i >= 0)
    പോകുക enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      പൂർണ്ണസംഖ്യ j = 1;
      എങ്കിൽ (0) {
	  ആകുമ്പോൾ (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      എങ്കിൽ (j >= 0)
	പോകുക enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  എങ്കിൽ (0) {
      വേണ്ടി (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  എങ്കിൽ (i > 0)
    പോകുക enterloop2;

  i = 1;
  എങ്കിൽ (0) {
      ചെയ്യുക {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } ആകുമ്പോൾ (i--);
  }
  എങ്കിൽ (i > 0)
    പോകുക enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  തിരഞ്ഞെടുപ്പ് (i) {
      എങ്കിൽ (0) {
	  printf ("error\n");
      അവസ്ഥ 42:
	  printf ("error2\n");
      അവസ്ഥ 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  തിരഞ്ഞെടുപ്പ് (i) {
      എങ്കിൽ (0) {
	  printf ("error3\n");
      സ്ഥിരസ്ഥിതി:
	  printf ("caseok2\n");
	  നിർത്തുക;
      അവസ്ഥ 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  തിരികെ 0;
}
