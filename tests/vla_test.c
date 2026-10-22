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
void smash(var_na *p, ကိန်းပြည့် n) {
  memset(p, 0, n);
}

ကိန်းပြည့် test1(ကိန်းပြည့် n) {
  ကိန်းပြည့် i;
  var_na *array_ptrs[LOOP_COUNT];
  
  အတွက် (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ပြန်ပေး (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ကိန်းပြည့် test2(ကိန်းပြည့် n) {
  var_na *array_ptrs[LOOP_COUNT];

  ကိန်းပြည့် i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  အကယ်၍ (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ပြန်ပေး (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

ကိန်းပြည့် test3(ကိန်းပြည့် n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ပြန်ပေး (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  အကယ်၍ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    အကယ်၍ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } မဟုတ်ပါက { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ကိန်းပြည့် main(ကိန်းပြည့် argc, var_na **argv) {
  const var_na *testname = NULL;
  ကိန်းပြည့် retval = EXIT_SUCCESS;
  အကယ်၍ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ပြန်ပေး retval;
}
