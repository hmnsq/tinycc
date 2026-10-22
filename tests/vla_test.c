/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>

#define LOOP_عدد 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
فراغ smash(حرف *p, صحيح n) {
  memset(p, 0, n);
}

صحيح test1(صحيح n) {
  صحيح i;
  حرف *array_ptrs[LOOP_عدد];
  
  لكل (i = 0; i < LOOP_عدد; ++i) {
    حرف test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  أرجع (array_ptrs[0]-array_ptrs[LOOP_عدد-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
صحيح test2(صحيح n) {
  حرف *array_ptrs[LOOP_عدد];

  صحيح i = 0;
loop:;
  حرف test[n];
  smash(test, n);
  إذا (i >= LOOP_عدد)
    اذهب end;
  array_ptrs[i] = test;
  ++i;
  اذهب loop;

end:
  smash(test, n);
  حرف test2[n];
  smash(test2, n);
  أرجع (array_ptrs[0] - array_ptrs[LOOP_عدد-1] < n) ? 0 : 1;
}

صحيح test3(صحيح n) {
  حرف test[n];
  smash(test, n);
  اذهب label;
label:
  smash(test, n);
  حرف test2[n];
  smash(test2, n);
  أرجع (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  إذا (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    إذا (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } وإلا { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

صحيح main(صحيح argc, حرف **argv) {
  ثابت حرف *testname = عدم;
  صحيح retval = EXIT_SUCCESS;
  إذا (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  أرجع retval;
}
