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
void smash(char *p, цео n) {
  memset(p, 0, n);
}

цео test1(цео n) {
  цео i;
  char *array_ptrs[LOOP_COUNT];
  
  за (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  врати (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
цео test2(цео n) {
  char *array_ptrs[LOOP_COUNT];

  цео i = 0;
loop:;
  char test[n];
  smash(test, n);
  ако (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  врати (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

цео test3(цео n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  врати (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ако (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ако (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } инако { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

цео main(цео argc, char **argv) {
  const char *testname = NULL;
  цео retval = EXIT_SUCCESS;
  ако (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  врати retval;
}
