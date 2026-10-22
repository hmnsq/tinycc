/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>

#define LOOP_গুনতি 1000
#define ARRAY_আকার 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
শূন্য smash(অক্ষর *p, পূর্ণসংখ্যা n) {
  memset(p, 0, n);
}

পূর্ণসংখ্যা test1(পূর্ণসংখ্যা n) {
  পূর্ণসংখ্যা i;
  অক্ষর *array_ptrs[LOOP_গুনতি];
  
  জন্য (i = 0; i < LOOP_গুনতি; ++i) {
    অক্ষর test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ফেরত (array_ptrs[0]-array_ptrs[LOOP_গুনতি-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
পূর্ণসংখ্যা test2(পূর্ণসংখ্যা n) {
  অক্ষর *array_ptrs[LOOP_গুনতি];

  পূর্ণসংখ্যা i = 0;
loop:;
  অক্ষর test[n];
  smash(test, n);
  যদি (i >= LOOP_গুনতি)
    যাও end;
  array_ptrs[i] = test;
  ++i;
  যাও loop;

end:
  smash(test, n);
  অক্ষর test2[n];
  smash(test2, n);
  ফেরত (array_ptrs[0] - array_ptrs[LOOP_গুনতি-1] < n) ? 0 : 1;
}

পূর্ণসংখ্যা test3(পূর্ণসংখ্যা n) {
  অক্ষর test[n];
  smash(test, n);
  যাও label;
label:
  smash(test, n);
  অক্ষর test2[n];
  smash(test2, n);
  ফেরত (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  যদি (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    যদি (t(ARRAY_আকার) == 0) { \
      fputs("success\n", stdout); \
    } অন্যথা { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv) {
  ধ্রুবক অক্ষর *testname = ফাঁকা;
  পূর্ণসংখ্যা retval = EXIT_SUCCESS;
  যদি (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ফেরত retval;
}
