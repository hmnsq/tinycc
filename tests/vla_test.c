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
void smash(char *p, 整数 n) {
  memset(p, 0, n);
}

整数 test1(整数 n) {
  整数 i;
  char *array_ptrs[LOOP_COUNT];
  
  ために (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  戻る (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
整数 test2(整数 n) {
  char *array_ptrs[LOOP_COUNT];

  整数 i = 0;
loop:;
  char test[n];
  smash(test, n);
  もし (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  戻る (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

整数 test3(整数 n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  戻る (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  もし (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    もし (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } 否则 { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

整数 メインページ(整数 argc, char **argv) {
  const char *testname = NULL;
  整数 retval = EXIT_SUCCESS;
  もし (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  戻る retval;
}
