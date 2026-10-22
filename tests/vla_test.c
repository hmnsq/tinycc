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
void smash(char *p, целое n) {
  memset(p, 0, n);
}

целое test1(целое n) {
  целое i;
  char *array_ptrs[LOOP_COUNT];
  
  для (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  вернуть (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
целое test2(целое n) {
  char *array_ptrs[LOOP_COUNT];

  целое i = 0;
loop:;
  char test[n];
  smash(test, n);
  если (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  вернуть (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

целое test3(целое n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  вернуть (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  если (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    если (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } иначе { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

целое основной(целое argc, char **argv) {
  const char *testname = NULL;
  целое retval = EXIT_SUCCESS;
  если (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  вернуть retval;
}
