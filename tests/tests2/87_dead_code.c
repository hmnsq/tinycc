/* This checks various ways of dead code inside if statements
   where there are non-obvious ways of how the code is actually
   not dead due to reachable by labels.  */
बाह्य पूर्णांक म_लिखो (स्थिर अक्षर *, ...);
अटल व्योम kb_wait_1(व्योम)
{
  अचिन्हित दीर्घ timeout = 2;
  करो {
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
	जबतक (1)
	  जबतक (i--)
	    some_label:
	      म_लिखो("error\n");
	जाओ some_label;
	})
      );
      timeout--;
  } जबतक (timeout);
}

अटल पूर्णांक global;

अटल व्योम foo(पूर्णांक i)
{
  global+=i;
  म_लिखो ("g=%d\n", global);
}

अटल पूर्णांक check(व्योम)
{
  म_लिखो ("check %d\n", global);
  वापस 1;
}

अटल व्योम dowhile(व्योम)
{
  करो {
      foo(1);
      अगर (global == 1) {
	  जारी;
      } अन्यथा अगर (global == 2) {
	  जारी;
      }
      /* The following break shouldn't disable the check() call,
         as it's reachable by the continues above.  */
      अवरोध;
  } जबतक (check());
}

अटल व्योम nondead_after_dead_return(व्योम)
{
  /* This statement expr is not entered, and hence that fact that it
     doesn't fall-through should not influence the surrounding code.  */
  0 && ({ वापस; 0;});
  म_लिखो ("nondead works\n");
  वापस;
}

पूर्णांक मुख्य (व्योम)
{
  पूर्णांक i = 1;
  kb_wait_1();

  /* Simple test of dead code at first sight which isn't actually dead. */
  अगर (0) {
yeah:
      म_लिखो ("yeah\n");
  } अन्यथा {
      म_लिखो ("boo\n");
  }
  अगर (i--)
    जाओ yeah;

  /* Some more non-obvious uses where the problems are loops, so that even
     the first loop statements aren't actually dead.  */
  i = 1;
  अगर (0) {
      जबतक (i--) {
	  म_लिखो ("once\n");
enterloop:
	  म_लिखो ("twice\n");
      }
  }
  अगर (i >= 0)
    जाओ enterloop;

  /* The same with statement expressions.  One might be tempted to
     handle them specially by counting if inside statement exprs and
     not unsuppressing code at loops at all then.
     See kb_wait_1 for the other side of the medal where that wouldn't work.  */
  i = ({
      पूर्णांक j = 1;
      अगर (0) {
	  जबतक (j--) {
	      म_लिखो ("SEonce\n");
    enterexprloop:
	      म_लिखो ("SEtwice\n");
	  }
      }
      अगर (j >= 0)
	जाओ enterexprloop;
      j; });

  /* The other two loop forms: */
  i = 1;
  अगर (0) {
      क्रम (i = 1; i--;) {
	  म_लिखो ("once2\n");
enterloop2:
	  म_लिखो ("twice2\n");
      }
  }
  अगर (i > 0)
    जाओ enterloop2;

  i = 1;
  अगर (0) {
      करो {
	  म_लिखो ("once3\n");
enterloop3:
	  म_लिखो ("twice3\n");
      } जबतक (i--);
  }
  अगर (i > 0)
    जाओ enterloop3;

  /* And check that case and default labels have the same effect
     of disabling code suppression.  */
  i = 41;
  चयन (i) {
      अगर (0) {
	  म_लिखो ("error\n");
      हाल 42:
	  म_लिखो ("error2\n");
      हाल 41:
	  म_लिखो ("caseok\n");
      }
  }

  i = 41;
  चयन (i) {
      अगर (0) {
	  म_लिखो ("error3\n");
      शेष:
	  म_लिखो ("caseok2\n");
	  अवरोध;
      हाल 42:
	  म_लिखो ("error4\n");
      }
  }

  dowhile();
  nondead_after_dead_return();

  वापस 0;
}
