/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
बाह्य पूर्णाङ्क म_लिखो (ध्रुव वर्ण *, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
  अचिन्हित दीर्घ timeout = 2;
  कुरु {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       म_लिखो("timeout=%ld\n", timeout) :
       ({
	पूर्णाङ्क i = 1;
	यावत् (1)
	  यावत् (i--)
	    some_label:
	      म_लिखो("error\n");
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
  म_लिखो ("g=%d\n", global);
}

स्थिर पूर्णाङ्क check(शून्य)
{
  म_लिखो ("check %d\n", global);
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
  म_लिखो ("nondead works\n");
  प्रत्यागम;
}

पूर्णाङ्क main (शून्य)
{
  पूर्णाङ्क i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  यदि (0) {
yeah:
      म_लिखो ("yeah\n");
  } अन्यथा {
      म_लिखो ("boo\n");
  }
  यदि (i--)
    गच्छ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  यदि (0) {
      यावत् (i--) {
	  म_लिखो ("once\n");
enterloop:
	  म_लिखो ("twice\n");
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
	      म_लिखो ("SEonce\n");
    enterexprloop:
	      म_लिखो ("SEtwice\n");
	  }
      }
      यदि (j >= 0)
	गच्छ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  यदि (0) {
      प्रति (i = 1; i--;) {
	  म_लिखो ("once2\n");
enterloop2:
	  म_लिखो ("twice2\n");
      }
  }
  यदि (i > 0)
    गच्छ enterloop2;

  i = 1;
  यदि (0) {
      कुरु {
	  म_लिखो ("once3\n");
enterloop3:
	  म_लिखो ("twice3\n");
      } यावत् (i--);
  }
  यदि (i > 0)
    गच्छ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  विकल्प (i) {
      यदि (0) {
	  म_लिखो ("error\n");
      पक्ष 42:
	  म_लिखो ("error2\n");
      पक्ष 41:
	  म_लिखो ("caseok\n");
      }
  }

  i = 41;
  विकल्प (i) {
      यदि (0) {
	  म_लिखो ("error3\n");
      स्वभाव:
	  म_लिखो ("caseok2\n");
	  भङ्ग;
      पक्ष 42:
	  म_लिखो ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  प्रत्यागम 0;
}
