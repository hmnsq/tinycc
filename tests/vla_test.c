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
void smash(char *p, цяло n) {
  memset(p, 0, n);
}

цяло test1(цяло n) {
  цяло i;
  char *array_ptrs[LOOP_COUNT];
  
  за (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  върни (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
цяло test2(цяло n) {
  char *array_ptrs[LOOP_COUNT];

  цяло i = 0;
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
  върни (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

цяло test3(цяло n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  върни (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ако (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ако (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } иначе { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

цяло main(цяло argc, char **argv) {
  const char *testname = NULL;
  цяло retval = EXIT_SUCCESS;
  ако (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  върни retval;
}
