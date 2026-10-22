/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <string.h>

#define LOOP_গুনতি 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
শূন্য smash(ৱর্ণ *p, পূর্ণাঙ্ক n) {
  memset(p, 0, n);
}

পূর্ণাঙ্ক test1(পূর্ণাঙ্ক n) {
  পূর্ণাঙ্ক i;
  ৱর্ণ *array_ptrs[LOOP_গুনতি];
  
  বাবে (i = 0; i < LOOP_গুনতি; ++i) {
    ৱর্ণ test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ঘূৰাই (array_ptrs[0]-array_ptrs[LOOP_গুনতি-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
পূর্ণাঙ্ক test2(পূর্ণাঙ্ক n) {
  ৱর্ণ *array_ptrs[LOOP_গুনতি];

  পূর্ণাঙ্ক i = 0;
loop:;
  ৱর্ণ test[n];
  smash(test, n);
  যদি (i >= LOOP_গুনতি)
    গচ্ছ end;
  array_ptrs[i] = test;
  ++i;
  গচ্ছ loop;

end:
  smash(test, n);
  ৱর্ণ test2[n];
  smash(test2, n);
  ঘূৰাই (array_ptrs[0] - array_ptrs[LOOP_গুনতি-1] < n) ? 0 : 1;
}

পূর্ণাঙ্ক test3(পূর্ণাঙ্ক n) {
  ৱর্ণ test[n];
  smash(test, n);
  গচ্ছ label;
label:
  smash(test, n);
  ৱর্ণ test2[n];
  smash(test2, n);
  ঘূৰাই (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  যদি (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    যদি (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } অন্যথা { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv) {
  ধ্রুৱ ৱর্ণ *testname = রিক্ত;
  পূর্ণাঙ্ক retval = EXIT_SUCCESS;
  যদি (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ঘূৰাই retval;
}
