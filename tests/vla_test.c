/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>

#define LOOP_ಎಣಿಕೆ 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
ಶೂನ್ಯ smash(ವರ್ಣ *p, ಪೂರ್ಣಾಙ್ಕ n) {
  memset(p, 0, n);
}

ಪೂರ್ಣಾಙ್ಕ test1(ಪೂರ್ಣಾಙ್ಕ n) {
  ಪೂರ್ಣಾಙ್ಕ i;
  ವರ್ಣ *array_ptrs[LOOP_ಎಣಿಕೆ];
  
  ಪ್ರತಿ (i = 0; i < LOOP_ಎಣಿಕೆ; ++i) {
    ವರ್ಣ test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ಪ್ರತ್ಯಾಗಮ (array_ptrs[0]-array_ptrs[LOOP_ಎಣಿಕೆ-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ಪೂರ್ಣಾಙ್ಕ test2(ಪೂರ್ಣಾಙ್ಕ n) {
  ವರ್ಣ *array_ptrs[LOOP_ಎಣಿಕೆ];

  ಪೂರ್ಣಾಙ್ಕ i = 0;
loop:;
  ವರ್ಣ test[n];
  smash(test, n);
  ಯದಿ (i >= LOOP_ಎಣಿಕೆ)
    ಗಚ್ಛ end;
  array_ptrs[i] = test;
  ++i;
  ಗಚ್ಛ loop;

end:
  smash(test, n);
  ವರ್ಣ test2[n];
  smash(test2, n);
  ಪ್ರತ್ಯಾಗಮ (array_ptrs[0] - array_ptrs[LOOP_ಎಣಿಕೆ-1] < n) ? 0 : 1;
}

ಪೂರ್ಣಾಙ್ಕ test3(ಪೂರ್ಣಾಙ್ಕ n) {
  ವರ್ಣ test[n];
  smash(test, n);
  ಗಚ್ಛ label;
label:
  smash(test, n);
  ವರ್ಣ test2[n];
  smash(test2, n);
  ಪ್ರತ್ಯಾಗಮ (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  ಯದಿ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ಯದಿ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } ಅನ್ಯಥಾ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv) {
  ಧ್ರುವ ವರ್ಣ *testname = ರಿಕ್ತ;
  ಪೂರ್ಣಾಙ್ಕ retval = EXIT_SUCCESS;
  ಯದಿ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  ಪ್ರತ್ಯಾಗಮ retval;
}
