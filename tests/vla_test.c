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
void smash(char *p, ціле n) {
  memset(p, 0, n);
}

ціле test1(ціле n) {
  ціле i;
  char *array_ptrs[LOOP_COUNT];
  
  для (i = 0; i < LOOP_COUNT; ++i) {
    char test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  повернути (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ціле test2(ціле n) {
  char *array_ptrs[LOOP_COUNT];

  ціле i = 0;
loop:;
  char test[n];
  smash(test, n);
  якщо (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  повернути (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

ціле test3(ціле n) {
  char test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  char test2[n];
  smash(test2, n);
  повернути (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  якщо (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    якщо (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } інакше { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ціле main(ціле argc, char **argv) {
  const char *testname = NULL;
  ціле retval = EXIT_SUCCESS;
  якщо (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  повернути retval;
}
