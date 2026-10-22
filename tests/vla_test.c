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
void smash(var_na *p, ཧྲིལ n) {
  memset(p, 0, n);
}

ཧྲིལ test1(ཧྲིལ n) {
  ཧྲིལ i;
  var_na *array_ptrs[LOOP_COUNT];
  
  ཆེད་དུ (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ཕྱིར (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ཧྲིལ test2(ཧྲིལ n) {
  var_na *array_ptrs[LOOP_COUNT];

  ཧྲིལ i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  གལ་ཏེ (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ཕྱིར (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

ཧྲིལ test3(ཧྲིལ n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ཕྱིར (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  གལ་ཏེ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    གལ་ཏེ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } དེ་མིན { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ཧྲིལ གཙོ(ཧྲིལ argc, var_na **argv) {
  const var_na *testname = NULL;
  ཧྲིལ retval = EXIT_SUCCESS;
  གལ་ཏེ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ཕྱིར retval;
}
