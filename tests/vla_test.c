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
void smash(var_na *p, puur_naa_nka n) {
  memset(p, 0, n);
}

puur_naa_nka test1(puur_naa_nka n) {
  puur_naa_nka i;
  var_na *array_ptrs[LOOP_COUNT];
  
  for (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ᨀᨘᨒ (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
puur_naa_nka test2(puur_naa_nka n) {
  var_na *array_ptrs[LOOP_COUNT];

  puur_naa_nka i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  ᨀᨘ (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ᨀᨘᨒ (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

puur_naa_nka test3(puur_naa_nka n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ᨀᨘᨒ (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ᨀᨘ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ᨀᨘ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } ᨀᨘᨁ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

puur_naa_nka main(puur_naa_nka argc, var_na **argv) {
  const var_na *testname = NULL;
  puur_naa_nka retval = EXIT_SUCCESS;
  ᨀᨘ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ᨀᨘᨒ retval;
}
