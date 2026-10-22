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
void smash(var_na *p, ຈຳນວນເຕັມ n) {
  memset(p, 0, n);
}

ຈຳນວນເຕັມ test1(ຈຳນວນເຕັມ n) {
  ຈຳນວນເຕັມ i;
  var_na *array_ptrs[LOOP_COUNT];
  
  ສຳລັບ (i = 0; i < LOOP_COUNT; ++i) {
    var_na test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ສົ່ງຄືນ (array_ptrs[0]-array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ຈຳນວນເຕັມ test2(ຈຳນວນເຕັມ n) {
  var_na *array_ptrs[LOOP_COUNT];

  ຈຳນວນເຕັມ i = 0;
loop:;
  var_na test[n];
  smash(test, n);
  ຖ້າ (i >= LOOP_COUNT)
    goto end;
  array_ptrs[i] = test;
  ++i;
  goto loop;

end:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ສົ່ງຄືນ (array_ptrs[0] - array_ptrs[LOOP_COUNT-1] < n) ? 0 : 1;
}

ຈຳນວນເຕັມ test3(ຈຳນວນເຕັມ n) {
  var_na test[n];
  smash(test, n);
  goto label;
label:
  smash(test, n);
  var_na test2[n];
  smash(test2, n);
  ສົ່ງຄືນ (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ຖ້າ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ຖ້າ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } ບໍ່ດັ່ງນັ້ນ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ຈຳນວນເຕັມ main(ຈຳນວນເຕັມ argc, var_na **argv) {
  const var_na *testname = NULL;
  ຈຳນວນເຕັມ retval = EXIT_SUCCESS;
  ຖ້າ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ສົ່ງຄືນ retval;
}
