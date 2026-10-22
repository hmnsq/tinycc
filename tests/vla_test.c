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
void smash(char *p, số_nguyên n) {
  memset(p, 0, n);
}

số_nguyên test1(số_nguyên n) {
  số_nguyên i;
  char *array_ptrs[LOOP_COUNT];
  
  cho (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  trả_về (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
số_nguyên test2(số_nguyên n) {
  char *array_ptrs[LOOP_COUNT];

  số_nguyên i = 0;
loop:;
  char test[n];
  smash(test, n);
  nếu (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  trả_về (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

số_nguyên test3(số_nguyên n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  trả_về (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  nếu (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    nếu (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } không_thì { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

số_nguyên main(số_nguyên argc, char **argv) {
  const char *testname = NULL;
  số_nguyên retval = EXIT_SUCCESS;
  nếu (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  trả_về retval;
}
