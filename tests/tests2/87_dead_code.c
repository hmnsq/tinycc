/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
خارجي صحيح printf (ثابت حرف *, ...);
ساكن فراغ kb_wait_1(فراغ)
{
  unsigned long timeout = 2;
  ܥܒܕ {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	صحيح i = 1;
	ܟܡܐ (1)
	  ܟܡܐ (i--)
	    some_label:
	      printf("error\n");
	اذهب some_label;
	})
      );
      timeout--;
  } ܟܡܐ (timeout);
}

ساكن صحيح global;

ساكن فراغ foo(صحيح i)
{
  global+=i;
  printf ("g=%d\n", global);
}

ساكن صحيح check(فراغ)
{
  printf ("check %d\n", global);
  ܦܢܐ 1;
}

ساكن فراغ dowhile(فراغ)
{
  ܥܒܕ {
      foo(1);
      ܐܢ (global == 1) {
	  استمر;
      } ܐܚܪܢܐ ܐܢ (global == 2) {
	  استمر;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      اكسر;
  } ܟܡܐ (check());
}

ساكن فراغ nondead_after_dead_return(فراغ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ܦܢܐ; 0;});
  printf ("nondead works\n");
  ܦܢܐ;
}

صحيح main (فراغ)
{
  صحيح i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  ܐܢ (0) {
yeah:
      printf ("yeah\n");
  } ܐܚܪܢܐ {
      printf ("boo\n");
  }
  ܐܢ (i--)
    اذهب yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  ܐܢ (0) {
      ܟܡܐ (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  ܐܢ (i >= 0)
    اذهب enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      صحيح j = 1;
      ܐܢ (0) {
	  ܟܡܐ (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      ܐܢ (j >= 0)
	اذهب enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  ܐܢ (0) {
      لكل (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  ܐܢ (i > 0)
    اذهب enterloop2;

  i = 1;
  ܐܢ (0) {
      ܥܒܕ {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } ܟܡܐ (i--);
  }
  ܐܢ (i > 0)
    اذهب enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  بدل (i) {
      ܐܢ (0) {
	  printf ("error\n");
      حالة 42:
	  printf ("error2\n");
      حالة 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  بدل (i) {
      ܐܢ (0) {
	  printf ("error3\n");
      افتراضي:
	  printf ("caseok2\n");
	  اكسر;
      حالة 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ܦܢܐ 0;
}
