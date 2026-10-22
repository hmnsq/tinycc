/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
बाह्य पूर्णाङ्क प्रारूप_लिख (ध्रुव वर्ण *, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
  अचिह्नित दीर्घ timeout = 2;
  कुरु {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       प्रारूप_लिख("timeout=%ld\n", timeout) :
       ({
	पूर्णाङ्क i = 1;
	यावत् (1)
	  यावत् (i--)
	    some_label:
	      प्रारूप_लिख("error\n");
	गच्छ some_label;
	})
      );
      timeout--;
  } यावत् (timeout);
}

स्थिर पूर्णाङ्क global;

स्थिर शून्य foo(पूर्णाङ्क i)
{
  global+=i;
  प्रारूप_लिख ("g=%d\n", global);
}

स्थिर पूर्णाङ्क check(शून्य)
{
  प्रारूप_लिख ("check %d\n", global);
  प्रत्यागम 1;
}

स्थिर शून्य dowhile(शून्य)
{
  कुरु {
      foo(1);
      यदि (global == 1) {
	  अनुवर्त;
      } अन्यथा यदि (global == 2) {
	  अनुवर्त;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      भङ्ग;
  } यावत् (check());
}

स्थिर शून्य nondead_after_dead_return(शून्य)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ प्रत्यागम; 0;});
  प्रारूप_लिख ("nondead works\n");
  प्रत्यागम;
}

पूर्णाङ्क मुख्यम् (शून्य)
{
  पूर्णाङ्क i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  यदि (0) {
yeah:
      प्रारूप_लिख ("yeah\n");
  } अन्यथा {
      प्रारूप_लिख ("boo\n");
  }
  यदि (i--)
    गच्छ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  यदि (0) {
      यावत् (i--) {
	  प्रारूप_लिख ("once\n");
enterloop:
	  प्रारूप_लिख ("twice\n");
      }
  }
  यदि (i >= 0)
    गच्छ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      पूर्णाङ्क j = 1;
      यदि (0) {
	  यावत् (j--) {
	      प्रारूप_लिख ("SEonce\n");
    enterexprloop:
	      प्रारूप_लिख ("SEtwice\n");
	  }
      }
      यदि (j >= 0)
	गच्छ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  यदि (0) {
      प्रति (i = 1; i--;) {
	  प्रारूप_लिख ("once2\n");
enterloop2:
	  प्रारूप_लिख ("twice2\n");
      }
  }
  यदि (i > 0)
    गच्छ enterloop2;

  i = 1;
  यदि (0) {
      कुरु {
	  प्रारूप_लिख ("once3\n");
enterloop3:
	  प्रारूप_लिख ("twice3\n");
      } यावत् (i--);
  }
  यदि (i > 0)
    गच्छ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  विकल्प (i) {
      यदि (0) {
	  प्रारूप_लिख ("error\n");
      पक्ष 42:
	  प्रारूप_लिख ("error2\n");
      पक्ष 41:
	  प्रारूप_लिख ("caseok\n");
      }
  }

  i = 41;
  विकल्प (i) {
      यदि (0) {
	  प्रारूप_लिख ("error3\n");
      स्वभाव:
	  प्रारूप_लिख ("caseok2\n");
	  भङ्ग;
      पक्ष 42:
	  प्रारूप_लिख ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  प्रत्यागम 0;
}
