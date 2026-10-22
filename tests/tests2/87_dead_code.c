/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
خارجي صحيح printf (ثابت حرف *, ...);
ساكن فراغ kb_wait_1(فراغ)
{
  unsigned long timeout = 2;
  افعل {
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
	بينما (1)
	  بينما (i--)
	    some_label:
	      printf("error\n");
	اذهب some_label;
	})
      );
      timeout--;
  } بينما (timeout);
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
  إرجاع 1;
}

ساكن فراغ dowhile(فراغ)
{
  افعل {
      foo(1);
      إذا (global == 1) {
	  استمر;
      } وإلا إذا (global == 2) {
	  استمر;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      اكسر;
  } بينما (check());
}

ساكن فراغ nondead_after_dead_return(فراغ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ إرجاع; 0;});
  printf ("nondead works\n");
  إرجاع;
}

صحيح الرئيسية (فراغ)
{
  صحيح i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  إذا (0) {
yeah:
      printf ("yeah\n");
  } وإلا {
      printf ("boo\n");
  }
  إذا (i--)
    اذهب yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  إذا (0) {
      بينما (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  إذا (i >= 0)
    اذهب enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      صحيح j = 1;
      إذا (0) {
	  بينما (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      إذا (j >= 0)
	اذهب enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  إذا (0) {
      لكل (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  إذا (i > 0)
    اذهب enterloop2;

  i = 1;
  إذا (0) {
      افعل {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } بينما (i--);
  }
  إذا (i > 0)
    اذهب enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  بدل (i) {
      إذا (0) {
	  printf ("error\n");
      حالة 42:
	  printf ("error2\n");
      حالة 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  بدل (i) {
      إذا (0) {
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

  إرجاع 0;
}
