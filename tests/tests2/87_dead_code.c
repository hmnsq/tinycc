/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
বাহ্যিক পূর্ণসংখ্যা printf (ধ্রুবক অক্ষর *, ...);
স্থির শূন্য kb_wait_1(শূন্য)
{
  unsigned long timeout = 2;
  করো {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       printf("timeout=%ld\n", timeout) :
       ({
	পূর্ণসংখ্যা i = 1;
	যখন (1)
	  যখন (i--)
	    some_label:
	      printf("error\n");
	যাও some_label;
	})
      );
      timeout--;
  } যখন (timeout);
}

স্থির পূর্ণসংখ্যা global;

স্থির শূন্য foo(পূর্ণসংখ্যা i)
{
  global+=i;
  printf ("g=%d\n", global);
}

স্থির পূর্ণসংখ্যা check(শূন্য)
{
  printf ("check %d\n", global);
  ফেরত 1;
}

স্থির শূন্য dowhile(শূন্য)
{
  করো {
      foo(1);
      যদি (global == 1) {
	  চালু;
      } অন্যথা যদি (global == 2) {
	  চালু;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      বিরতি;
  } যখন (check());
}

স্থির শূন্য nondead_after_dead_return(শূন্য)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ ফেরত; 0;});
  printf ("nondead works\n");
  ফেরত;
}

পূর্ণসংখ্যা প্রধান (শূন্য)
{
  পূর্ণসংখ্যা i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  যদি (0) {
yeah:
      printf ("yeah\n");
  } অন্যথা {
      printf ("boo\n");
  }
  যদি (i--)
    যাও yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  যদি (0) {
      যখন (i--) {
	  printf ("once\n");
enterloop:
	  printf ("twice\n");
      }
  }
  যদি (i >= 0)
    যাও enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      পূর্ণসংখ্যা j = 1;
      যদি (0) {
	  যখন (j--) {
	      printf ("SEonce\n");
    enterexprloop:
	      printf ("SEtwice\n");
	  }
      }
      যদি (j >= 0)
	যাও enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  যদি (0) {
      জন্য (i = 1; i--;) {
	  printf ("once2\n");
enterloop2:
	  printf ("twice2\n");
      }
  }
  যদি (i > 0)
    যাও enterloop2;

  i = 1;
  যদি (0) {
      করো {
	  printf ("once3\n");
enterloop3:
	  printf ("twice3\n");
      } যখন (i--);
  }
  যদি (i > 0)
    যাও enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  নির্বাচন (i) {
      যদি (0) {
	  printf ("error\n");
      ক্ষেত্র 42:
	  printf ("error2\n");
      ক্ষেত্র 41:
	  printf ("caseok\n");
      }
  }

  i = 41;
  নির্বাচন (i) {
      যদি (0) {
	  printf ("error3\n");
      পূর্বনির্ধারিত:
	  printf ("caseok2\n");
	  বিরতি;
      ক্ষেত্র 42:
	  printf ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  ফেরত 0;
}
