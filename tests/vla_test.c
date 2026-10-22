/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LOOP_COUNT 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
void smash(var_na *p, පූර්ණ_සංඛ්‍යා n) {
  memset(p, 0, n);
}

පූර්ණ_සංඛ්‍යා test1(පූර්ණ_සංඛ්‍යා n) {
  පූර්ණ_සංඛ්‍යා i;
  var_na *array_ptrs[LOOP_COUNT];
  
  සඳහා (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ආපසු (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
පූර්ණ_සංඛ්‍යා test2(පූර්ණ_සංඛ්‍යා n) {
  var_na *array_ptrs[LOOP_COUNT];

  පූර්ණ_සංඛ්‍යා i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  නම් (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ආපසු (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

පූර්ණ_සංඛ්‍යා test3(පූර්ණ_සංඛ්‍යා n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ආපසු (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  නම් (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    නම් (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } නැතහොත් { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

පූර්ණ_සංඛ්‍යා main(පූර්ණ_සංඛ්‍යා argc, var_na **argv) {
  const var_na *testname = NULL;
  පූර්ණ_සංඛ්‍යා retval = EXIT_SUCCESS;
  නම් (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ආපසු retval;
}
