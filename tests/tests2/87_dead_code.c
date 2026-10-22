/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
બાહ્ય પૂર્ણાંક printf (અચલ અક્ષર *, ...);
સ્થિર શૂન્ય kb_wait_1(શૂન્ય)
{
  unsigned long timeout = 2;
  કરો {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	પૂર્ણાંક i = 1;
	જ્યારે (1)
	  જ્યારે (i--)
	    some_label:
	      printf("error\n");
	જાઓ some_label;
	})
      );
      timeout--;
  } જ્યારે (timeout);
}

સ્થિર પૂર્ણાંક global;

સ્થિર શૂન્ય foo(પૂર્ણાંક i)
{
  global+=i;
  printf ("g=%d\n", global);
}

સ્થિર પૂર્ણાંક check(શૂન્ય)
{
  printf ("check %d\n", global);
  પાછા 1;
}

સ્થિર શૂન્ય dowhile(શૂન્ય)
{
  કરો {
      foo(1);
      જો (global == 1) {
	  ચાલુ;
      } નહીંતર જો (global == 2) {
	  ચાલુ;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      તોડો;
  } જ્યારે (check());
}

સ્થિર શૂન્ય nondead_after_dead_return(શૂન્ય)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ પાછા; 0;});
  printf ("nondead works\n");
  પાછા;
}

પૂર્ણાંક મુખ્ય (શૂન્ય)
{
  પૂર્ણાંક i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  જો (0) {
yeah:
      printf ("yeah\n");
  } નહીંતર {
      printf ("boo\n");
  }
  જો (i--)
    જાઓ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  જો (0) {
      જ્યારે (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  જો (i >= 0)
    જાઓ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      પૂર્ણાંક j = 1;
      જો (0) {
	  જ્યારે (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      જો (j >= 0)
	જાઓ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  જો (0) {
      માટે (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  જો (i > 0)
    જાઓ enterloop2;

  i = 1;
  જો (0) {
      કરો {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } જ્યારે (i--);
  }
  જો (i > 0)
    જાઓ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  પસંદગી (i) {
      જો (0) {
	  printf ("error\n");
      સ્થિતિ 42:
	  printf ("error2\n");
      સ્થિતિ 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  પસંદગી (i) {
      જો (0) {
	  printf ("error3\n");
      મૂળભૂત:
	  printf ("caseok2\n");
	  તોડો;
      સ્થિતિ 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  પાછા 0;
}
