/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
बाह्य पूर्णांक म_लिखो (स्थिरांक अक्षर *, ...);
स्थिर शून्य kb_wait_1(शून्य)
{
  अचिन्हित दीर्घ timeout = 2;
  करा {
      /* Here the else arm is a statement expression that's supposed
         to be suppressed.  The label inside the while would unsuppress
	 code generation again if not handled correctly.  And that
	 would wreak havoc to the cond-expression because there's no
	 jump-around emitted, the whole statement expression really
	 needs to not generate code (perhaps except useless forward jumps).  */
      (1 ? 
       म_लिखो("timeout=%ld\n", timeout) :
       ({
	पूर्णांक i = 1;
	पर्यंत (1)
	  पर्यंत (i--)
	    some_label:
	      म_लिखो("error\n");
	जा some_label;
	})
      );
      timeout--;
  } पर्यंत (timeout);
}

स्थिर पूर्णांक global;

स्थिर शून्य foo(पूर्णांक i)
{
  global+=i;
  म_लिखो ("g=%d\n", global);
}

स्थिर पूर्णांक check(शून्य)
{
  म_लिखो ("check %d\n", global);
  परत 1;
}

स्थिर शून्य dowhile(शून्य)
{
  करा {
      foo(1);
      जर (global == 1) {
	  सुरूठेवा;
      } अन्यथा जर (global == 2) {
	  सुरूठेवा;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      थांबा;
  } पर्यंत (check());
}

स्थिर शून्य nondead_after_dead_return(शून्य)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ परत; 0;});
  म_लिखो ("nondead works\n");
  परत;
}

पूर्णांक main (शून्य)
{
  पूर्णांक i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  जर (0) {
yeah:
      म_लिखो ("yeah\n");
  } अन्यथा {
      म_लिखो ("boo\n");
  }
  जर (i--)
    जा yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  जर (0) {
      पर्यंत (i--) {
	  म_लिखो ("once\n");
enterloop:
	  म_लिखो ("twice\n");
      }
  }
  जर (i >= 0)
    जा enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      पूर्णांक j = 1;
      जर (0) {
	  पर्यंत (j--) {
	      म_लिखो ("SEonce\n");
    enterexprloop:
	      म_लिखो ("SEtwice\n");
	  }
      }
      जर (j >= 0)
	जा enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  जर (0) {
      साठी (i = 1; i--;) {
	  म_लिखो ("once2\n");
enterloop2:
	  म_लिखो ("twice2\n");
      }
  }
  जर (i > 0)
    जा enterloop2;

  i = 1;
  जर (0) {
      करा {
	  म_लिखो ("once3\n");
enterloop3:
	  म_लिखो ("twice3\n");
      } पर्यंत (i--);
  }
  जर (i > 0)
    जा enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  निवड (i) {
      जर (0) {
	  म_लिखो ("error\n");
      स्थिती 42:
	  म_लिखो ("error2\n");
      स्थिती 41:
	  म_लिखो ("caseok\n");
      }
  }

  i = 41;
  निवड (i) {
      जर (0) {
	  म_लिखो ("error3\n");
      पूर्वनिर्धारित:
	  म_लिखो ("caseok2\n");
	  थांबा;
      स्थिती 42:
	  म_लिखो ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  परत 0;
}
