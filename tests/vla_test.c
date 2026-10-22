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
शून्य smash(वर्ण *p, पूर्णाङ्क n) {
  memset(p, 0, n);
}

पूर्णाङ्क test1(पूर्णाङ्क n) {
  पूर्णाङ्क i;
  वर्ण *array_ptrs[LOOP_मोजणी];
  
  प्रति (i = 0; i < LOOP_मोजणी; ++i) {
    वर्ण test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  प्रत्यागम (array_ptrs[0]-array_ptrs[LOOP_मोजणी-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
पूर्णाङ्क test2(पूर्णाङ्क n) {
  वर्ण *array_ptrs[LOOP_मोजणी];

  पूर्णाङ्क i = 0;
loop:;
  वर्ण test[n];
  smash(test, n);
  यदि (i >= LOOP_मोजणी)
    गच्छ end;
  array_ptrs[i] = test;
  ++i;
  गच्छ loop;

end:
  smash(test, n);
  वर्ण test2[n];
  smash(test2, n);
  प्रत्यागम (array_ptrs[0] - array_ptrs[LOOP_मोजणी-1] < n) ? 0 : 1;
}

पूर्णाङ्क test3(पूर्णाङ्क n) {
  वर्ण test[n];
  smash(test, n);
  गच्छ label;
label:
  smash(test, n);
  वर्ण test2[n];
  smash(test2, n);
  प्रत्यागम (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  यदि (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    यदि (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } अन्यथा { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv) {
  ध्रुव वर्ण *testname = रिक्त;
  पूर्णाङ्क retval = EXIT_SUCCESS;
  यदि (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  प्रत्यागम retval;
}
