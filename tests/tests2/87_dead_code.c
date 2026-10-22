/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
خارجي صحيح چاپ_کړه (ثابت حرف *, ...);
ساكن فراغ kb_wait_1(فراغ)
{
  بینښه اوږد timeout = 2;
  افعل {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       چاپ_کړه("timeout=%ld\n", timeout) :
       ({
	صحيح i = 1;
	طالما (1)
	  طالما (i--)
	    some_label:
	      چاپ_کړه("error\n");
	اذهب some_label;
	})
      );
      timeout--;
  } طالما (timeout);
}

ساكن صحيح global;

ساكن فراغ foo(صحيح i)
{
  global+=i;
  چاپ_کړه ("g=%d\n", global);
}

ساكن صحيح check(فراغ)
{
  چاپ_کړه ("check %d\n", global);
  أرجع 1;
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
  } طالما (check());
}

ساكن فراغ nondead_after_dead_return(فراغ)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ أرجع; 0;});
  چاپ_کړه ("nondead works\n");
  أرجع;
}

صحيح اصلي (فراغ)
{
  صحيح i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  إذا (0) {
yeah:
      چاپ_کړه ("yeah\n");
  } وإلا {
      چاپ_کړه ("boo\n");
  }
  إذا (i--)
    اذهب yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  إذا (0) {
      طالما (i--) {
	  چاپ_کړه ("once\n");
enterloop:
	  چاپ_کړه ("twice\n");
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
	  طالما (j--) {
	      چاپ_کړه ("SEonce\n");
    enterexprloop:
	      چاپ_کړه ("SEtwice\n");
	  }
      }
      إذا (j >= 0)
	اذهب enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  إذا (0) {
      لكل (i = 1; i--;) {
	  چاپ_کړه ("once2\n");
enterloop2:
	  چاپ_کړه ("twice2\n");
      }
  }
  إذا (i > 0)
    اذهب enterloop2;

  i = 1;
  إذا (0) {
      افعل {
	  چاپ_کړه ("once3\n");
enterloop3:
	  چاپ_کړه ("twice3\n");
      } طالما (i--);
  }
  إذا (i > 0)
    اذهب enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  بدل (i) {
      إذا (0) {
	  چاپ_کړه ("error\n");
      حالة 42:
	  چاپ_کړه ("error2\n");
      حالة 41:
	  چاپ_کړه ("caseok\n");
      }
  }

  i = 41;
  بدل (i) {
      إذا (0) {
	  چاپ_کړه ("error3\n");
      افتراضي:
	  چاپ_کړه ("caseok2\n");
	  اكسر;
      حالة 42:
	  چاپ_کړه ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  أرجع 0;
}
