/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#شامل <stdlib.h>
#شامل <stdio.h>
#شامل <string.h>

#تعریف_کرو LOOP_گنتی 1000
#تعریف_کرو ARRAY_سائز 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
خالی smash(حرف *p, صحیح n) {
  memset(p, 0, n);
}

صحیح test1(صحیح n) {
  صحیح i;
  حرف *array_ptrs[LOOP_گنتی];
  
  برائے (i = 0; i < LOOP_گنتی; ++i) {
    حرف test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  واپس (array_ptrs[0]-array_ptrs[LOOP_گنتی-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
صحیح test2(صحیح n) {
  حرف *array_ptrs[LOOP_گنتی];

  صحیح i = 0;
loop:;
  حرف test[n];
  smash(test, n);
  اگر (i >= LOOP_گنتی)
    جاؤ انتہا;
  array_ptrs[i] = test;
  ++i;
  جاؤ loop;

انتہا:
  smash(test, n);
  حرف test2[n];
  smash(test2, n);
  واپس (array_ptrs[0] - array_ptrs[LOOP_گنتی-1] < n) ? 0 : 1;
}

صحیح test3(صحیح n) {
  حرف test[n];
  smash(test, n);
  جاؤ label;
label:
  smash(test, n);
  حرف test2[n];
  smash(test2, n);
  واپس (test-test2 >= n) ? 0 : 1;
}

#تعریف_کرو تسلسل_TEST(t) \
  اگر (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    اگر (t(ARRAY_سائز) == 0) { \
      fputs("success\n", stdout); \
    } ورنہ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

صحیح مین(صحیح argc, حرف **argv) {
  ثابت حرف *testname = تہی;
  صحیح retval = EXIT_SUCCESS;
  اگر (argc > 1)
    testname = argv[1];
  تسلسل_TEST(test1)
  تسلسل_TEST(test2)
  تسلسل_TEST(test3)
  واپس retval;
}
