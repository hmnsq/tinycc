/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>

#define LOOP_شمار 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
تهی smash(نویسه *p, صحیح n) {
  memset(p, 0, n);
}

صحیح test1(صحیح n) {
  صحیح i;
  نویسه *array_ptrs[LOOP_شمار];
  
  برای (i = 0; i < LOOP_شمار; ++i) {
    نویسه test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  بازگشت (array_ptrs[0]-array_ptrs[LOOP_شمار-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
صحیح test2(صحیح n) {
  نویسه *array_ptrs[LOOP_شمار];

  صحیح i = 0;
loop:;
  نویسه test[n];
  smash(test, n);
  اگر (i >= LOOP_شمار)
    برو end;
  array_ptrs[i] = test;
  ++i;
  برو loop;

end:
  smash(test, n);
  نویسه test2[n];
  smash(test2, n);
  بازگشت (array_ptrs[0] - array_ptrs[LOOP_شمار-1] < n) ? 0 : 1;
}

صحیح test3(صحیح n) {
  نویسه test[n];
  smash(test, n);
  برو label;
label:
  smash(test, n);
  نویسه test2[n];
  smash(test2, n);
  بازگشت (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  اگر (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    اگر (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } وگرنه { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

صحیح اصلی(صحیح argc, نویسه **argv) {
  ثابت نویسه *testname = پوچ;
  صحیح retval = EXIT_SUCCESS;
  اگر (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  بازگشت retval;
}
