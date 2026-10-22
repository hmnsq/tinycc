/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
بیرونی صحیح printf (ثابت نویسه *, ...);
ایستا تهی kb_wait_1(تهی)
{
  unsigned long timeout = 2;
  انجامبده {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	صحیح i = 1;
	وقتی (1)
	  وقتی (i--)
	    some_label:
	      printf("error\n");
	برو some_label;
	})
      );
      timeout--;
  } وقتی (timeout);
}

ایستا صحیح global;

ایستا تهی foo(صحیح i)
{
  global+=i;
  printf ("g=%d\n", global);
}

ایستا صحیح check(تهی)
{
  printf ("check %d\n", global);
  بازگشت 1;
}

ایستا تهی dowhile(تهی)
{
  انجامبده {
      foo(1);
      اگر (global == 1) {
	  ادامه;
      } وگرنه اگر (global == 2) {
	  ادامه;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      بشکن;
  } وقتی (check());
}

ایستا تهی nondead_after_dead_return(تهی)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ بازگشت; 0;});
  printf ("nondead works\n");
  بازگشت;
}

صحیح اصلی (تهی)
{
  صحیح i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  اگر (0) {
yeah:
      printf ("yeah\n");
  } وگرنه {
      printf ("boo\n");
  }
  اگر (i--)
    برو yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  اگر (0) {
      وقتی (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  اگر (i >= 0)
    برو enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      صحیح j = 1;
      اگر (0) {
	  وقتی (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      اگر (j >= 0)
	برو enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  اگر (0) {
      برای (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  اگر (i > 0)
    برو enterloop2;

  i = 1;
  اگر (0) {
      انجامبده {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } وقتی (i--);
  }
  اگر (i > 0)
    برو enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  انتخاب (i) {
      اگر (0) {
	  printf ("error\n");
      حالت 42:
	  printf ("error2\n");
      حالت 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  انتخاب (i) {
      اگر (0) {
	  printf ("error3\n");
      پیشفرض:
	  printf ("caseok2\n");
	  بشکن;
      حالت 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  بازگشت 0;
}
