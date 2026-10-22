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
void smash(var_na *p, จำนวนเต็ม n) {
  memset(p, 0, n);
}

จำนวนเต็ม test1(จำนวนเต็ม n) {
  จำนวนเต็ม i;
  var_na *array_ptrs[LOOP_COUNT];
  
  สำหรับ (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  คืน (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
จำนวนเต็ม test2(จำนวนเต็ม n) {
  var_na *array_ptrs[LOOP_COUNT];

  จำนวนเต็ม i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  ถ้า (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  คืน (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

จำนวนเต็ม test3(จำนวนเต็ม n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  คืน (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ถ้า (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ถ้า (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } มิฉะนั้น { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

จำนวนเต็ม หลัก(จำนวนเต็ม argc, var_na **argv) {
  const var_na *testname = NULL;
  จำนวนเต็ม retval = EXIT_SUCCESS;
  ถ้า (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  คืน retval;
}
