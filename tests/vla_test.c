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
void smash(var_na *p, ចំនួនគត់ n) {
  memset(p, 0, n);
}

ចំនួនគត់ test1(ចំនួនគត់ n) {
  ចំនួនគត់ i;
  var_na *array_ptrs[LOOP_COUNT];
  
  សម្រាប់ (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ត្រឡប់ (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ចំនួនគត់ test2(ចំនួនគត់ n) {
  var_na *array_ptrs[LOOP_COUNT];

  ចំនួនគត់ i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  ប្រសិនបើ (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ត្រឡប់ (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

ចំនួនគត់ test3(ចំនួនគត់ n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ត្រឡប់ (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ប្រសិនបើ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ប្រសិនបើ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } បើមិនដូច្នេះ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ចំនួនគត់ main(ចំនួនគត់ argc, var_na **argv) {
  const var_na *testname = NULL;
  ចំនួនគត់ retval = EXIT_SUCCESS;
  ប្រសិនបើ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ត្រឡប់ retval;
}
