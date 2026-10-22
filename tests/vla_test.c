/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>

#define LOOP_मोजणी 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
शून्य smash(अक्षर *p, पूर्णांक n) {
  स_रखो(p, 0, n);
}

पूर्णांक test1(पूर्णांक n) {
  पूर्णांक i;
  अक्षर *array_ptrs[LOOP_मोजणी];
  
  साठी (i = 0; i < LOOP_मोजणी; ++i) {
    अक्षर test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  परत (array_ptrs[0]-array_ptrs[LOOP_मोजणी-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
पूर्णांक test2(पूर्णांक n) {
  अक्षर *array_ptrs[LOOP_मोजणी];

  पूर्णांक i = 0;
loop:;
  अक्षर test[n];
  smash(test, n);
  जर (i >= LOOP_मोजणी)
    जा end;
  array_ptrs[i] = test;
  ++i;
  जा loop;

end:
  smash(test, n);
  अक्षर test2[n];
  smash(test2, n);
  परत (array_ptrs[0] - array_ptrs[LOOP_मोजणी-1] < n) ? 0 : 1;
}

पूर्णांक test3(पूर्णांक n) {
  अक्षर test[n];
  smash(test, n);
  जा label;
label:
  smash(test, n);
  अक्षर test2[n];
  smash(test2, n);
  परत (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  जर (!testname || (म_भेद(#t, testname) == 0)) { \
    ख_माला_दो(#t "... ", मानक_निकास); \
    ख_साफ(मानक_निकास); \
    जर (t(ARRAY_SIZE) == 0) { \
      ख_माला_दो("success\n", मानक_निकास); \
    } अन्यथा { \
      ख_माला_दो("failure\n", मानक_निकास); \
      retval = निकास_त्रुटि; \
    } \
  }

पूर्णांक main(पूर्णांक argc, अक्षर **argv) {
  स्थिरांक अक्षर *testname = रिक्त;
  पूर्णांक retval = निकास_सफल;
  जर (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  परत retval;
}
