/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
বাহ্য পূর্ণাঙ্ক printf (ধ্রুব বর্ণ *, ...);
স্থির শূন্য kb_wait_1(শূন্য)
{
  unsigned long timeout = 2;
  কুরু {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	পূর্ণাঙ্ক i = 1;
	যাবত্ (1)
	  যাবত্ (i--)
	    some_label:
	      printf("error\n");
	গচ্ছ some_label;
	})
      );
      timeout--;
  } যাবত্ (timeout);
}

স্থির পূর্ণাঙ্ক global;

স্থির শূন্য foo(পূর্ণাঙ্ক i)
{
  global+=i;
  printf ("g=%d\n", global);
}

স্থির পূর্ণাঙ্ক check(শূন্য)
{
  printf ("check %d\n", global);
  প্রত্যাগম 1;
}

স্থির শূন্য dowhile(শূন্য)
{
  কুরু {
      foo(1);
      যদি (global == 1) {
	  অনুবর্ত;
      } অন্যথা যদি (global == 2) {
	  অনুবর্ত;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      ভঙ্গ;
  } যাবত্ (check());
}

স্থির শূন্য nondead_after_dead_return(শূন্য)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ প্রত্যাগম; 0;});
  printf ("nondead works\n");
  প্রত্যাগম;
}

পূর্ণাঙ্ক main (শূন্য)
{
  পূর্ণাঙ্ক i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  যদি (0) {
yeah:
      printf ("yeah\n");
  } অন্যথা {
      printf ("boo\n");
  }
  যদি (i--)
    গচ্ছ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  যদি (0) {
      যাবত্ (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  যদি (i >= 0)
    গচ্ছ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      পূর্ণাঙ্ক j = 1;
      যদি (0) {
	  যাবত্ (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      যদি (j >= 0)
	গচ্ছ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  যদি (0) {
      প্রতি (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  যদি (i > 0)
    গচ্ছ enterloop2;

  i = 1;
  যদি (0) {
      কুরু {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } যাবত্ (i--);
  }
  যদি (i > 0)
    গচ্ছ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  বিকল্প (i) {
      যদি (0) {
	  printf ("error\n");
      পক্ষ 42:
	  printf ("error2\n");
      পক্ষ 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  বিকল্প (i) {
      যদি (0) {
	  printf ("error3\n");
      স্বভাব:
	  printf ("caseok2\n");
	  ভঙ্গ;
      পক্ষ 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  প্রত্যাগম 0;
}
