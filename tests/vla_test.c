/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>

#define LOOP_ଗଣନା 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
ଶୂନ୍ୟ smash(ଅକ୍ଷର *p, ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  memset(p, 0, n);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
  ଅକ୍ଷର *array_ptrs[LOOP_ଗଣନା];
  
  ପାଇଁ (i = 0; i < LOOP_ଗଣନା; ++i) {
    ଅକ୍ଷର test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ଫେରନ୍ତୁ (array_ptrs[0]-array_ptrs[LOOP_ଗଣନା-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ପୂର୍ଣ୍ଣସଂଖ୍ୟା test2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  ଅକ୍ଷର *array_ptrs[LOOP_ଗଣନା];

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = 0;
loop:;
  ଅକ୍ଷର test[n];
  smash(test, n);
  ଯଦି (i >= LOOP_ଗଣନା)
    ଯାଅ end;
  array_ptrs[i] = test;
  ++i;
  ଯାଅ loop;

end:
  smash(test, n);
  ଅକ୍ଷର test2[n];
  smash(test2, n);
  ଫେରନ୍ତୁ (array_ptrs[0] - array_ptrs[LOOP_ଗଣନା-1] < n) ? 0 : 1;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା test3(ପୂର୍ଣ୍ଣସଂଖ୍ୟା n) {
  ଅକ୍ଷର test[n];
  smash(test, n);
  ଯାଅ label;
label:
  smash(test, n);
  ଅକ୍ଷର test2[n];
  smash(test2, n);
  ଫେରନ୍ତୁ (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ଯଦି (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ଯଦି (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } ଅନ୍ୟଥା { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv) {
  ଅଚଳ ଅକ୍ଷର *testname = ଖାଲି;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା retval = EXIT_SUCCESS;
  ଯଦି (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ଫେରନ୍ତୁ retval;
}
