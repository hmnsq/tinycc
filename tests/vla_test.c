/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश <string.h>

#घोषणा LOOP_गिनती 1000
#घोषणा ARRAY_आकार 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
व्योम smash(अक्षर *p, पूर्णांक n) {
  स_रखो(p, 0, n);
}

पूर्णांक test1(पूर्णांक n) {
  पूर्णांक i;
  अक्षर *array_ptrs[LOOP_गिनती];
  
  क्रम (i = 0; i < LOOP_गिनती; ++i) {
    अक्षर test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  वापस (array_ptrs[0]-array_ptrs[LOOP_गिनती-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
पूर्णांक test2(पूर्णांक n) {
  अक्षर *array_ptrs[LOOP_गिनती];

  पूर्णांक i = 0;
loop:;
  अक्षर test[n];
  smash(test, n);
  अगर (i >= LOOP_गिनती)
    जाओ end;
  array_ptrs[i] = test;
  ++i;
  जाओ loop;

end:
  smash(test, n);
  अक्षर test2[n];
  smash(test2, n);
  वापस (array_ptrs[0] - array_ptrs[LOOP_गिनती-1] < n) ? 0 : 1;
}

पूर्णांक test3(पूर्णांक n) {
  अक्षर test[n];
  smash(test, n);
  जाओ label;
label:
  smash(test, n);
  अक्षर test2[n];
  smash(test2, n);
  वापस (test-test2 >= n) ? 0 : 1;
}

#घोषणा RUN_TEST(t) \
  अगर (!testname || (म_भेद(#t, testname) == 0)) { \
    ख_माला_दो(#t "... ", मानक_निकास); \
    ख_साफ(मानक_निकास); \
    अगर (t(ARRAY_आकार) == 0) { \
      ख_माला_दो("success\n", मानक_निकास); \
    } अन्यथा { \
      ख_माला_दो("failure\n", मानक_निकास); \
      retval = निकास_त्रुटि; \
    } \
  }

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv) {
  स्थिर अक्षर *testname = शून्य;
  पूर्णांक retval = निकास_सफल;
  अगर (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  वापस retval;
}
