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
void smash(char *p, 정수 n) {
  memset(p, 0, n);
}

정수 test1(정수 n) {
  정수 i;
  char *array_ptrs[LOOP_COUNT];
  
  위해 (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  반환 (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
정수 test2(정수 n) {
  char *array_ptrs[LOOP_COUNT];

  정수 i = 0;
loop:;
  char test[n];
  smash(test, n);
  만약 (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  반환 (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

정수 test3(정수 n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  반환 (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  만약 (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    만약 (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } 아니면 { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

정수 main(정수 argc, char **argv) {
  const char *testname = NULL;
  정수 retval = EXIT_SUCCESS;
  만약 (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  반환 retval;
}
