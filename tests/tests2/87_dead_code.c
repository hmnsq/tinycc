/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
خارجی صحیح لکھو (ثابت حرف *, ...);
ساکن خالی kb_wait_1(خالی)
{
  غیرعلامتی طویل timeout = 2;
  کرو {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       لکھو("timeout=%ld\n", timeout) :
       ({
	صحیح i = 1;
	جب (1)
	  جب (i--)
	    some_label:
	      لکھو("error\n");
	جاؤ some_label;
	})
      );
      timeout--;
  } جب (timeout);
}

ساکن صحیح global;

ساکن خالی foo(صحیح i)
{
  global+=i;
  لکھو ("g=%d\n", global);
}

ساکن صحیح check(خالی)
{
  لکھو ("check %d\n", global);
  واپس 1;
}

ساکن خالی dowhile(خالی)
{
  کرو {
      foo(1);
      اگر (global == 1) {
	  جاری;
      } ورنہ اگر (global == 2) {
	  جاری;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      توڑو;
  } جب (check());
}

ساکن خالی nondead_after_dead_return(خالی)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ واپس; 0;});
  لکھو ("nondead works\n");
  واپس;
}

صحیح مین (خالی)
{
  صحیح i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  اگر (0) {
yeah:
      لکھو ("yeah\n");
  } ورنہ {
      لکھو ("boo\n");
  }
  اگر (i--)
    جاؤ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  اگر (0) {
      جب (i--) {
	  لکھو ("once\n");
enterloop:
	  لکھو ("twice\n");
      }
  }
  اگر (i >= 0)
    جاؤ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      صحیح j = 1;
      اگر (0) {
	  جب (j--) {
	      لکھو ("SEonce\n");
    enterexprloop:
	      لکھو ("SEtwice\n");
	  }
      }
      اگر (j >= 0)
	جاؤ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  اگر (0) {
      برائے (i = 1; i--;) {
	  لکھو ("once2\n");
enterloop2:
	  لکھو ("twice2\n");
      }
  }
  اگر (i > 0)
    جاؤ enterloop2;

  i = 1;
  اگر (0) {
      کرو {
	  لکھو ("once3\n");
enterloop3:
	  لکھو ("twice3\n");
      } جب (i--);
  }
  اگر (i > 0)
    جاؤ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  انتخاب (i) {
      اگر (0) {
	  لکھو ("error\n");
      حالت 42:
	  لکھو ("error2\n");
      حالت 41:
	  لکھو ("caseok\n");
      }
  }

  i = 41;
  انتخاب (i) {
      اگر (0) {
	  لکھو ("error3\n");
      طےشدہ:
	  لکھو ("caseok2\n");
	  توڑو;
      حالت 42:
	  لکھو ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  واپس 0;
}
